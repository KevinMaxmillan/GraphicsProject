#pragma once
#include <GL/glut.h>
#include <math.h>

void piller(float height) {
    glPushMatrix();
    glColor3f(0.35, 0.35, 0.35);
    glTranslatef(20, height / 2, -20); 
    glScalef(2, height, 2);
    glutSolidCube(1);
    glPopMatrix();

    for (int i = -1; i < 1; i++) {
        for (int j = -1; j < 1; j++) {
            glPushMatrix();
            glColor3f(0.1, 0.1, 0.1);
            glTranslatef(j + 0.5 + 20, 10.25, i + 0.5 - 20); 
            glScalef(0.2, 20.5, 0.2);
            glutSolidCube(1);
            glPopMatrix();
        }
    }
}

void window() {
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

void windowloop() {
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (!(x == 0 && y == 2)) {
                glPushMatrix();
                glColor3f(0.1, 0.1, 0.1);
                glTranslatef(32 + (x * 7), 4 + (y * 7), -19.7); 
                window();
                glPopMatrix();
            }
        }
    }

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
          
                glPushMatrix();
                glColor3f(0.1, 0.1, 0.1);
                glTranslatef(32 + (x * 7), 4 + (y * 7), -49.7);
                window();
                glPopMatrix();
            
        }
    }

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (!(x == 0 && y == 2)) {
                glPushMatrix();
                glColor3f(0.1, 0.1, 0.1);
                glRotatef(90, 0, 1, 0);
                glTranslatef(32 + (x * 7), 4 + (y * 7), 19.7); 
                window();
                glPopMatrix();
            }
        }
    }
}

void walls() {

    int wallPattern1[18] = { 1, 3, 4, 7, 8, 10, 8, 13, 17, 15, 16, 19, 18, 19, 20, 21, 22, 25 };
    int wallPattern2[19] = { 2, 3, 5, 6, 9, 11, 12, 14, 17, 16, 19, 18, 20, 21, 22, 23, 24, 25 };
    int wallPattern3[19] = { 2, 3, 5, 6, 9, 11, 12, 14, 17, 16, 19,3, 5, 6, 9, 11, 12, 14, 17 };


    for (int i = 0; i < 20; i++) {
        int height = wallPattern1[i];
        glPushMatrix();
        glColor3f(0.62, 0.77, 0.66);
        glTranslatef(i + 20, height - i, 0 - 20); 
        glScalef(1, height, 0.5);
        glutSolidCube(1);
        glPopMatrix();
    }

    for (int i = 0; i < 20; i++) {
        int height = wallPattern2[i];
        glPushMatrix();
        glColor3f(0.62, 0.77, 0.66);
        glTranslatef(0 + 20, height - i, -i - 20); 
        glScalef(0.5, height, 1);
        glutSolidCube(1);
        glPopMatrix();
    }

    for (int i = 0; i < 14; i++) {
        int height = wallPattern2[i];
        glPushMatrix();
        glColor3f(0.62, 0.77, 0.66);
        glTranslatef(height + 20, 20.5, i - 14 - 20);
        glScalef(height, 0.5, 1);
        glutSolidCube(1);
        glPopMatrix();
    }

    for (int i = 0; i < 14; i++) {
        int height = wallPattern2[i];
        glPushMatrix();
        glColor3f(0.62, 0.77, 0.66);
        glTranslatef(-height + 32.5 + 20, 20.5, -i - 15.5 - 20); 
        glScalef(height, 0.5, 1);
        glutSolidCube(1);
        glPopMatrix();
    }


    glPushMatrix();
    glColor3f(0.62, 0.77, 0.66);
    glTranslatef(47, 20.5, -43);
    glScalef(10, 0.5, 12);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.62, 0.77, 0.66);
    glTranslatef(45, 10.5, -20);
    glScalef(15, 21, 0.5);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.62, 0.77, 0.66);
    glTranslatef(20, 10.5, -43);
    glScalef(0.5, 21, 12);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.62, 0.77, 0.66);
    glTranslatef(36.25, 10.5, -49);
    glScalef(32.5, 21, 0.5);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.62, 0.77, 0.66);
    glTranslatef(52.5, 10.5, -34.5);
    glScalef(0.5, 21, 29);
    glutSolidCube(1);
    glPopMatrix();

  
    glPushMatrix();
    glColor3f(0.62, 0.77, 0.66);
    glTranslatef(36.25, 7, -34.5);
    glScalef(32.5, 0.5, 29);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.62, 0.77, 0.66);
    glTranslatef(36.25, 14, -34.5);
    glScalef(32.5, 0.5, 29);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.35, 0.35, 0.35);
    glTranslatef(8, 0, -8);
    piller(15);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.35, 0.35, 0.35);
    glTranslatef(24, 0, -8);
    piller(20);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.35, 0.35, 0.35);
    glTranslatef(8, 0, -24);
    piller(18);
    glPopMatrix();

 
    glPushMatrix();
    glColor3f(0.35, 0.35, 0.35);
    glTranslatef(24, 0, -24);
    piller(20);
    glPopMatrix();
}

void building1() {
    walls();
    windowloop();
}

