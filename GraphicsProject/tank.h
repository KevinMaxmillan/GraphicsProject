#pragma once
#include <gl\glut.h>
#include <math.h>

GLUquadricObj* quadratic1 = gluNewQuadric();
float pi = 3.14;



void Partialcylinder(float radius, float height, float angle, float slices) {
	
	float x = 0, y = 0, z = 0;
	glBegin(GL_QUAD_STRIP);
	for (float i = 0; i <= slices; i++) {
		glPushMatrix();
		x = radius * cos(angle);
		z = radius * sin(angle);
		glVertex3f(x, y, z);
		glVertex3f(x, y + height, z);
		angle += pi / 1000;
		glPopMatrix();
	}
	glEnd(); 
	
}


void drawDisk(double radius, int n) {
	
	double angle = 0;
	
	
	glBegin(GL_POLYGON);
	for (int c = 0; c <= n; c++) {
		glPushMatrix();
		double x = radius * cos(angle);
		double y = radius * sin(angle);
		glVertex2d(x, y);
		angle = angle + ((2 * pi) / n);
		glPopMatrix();
	}
	glEnd();
	
}
void mesh() {
	glColor3f(0.1, 0.1, 0.1);
	for (int i = 0; i < 7; i++) {

			glPushMatrix();
			glTranslatef(-0.6+(float)i * 0.2, 0,0);
			glScalef(0.02, 0.01, 1.2);
			glutSolidCube(1);
			glPopMatrix();	
	}
	for (int i = 0; i < 7; i++) {

		glPushMatrix();
		glTranslatef(0, 0,-0.6+(float)i * 0.2);
		glScalef(1.2, 0.01, 0.08);
		glutSolidCube(1);
		glPopMatrix();
	}
}
void stripes(float radius, float curve) {
	for (float angle = 20; angle <= curve; angle++) {
		float x = 0, y = 0, z = 0;
		glPushMatrix();
		x = radius * cos(angle);
		y = radius * sin(angle);
		glTranslatef(x, y, 0);
		glScalef(0.2, 0.2, 1.5);
		glutSolidCube(1);
		angle += 30;
		glPopMatrix();


	}
	
}
void cylinder(float radius, float height) {
	
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0, 0, height);
	drawDisk(radius, 100);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	drawDisk(radius, 100);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	gluCylinder(quadratic1, radius, radius, height, 100, 100);
	glPopMatrix();
	

}
void wheel1() {
	
	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(0, 0, 0.5);
	drawDisk(0.2,100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.18, 0.18, 0.18);
	glTranslatef(0, 0, -0.5);
	gluCylinder(quadratic1, 0.2, 0.2, 1, 100, 100);
	glPopMatrix();

	for (float angle = 0; angle < 360; angle += 72) {
		glPushMatrix();
		glColor3f(0.1, 0.1, 0.1);
		glRotatef(angle, 0, 0, 1);
		glTranslatef(0, 0.1, 0);
		glScalef(0.15, 0.6, 0.5);
		glutSolidCube(1);
		glPopMatrix();


	}

	glPushMatrix();
	glColor3f(0.18, 0.18, 0.18);
	glTranslatef(0, 0, -0.5);
	gluCylinder(quadratic1, 0.8, 0.8, 1, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.18, 0.18, 0.18);
	glTranslatef(0, 0, -0.5);
	gluCylinder(quadratic1, 0.4, 0.4, 1, 100, 100);
	glPopMatrix();

	
	float angle = 0;
	for (float angle = 0; angle <360; angle+=15) {
		glPushMatrix();
		glColor3f(0.18, 0.18, 0.18);
		glRotatef(angle, 0, 0, 1);
		glTranslatef(0, 0.85, 0);
		glScalef(0.1, 0.1, 1);
		glutSolidCube(1);
		glPopMatrix();

	
	}
	

	
	for (float angle = 0; angle <360; angle +=45 ) {
		glPushMatrix();
		glRotatef(angle, 0, 0, 1);
		glColor3f(0.1, 0.1, 0.1);
		glTranslatef(0, 0.6, 0);
		glScalef(0.2, 0.4, 1);
		glutSolidCube(1);
		glPopMatrix();


	}

}
void TankWeapon() {

	glTranslated(0, 3.7, 0);
	glColor3f(0.46, 0.32, 0.05);
	glPushMatrix();
	cylinder(2, 1.001);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glTranslatef(1.5, 0, 0);
	cylinder(1, 0.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glScalef(1, 1, 0.9);
	cylinder(1.8, 1.2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glTranslatef(0.3, 1.2, 0.4);
	cylinder(0.8, 0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 1.3, 0.4);
	cylinder(0.7, 0.3);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glScalef(0.6, 1, 3.2);
	glTranslatef(-2.2, 0.5, 0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glScalef(0.6, 1, 2.5);
	glTranslatef(-2.6, 0.5, 0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glScalef(0.8, 1, 1.5);
	glTranslatef(-2.2, 0.5, 0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glScalef(0.4, 1, 0.3);
	glTranslatef(-4.45, 0.5, -3.6);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glScalef(0.4, 1, 0.3);
	glTranslatef(-4.45, 0.5, 3.6);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(-2.2, 0.5, 0);
	glRotatef(-90, 0, 1, 0);
	glutSolidTorus(0.1, 0.4, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(-3.9, 0.5, 0);
	glRotatef(-90, 0, 1, 0);
	glutSolidTorus(0.1, 0.3, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(-5, 0.5, 0);
	glRotatef(-90, 0, 1, 0);
	glutSolidTorus(0.1, 0.2, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glTranslatef(-3.9, 0.5, 0);
	glRotatef(-90, 0, 0, 1);
	cylinder(0.4, 2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glTranslatef(-5, 0.5, 0);
	glRotatef(-90, 0, 0, 1);
	cylinder(0.3, 2);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glTranslatef(-4, 0.5, 0);
	glRotatef(-90, 0, 1, 0);
	gluCylinder(quadratic, 0.2, 0.2, 5, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(1.8, 0.5, 0.2);
	glutSolidTorus(0.1, 0.4, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(1.8, 0.5, -0.2);
	glutSolidTorus(0.1, 0.4, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(1.8, 0.5, 0.45);
	glutSolidTorus(0.1, 0.4, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(1.8, 0.5, -0.45);
	glutSolidTorus(0.1, 0.4, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0.8, 0.8, 1.15);
	glutSolidTorus(0.1, 0.2, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(0.3, 1.5, 0.6);
	glutSolidTorus(0.05, 0.2, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glScalef(0.5, 0.2, 0.6);
	glTranslatef(0, 6, -1.3);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(-0.3, 1.25, -0.7);
	glutSolidTorus(0.05, 0.1, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(-0.3, 1.25, -0.9);
	glutSolidTorus(0.05, 0.1, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(0, 0, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidTorus(0.2, 1.5, 100, 250);
	glPopMatrix();



}
void TankBody() {

	glTranslated(0, 1.1, 0);

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glTranslatef(0.8, 2, 0);
	glScalef(8.5, 1.4, 5.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glTranslatef(0.8, 0.6, 0);
	glScalef(8.5, 2.2, 3.4);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(-4, 0.6, 0);
	glRotatef(45, 0, 0, 1);
	glScalef(0.1, 2.2, 3.4);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(-3.4, 2.2, -1.3);
	glutSolidSphere(0.45,300,300);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(-3.4, 2.2, -1.3);
	glScalef(1, 0.1, 0.7);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(-3.35, 2.4, -1.3);
	glScalef(1, 0.1, 0.7);
	glutSolidCube(1);
	glPopMatrix();
	
	//
	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(-3.4, 2.2, 1.3);
	glutSolidSphere(0.45, 300, 300);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(-3.4, 2.2, 1.3);
	glScalef(1, 0.3, 0.6);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(-2.8, 2.2, 1.3);
	glRotatef(-90, 0, 1, 0);
	gluCylinder(quadratic, 0.2, 0.05, 2, 200, 200);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glRotatef(10, 0, 0, 1);
	glTranslatef(-3.8, 2.2, 0);
	glScalef(1.5, 0.05, 6.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(0.8, 1.45, 3);
	glRotatef(-4, 0, 0, 1);
	glRotatef(30, 1, 0, 0);
	glScalef(8.5, 0.05, 0.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(0.8, 1.55, 2.8);
	glRotatef(-4, 0, 0, 1);
	glScalef(8.5, 0.5, 0.1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(0.8, 1.45, -3);
	glRotatef(-4, 0, 0, 1);
	glRotatef(-30, 1, 0, 0);
	glScalef(8.5, 0.05, 0.5);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(0.8, 1.55, -2.8);
	glRotatef(-4, 0, 0, 1);
	glScalef(8.5, 0.5, 0.1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(5.4, 0.6, 2.4);
	glRotatef(40, 0, 0, 1);
	glScalef(0.05, 1.1, 1.6);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glTranslatef(5, 1.15, 2.2);
	glScalef(0.1, 0.3, 1.1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(5.4, 0.6, -2.4);
	glRotatef(40, 0, 0, 1);
	glScalef(0.05, 1.1, 1.6);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glTranslatef(5, 1.15, -2.2);
	glScalef(0.1, 0.3, 1.1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(5.3, 1.35, -0.5);
	cylinder(0.3, 1.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(5.3, 1.35, 0.5);
	cylinder(0.3, 1.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glTranslatef(5.3, 1.9, -0.5);
	glScalef(0.8, 1.5, 0.8);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glTranslatef(5.3, 1.9, 0.5);
	glScalef(0.8, 1.5, 0.8);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(5.3, 2.5, 0.5);
	cylinder(0.2, 0.4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(5.3, 2.5, -0.5);
	cylinder(0.2, 0.4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(5.2, 2.3, 2.5);
	cylinder(0.2, 0.4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(5.2, 2.3, 2.5);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic,0.2, 0.1,0.3, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(5.2, 2.3, 2.1);
	cylinder(0.2, 0.4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(5.2, 2.3, 2.1);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 0.2, 0.1, 0.3, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(5.2, 2.3, -2.5);
	cylinder(0.2, 0.4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(5.2, 2.3, -2.5);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 0.2, 0.1, 0.3, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(5.2, 2.3, -2.1);
	cylinder(0.2, 0.4);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.36, 0.22, 0.05);
	glTranslatef(5.2, 2.3, -2.1);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 0.2, 0.1, 0.3, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glTranslatef(5, 2.6, 0.5);
	glRotatef(-5, 0, 1, 0);
	glutSolidTorus(0.15, 0.35, 100, 250);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glTranslatef(4.75, 2.8, 0.5);
	glRotatef(-95, 0, 1, 0);
	gluCylinder(quadratic, 0.16, 0.16, 4, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glTranslatef(5, 2.6, -0.5);
	glRotatef(5, 0, 1, 0);
	glutSolidTorus(0.15, 0.35, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glTranslatef(4.75, 2.8, -0.5);
	glRotatef(-85, 0, 1, 0);
	gluCylinder(quadratic, 0.16, 0.16, 4, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glTranslatef(4, 2.3, 2.1);
	glScalef(0.02, 4, 0.02);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.46, 0.32, 0.05);
	glTranslatef(4, 2.3, 1.9);
	glScalef(0.02, 3, 0.02);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3,2.8,-1.7);
	mesh();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3, 2.8, 1.7);
	mesh();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, 2.8, -1.7);
	mesh();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, 2.8, 1.7);
	mesh();
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(4, 2.1, -2.8);
	glutSolidTorus(0.1,0.3,200,200);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(4.4, 2.1, -2.8);
	glutSolidTorus(0.1, 0.3, 200, 200);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(4, 2.1, 2.8);
	glutSolidTorus(0.1, 0.3, 200, 200);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(4.4, 2.1, 2.8);
	glutSolidTorus(0.1, 0.3, 200, 200);
	glPopMatrix();

}
void Wheels() {
	
	
	glPushMatrix();
	glScalef(1.25, 1.25, 1);
	glTranslatef(0.2, 0.95, 0.15);
	wheel1();
	glPopMatrix();

	glPushMatrix();
	glScalef(1.15, 1.15, 1);
	glTranslatef(2, 0.9, 0.15);
	wheel1();
	glPopMatrix();

	glPushMatrix();
	glScalef(1.07, 1.07, 1);
	glTranslatef(3.9, 0.9, 0.15);
	wheel1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, 0.9, 0.15);
	wheel1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7.7, 0.87, 0.15);
	glScalef(0.95, 0.95, 1);
	wheel1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.1, 0.87, 0.15);
	glScalef(0.65, 0.65, 1);
	wheel1();
	glPopMatrix();


}
void TankTire() {


	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(0, 1.15, -0.75);
	glRotatef(90, 1, 0, 0);
	glRotatef(143, 0, 1, 0);
	Partialcylinder(1.15, 1.5, 180,1000);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(4.5, 0, 0);
	glScalef(9, 0.01, 1.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(9, 0.8, -0.75);
	glRotatef(90, 1, 0, 0);
	glRotatef(-37, 0, 1, 0);
	Partialcylinder(0.8, 1.5, 180, 1000);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(4.5, 1.95, 0);
	glRotatef(-4.447, 0, 0, 1);
	glScalef(9, 0.01, 1.5);
	glutSolidCube(1);
	glPopMatrix();

	
	GLfloat X;
	for (X =0; X <= 9; X += 0.4) {
		glPushMatrix();
		glColor3f(0.1, 0.1, 0.1);
		glTranslatef(X, -0.05, 0);
		glScalef(0.15, 0.2, 1.5);
		glutSolidCube(1);
		glPopMatrix();

	}
	for (X = 0; X <= 9; X += 0.4) {
		glPushMatrix();
		glColor3f(0.1, 0.1, 0.1);
		glRotatef(-4.447, 0, 0, 1);
		glTranslatef(X, 2.35, 0);
		glScalef(0.15, 0.2, 1.5);
		glutSolidCube(1);
		glPopMatrix();

	}
	

	 
	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(9, 0.8, 0);
	stripes(0.8, 180);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(0, 1.15, 0);
	glScalef(-1, 1, 1);
	stripes(1.15, 180);
	glPopMatrix();
	
	
	
	Wheels();
	
	
	
}
void Tank() {
	
	
	TankWeapon();
	glTranslatef(-4.5, -4.1, 2.5);
	TankTire();
	glTranslatef(0, 0, -5);
	glScalef(1, 1, -1);
	TankTire();
	glTranslatef(4.5, 0, -2.5);
	TankBody();




}

