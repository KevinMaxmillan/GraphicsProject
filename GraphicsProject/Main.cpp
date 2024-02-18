#include <gl\glut.h>
#include "lamppost.h"
#include "tank.h"
#include "tree1.h"
#include "bench.h"
#include "building1.h"
#include "floor.h"
#include "building2.h"
#include "building3.h"
#include "building4.h"
#include "fence.h"
#include "barrels.h"
#include "wreckedobjects.h"
#include "soldier.h"

GLfloat camX = 0.0; GLfloat camY = 0.0; GLfloat camZ = 0.0;
GLfloat sceRX = 0.0; GLfloat sceRY = 0.0; GLfloat sceRZ = 0.0;
GLfloat sceTX = 0.0; GLfloat sceTY = 0.0; GLfloat sceTZ = 0.0;
GLfloat objRX = 0.0; GLfloat objRY = 0.0; GLfloat objRZ = 0.0;
GLfloat objTX = 0.0; GLfloat objTY = 0.0; GLfloat objTZ = 0.0;
GLfloat Look = 0.0;
GLfloat a = 0;


void setLighting() {

	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	GLfloat qaAmbientLight[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat qaDiffuseLight[] = { 1, 1, 1, 1.0 };
	GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	GLfloat qaLightPosition[] = { -4.0, 5,a, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);

	glLightfv(GL_LIGHT1, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, qaSpecularLight);

	GLfloat qaLightPosition1[] = { 4.0, 5,a, 1.0 };
	glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);

	GLfloat SpecRef[] = { 0.7,0.7,0.7,1.0 };
	GLint Shine = 128;
	glShadeModel(GL_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, SpecRef);
	glMateriali(GL_FRONT, GL_SHININESS, Shine);

}
void Movingtank() {
	glTranslatef(0, 0.8, 0);
	glTranslatef(objTX, objTY, objTZ);
	glRotatef(objRY, 0.0, 1.0, 0.0);
	Tank();
}
void init(void) {
	glClearColor(0.0, 0, 0, 1.0);
	glClearDepth(1.0);

	glEnable(GL_TEXTURE_2D);

	glEnable(GL_DEPTH_TEST);
	
	loadTexture();
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	setLighting();

	glPushMatrix();
	gluLookAt(7.0+camX, 10 + camY, 0+camZ, 0.0, 4, 0.0, 0.0, 2.0, 0.0);
	glTranslatef(sceTX, sceTY, sceTZ);
	glRotatef(sceRY, 0.0, 1.0, 0.0);
	

	building1();
	building2();
	building3();
	building4();
	fenceplacement();
	lamppostplacement();
	street();
	tree();
	wreckagepositioning();
	barrelPositioning();
	soldierset1();
	soldierset2();
	cylinderbackground();
	Movingtank();

	glPopMatrix();

	glutSwapBuffers();
}
void reshape(GLsizei w, GLsizei h) {

	glViewport(0, 0, w, h);
	GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(120.0, aspect_ratio, 1.0, 100.0);
}
void keyboardSpecial(int key, int x, int y) {
	if (key == GLUT_KEY_UP)
		camY += 1;
	if (key == GLUT_KEY_DOWN)
		camY -= 1;
	if (key == GLUT_KEY_RIGHT)
		sceTX += 1;
	if (key == GLUT_KEY_LEFT)
		sceTX -= 1;
	glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y) {
	
	//camera views
	if (key == '1') {
		camX = -7;
		camZ = 13;
		camY = 0;

	}
		

	if (key == '2') {
		camX = -7;
		camY = 15;
		camZ = 25;

	}

	if (key == '3') {
		camX = 0;
		camY = 0;
		camZ = 0;

	}
	

	if (key == 'x')
		a += 1;
	if (key == 'X')
		a -= 1;

	if (key == 'Z')
		sceTZ += 1;
	if (key == 'z')
		sceTZ -= 1;

	//tank movement
	if (key == 'w')
		objTX -= 0.5;

	if (key == 's')
		objTX += 0.5;

	if (key == 'w')
		wr += 20;
	
	if (key == 's')
		wr -= 20;

	if (key == 'w')
		sceTX += 0.5;

	if (key == 's')
		sceTX -= 0.5;

	//weapon rotation
	if (key == 'q')
		if (weaponR != 60)
			weaponR += 5;

	if (key == 'e')
		if(weaponR != -60)
			weaponR -= 5;

	if (key == 'e')
		if (sceRY != 60)
			sceRY += 5;

	if (key == 'q')
		if (sceRY != -60)
			sceRY -= 5;


	//tank rotation
	if (key == 'a')

		objRY += 2;

	if (key == 'd')
		objRY -= 2;

	if (key == 'a')

		sceRY -= 2;

	if (key == 'd')
		sceRY += 2;


	//scene rotation
	if (key == 'y')
		sceRY += 5;
	if (key == 'Y')
		sceRY -= 5;

	glutPostRedisplay();
}
void main(int) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1080, 1080);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Complex 3D Shapes");
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboardSpecial);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	init();
	glutMainLoop();
}