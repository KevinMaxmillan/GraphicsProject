#pragma once
#include <gl\glut.h>
#include <math.h>
void cylinderbackground(float radius, float height) {

    glPushMatrix();
    glColor3f(0.196078,0.6 , 0.8);
    glRotatef(-90, 1, 0, 0);
    glTranslatef(0, 0, height);
    drawDisk(radius, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.196078, 0.6, 0.8);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(quadratic1, radius, radius, height, 100, 100);
    glPopMatrix();

  


}
void floor() {
   
    glPushMatrix();
    glColor3f(0.15, 0.15, 0.15);
    glScalef(90, 0.01, 90);
    glutSolidSphere(1.0,100,100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.15, 0.15, 0.15);
    cylinderbackground(90, 70);
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

    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(140, 0.2, 0.4);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(0.4, 0.2, 140);
    glutSolidCube(1.0);
    glPopMatrix();
}

void street() {
    road();
    
    floor();
}