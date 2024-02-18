#pragma once
#include <gl\glut.h>
#include <math.h>

GLUquadricObj* quadratic2 = gluNewQuadric();


void head() {
	//head
	glPushMatrix();
	glColor3f(0.92, 0.78, 0.62);
	glTranslatef(0, 4, 0);
	glScalef(0.55, 0.65, 0.55);
	glutSolidSphere(0.4, 100, 100);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0, 0.2, 0);
	glTranslatef(0, 3.8, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic2,0.6, 0.3, 1, 100, 100);
	glPopMatrix();

}
void arms() {
	//upper hand
	glPushMatrix();
	glColor3f(0, 0.2, 0);
	glTranslatef(0.6, 3.65, 0);
	glRotatef(-10, 0, 1, 0);
	glRotatef(40, 1, 0, 0);
	gluCylinder(quadratic2,0.2, 0.15, 1,100,100);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0, 0.2, 0);
	glTranslatef(-0.6, 3.7, 0);
	glRotatef(-10, 0, 1, 0);
	glRotatef(80, 1, 0, 0);
	gluCylinder(quadratic2, 0.2, 0.15, 1, 100, 100);
	glPopMatrix();

	//forearms
	glPushMatrix();
	glColor3f(0.92, 0.78, 0.62);
	glTranslatef(0.5, 3, 0.7);
	glRotatef(-10, 0, 1, 0);
	glRotatef(-35, 1, 0, 0);
	gluCylinder(quadratic2, 0.1, 0.07, 1, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.92, 0.78, 0.62);
	glTranslatef(-0.6, 2.6, 0.3);
	glRotatef(30, 0, 1, 0);
	glRotatef(-65, 1, 0, 0);
	gluCylinder(quadratic2, 0.1, 0.07, 1, 100, 100);
	glPopMatrix();

}
void legs() {
	//upperleg
	glPushMatrix();
	glColor3f(0, 0.2, 0);
	glTranslatef(0.3, 2.7, 0);
	glRotatef(70, 1, 0, 0);
	gluCylinder(quadratic2, 0.3, 0.25, 1.2, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0.2, 0);
	glTranslatef(-0.3, 2.7, 0);
	glRotatef(100, 1, 0, 0);
	gluCylinder(quadratic2, 0.3, 0.25, 1.2, 100, 100);
	glPopMatrix();

	//calf
	glPushMatrix();
	glColor3f(0, 0.2, 0);
	glTranslatef(0.3, 1.6, 0.3);
	glRotatef(110, 1, 0, 0);
	gluCylinder(quadratic2, 0.2, 0.15, 1.5, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0.2, 0);
	glTranslatef(-0.3, 1.6, -0.1);
	glRotatef(100, 1, 0, 0);
	gluCylinder(quadratic2, 0.2, 0.15, 1.5, 100, 100);
	glPopMatrix();

}
void shoes() {
	//shoes
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-0.3, 0.1, 0);
	glScalef(0.55, 0.55, 0.65);
	glutSolidSphere(0.4, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0.25, 0.1, 0);
	glScalef(0.55, 0.55, 0.75);
	glutSolidSphere(0.4, 100, 100);
	glPopMatrix();
}
void gun() {

	//gun
	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(0, 3.65, 0.9);
	glRotatef(30, 0, 1, 0);
	glScalef(0.35, 1, 1);
	gluCylinder(quadratic2, 0.1, 0.05, 2.3, 100, 100);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.42, 0.27, 0.2);
	glTranslatef(0, 3.65, 1);
	glRotatef(30, 0, 1, 0);
	glRotatef(160, 1, 0, 0);
	glScalef(0.35, 1, 1);
	gluCylinder(quadratic2, 0.1, 0.25, 0.7, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.42, 0.27, 0.2);
	glRotatef(12, 0, 1, 0);
	glTranslatef(0, 3.65, 1.5);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic2, 0.05, 0.05, 0.3, 100, 100);
	glPopMatrix();

}

void soldier(float x, float y, float z, float angle, float axisX, float axisY, float axisZ) {

	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(angle, axisX, axisY, axisZ);
	head();
	arms();
	legs();
	shoes();
	gun();
	glPopMatrix();

}

void soldierset1() {

	float soldierPositionsX[5] = { -7.0, -7.5, -2.0, -5.5, -2.5 };
	float soldierPositionsZ[5] = { -25.0, -22.5, -28.0, -21.0, -25.0 };

	// Draw barrels
	float angle = -30.0;
	float axisX = 0.0, axisY = 1.0, axisZ = 0.0;
	for (int i = 0; i < 5; i++) {
		float x = soldierPositionsX[i];
		float z = soldierPositionsZ[i];
		if (i == 1 || i == 3) {
			soldier(x, 0, z, angle, axisX, axisY, axisZ);
		}
		else {
			soldier(x, 0.0, z, 0.0, axisX, axisY, axisZ);
		}
	}

}

void soldierset2() {

	float soldierPositionsZ[5] = { 7.0, 7.5, 2.0, 5.5, 2.5 };
	float soldierPositionsX[5] = { -33.0, -30.5, -35.0, -29.0, -33.0 };

	// Draw barrels
	float angle = -30.0;
	float axisX = 0.0, axisY = 1.0, axisZ = 0.0;
	for (int i = 0; i < 5; i++) {
		float x = soldierPositionsX[i];
		float z = soldierPositionsZ[i];
		if (i == 1 || i == 5) {
			soldier(x, 0, z, 90+angle, axisX, axisY, axisZ);
		}
		else {
			soldier(x, 0.0, z, 90.0, axisX, axisY, axisZ);
		}
	}

}
