#pragma once
#include <gl\glut.h>
#include <math.h>

void floor() {
   
    glPushMatrix();
    glColor3f(0.15, 0.15, 0.15);
    glScalef(120, 0.01, 120);
    glutSolidCube(1.0);
    glPopMatrix();


   
}

void road() {
    glColor3f(0.1, 0.1, 0.1);

    glPushMatrix();
    glTranslatef(15, 0.25, 35);
    glScalef(0.4, 0.5, 40);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-15, 0.25, 35);
    glScalef(0.4, 0.5, 40);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15, 0.25, -35);
    glScalef(0.4, 0.5, 40);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-15, 0.25, -35);
    glScalef(0.4, 0.5, 40);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(35, 0.25, 15);
    glScalef(40, 0.5, 0.4);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(35, 0.25, -15);
    glScalef(40, 0.5, 0.4);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-35, 0.25, 15);
    glScalef(40, 0.5, 0.4);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-35, 0.25, -15);
    glScalef(40, 0.5, 0.4);
    glutSolidCube(1.0);
    glPopMatrix();
}

void street() {
    road();
    
    floor();
}