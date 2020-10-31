#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <GL/glut.h>

void dibuja() {
	glClear(GL_COLOR_BUFFER_BIT);
	// BLOQUE DE CODIGO EN OPENGL
	glBegin(GL_POLYGON); // POLIGONO BASICO: PENTAGONO
		glVertex2f(0, 1);
		glVertex2f(-1, 0.3);
		glVertex2f(-0.6, -0.8);
		glVertex2f(0.6, -0.8);
		glVertex2f(1, 0.3);
	glEnd();
	glFlush();
	
}

int main(int argc, char** argv) {
	
	glutInit(&argc, argv);
	glutCreateWindow("E_03_Pentagono");
	glutDisplayFunc(dibuja);
	glutMainLoop();
	
	return 0;
}
