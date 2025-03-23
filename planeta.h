#ifndef PLANETA_H
#define PLANETA_H
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#define PI 3.1416
#define ESCALA 0.3f

typedef struct Planeta 
{
    float semiejeMayor;      // tamaño semieixo maior (a)
    float semiejeMenor;      // tamaño semieixo menor (b)
    float centroOrbitaX;     // desprazamento sobre o centro en x
    float centroOrbitaZ;     // desprazamento sobre o centro en z
    float inclinacionOrbita; // inclinación da órbita en graos

    float giroActual;    // ángulo actual sobre si mesmo
    float velocidadGiro; // velocidade de rotación sobre o propio eixo
    float orbitaActual;  // ángulo actual na órbita
    float velocidadOrbita; // velocidade de traslación
    //? esto é para permitir velocidades de traslación e rotación distintas
    
    float radio;    // tamaño do planeta
    float color[3]; // cor do planeta 
    struct Planeta *orbitaAlrededor;  // para satélites
    int lista;   // lista GLU (será a da esfera)
    int orbitaActiva; // 0 ou 1 según se se ve a órbita
} Planeta;

void dibujarPlaneta(Planeta *p);
void myEsfera();
void obtenerPosicionPlaneta(Planeta *p, float *x, float *y, float *z);

#endif
