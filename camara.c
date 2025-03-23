// ?
// * Cámara
// ?

#include "camara.h"
#include "planeta.h"
#include <stdio.h>
#define PI 3.1416

// cámara:
float angulo = 0.0f, beta = 0.0f, vel = 0.2f * ESCALA;
float camX = -9.0f, camY = 1.0f, camZ = 0.0f;
float enfoqueX = -8.0f, enfoqueY = 1.0, enfoqueZ = 0.0f;
float arribaX = 0.0f, arribaY = 1.0f, arribaZ = 0.0f;
float fov = 30.0f;

// telescopio: (o planeta ao que enfoca controlase en solar.c)
int telescopioActivo = 0;
Planeta *baseTelescopio = NULL;
Planeta *enfoqueTelescopio = NULL;

// rato para arrastrar a cámara
int ratonOrigenX, ratonOrigenY, ratonPulsado = 0;
float velRaton = 0.5f;

// ? --- TELESCOPIO --- ? //
void activarTelescopio()
{
    telescopioActivo = !telescopioActivo;
    if (telescopioActivo)
    {
        printf("Telescopio activado\n");
    }
    else
    {
        printf("Telescopio desactivado\n");
        resetCamera(2);
    }
}

void situarTelescopio(Planeta *planeta)
{
    if (planeta == enfoqueTelescopio)
    {
        printf("Error: el telescopio no puede apuntar a si mismo\n");
        return;
    }
    baseTelescopio = planeta;
}

void apuntarTelescopio(Planeta *planeta)
{
    if (planeta == baseTelescopio)
    {
        printf("Error: el telescopio no puede apuntar a si mismo\n");
        return;
    }
    enfoqueTelescopio = planeta;
}

// ? --- REDIMENSIONADO --- ? //

void perspectiva(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fov, (float)w / (float)h, 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

// ? --- CÁMARA --- ? //

void camera()
{
    if (telescopioActivo)
    {
        obtenerPosicionPlaneta(baseTelescopio, &camX, &camY, &camZ);
        obtenerPosicionPlaneta(enfoqueTelescopio, &enfoqueX, &enfoqueY, &enfoqueZ);
    }
    else
    {
        if (angulo > 89.0f)
            angulo = 89.0f;
        if (angulo < -89.0f)
            angulo = -89.0f;
        float radY = beta * PI / 180.0f;
        float radX = angulo * PI / 180.0f;
        enfoqueX = camX + cos(radY) * cos(radX);
        enfoqueY = camY + sin(radX);
        enfoqueZ = camZ + sin(radY) * cos(radX);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camX, camY, camZ, enfoqueX, enfoqueY, enfoqueZ, arribaX, arribaY, arribaZ);
}

void resetCamera(int pos)
{
    angulo = 0.0f;
    beta = 0.0f;
    vel = 0.1f;
    if (pos == 0) // posición inicial
    {
        camX = -7.5f;
        camY = 7.5f;
        camZ = 0.0f;
        enfoqueX = -3.5f;
        enfoqueY = 3.5f;
        enfoqueZ = 0.0f;
        angulo = -45;
    }
    else if (pos == 1) // vista desde arrba
    {
        camX = 0.0f;
        camY = 8.0f;
        camZ = 0.0f;
        enfoqueX = 0.0f;
        enfoqueY = 6.0f;
        enfoqueZ = 0.0f;
        angulo = -90;
    }
    else if (pos == 2) // vista plana
    {
        camX = -9.0f;
        camY = 1.0f;
        camZ = 0.0f;
        enfoqueX = -8.0f;
        enfoqueY = 1.0f;
        enfoqueZ = 0.0f;
        angulo = 0;
    }
    arribaX = 0.0f;
    arribaY = 1.0f;
    arribaZ = 0.0f;
    fov = 45.0f;
    camera();
}

// ? --- ENTRADA --- ? //
void ratonMov(int x, int y)
{
    if (ratonPulsado)
    {
        int dx = x - ratonOrigenX;
        int dy = y - ratonOrigenY;

        beta -= dx * 0.2f;  
        angulo += dy * 0.2f;
        ratonOrigenX = x;
        ratonOrigenY = y;

        camera();
        glutPostRedisplay();
    }
}

void ratonClick(int tecla, int raton, int x, int y)
{
    if (tecla == GLUT_LEFT_BUTTON)
    { //? permite arrastrar co rato (clic esquerdo)
        if (raton == GLUT_DOWN)
        {
            ratonPulsado = 1;
            ratonOrigenX = x;
            ratonOrigenY = y;
        }
        else
        {
            ratonPulsado = 0;
        }
    }
}

void teclado(unsigned char tecla, int x, int y)
{
    switch (tecla)
    {
    case 'w': // Avanzar
        camX += cos(beta * PI / 180.0f) * vel;
        camZ += sin(beta * PI / 180.0f) * vel;
        break;
    case 's': // Retroceder
        camX -= cos(beta * PI / 180.0f) * vel;
        camZ -= sin(beta * PI / 180.0f) * vel;
        break;
    case 'a': // Mover á esquerda
        camX -= sin(beta * PI / 180.0f) * vel;
        camZ += cos(beta * PI / 180.0f) * vel;
        break;
    case 'd': // Mover á dereita
        camX += sin(beta * PI / 180.0f) * vel;
        camZ -= cos(beta * PI / 180.0f) * vel;
        break;

    case 'q': // Subir
        camY += vel;
        break;
    case 'e': // Baixar
        camY -= vel;
        break;
    
    // Posiciones cámara:
    case 'c':
        resetCamera(0);
        break;
    case 'x':
        resetCamera(1);
        break;
    case 'z':
        resetCamera(2);
        break;

    // Zoom:
    case '+': 
        if (fov > 10.0f)
            fov -= 2.0f;
        perspectiva(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
        break;
    case '-': 
        if (fov < 90.0f)
            fov += 2.0f;
        perspectiva(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
        break;
    case 'm': // Imprimir variables da cámara
        printf("Posición de la cámara: X=%.2f, Y=%.2f, Z=%.2f\n", camX, camY, camZ);
        printf("Enfoque de la cámara: X=%.2f, Y=%.2f, Z=%.2f\n", enfoqueX, enfoqueY, enfoqueZ);
        printf("Ángulo de la cámara: %.2f\n", angulo);
        printf("Beta de la cámara: %.2f\n", beta);
        printf("Velocidad de la cámara: %.2f\n", vel);
        printf("FOV de la cámara: %.2f\n", fov);
        break;
    case 27: // ESC para saír
        exit(0);
    }
    camera();
    glutPostRedisplay();
}
