#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <GL/glut.h>

#define ancho 400
const int alto = 400;
#define profundidad 300


void dibuja(); // prototipo para avisar al compilador que
			   // despues de main esta su implementación
			   
int main(int argc, char** argv) {
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	//  |   OPERADOR OR A NIVEL DE BIT 
	//  ||  OPERADOR OR LOGICO
	/*
		00110011   GLUT_RGBA
				       |
		11111111   GLUT_SINGLE
		11111111   
	*/
	
	glutInitWindowPosition(100,0);
	glutInitWindowSize(ancho, alto);
	glutCreateWindow("SISTEMA CARTESIANO EN OPENGL");
	//PROYECCION ORTOGRAFICA
	glOrtho(-(ancho/2), ancho/2, -(alto/2), alto/2, -profundidad, profundidad);
	glClearColor(1,1,1,0); // COLOR PARA EL FONDO DE LA PLANO
	// LOS COLORES VAN DE 0.0 - 1.0
	glutDisplayFunc(dibuja);
	glutMainLoop();  // SE MANTIENE EL REDIBUJADO 
	

	return 0;
}

void dibuja() {
	glClear(GL_COLOR_BUFFER_BIT);
	// DIBUJAR EL EJE CARTESIANO
	glColor3f(0,0,0);
	glBegin(GL_LINES);
		glVertex3f(-ancho/2, 0,0);
		glVertex3f(ancho/2, 0, 0);
		glVertex3f(0,alto/2, 0);
		glVertex3f(0,-alto/2, 0);
	glEnd();
	// DIBUJAR EL TRIANGULO
	//glColor3f(1,0,0);
	glBegin(GL_POLYGON);
		glColor3f(0.8,0.8,0);
		glVertex3f(0,100,0);
		glColor3f(0,.8,0.3);
		glVertex3f(150,-150,0);
		glColor3f(0.4,0.3,1.0);
		glVertex3d(-150,-150,0);
	glEnd();
	glFlush();
}
