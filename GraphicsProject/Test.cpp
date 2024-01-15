#include <gl\glut.h>
#include <math.h>

//variables to move the camera
GLfloat camX = 0.0; GLfloat camY = 0.0; GLfloat camZ = 0.0;

//variables to move the scene
GLfloat sceRX = 0.0; GLfloat sceRY = 0.0; GLfloat sceRZ = 0.0;
GLfloat sceTX = 0.0; GLfloat sceTY = 0.0; GLfloat sceTZ = 0.0;

//variables to move the snowman
GLfloat objRX = 0.0; GLfloat objRY = 0.0; GLfloat objRZ = 0.0;
GLfloat objTX = 0.0; GLfloat objTY = 0.0; GLfloat objTZ = 0.0;
float angle = 0;
float pi = 3.14;
float x = 0, y = 0, z = 0;

//GLfloat vertices[][3] = { {-3,0,2},{3,0,2},{3,0,-2},{-3,0,-2} };
GLfloat a = 5;

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

//void surface4(int v1, int v2, int v3, int v4) {
//	glBegin(GL_POLYGON);
//	glVertex3fv(vertices[v1]);
//	glVertex3fv(vertices[v2]);
//	glVertex3fv(vertices[v3]);
//	glVertex3fv(vertices[v4]);
//	glEnd();
//}

void surface(float l, float w) {
	glTranslatef(-l / 2, 0, -w / 2);
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 0);
	glVertex3f(l, 0, 0);
	glVertex3f(l, 0, w);
	glVertex3f(0, 0, w);
	glEnd();

}

//void surface3(int v1, int v2, int v3) {
//	glBegin(GL_POLYGON);
//	glVertex3fv(vertices[v1]);
//	glVertex3fv(vertices[v2]);
//	glVertex3fv(vertices[v3]);
//	glEnd();
//}

void drawDisk(double radius, int n) {
	double angle = 0;
	glBegin(GL_POLYGON);
	for (int c = 0; c <= n; c++) {
		double x = radius * cos(angle);
		double y = radius * sin(angle);
		glVertex2d(x, y);
		angle = angle + ((2 * pi) / n);
	}
	glEnd();

}
void hollowcylinder(float radius, float height) {

	glBegin(GL_QUAD_STRIP);
	for (float angle = 0; angle <= 360; angle++) {
		x = radius * cos(angle);
		z = radius * sin(angle);
		glVertex3f(x, y, z);
		glVertex3f(x, y + height, z);


	}
	glEnd();
}
void cylinder(float radius, float height) {
	
	glPushMatrix();
	glTranslatef(0, height, 0);
	glRotatef(90,1,0,0);
	drawDisk(radius, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	drawDisk(radius, 100);
	glPopMatrix();

	glBegin(GL_QUAD_STRIP);
	for (float angle = 0; angle <= 360; angle++) {
		x = radius * cos(angle);
		z = radius * sin(angle);
		glVertex3f(x, y, z);
		glVertex3f(x, y + height, z);


	}
	glEnd();
}


void box(float l, float w, float h){

	glTranslatef(-l/2, 0, -w/2);
	//Top
	glBegin(GL_POLYGON);
	glVertex3f(0,h,0);
	glVertex3f(l,h,0);
	glVertex3f(l,h,w);
	glVertex3f(0,h,w);
	glEnd();

	// Bottom
	glBegin(GL_POLYGON);
	glVertex3f(0,0,0);
	glVertex3f(l,0,0);
	glVertex3f(l,0,w);
	glVertex3f(0,0,w);
	glEnd();

	// Front
	glBegin(GL_POLYGON);
	glVertex3f(0,0,0);
	glVertex3f(l,0,0);
	glVertex3f(l,h,0);
	glVertex3f(0,h,0);
	glEnd();

	// Back
	glBegin(GL_POLYGON);
	glVertex3f(0,0,w);
	glVertex3f(l,0,w);
	glVertex3f(l,h,w);
	glVertex3f(0,h,w);
	glEnd();

	// Left
	glBegin(GL_POLYGON);
	glVertex3f(0,0,0);
	glVertex3f(0,h,0);
	glVertex3f(0,h,w);
	glVertex3f(0,0,w);
	glEnd();

	// Right
	glBegin(GL_POLYGON);
	glVertex3f(l,0,0);
	glVertex3f(l,h,0);
	glVertex3f(l,h,w);
	glVertex3f(l,0,w);
	glEnd();
}
void Tank() {
	glRotatef(objRY, 0, 1, 0);
	glRotatef(objRX, 1, 0, 0);
	glRotatef(objRZ, 0, 0, 1);
	
	//tank body
	glPushMatrix();
	box(6, 4, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1, 0);
	box(5.2, 3, 1);
	glPopMatrix();

	//top part
	glPushMatrix();

	//firing cylinder
	glPushMatrix();
	glTranslatef(0, 1, 0);
	cylinder(1.5, 0.8);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 1.8, 0.5);
	cylinder(0.6, 0.1);
	hollowcylinder(0.65, 0.105);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.4, 1.8, -0.7);
	box(0.6, 0.75, 0.12);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.4, 1.8, -0.7);
	box(0.02, 0.02, 0.6);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.4, 1.8, -0.8);
	box(0.02, 0.02, 0.4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.4, 1, 0);
	box(0.6, 1.7, 0.79);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.15, 1, 0);
	box(0.6, 2, 0.79);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1, 0);
	cylinder(1.5, 0.8);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90,0,0,1 );
	glTranslatef(1.5,1.7, 0);
	hollowcylinder(0.15, 5);
	cylinder(0.2, 3);
	cylinder(0.25, 1.5);
	glPopMatrix();

	glPopMatrix();


}

void setLighting() {
	// Lighting set up
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Set lighting intensity and color
	GLfloat qaAmbientLight[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat qaDiffuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	// Set the light position

	GLfloat qaLightPosition[] = { 1.0, 3.0, a, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
}

void drawTankWithLighting() {
	
	// Set material properties
	GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat qaGreen[] = { 0.0, 1.0, 0.0, 1.0 };
	GLfloat qaRed[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat qaBlue[] = { 0.0, 0.0, 1.0, 1.0 };
	GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat qaLowAmbient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat qaFullAmbient[] = { 1.0, 1.0, 1.0, 1.0 };

	setLighting();
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaGreen);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaGreen);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);

	// Draw a pyramid
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	Tank();
	glPopMatrix();


	glPopMatrix();



}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
}

void display(void) {

	setLighting();
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gluLookAt(0.0 + camX, 3.0 + camY, 3.0 + camZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	//draw grid
	/*drawGrid();
	drawAxes();*/

	glPushMatrix();
	drawTankWithLighting();
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();


}

void reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Define the Perspective projection frustum 
	// (FOV_in_vertical, aspect_ratio, z-distance to the near plane from the camera position, z-distance to far plane from the camera position)
	gluPerspective(120.0, aspect_ratio, 1.0, 100.0);

}

void keyboardSpecial(int key, int x, int y) {
	if (key == GLUT_KEY_UP)
		camX += 1;

	if (key == GLUT_KEY_DOWN)
		camX -= 1;

	if (key == GLUT_KEY_RIGHT)
		camZ += 1;

	if (key == GLUT_KEY_LEFT)
		camZ -= 1;

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {

	if (key == '1')
		glEnable(GL_LIGHT0);

	if (key == '!')
		glDisable(GL_LIGHT0);

	if (key == 'z')
		a++;

	if (key == '!Z')
		a--;

	if (key == 'a')
		objRY++;

	if (key == 'd')
		objRY--;

	if (key == 'w')
		objRX++;

	if (key == 's')
		objRX--;

	if (key == 'q')
		objRZ++;

	if (key == 'e')
		objRZ--;

	glutPostRedisplay();
}


void main(void) {
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



