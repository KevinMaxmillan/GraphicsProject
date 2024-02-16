#pragma once
#include <gl\glut.h>
#include <math.h>
float cubeSizes[20] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0 };

float cubePositions[20][2] = {
    {1.0, 1.5}, {2.5, -2.5}, {-3.0, 3.0}, {0.5, -4.0}, {-2.5, 0.0},
    {3.0, 2.5}, {-4.0, -3.5}, {0.0, 4.0}, {2.5, -1.0}, {-1.5, 1.5},
    {-3.5, -2.0}, {1.5, 3.5}, {0.0, -1.5}, {4.0, 0.0}, {-1.0, -3.0},
    {2.0, 4.0}, {-2.0, -4.0}, {3.5, 1.0}, {-4.0, -0.5}, {1.0, 2.0}
};

void Cube(float size, float x, float y, float z, float angle, float axisX, float axisY, float axisZ) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(angle, axisX, axisY, axisZ);
    glScalef(size, size, size);
    glutSolidCube(1);
    glPopMatrix();
}


void wreckage() {
   

    for (int i = 0; i < 20; i++) {
        float x = cubePositions[i][0];
        float z = cubePositions[i][1];
        float angle = 0.0;
        float axisX = 0.0, axisY = 0.0, axisZ = 0.0;

        if (cubeSizes[i] < 1.0) {
            angle = 45.0; 
            axisZ = 1.0;
            
            
        }
        if (cubeSizes[i] > 1.0) {
            angle = -45.0; 
            axisX = 1.0;  
            axisY = 1.0;
        }
      Cube(cubeSizes[i], x, 0, z, angle, axisX, axisY, axisZ);
    }

}

void wreckagepositioning() {

    glPushMatrix();
    glColor3f(0.91, 0.76, 0.65);
    glTranslatef(10,1,-30);
    wreckage();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glScalef(1.5, 1.5, 1.5);
    glTranslatef(-20, 1, -4);
    wreckage();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.52, 0.37, 0.26);
    glScalef(1.5, 1.5, 1.5);
    glTranslatef(20, 1, 4);
    wreckage();
    glPopMatrix();

}