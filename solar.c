// ?
// * Sistema Solar
// ?

// * Autor: Manuel Pereiro Conde

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>

#include "camara.h"
#include "planeta.h"

const int W_WIDTH = 600;
const int W_HEIGHT = 600;

int listaPlaneta;
int modo = 0;


//? --- PLANETAS --- ? //
Planeta sol = {
	.semiejeMayor = 0.0f,
	.semiejeMenor = 0.0f,
	.centroOrbitaX = 0.0f,
	.centroOrbitaZ = 0.0f,
	.inclinacionOrbita = 0.0f,

	.giroActual = 0.0f,
	.orbitaActual = 0.0f,
	.velocidadGiro = 0.2f,
	.velocidadOrbita = 0.0f,

	.radio = 1.8f * ESCALA,
	.color = {1.0f, 1.0f, 0.0f},
	.orbitaAlrededor = NULL,
	.lista = 0,
	.orbitaActiva = 0};

Planeta tierra = {
	.semiejeMayor = 6.2f * ESCALA,
	.semiejeMenor = 5.7f * ESCALA,
	.centroOrbitaX = -0.4f * ESCALA,
	.centroOrbitaZ = 0.0f,
	.inclinacionOrbita = 0.0f,

	.giroActual = 0.0f,
	.orbitaActual = 0.0f,
	.velocidadGiro = 2.5f,
	.velocidadOrbita = 1.0f,

	.radio = 0.4f * ESCALA,
	.color = {0.0f, 0.0f, 1.0f},
	.orbitaAlrededor = &sol,
	.lista = 0,
	.orbitaActiva = 1};

Planeta luna = {
	.semiejeMayor = 1.2f * ESCALA,
	.semiejeMenor = 1.2f * ESCALA,
	.centroOrbitaX = 0.0f,
	.centroOrbitaZ = 0.0f,
	.inclinacionOrbita = 0.0f,

	.giroActual = 0.0f,
	.orbitaActual = 0.0f,
	.velocidadGiro = 7.0f,
	.velocidadOrbita = 10.0f,

	.radio = 0.1f * ESCALA,
	.color = {0.5f, 0.5f, 0.5f},
	.orbitaAlrededor = &tierra,
	.lista = 0,
	.orbitaActiva = 1};

Planeta marte = {
	.semiejeMayor = 7.9f * ESCALA,
	.semiejeMenor = 7.3f * ESCALA,
	.centroOrbitaX = -0.8f * ESCALA,
	.centroOrbitaZ = 0.0f,
	.inclinacionOrbita = 1.85f,

	.giroActual = 0.0f,
	.orbitaActual = 0.0f,
	.velocidadGiro = 1.9f,
	.velocidadOrbita = 0.7f,

	.radio = 0.35f * ESCALA,
	.color = {0.8f, 0.3f, 0.0f},
	.orbitaAlrededor = &sol,
	.lista = 0,
	.orbitaActiva = 1};

Planeta mercurio = {
	.semiejeMayor = 2.4f * ESCALA,
	.semiejeMenor = 2.2f * ESCALA,
	.centroOrbitaX = -0.2f * ESCALA,
	.centroOrbitaZ = 0.0f,
	.inclinacionOrbita = 7.0f,

	.giroActual = 0.0f,
	.orbitaActual = 0.0f,
	.velocidadGiro = 4.2f,
	.velocidadOrbita = 4.1f,

	.radio = 0.15f * ESCALA,
	.color = {0.5f, 0.5f, 0.5f},
	.orbitaAlrededor = &sol,
	.lista = 0,
	.orbitaActiva = 1};

Planeta venus = {
	.semiejeMayor = 3.6f * ESCALA,
	.semiejeMenor = 3.3f * ESCALA,
	.centroOrbitaX = -0.3f * ESCALA,
	.centroOrbitaZ = 0.0f,
	.inclinacionOrbita = 3.4f,

	.giroActual = 0.0f,
	.orbitaActual = 0.0f,
	.velocidadGiro = 1.8f,
	.velocidadOrbita = 1.3f,

	.radio = 0.4f * ESCALA,
	.color = {0.9f, 0.7f, 0.0f},
	.orbitaAlrededor = &sol,
	.lista = 0,
	.orbitaActiva = 1};

Planeta jupiter = {
	.semiejeMayor = 12.7f * ESCALA,
	.semiejeMenor = 12.2f * ESCALA,
	.centroOrbitaX = -1.2f * ESCALA,
	.centroOrbitaZ = 0.0f,
	.inclinacionOrbita = 1.3f,

	.giroActual = 0.0f,
	.orbitaActual = 0.0f,
	.velocidadGiro = 0.9f,
	.velocidadOrbita = 0.4f,

	.radio = 1.0f * ESCALA,
	.color = {0.8f, 0.6f, 0.3f},
	.orbitaAlrededor = &sol,
	.lista = 0,
	.orbitaActiva = 1};

Planeta saturno = {
	.semiejeMayor = 15.3f * ESCALA,
	.semiejeMenor = 14.5f * ESCALA,
	.centroOrbitaX = -1.5f * ESCALA,
	.centroOrbitaZ = 0.0f,
	.inclinacionOrbita = 2.5f,

	.giroActual = 0.0f,
	.orbitaActual = 0.0f,
	.velocidadGiro = 0.7f,
	.velocidadOrbita = 0.2f,

	.radio = 0.85 * ESCALA,
	.color = {0.9f, 0.8f, 0.5f},
	.orbitaAlrededor = &sol,
	.lista = 0,
	.orbitaActiva = 1};

Planeta urano = {
	.semiejeMayor = 18.4f * ESCALA,
	.semiejeMenor = 17.9f * ESCALA,
	.centroOrbitaX = -1.8f * ESCALA,
	.centroOrbitaZ = 0.0f,
	.inclinacionOrbita = 0.8f,

	.giroActual = 0.0f,
	.orbitaActual = 0.0f,
	.velocidadGiro = 0.5f,
	.velocidadOrbita = 0.05f,

	.radio = 0.6f * ESCALA,
	.color = {0.4f, 0.7f, 0.9f},
	.orbitaAlrededor = &sol,
	.lista = 0,
	.orbitaActiva = 1};

Planeta neptuno = {
	.semiejeMayor = 19.9f * ESCALA,
	.semiejeMenor = 19.2f * ESCALA,
	.centroOrbitaX = -2.0f * ESCALA,
	.centroOrbitaZ = 0.0f,
	.inclinacionOrbita = 1.8f,

	.giroActual = 0.0f,
	.orbitaActual = 0.0f,
	.velocidadGiro = 0.4f,
	.velocidadOrbita = 0.03f,

	.radio = 0.55f * ESCALA,
	.color = {0.2f, 0.4f, 0.8f},
	.orbitaAlrededor = &sol,
	.lista = 0,
	.orbitaActiva = 1};

Planeta pluton = {
	.semiejeMayor = 23.5f * ESCALA,
	.semiejeMenor = 22.0f * ESCALA,
	.centroOrbitaX = -2.3f,
	.centroOrbitaZ = 0.0f,
	.inclinacionOrbita = 17.2f,

	.giroActual = 0.0f,
	.orbitaActual = 0.0f,
	.velocidadGiro = 0.2f,
	.velocidadOrbita = 0.01f,

	.radio = 0.25f * ESCALA,
	.color = {0.6f, 0.4f, 0.3f},
	.orbitaAlrededor = &sol,
	.lista = 0,
	.orbitaActiva = 1};

Planeta ISS = {
	.semiejeMayor = 0.7f * ESCALA,
	.semiejeMenor = 0.6f * ESCALA,
	.centroOrbitaX = 0.0f,
	.centroOrbitaZ = 0.0f,
	.inclinacionOrbita = 51.6f,

	.giroActual = 0.0f,
	.orbitaActual = 0.0f,
	.velocidadGiro = -15.0f,
	.velocidadOrbita = 16.0f,

	.radio = 0.05f * ESCALA,
	.color = {1.0f, 1.0f, 1.0f},
	.orbitaAlrededor = &tierra,
	.lista = 0,
	.orbitaActiva = 1};

// ? --- MOVIMIENTO --- ? //
void actualizarPosicion(Planeta *p)
{
	p->giroActual += p->velocidadGiro;
	p->orbitaActual += p->velocidadOrbita;

	if (p->giroActual >= 360.0f)
		p->giroActual -= 360.0f;

	if (p->orbitaActual >= 360.0f)
		p->orbitaActual -= 360.0f;
}

Planeta *planetas[] = {&sol, &tierra, &ISS, &luna, &marte,   &mercurio, &venus, 
                       &jupiter, &saturno, &urano, &neptuno, &pluton};

void actualizarOrbita(int value)
{
    for (int i = 0; i < sizeof(planetas) / sizeof(planetas[0]); i++)
    {
        actualizarPosicion(planetas[i]);
    }

    glutPostRedisplay();
    glutTimerFunc(50, actualizarOrbita, 0);
}


// ? --- DIBUJO --- ? //
void ejes(){

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(1.5f, 0.0f, 0.0f);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.5f, 0.0f);
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0, 1.5f);
    glEnd();

    // Diagonal
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0.5, 0.5f);
    glEnd();
}


void listaEsfera() // para ter os eixos dentro dos planetas
{
	listaPlaneta = glGenLists(1);
	glNewList(listaPlaneta, GL_COMPILE);
	myEsfera();
	ejes();
	glEndList();
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    camera();


    // Debuxar Sol e planetas
    for (int i = 0; i < sizeof(planetas) / sizeof(planetas[0]); i++) {
        planetas[i]->lista = listaPlaneta;
        dibujarPlaneta(planetas[i]);
		if (planetas[i] != &tierra)
			glPopMatrix();
		if (planetas[i] == &luna)
			glPopMatrix();
    }
	//? Se é a terra non fai popmatrix para que a lúa e a ISS orbiten arredor dela
	//? Se é a lúa, fai 2 popmatrix para saír da órbita da terra tras dibuxarse



    glutSwapBuffers();
}

// ? --- TECLADO --- ? //
//? Permite mover telescopio e activar/desactivar órbitas
void especiales(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_F1:
		activarTelescopio();
		situarTelescopio(&tierra);
		apuntarTelescopio(&marte);
		break;

	case GLUT_KEY_F2:

		tierra.orbitaActiva = !tierra.orbitaActiva;
		break;

	case GLUT_KEY_F3:
		marte.orbitaActiva = !marte.orbitaActiva;
		break;

	case GLUT_KEY_F4:
		mercurio.orbitaActiva = !mercurio.orbitaActiva;
		break;

	case GLUT_KEY_F5:
		venus.orbitaActiva = !venus.orbitaActiva;
		break;

	case GLUT_KEY_F6:
		jupiter.orbitaActiva = !jupiter.orbitaActiva;
		break;

	case GLUT_KEY_F7:
		saturno.orbitaActiva = !saturno.orbitaActiva;
		break;

	case GLUT_KEY_F8:
		urano.orbitaActiva = !urano.orbitaActiva;
		break;

	case GLUT_KEY_F9:
		neptuno.orbitaActiva = !neptuno.orbitaActiva;
		break;

	case GLUT_KEY_F10:
		pluton.orbitaActiva = !pluton.orbitaActiva;
		break;

	case GLUT_KEY_F11:
		ISS.orbitaActiva = !ISS.orbitaActiva;
		break;

	case GLUT_KEY_F12:
		luna.orbitaActiva = !luna.orbitaActiva;
		break;

	case GLUT_KEY_RIGHT:
		printf("Apuntando desde la Luna...\n");
		situarTelescopio(&luna);
		break;

	case GLUT_KEY_LEFT:
		printf("Apuntando desde la Tierra...\n");
		situarTelescopio(&tierra);
		break;

	case GLUT_KEY_UP:
		printf("Apuntando desde la ISS...\n");
		situarTelescopio(&ISS);
		break;

	case GLUT_KEY_DOWN:
		printf("Apuntando desde el Sol...\n");
		situarTelescopio(&sol);
		break;

	case GLUT_KEY_PAGE_UP:

		{
			if (modo == 0)
			{
				printf("Modo polígono: relleno\n");
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}
			else
			{
				printf("Modo polígono: línea\n");
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}
			modo = !modo;
		}
		break;
	}
}

void menu(int opcion)
{
	if (telescopioActivo == 0)
	{
		printf("El telescopio no está activo! Se puede activar con F1.\n");
		return;
	}
	switch (opcion)
	{
	case 1:
		printf("Apuntando a la Tierra...\n");
		apuntarTelescopio(&tierra);
		break;
	case 2:
		printf("Apuntando a Marte...\n");
		apuntarTelescopio(&marte);
		break;
	case 3:
		printf("Apuntando a Mercurio...\n");
		apuntarTelescopio(&mercurio);
		break;
	case 4:
		printf("Apuntando a Venus...\n");
		apuntarTelescopio(&venus);
		break;
	case 5:
		printf("Apuntando a Júpiter...\n");
		apuntarTelescopio(&jupiter);
		break;
	case 6:
		printf("Apuntando a Saturno...\n");
		apuntarTelescopio(&saturno);
		break;
	case 7:
		printf("Apuntando a Urano...\n");
		apuntarTelescopio(&urano);
		break;
	case 8:
		printf("Apuntando a Neptuno...\n");
		apuntarTelescopio(&neptuno);
		break;
	case 9:
		printf("Apuntando a Plutón...\n");
		apuntarTelescopio(&pluton);
		break;
	case 10:
		printf("Apuntando a la ISS...\n");
		apuntarTelescopio(&ISS);
		break;
	case 11:
		printf("Apuntando a la Luna...\n");
		apuntarTelescopio(&luna);
		break;
	}
}

void crearMenu()
{
	int menuPlanetas = glutCreateMenu(menu);
	glutAddMenuEntry("Tierra", 1);
	glutAddMenuEntry("Marte", 2);
	glutAddMenuEntry("Mercurio", 3);
	glutAddMenuEntry("Venus", 4);
	glutAddMenuEntry("Júpiter", 5);
	glutAddMenuEntry("Saturno", 6);
	glutAddMenuEntry("Urano", 7);
	glutAddMenuEntry("Neptuno", 8);
	glutAddMenuEntry("Plutón", 9);
	glutAddMenuEntry("ISS", 10);
	glutAddMenuEntry("Luna", 11);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void openGLInit()
{
	glClearDepth(1.0f);
	glClearColor(0.0f, 0.0f, 0.01f, 1.0f);
	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_NORMALIZE);
	glCullFace(GL_BACK);
	resetCamera(0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
}

// ? --- MAIN --- ? //
int main(int argc, char **argv)
{
	// init
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(W_WIDTH, W_HEIGHT);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("Sistema solar");
	listaEsfera();
	openGLInit();
	crearMenu();
	glutReshapeFunc(perspectiva);
	glutKeyboardFunc(teclado);
	glutSpecialFunc(especiales);

	glutDisplayFunc(myDisplay);
	glutMotionFunc(ratonMov);
	glutMouseFunc(ratonClick);

	glutTimerFunc(50, actualizarOrbita, 0);
	glutMainLoop();
	return 0;
}
