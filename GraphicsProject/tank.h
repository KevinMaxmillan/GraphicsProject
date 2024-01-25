#pragma once
#include <gl\glut.h>
#include <math.h>

GLUquadricObj* quadratic1 = gluNewQuadric();
//GLfloat vertices[][3] = { {1,0,1},{-1,0,1},{-1,0,-1},{1,0,-1},{0,0.5,0},{-0.17,0,0},{0.17,0,0},{0.22,0.4,0},{-0.22,0.4,0} };
float pi = 3.14;



void Partialcylinder(float radius, float height, float angle, float slices) {
	
	float x = 0, y = 0, z = 0;
	glBegin(GL_QUAD_STRIP);
	for (float i = 0; i <= slices; i++) {
		x = radius * cos(angle);
		z = radius * sin(angle);
		glVertex3f(x, y, z);
		glVertex3f(x, y + height, z);
		angle += pi / 1000;
	}
	glEnd();
	
}

//void surface4(int v1, int v2, int v3, int v4) {
//	glBegin(GL_POLYGON);
//	glVertex3fv(vertices[v1]);
//	glVertex3fv(vertices[v2]);
//	glVertex3fv(vertices[v3]);
//	glVertex3fv(vertices[v4]);
//	glEnd();
//}
//void surface3(int v1, int v2, int v3) {
//	glBegin(GL_POLYGON);
//	glVertex3fv(vertices[v1]);
//	glVertex3fv(vertices[v2]);
//	glVertex3fv(vertices[v3]);
//	glEnd();
//}
void drawDisk(double radius, int n) {
	double angle = 0;
	glBegin(GL_POLYGON);
	for (int c = 0; c <= n; c++) {
		double x = radius * cos(angle);
		double y = radius * sin(angle);
		glVertex2d(x, y);
		angle = angle + ((2 * pi) / n);
	}
	glEnd();

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
void TankWeapon() {

	glTranslated(0, 4.1, 0);

	glPushMatrix();
	GLfloat qaGrey[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat qaLowAmbient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat qaFullAmbient[] = { 1.0, 1.0, 1.0, 1.0 };

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaGrey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaGrey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);


	glPushMatrix();
	cylinder(2, 1.001);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, 0, 0);
	cylinder(1, 0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 0);
	glScalef(1, 1, 0.9);
	cylinder(1.8, 1.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 1.2, 0.4);
	cylinder(0.8, 0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 1.3, 0.4);
	cylinder(0.7, 0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.3, 0.5, 0);
	glScalef(0.6, 1, 3.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.7, 0.5, 0);
	glScalef(0.6, 1, 2.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.8, 0.5, 0);
	glScalef(0.8, 1, 1.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.9, 0.5, -1.1);
	glScalef(0.4, 1, 0.3);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.9, 0.5, 1.1);
	glScalef(0.4, 1, 0.3);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.2, 0.5, 0);
	glRotatef(-90, 0, 1, 0);
	glutSolidTorus(0.1, 0.4, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.9, 0.5, 0);
	glRotatef(-90, 0, 1, 0);
	glutSolidTorus(0.1, 0.3, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5, 0.5, 0);
	glRotatef(-90, 0, 1, 0);
	glutSolidTorus(0.1, 0.2, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.9, 0.5, 0);
	glRotatef(-90, 0, 0, 1);
	cylinder(0.4, 2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5, 0.5, 0);
	glRotatef(-90, 0, 0, 1);
	cylinder(0.3, 2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4, 0.5, 0);
	glRotatef(-90, 0, 1, 0);
	gluCylinder(quadratic, 0.2, 0.2, 5, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.8, 0.5, 0.2);
	glutSolidTorus(0.1, 0.4, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.8, 0.5, -0.2);
	glutSolidTorus(0.1, 0.4, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.8, 0.5, 0.45);
	glutSolidTorus(0.1, 0.4, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.8, 0.5, -0.45);
	glutSolidTorus(0.1, 0.4, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0.8, 0.8, 1.15);
	glutSolidTorus(0.1, 0.2, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 1.5, 0.6);
	glutSolidTorus(0.05, 0.2, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.2, -0.8);
	glScalef(0.5, 0.2, 0.6);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.3, 1.25, -0.7);
	glutSolidTorus(0.05, 0.1, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.3, 1.25, -0.9);
	glutSolidTorus(0.05, 0.1, 100, 250);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0, 0, 0);
	glutSolidTorus(0.2, 1.5, 100, 250);
	glPopMatrix();


	glPopMatrix();



}
void TankBody() {

	glPushMatrix();
	glTranslated(0, 1.1, 0);
	GLfloat qaGrey[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat qaLowAmbient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat qaFullAmbient[] = { 1.0, 1.0, 1.0, 1.0 };

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaGrey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaGrey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);

	glPushMatrix();
	glTranslatef(0.8, 2, 0);
	glScalef(8.5, 1.4, 5.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.8, 0.6, 0);
	glScalef(8.5, 1.4, 3.4);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glRotatef(10, 0, 0, 1);
	glTranslatef(-3.8, 2.2, 0);
	glScalef(1.5, 0.05, 6.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.8, 1.45, 3);
	glRotatef(-4, 0, 0, 1);
	glRotatef(30, 1, 0, 0);
	glScalef(8.5, 0.05, 0.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.8, 1.55, 2.8);
	glRotatef(-4, 0, 0, 1);
	glScalef(8.5, 0.5, 0.1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.8, 1.45, -3);
	glRotatef(-4, 0, 0, 1);
	glRotatef(-30, 1, 0, 0);
	glScalef(8.5, 0.05, 0.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.8, 1.55, -2.8);
	glRotatef(-4, 0, 0, 1);
	glScalef(8.5, 0.5, 0.1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.4, 0.6, 2.4);
	glRotatef(40, 0, 0, 1);
	glScalef(0.05, 1.1, 1.6);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5, 1.15, 2.2);
	glScalef(0.1, 0.3, 1.1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.4, 0.6, -2.4);
	glRotatef(40, 0, 0, 1);
	glScalef(0.05, 1.1, 1.6);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5, 1.15, -2.2);
	glScalef(0.1, 0.3, 1.1);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();

}
void TankTire1() {

	
	glPushMatrix();
	
	GLfloat qaGrey[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat qaLowAmbient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat qaFullAmbient[] = { 1.0, 1.0, 1.0, 1.0 };
	glTranslatef(-4.5, 0, 2.5);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaGrey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaGrey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);

	glPushMatrix();
	glTranslatef(0, 1.15, -0.75);
	glRotatef(90, 1, 0, 0);
	glRotatef(143, 0, 1, 0);
	Partialcylinder(1.15, 1.5, 180,1000);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.5, 0, 0);
	glScalef(9, 0.01, 1.5);
	glutSolidCube(1);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(9, 0.8, -0.75);
	glRotatef(90, 1, 0, 0);
	glRotatef(-37, 0, 1, 0);
	Partialcylinder(0.8, 1.5, 180, 1000);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.5, 1.95, 0);
	glRotatef(-4.447, 0, 0, 1);
	glScalef(9, 0.01, 1.5);
	glutSolidCube(1);
	glPopMatrix();


	GLfloat X;
	for (X =0; X <= 9; X += 0.4) {
		glPushMatrix();
		glTranslatef(X, -0.05, 0);
		glScalef(0.15, 0.2, 1.5);
		glutSolidCube(1);
		glPopMatrix();

	}
	for (X = 0; X <= 9; X += 0.4) {
		glPushMatrix();
		glRotatef(-4.447, 0, 0, 1);
		glTranslatef(X, 2.35, 0);
		glScalef(0.15, 0.2, 1.5);
		glutSolidCube(1);
		glPopMatrix();

	}
	
	
	glPopMatrix();

}


void TankTire2() {

	glPushMatrix();

	GLfloat qaGrey[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat qaLowAmbient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat qaFullAmbient[] = { 1.0, 1.0, 1.0, 1.0 };
	glTranslatef(-4.5, 0, -2.5);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaGrey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaGrey);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);

	glPushMatrix();
	glTranslatef(0, 1.15, -0.75);
	glRotatef(90, 1, 0, 0);
	glRotatef(143, 0, 1, 0);
	Partialcylinder(1.15, 1.5, 180, 1000);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.5, 0, 0);
	glScalef(9, 0.01, 1.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9, 0.8, -0.75);
	glRotatef(90, 1, 0, 0);
	glRotatef(-37, 0, 1, 0);
	Partialcylinder(0.8, 1.5, 180, 1000);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.5, 1.95, 0);
	glRotatef(-4.447, 0, 0, 1);
	glScalef(9, 0.01, 1.5);
	glutSolidCube(1);
	glPopMatrix();


	GLfloat X;
	for (X = 0; X <= 9; X += 0.4) {
		glPushMatrix();
		glTranslatef(X, -0.05, 0);
		glScalef(0.15, 0.2, 1.5);
		glutSolidCube(1);
		glPopMatrix();

	}
	for (X = 0; X <= 9; X += 0.4) {
		glPushMatrix();
		glRotatef(-4.447, 0, 0, 1);
		glTranslatef(X, 2.35, 0);
		glScalef(0.15, 0.2, 1.5);
		glutSolidCube(1);
		glPopMatrix();

	}

	glPopMatrix();



}
void Tank() {
	
	TankTire1();
	TankTire2();
	TankBody();
	TankWeapon();
	
	

}

