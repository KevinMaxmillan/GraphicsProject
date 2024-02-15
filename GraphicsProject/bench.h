#pragma once
#include <gl\glut.h>
#include <math.h>

void bench() {
	glColor3f(0.37, 0.18, 0.05);

	glPushMatrix();
	glTranslatef(2.5, 1.5, 0);
	glScalef(0.2,3,0.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, 1.5, 0);
	glScalef(0.2, 3, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.5, 0.75, 1.5);
	glScalef(0.2, 1.5, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, 0.75, 1.5);
	glScalef(0.2, 1.5, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 2.25, 0);
	glScalef(5, 1, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.5, 0.85);
	glScalef(5.4, 0.2, 1.7);
	glutSolidCube(1);
	glPopMatrix();
}