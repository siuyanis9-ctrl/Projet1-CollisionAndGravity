#ifndef OBJET
#define OBJET

#include <SDL.h>

class SPEED {
public:
	float vx;
	float vy;
};

class COLOR {
public:
	int r;
	int g;
	int b;
};

class BALL {
public:
	float x;
	float y;
	float radius;
	SPEED speed;
	COLOR color;

	void drawCircle(SDL_Renderer* renderer) {
		SDL_SetRenderDrawColor(renderer, color.r, color.b, color.g, 255);
		for (float w = 0; w < radius * 2; w++) {
			for (int h = 0; h < radius * 2; h++) {
				float dx = radius - w;
				float dy = radius - h;
				if ((dx * dx + dy * dy) <= (radius * radius)) {
					SDL_RenderDrawPoint(renderer, (int)(x + dx), (int)(y + dy));
				}
			}
		}
	}
	void collisionRebord(float hauteur, float largeur) {
		if (x + radius >= largeur) {
			// permet de tp la ball un peu plus loin pour eviter quelle rebondisse dans le rebord 
			x = largeur - radius;
			speed.vx *= -1;
		}
		else if (x - radius <= 0) {
			x = radius;
			speed.vx *= -1;
		}

		if (y + radius >= hauteur) {
			y = hauteur - radius;
			speed.vy *= -1;
		}
		else if (y - radius <= 0) {
			y = radius;
			speed.vy *= -1;
		}
	}
	void mouvement() {
		x += speed.vx;
		y += speed.vy;
	}
};

#endif