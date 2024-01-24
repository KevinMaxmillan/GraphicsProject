#pragma once
#include <gl\glut.h>

GLUquadricObj* quadratic = gluNewQuadric();
GLfloat vertices[][3] = { {1,0,1},{-1,0,1},{-1,0,-1},{1,0,-1},{0,0.5,0},{-0.17,0,0},{0.17,0,0},{0.22,0.4,0},{-0.22,0.4,0} };




void surface4(int v1, int v2, int v3, int v4) {
	glBegin(GL_POLYGON);
	glVertex3fv(vertices[v1]);
	glVertex3fv(vertices[v2]);
	glVertex3fv(vertices[v3]);
	glVertex3fv(vertices[v4]);
	glEnd();
}
void surface3(int v1, int v2, int v3) {
	glBegin(GL_POLYGON);
	glVertex3fv(vertices[v1]);
	glVertex3fv(vertices[v2]);
	glVertex3fv(vertices[v3]);
	glEnd();
}
void LampPost() {
	GLfloat qaGrey[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat qaGreen[] = { 0.0, 1.0, 0.0, 1.0 };
	GLfloat qaYellow[] = { 1.0, 1.0, 0.0, 0.6 };
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat qaLowAmbient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat qaFullAmbient[] = { 1.0, 1.0, 1.0, 1.0 };

	//footer
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaWhite);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaWhite);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);

	glPushMatrix();
	glTranslatef(0, 0, 0);
	glScalef(1.5, 0.2, 1.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.75, 0);
	glScalef(1, 1.5, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 5, 0);
	glScalef(0.4, 0.03, 0.4);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 5.35, 0);
	glScalef(0.5, 0.01, 0.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.65, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(0.15, 0.2, 100, 250);
	glPopMatrix();

	glPopMatrix();

	//pole
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaGrey);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaGrey);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);

	glPushMatrix();
	glTranslatef(0, 5, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 0.15, 0.15, 4, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 4, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 0.25, 0.25, 3, 100, 100);
	glPopMatrix();

	glPopMatrix();

	//light post
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaWhite);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaWhite);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);

	glPushMatrix();
	glTranslatef(0.2, 5.2, -0.2);
	glRotatef(-10, 1, 0, 1);
	glScalef(0.02, 0.4, 0.02);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.2, 5.2, 0.2);
	glRotatef(10, 1, 0, 1);
	glScalef(0.02, 0.4, 0.02);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.2, 5.2, 0.2);
	glRotatef(10, 1, 0, 0);
	glRotatef(-10, 0, 0, 1);
	glScalef(0.02, 0.4, 0.02);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.2, 5.2, -0.2);
	glRotatef(-10, 1, 0, 0);
	glRotatef(10, 0, 0, 1);
	glScalef(0.02, 0.4, 0.02);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaWhite);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaWhite);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
	glTranslatef(0, 5.35, 0);
	glScalef(0.35, 0.35, 0.35);
	surface3(0, 1, 4);
	surface3(1, 2, 4);
	surface3(2, 3, 4);
	surface3(0, 3, 4);
	glPopMatrix();

	//glasses
	glPushMatrix();
	glEnable(GL_BLEND);
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaYellow);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaYellow);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);

	glPushMatrix();
	glTranslatef(0, 5, -0.18);
	glRotatef(-10, 1, 0, 0);
	surface4(5, 6, 7, 8);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 5, 0.18);
	glRotatef(10, 1, 0, 0);
	surface4(5, 6, 7, 8);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.18, 5, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(10, 1, 0, 0);
	surface4(5, 6, 7, 8);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.18, 5, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(-10, 1, 0, 0);
	surface4(5, 6, 7, 8);
	glPopMatrix();

	glDisable(GL_BLEND);
	glPopMatrix();

}
