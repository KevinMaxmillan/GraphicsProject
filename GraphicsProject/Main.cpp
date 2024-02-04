#include <gl\glut.h>
#include "lamppost.h"
#include "tank.h"
#include "tree1.h"

GLfloat camX = 0.0; GLfloat camY = 0.0; GLfloat camZ = 0.0;
GLfloat sceRX = 0.0; GLfloat sceRY = 0.0; GLfloat sceRZ = 0.0;
GLfloat sceTX = 0.0; GLfloat sceTY = 0.0; GLfloat sceTZ = 0.0;
GLfloat objRX = 0.0; GLfloat objRY = 0.0; GLfloat objRZ = 0.0;
GLfloat objTX = 0.0; GLfloat objTY = 0.0; GLfloat objTZ = 0.0;
GLfloat a = 0;


void setLighting() {

	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	GLfloat qaAmbientLight[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat qaDiffuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	GLfloat qaLightPosition[] = { -4.0, 5,a, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);

	glLightfv(GL_LIGHT1, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, qaSpecularLight);

	GLfloat qaLightPosition1[] = { 4.0, 5,a, 1.0 };
	glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);

	GLfloat SpecRef[] = { 0.7,0.7,0.7,1.0 };
	GLint Shine = 128;
	glShadeModel(GL_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, SpecRef);
	glMateriali(GL_FRONT, GL_SHININESS, Shine);

}
void drawGrid() {

	GLfloat step = 1.0f;
	GLint line;
	glBegin(GL_LINES);
	for (line = -20; line <= 20; line += step) {
		glVertex3f(line, -0.4, 20);
		glVertex3f(line, -0.4, -20);
		glVertex3f(20, -0.4, line);
		glVertex3f(-20, -0.4, line);
	}
	glEnd();
}
void drawAxes() {
	glBegin(GL_LINES);
	glLineWidth(1.5);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-200, 0, 0);
	glVertex3f(200, 0, 0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0, -200, 0);
	glVertex3f(0, 200, 0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0, 0, -200);
	glVertex3f(0, 0, 200);
	glEnd();
}

void Movingtank() {

	glTranslatef(objTX, objTY, objTZ);
	glRotatef(objRY, 0.0, 1.0, 0.0);
	Tank();
}
void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	setLighting();

	glPushMatrix();
	gluLookAt(0.0, 5.0 + camY, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glTranslatef(sceTX, sceTY, sceTZ);
	glRotatef(sceRY, 0.0, 1.0, 0.0);
	glColor3f(1, 1, 1);

	drawGrid();
	drawAxes();
	//LampPost();
	tree();

	//Movingtank();

	
	glPopMatrix();

	glutSwapBuffers();
}
void reshape(GLsizei w, GLsizei h) {

	glViewport(0, 0, w, h);
	GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(120.0, aspect_ratio, 1.0, 100.0);
}
void keyboardSpecial(int key, int x, int y) {
	if (key == GLUT_KEY_UP)
		camY += 1;
	if (key == GLUT_KEY_DOWN)
		camY -= 1;
	if (key == GLUT_KEY_RIGHT)
		sceTX += 1;
	if (key == GLUT_KEY_LEFT)
		sceTX -= 1;
	glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y) {
	if (key == 'x')
		a += 1;
	if (key == 'X')
		a -= 1;
	if (key == 'Z')
		sceTZ += 1;
	if (key == 'z')
		sceTZ -= 1;

	if (key == 'w')

		objTX -= 0.1;

	if (key == 's')
		objTX += 0.1;

	if (key == 'a')

		objRY -= 1;

	if (key == 'd')
		objRY += 1;



	if (key == 'y')
		sceRY += 1;
	if (key == 'Y')
		sceRY -= 1;
	glutPostRedisplay();
}
void main(int) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Complex 3D Shapes");
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboardSpecial);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	init();
	glutMainLoop();
}