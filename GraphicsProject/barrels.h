#pragma once
#include <gl\glut.h>
#include <math.h>

void drawDisk1(double radius, int n) {

	double angle = 0;


	glBegin(GL_POLYGON);
	for (int c = 0; c <= n; c++) {
		glPushMatrix();
		double x = radius * cos(angle);
		double y = radius * sin(angle);
		glVertex3d(x, y,0);
		angle = angle + ((2 * pi) / n);
		glPopMatrix();
	}
	glEnd();

}
void barrel(float radius, float height) {

	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0, 0, height-0.1);
	drawDisk1(radius, 100);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	drawDisk1(radius, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.62, 0.35, 0.20);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(quadratic1, radius, radius, height, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.52, 0.35, 0.26);
	glTranslatef(0, height/2, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidTorus(0.2,radius-0.1,100,100);
	glPopMatrix();


}

void drawBarrel(float x, float y, float z, float angle, float axisX, float axisY, float axisZ) {
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(angle, axisX, axisY, axisZ); 
	barrel(1.5, 3);
	glPopMatrix();
}

void setofbarrels1() {
	float barrelPositionsX[5] = { 7.0, 7.5, 2.0, 5.5, 2.5 };
	float barrelPositionsZ[5] = { 25.0, 22.5, 28.0, 21.0, 25.0 };

	// Draw barrels
	float angle = -90.0; 
	float axisX = 1.0, axisY = 0.0, axisZ = 1.0; 
	for (int i = 0; i < 5; i++) {
		float x = barrelPositionsX[i];
		float z = barrelPositionsZ[i];
		if (i == 1 || i == 4) { 
			float y = 1.5;
			drawBarrel(x, y, z, angle, axisX, axisY, axisZ);
		}
		else {
			drawBarrel(x, 0.0, z, 0.0, axisX, axisY, axisZ);
		}
	}
}

void setofbarrels2() {
	float barrelPositionsZ[5] = { 7.0, 7.5, 2.0, 5.5, 2.5 };
	float barrelPositionsX[5] = { -25.0, -22.5, -28.0, -18.0, -25.0 };

	// Draw barrels
	float angle = -90.0;
	float axisX = 1.0, axisY = 0.0, axisZ = 1.0;
	for (int i = 0; i < 5; i++) {
		float x = barrelPositionsX[i];
		float z = barrelPositionsZ[i];
		if (i == 1 || i == 4) {
			float y = 1.5;
			drawBarrel(x, y, z, angle, axisX, axisY, axisZ);
		}
		else {
			drawBarrel(x, 0.0, z, 0.0, axisX, axisY, axisZ);
		}
	}
}
void barrelPositioning() {

	setofbarrels1();
	setofbarrels2();
	
	
}