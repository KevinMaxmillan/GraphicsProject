#pragma once
#include <GL/glut.h>
#include <math.h>

void window4() {
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glScalef(2, 3, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glScalef(2, 0.2, 0.1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glScalef(0.2, 3, 0.1);
    glutSolidCube(1);
    glPopMatrix();
}

void windowloop4() {
    for (int x = 0; x < 6; x++) {
        for (int y = 0; y < 2; y++) {
            if (!(x == 0 && y == 2)) {
                glPushMatrix();
                glTranslatef(-53 + (x * 5), 3 + (y * 5),-20 );
                window();
                glPopMatrix();
            }
        }
    }

    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 1; y++) {
            if (!(x == 0 && y == 2)) {
                glPushMatrix();
                glRotatef(90, 0, 1, 0);
                glTranslatef(25 + (x * 5), 3 + (y * 5), -20);
                window();
                glPopMatrix();
            }
        }
    }

    
}
void walls4() {

    int wallPattern[25] = { 12, 9, 11, 12, 9, 12, 8, 10, 12, 7, 12, 11, 12, 10, 8, 9, 12, 10, 11, 7, 8, 12, 11, 9, 10 };
    int wallPattern1[25] = { 36, 33, 35, 33, 33, 36, 32, 34, 33, 31, 36, 35, 36, 34, 32, 30, 36, 34, 35, 31, 32, 33, 35, 33, 34 };




    for (int i = 0; i < 25; i++) {
        int height = wallPattern[i];
        glPushMatrix();
        glColor3f(0.32, 0.27, 0.16);
        glTranslatef(-21, height / 2, i - 45);
        glScalef(0.5, height, 1);
        glutSolidCube(1);
        glPopMatrix();
    }

    for (int i = 0; i < 25; i++) {
        int height = wallPattern[i];
        glPushMatrix();
        glColor3f(0.32, 0.27, 0.16);
        glTranslatef(-41+height / 2,11.5, i -45);
        glScalef(height,0.5 , 1);
        glutSolidCube(1);
        glPopMatrix();
    }

    glPushMatrix();
    glColor3f(0.32, 0.27, 0.16);
    glTranslatef(-51 , 11.5,  -33);
    glScalef(20, 0.5, 25);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.32, 0.27, 0.16);
    glTranslatef(-41, 5, -33);
    glScalef(40, 0.5, 25);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.32, 0.27, 0.16);
    glTranslatef(-61, 12 / 2,-33);
    glScalef(0.5, 12, 25);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.32, 0.27, 0.16);
    glTranslatef(-41, 12 / 2, -20.5);
    glScalef(40, 12, 0.5);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.32, 0.27, 0.16);
    glTranslatef(-41, 12 / 2, -45);
    glScalef(40, 12, 0.5);
    glutSolidCube(1);
    glPopMatrix();

}

void building4() {

    walls4();
    windowloop4();
}
   

