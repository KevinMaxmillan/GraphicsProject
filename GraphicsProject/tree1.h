#pragma once
#include <gl\glut.h>
#include <math.h>

void bush() {

	
	glColor3f(0,0.4,0);
	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	glutSolidSphere(1, 250, 250);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.7, 0.1, 0);
	glutSolidSphere(0.8, 250, 250);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.7, 0, 0);
	glutSolidSphere(0.8, 250, 250);
	glPopMatrix();

	

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
	glRotatef(-270, 0, 1, 0);
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
void bushplacement() {
	glPushMatrix();
	glTranslatef(0,7, 0);
	glRotatef(-15, 0, 1, 0);
	bush();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 5.8, 1.4);
	glRotatef(45, 0, 1, 0);
	glScalef(0.6, 0.6, 0.6);
	bush();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 6.3, -1.5);
	glScalef(0.7, 0.7, 0.7);
	bush();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 5, 0.5);
	glScalef(0.4, 0.4, 0.4);
	bush();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1, 6, 0);
	glRotatef(-45, 0, 1, 0);
	glScalef(0.5, 0.5, 0.5);
	bush();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.3, 6.5, 0);
	glRotatef(60, 0, 1, 0);
	glScalef(0.7, 0.7, 0.7);
	bush();
	glPopMatrix();

}
void tree() {


	bushplacement();
	trunk();
	
}