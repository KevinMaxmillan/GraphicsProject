#pragma once
#include <gl\glut.h>
#include <math.h>


void fence() {

	

	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	glColor3f(0.3, 0.3, 0.3);
	glScalef(8, 1, 1);
	glutSolidCube(1);
	glPopMatrix();

	for(int i=0; i<8; i++){
		glPushMatrix();
		glColor3f(0.1, 0.1, 0.1);
		glTranslatef(-3.5 + i, 3.25, 0);
		glScalef(0.2, 6.5, 0.2);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.1, 0.1, 0.1);
		glTranslatef(-3.5+i, 6.5, 0);
		glRotatef(-90, 1, 0, 0);
		glutSolidCone(0.2, 1, 100, 100);
		glPopMatrix();
	}

	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(0, 5, 0);
	glScalef(7, 0.2, 0.2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(0, 2, 0);
	glScalef(7, 0.2, 0.2);
	glutSolidCube(1);
	glPopMatrix();
	
}

void fenceplacement() {

	//rf
	glPushMatrix();
	glTranslatef(17.5, 0, -14);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(24.5, 0, -14);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(31.5, 0, -14);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(38.5, 0, -14);
	glRotatef(30, 1, 0, 0);
	glRotatef(-30, 0, 1, 0);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(46.5, 0, -14);
	glRotatef(30, 1, 0, 0);
	glRotatef(30, 0, 1, 0);
	fence();
	glPopMatrix();


	//rr
	glPushMatrix();
	glTranslatef(14, 0, -18.5);
	glRotatef(-90, 0, 1, 0);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(14, 0, -23.5);
	glRotatef(-90, 0, 1, 0);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(14, 0, -34);
	glRotatef(-30, 0, 1, 0);
	glRotatef(60, 1, 0, 0);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(14, 0, -36);
	glRotatef(30, 0, 1, 0);
	glRotatef(-60, 1, 0, 0);
	fence();
	glPopMatrix();


	//ll
	glPushMatrix();
	glTranslatef(-14, 0, -18.5);
	glRotatef(-90, 0, 1, 0);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-14, 0, -23.5);
	glRotatef(-90, 0, 1, 0);
	glRotatef(-10, 1, 0, 0);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-14, 0, -30.5);
	glRotatef(-90, 0, 1, 0);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-14, 0, -37.5);
	glRotatef(-90, 0, 1, 0);
	fence();
	glPopMatrix();

	//lf
	glPushMatrix();
	glTranslatef(-17.5, 0, -14);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-24.5, 0, -14);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-31.5, 0, -14);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-44.5, 0, -14);
	fence();
	glPopMatrix();

	//lb
	glPushMatrix();
	glTranslatef(-17.5, 0, 14);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-24.5, 0, 14);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-31.5, 0, 14);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-44.5, 0, 14);
	fence();
	glPopMatrix();

	//llb
	glPushMatrix();
	glTranslatef(-14, 0, 18.5);
	glRotatef(-90, 0, 1, 0);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-14, 0, 23.5);
	glRotatef(-90, 0, 1, 0);
	glRotatef(-10, 1, 0, 0);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-14, 0, 30.5);
	glRotatef(-90, 0, 1, 0);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-14, 0, 37.5);
	glRotatef(-90, 0, 1, 0);
	fence();
	glPopMatrix();

	//rb
	glPushMatrix();
	glTranslatef(17.5, 0, 14);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(24.5, 0, 14);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(31.5, 0, 14);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(38.5, 0, 14);
	glRotatef(-30, 1, 0, 0);
	glRotatef(-30, 0, 1, 0);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(46.5, 0, 14);
	glRotatef(-30, 1, 0, 0);
	glRotatef(30, 0, 1, 0);
	fence();
	glPopMatrix();

	//rrb
	glPushMatrix();
	glTranslatef(14, 0, 18.5);
	glRotatef(-90, 0, 1, 0);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(14, 0, 23.5);
	glRotatef(-90, 0, 1, 0);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(14, 0, 30);
	glRotatef(-30, 0, 1, 0);
	glRotatef(60, 1, 0, 0);
	fence();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(14, 0, 40);
	glRotatef(30, 0, 1, 0);
	glRotatef(-60, 1, 0, 0);
	fence();
	glPopMatrix();


}