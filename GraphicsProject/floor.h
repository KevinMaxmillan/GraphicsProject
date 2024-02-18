#pragma once
#include <gl\glut.h>
#include <math.h>
#include <SOIL2.h>
#include <stdio.h>

GLuint textureID;
constexpr float Pi = 3.14159265358979323846;

void loadTexture() {
    textureID = SOIL_load_OGL_texture(
        "sky.jpeg",  // Replace with the path to your texture file
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
    );

    if (!textureID) {
        printf("Texture loading failed: %s\n", SOIL_last_result());
    }
}

//void drawDisk2(double radius, int n) {
//
//    double angle = 0;
//
//
//    glBegin(GL_POLYGON);
//    for (int c = 0; c <= n; c++) {
//        glPushMatrix();
//        double x = radius * cos(angle);
//        double y = radius * sin(angle);
//        glVertex2d(x, y);
//        angle = angle + ((2 * Pi) / n);
//        glPopMatrix();
//    }
//    glEnd();
//
//}

void cylinderbackground() {

    glPushMatrix();
    GLUquadric* quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE);

    glBindTexture(GL_TEXTURE_2D, textureID);

    glColor3f(0.6, 0.6, 0.6);
    glRotatef(180, 0, 1, 0);
    glRotatef(-90, 1, 0, 0);
 
    gluCylinder(quad, 90, 90, 100, 100, 100);
    
    gluDeleteQuadric(quad);
    glPopMatrix();
   
  


}
void floor() {
   
    glPushMatrix();
    glColor3f(0.15, 0.15, 0.15);
    glScalef(180, 0.01, 180);
    glutSolidCube(1);
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
    glScalef(70, 0.2, 0.4);
    glTranslatef(0.7, 0, 0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(70, 0.2, 0.4);
    glTranslatef(-0.7, 0, 0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(0.4, 0.2, 70);
    glTranslatef(0, 0, -0.7);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(0.4, 0.2, 70);
    glTranslatef(0, 0, 0.7);
    glutSolidCube(1.0);
    glPopMatrix();
}

void street() {
    road();
    
    floor();
}