#pragma once

#include <GL/glut.h>
#include <math.h>

void component1() {

    glPushMatrix();
    glColor3f(0.42, 0.27, 0.2);
    glTranslatef(30, 0, 30);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(quadratic1, 5, 5, 15, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.42, 0.27, 0.2);
    glTranslatef(30, 0, 30);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(quadratic1, 2, 2, 20, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.62, 0.57, 0.46);
    glTranslatef(30, 0, 30);
    glRotatef(-90, 1, 0, 0);
    glutSolidTorus(1, 5, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.62, 0.57, 0.46);
    glTranslatef(30, 15, 30);
    glRotatef(-90, 1, 0, 0);
    glutSolidTorus(1, 5, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glScalef(15, 1.5, 1);
    glTranslatef(2.5, 12, 30);
    glutWireCube(1);
    glPopMatrix();
}

void component2() {
    glPushMatrix();
    glColor3f(0.42, 0.27, 0.2);
    glTranslatef(30, 0, 45);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(quadratic1, 5, 5, 15, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.42, 0.27, 0.2);
    glTranslatef(30, 0, 45);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(quadratic1, 2, 2, 20, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.62, 0.57, 0.46);
    glTranslatef(30, 0, 45);
    glRotatef(-90, 1, 0, 0);
    glutSolidTorus(1, 5, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.62, 0.57, 0.46);
    glTranslatef(30, 15, 45);
    glRotatef(-90, 1, 0, 0);
    glutSolidTorus(1, 5, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glScalef(1, 1.5, 15);
    glTranslatef(30, 12, 2.5);
    glutWireCube(1);
    glPopMatrix();
}

void component3() {
    glPushMatrix();
    glColor3f(0.42, 0.27, 0.2);
    glTranslatef(45, 0, 30);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(quadratic1, 5, 5, 15, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.42, 0.27, 0.2);
    glTranslatef(45, 0, 30);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(quadratic1, 2, 2, 20, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.62, 0.57, 0.46);
    glTranslatef(45, 0, 30);
    glRotatef(-90, 1, 0, 0);
    glutSolidTorus(1, 5, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.62, 0.57, 0.46);
    glTranslatef(45, 15, 30);
    glRotatef(-90, 1, 0, 0);
    glutSolidTorus(1, 5, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glScalef(1, 1.5, 15);
    glTranslatef(45, 12, 2.5);
    glutWireCube(1);
    glPopMatrix();
}

void component4() {
    glPushMatrix();
    glColor3f(0.42, 0.27, 0.2);
    glTranslatef(45, 0, 45);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(quadratic1, 5, 5, 15, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.42, 0.27, 0.2);
    glTranslatef(45, 0, 45);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(quadratic1, 2, 2, 20, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.62, 0.57, 0.46);
    glTranslatef(45, 0, 45);
    glRotatef(-90, 1, 0, 0);
    glutSolidTorus(1, 5, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.62, 0.57, 0.46);
    glTranslatef(45, 15, 45);
    glRotatef(-90, 1, 0, 0);
    glutSolidTorus(1, 5, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glScalef(15, 1.5, 1);
    glTranslatef(2.5, 12, 45);
    glutWireCube(1);
    glPopMatrix();
}

void component5() {
    glPushMatrix();
    glColor3f(0.42, 0.27, 0.2);
    glTranslatef(60, 0, 45);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(quadratic1, 5, 5, 15, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.42, 0.27, 0.2);
    glTranslatef(60, 0, 45);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(quadratic1, 2, 2, 20, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.62, 0.57, 0.46);
    glTranslatef(60, 0, 45);
    glRotatef(-90, 1, 0, 0);
    glutSolidTorus(1, 5, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.62, 0.57, 0.46);
    glTranslatef(60, 15, 45);
    glRotatef(-90, 1, 0, 0);
    glutSolidTorus(1, 5, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glScalef(15, 1.5, 1);
    glTranslatef(3.5, 12, 30);
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glScalef(15, 1.5, 1);
    glTranslatef(3.5, 12, 45);
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glScalef(1, 1.5, 15);
    glTranslatef(60, 12, 2.5);
    glutWireCube(1);
    glPopMatrix();
}

void component6() {
    glPushMatrix();
    glColor3f(0.42, 0.27, 0.2);
    glTranslatef(60, 0, 30);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(quadratic1, 5, 5, 15, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.42, 0.27, 0.2);
    glTranslatef(60, 0, 30);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(quadratic1, 2, 2, 20, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.62, 0.57, 0.46);
    glTranslatef(60, 0, 30);
    glRotatef(-90, 1, 0, 0);
    glutSolidTorus(1, 5, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.62, 0.57, 0.46);
    glTranslatef(60, 15, 30);
    glRotatef(-90, 1, 0, 0);
    glutSolidTorus(1, 5, 100, 100);
    glPopMatrix();

   
}

void building3() {
    component1();
    component2();
    component3();
    component4();
    component5();
    component6();
}
