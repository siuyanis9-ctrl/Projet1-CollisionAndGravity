#include "physic.hpp"

bool collision(BALL un, BALL deux) {
	float vectDisX = deux.x - un.x;
	float vectDisY = deux.y - un.y;

	float distanceCarre = (vectDisX * vectDisX) + (vectDisY * vectDisY);
	float rayonCarre = (un.radius + deux.radius) * (un.radius + deux.radius);

	if (distanceCarre <= rayonCarre) return true;
	return false;
}

Vecteur vecteurNormaleCreation(BALL un, BALL deux) {
	float vectDisX = deux.x - un.x;
	float vectDisY = deux.y - un.y;

	float distance = sqrt((vectDisX * vectDisX) + (vectDisY * vectDisY));
	if (distance == 0) return { 1, 0 };

	Vecteur vectNormale;
	vectNormale.x = vectDisX / distance;
	vectNormale.y = vectDisY / distance;

	return vectNormale;
}

Vecteur vecteurAccelerationCreationTerrestre(float hb, float gd) {
	Vecteur acceleration;
	acceleration.x = gd;
	acceleration.y = hb;

	return acceleration;
}

void vitesseUpdateCollide(BALL* un, BALL* deux, Vecteur normale) {
	float v_n_balle1 = (un->speed.vx * normale.x) + (un->speed.vy * normale.y);
	float v_n_balle2 = (deux->speed.vx * normale.x) + (deux->speed.vy * normale.y);

	float pulse = v_n_balle1 - v_n_balle2;
	if (pulse < 0) return;

	// Collide
	un->speed.vx -= pulse * normale.x;
	un->speed.vy -= pulse * normale.y;

	deux->speed.vx += pulse * normale.x;
	deux->speed.vy += pulse * normale.y;
}

void vitesseUpdateGravity(BALL* ball, Vecteur acceleration, float resistance) {
	ball->speed.vx = (ball->speed.vx + acceleration.x) * resistance;
	ball->speed.vy = (ball->speed.vy + acceleration.y) * resistance;
}