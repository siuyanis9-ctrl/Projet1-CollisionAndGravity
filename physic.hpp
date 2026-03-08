#ifndef PHYSIC
#define PHYSIC

#include <cmath>
#include "ball.hpp"

class Vecteur {
public:
	float x;
	float y;
};

bool collision(BALL un, BALL deux);
Vecteur vecteurNormaleCreation(BALL un, BALL deux);
Vecteur vecteurAccelerationCreationTerrestre(float forceNHB, float forceNGD);
void vitesseUpdateCollide(BALL* un, BALL* deux, Vecteur normale);
void vitesseUpdateGravity(BALL* ball, Vecteur acceleration, float resistance);

#endif