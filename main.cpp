#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "ball.hpp"
#include "physic.hpp"

#define WIDTH 1280
#define HEIGH 720
#define NBALL 5
#define FORCEHB 0.2f
#define FORCEGD 0.5f
#define RESISTANCE 0.99f


BALL initialisationBall() {
	BALL tmp;
	tmp.x = float(rand() % (WIDTH - 30) + 30);
	tmp.y = float(rand() % (HEIGH - 30) + 30);
	tmp.radius = 20;
	tmp.color.r = Uint8(rand() % 256);
	tmp.color.g = Uint8(rand() % 256);
	tmp.color.b = Uint8(rand() % 256);
	tmp.speed.vx = float((rand() % 6) + 1);
	tmp.speed.vy = float((rand() % 6) + 1);
	return tmp;
}

void resoudreChevauchement(BALL* un, BALL* deux) {
	float dx = deux->x - un->x;
	float dy = deux->y - un->y;
	float distance = sqrtf(dx * dx + dy * dy);
	float distanceMin = un->radius + deux->radius;

	if (distance < distanceMin && distance > 0) {
		float overlap = distanceMin - distance;

		float nx = dx / distance;
		float ny = dy / distance;

		un->x -= nx * (overlap * 0.5f);
		un->y -= ny * (overlap * 0.5f);

		deux->x += nx * (overlap * 0.5f);
		deux->y += ny * (overlap * 0.5f);
	}
}

int main(int argc, char* argv[]) {
	srand((unsigned int)time(NULL));

	SDL_Window* window = NULL;
	SDL_Renderer* rendu = NULL;
	SDL_Event ev;

	BALL test[NBALL];
	Vecteur normale;
	Vecteur acceleration;

	bool running = true;

	float largeur = float(WIDTH);
	float hauteur = float(HEIGH);

	float intensiteForceHB = 0;
	float intensiteForceGD = 0;
	float resistance = 1;



	// Initialisation 
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cerr << "Echec Initilisation : " << SDL_GetError() << std::endl;
		return 1;
	}

	window = SDL_CreateWindow("Simulateur", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, int(largeur), int(hauteur), SDL_WINDOW_SHOWN);
	if (!window) {
		std::cerr << "Pointeur windows est NULL" << std::endl;
		return 1;
	}

	rendu = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!rendu) {
		std::cerr << "Echec Initilisation : " << SDL_GetError() << std::endl;
		return 1;
	}


	for (int i = 0; i < NBALL; i++) {
		test[i] = initialisationBall();
	}

	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);

	// Boucle

	while (running) {
		while (SDL_PollEvent(&ev) != 0) {
			switch (ev.type) {
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				switch (ev.key.keysym.sym) {
				case SDLK_k:
					intensiteForceHB = -intensiteForceHB;
					std::cout << "Gravite HB inversee : " << intensiteForceHB << std::endl;
					break;

				case SDLK_m:
					intensiteForceGD = -intensiteForceGD;
					std::cout << "Gravite GD inversee : " << intensiteForceGD << std::endl;
					break;

				case SDLK_j:
					if (intensiteForceHB != 0) {
						intensiteForceHB = 0;
						std::cout << "Gravite HB : OFF" << std::endl;
					}
					else {
						intensiteForceHB = FORCEHB;
						std::cout << "Gravite HB : ON" << std::endl;
					}
					break;

				case SDLK_l:
					if (intensiteForceGD != 0) {
						intensiteForceGD = 0;
						std::cout << "Gravite GD : OFF" << std::endl;
					}
					else {
						intensiteForceGD = FORCEGD;
						std::cout << "Gravite GD : ON" << std::endl;
					}
					break;

				case SDLK_b:
					if (intensiteForceGD != 0 || intensiteForceHB != 0) {
						intensiteForceGD = 0;
						intensiteForceHB = 0;
						std::cout << "Gravite ALL : OFF" << std::endl;
					}
					else {
						intensiteForceGD = FORCEGD;
						intensiteForceHB = FORCEHB;
						std::cout << "Gravite ALL : ON" << std::endl;
					}
					break;

				case SDLK_n:
					if (resistance != 1.0f) {
						resistance = 1.0f;
						std::cout << "Resistance : OFF" << std::endl;
					}
					else {
						resistance = RESISTANCE;
						std::cout << "Resistance : ON" << std::endl;
					}
					break;
				}
			}
		}
		SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
		SDL_RenderClear(rendu);
		acceleration = vecteurAccelerationCreationTerrestre(intensiteForceHB, intensiteForceGD);

		for (int i = 0; i < NBALL; i++) {
			vitesseUpdateGravity(&test[i], acceleration, resistance);
			test[i].mouvement();
			test[i].collisionRebord(hauteur, largeur);
		}

		for (int i = 0; i < NBALL; i++) {
			for (int j = i + 1; j < NBALL; j++) {
				resoudreChevauchement(&test[i], &test[j]);
				if (collision(test[i], test[j])) {
					normale = vecteurNormaleCreation(test[i], test[j]);
					vitesseUpdateCollide(&test[i], &test[j], normale);
				}
			}
		}

		for (int i = 0; i < NBALL; i++) {
			test[i].drawCircle(rendu);
		}

		SDL_RenderPresent(rendu);

		SDL_Delay(1);
	}

	// Fin

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
