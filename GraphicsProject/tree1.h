#pragma once
#include <gl\glut.h>
#include <math.h>
GLUquadricObj* quadratic2 = gluNewQuadric();

void bush(float radius) {

	

}
void trunk() {

	glColor3f(0.37, 0.18, 0.05);

	glPushMatrix();
	glTranslatef(0, 7, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 0.1, 0.5, 7, 1000, 1000);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 5, 0);
	glRotatef(-30, 1, 0, 0);
	gluCylinder(quadratic, 0.1, 0.05, 2, 1000, 1000);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 5.5, 0);
	glRotatef(-180, 0, 1, 0);
	glRotatef(-30, 1, 0, 0);
	gluCylinder(quadratic, 0.1, 0.05, 2, 1000, 1000);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 6, 0);
	glRotatef(-240, 0, 1, 0);
	glRotatef(-30, 1, 0, 0);
	gluCylinder(quadratic, 0.1, 0.05, 2, 1000, 1000);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 4.5, 0);
	glRotatef(-300, 0, 1, 0);
	glRotatef(-30, 1, 0, 0);
	gluCylinder(quadratic, 0.1, 0.05, 1, 1000, 1000);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 5.5, 0);
	glRotatef(-90, 0, 1, 0);
	glRotatef(-30, 1, 0, 0);
	gluCylinder(quadratic, 0.1, 0.05, 1, 1000, 1000);
	glPopMatrix();

}

void tree() {
	
	trunk();
	
}