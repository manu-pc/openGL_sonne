#ifndef CAMARA_H
#define CAMARA_H

#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdio.h>
#include <math.h>
#include "planeta.h"

#define PI 3.1416

// variables cámara:
extern float angulo, beta, vel;
extern float camX, camY, camZ;
extern float enfoqueX, enfoqueY, enfoqueZ;
extern float arribaX, arribaY, arribaZ;
extern float fov;

// variables rato para arrastrar
extern int ratonOrigenX, ratonOrigenY, ratonPulsado;
extern float velRaton;

// telescopio
extern int telescopioActivo;

// funciones cámara
void perspectiva(int w, int h);
void camera();
void resetCamera(int pos);
void ratonMov(int x, int y);
void ratonClick(int tecla, int raton, int x, int y);
void ratonRueda(int tecla, int dir, int x, int y);
void teclado(unsigned char tecla, int x, int y);
void activarTelescopio();
void situarTelescopio(Planeta *planeta);
void apuntarTelescopio(Planeta *planeta);

#endif 