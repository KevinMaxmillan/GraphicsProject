#pragma once
#include <GL/glut.h>
#include <math.h>
void piller2(float height) {
    glPushMatrix();
    glColor3f(0.35, 0.35, 0.35);
    glTranslatef(0, height / 2, 0);
    glScalef(1, height, 1);
    glutSolidCube(1);
    glPopMatrix();

    for (float i = -0.5; i < 0.5; i+=0.5) {
        for (float j = -0.5; j < 0.5; j+=0.5) {
            glPushMatrix();
            glColor3f(0.1, 0.1, 0.1);
            glTranslatef(j + 0.25, 10.25, i + 0.25);
            glScalef(0.2, 20.5, 0.2);
            glutSolidCube(1);
            glPopMatrix();
        }
    }
}
void window2() {
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
void windowloop2() {
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
         
                glPushMatrix();
                glColor3f(0.1, 0.1, 0.1);
                glTranslatef(-36 + (x * 5), 4 + (y * 7), 40);
                window();
                glPopMatrix();
            
        }
    }

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (!(y == 2)) {
                glPushMatrix();
                glColor3f(0.1, 0.1, 0.1);
                glTranslatef(-36 + (x * 5), 4 + (y * 7), 19);
                window();
                glPopMatrix();
            }
        }
    }

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (!(x == 0 && y == 2)) {
                glPushMatrix();
                glColor3f(0.1, 0.1, 0.1);
                glRotatef(-90, 0, 1, 0);
                glTranslatef(25 + (x * 5), 4 + (y * 7), 41.5);
                window();
                glPopMatrix();
            }
        }
    }

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (( y == 0)) {
                glPushMatrix();
                glColor3f(0.1, 0.1, 0.1);
                glRotatef(-90, 0, 1, 0);
                glTranslatef(25 + (x * 5), 4 + (y * 7), 20.5);
                window();
                glPopMatrix();
            }
        }
    }
}
void walls2() {

    int wallPattern1[20] = { 10, 7, 9, 11, 13, 18, 17, 19, 16, 20, 21, 15, 17, 15, 13, 17, 9, 10, 8, 12 };
    int wallPattern2[20] = { 9, 7, 17, 15, 17, 13, 11, 16, 20, 8, 10, 13, 21, 15, 17, 10, 12, 18, 19, 9 };
    int wallPattern3[20] = { 25, 24, 25, 23, 25, 20, 21, 19, 23, 20, 21, 23, 25, 24, 25, 20, 22, 25, 25, 20 };
    int wallPattern4[20] = { 22, 23, 20, 21, 25, 18, 24, 19, 20, 18, 25, 24, 19, 22, 21, 18, 23, 20, 25, 24 };



    for (int i = 0; i < 20; i++) {
        int height = wallPattern1[i];
        glPushMatrix();
        glColor3f(0.62,0.57,0.46);
        glTranslatef(i - 40.5, height/2, 19.5);
        glScalef(1, height, 0.5);
        glutSolidCube(1);
        glPopMatrix();
    }

    for (int i = 0; i < 20; i++) {
        int height = wallPattern2[i];
        glPushMatrix();
        glColor3f(0.62, 0.57, 0.46);
        glTranslatef(-21, height / 2, i + 20);
        glScalef(0.5, height, 1);
        glutSolidCube(1);
        glPopMatrix();
    }

    for (int i = 0; i < 20; i++) {
        int height = wallPattern3[i];
        glPushMatrix();
        glColor3f(0.62, 0.57, 0.46);
        glTranslatef(i - 40.5, height / 2, 39.5);
        glScalef(1, height, 0.5);
        glutSolidCube(1);
        glPopMatrix();
    }

    for (int i = 0; i < 20; i++) {
        int height = wallPattern4[i];
        glPushMatrix();
        glColor3f(0.62, 0.57, 0.46);
        glTranslatef(-41, height / 2, i + 20);
        glScalef(0.5, height, 1);
        glutSolidCube(1);
        glPopMatrix();
    }

    glPushMatrix();
    glColor3f(0.35, 0.35, 0.35);
    glTranslatef(-26,0,26);
    piller2(18);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.35, 0.35, 0.35);
    glTranslatef(-26, 0, 35);
    piller2(20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.35, 0.35, 0.35);
    glTranslatef(-35, 0, 26);
    piller2(15);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.35, 0.35, 0.35);
    glTranslatef(-35, 0, 35);
    piller2(22);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.62, 0.57, 0.46);
    glTranslatef(-31, 7, 29.5);
    glScalef(20, 0.5, 20);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.62, 0.57, 0.46);
    glTranslatef(-31, 14, 29.5);
    glScalef(20, 0.5, 20);
    glutSolidCube(1);
    glPopMatrix();

}

void building2() {
	walls2();
    windowloop2();
}
