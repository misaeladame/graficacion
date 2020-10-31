#include <GL/glut.h>
#define ancho 500
const int alto = 500;
#define profundidad 500
void dibuja();
void ejes();
void tecladoNormal(unsigned char tecla, int x, int y); // 1 BYTE
void tecladoEspecial(int tecla, int x, int y); // 2 BYTE
int posx=0, posy=0;
int angulo=0;
float esc=1;

int main(int argc, char** argv) {
	// DOCUMENTAR TODOS LOS METODOS
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(100, 0);
	glutInitWindowSize(ancho, alto);
	glutCreateWindow("Transformaciones Geometricas");
	glOrtho(-(ancho/2), (ancho/2), -(alto/2), (alto/2), -profundidad, profundidad);
	glClearColor(1, 1, 1, 0);
	glutDisplayFunc(dibuja);
	glutKeyboardFunc(tecladoNormal);
	glutSpecialFunc(tecladoEspecial);
	glutMainLoop();
	return 0;
}

void dibuja() {
	glClear(GL_COLOR_BUFFER_BIT);
	ejes();
	glPushMatrix();
		glTranslatef(posx, posy, 0);
		glRotatef(angulo, 0, 0, 1);
		glScalef(esc, esc, esc);
		glBegin(GL_POLYGON);
			glColor3f(1, 0, 0);glVertex3f(0, 100, 0);
			glColor3f(1, 1, 0);glVertex3f(50, -50, 0);
			glColor3f(0, 0, 1);glVertex3f(-50, -50, 0);
		glEnd();
	glPopMatrix();
	glutSwapBuffers();
}

void ejes() {
	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_LINES);
		glVertex3f(-ancho/2, 0, 0);
		glVertex3f(ancho/2, 0, 0);
		glVertex3f(0, alto/2, 0);
		glVertex3f(0, -alto/2, 0);
	glEnd();
}

void tecladoNormal(unsigned char tecla, int x, int y) {
	switch(tecla) {
		case 's': 
		case 'S': angulo--; break;
		case 27: exit(0);break;
		case 'g':
		case 'G': angulo++;break;
	}
	glutPostRedisplay();
}

void tecladoEspecial(int tecla, int x, int y) {
	switch(tecla) {
		case GLUT_KEY_UP : posy++;break;
		case GLUT_KEY_DOWN : posy--;break;
		case GLUT_KEY_RIGHT : posx++;break;
		case GLUT_KEY_LEFT : posx--;break;
		case GLUT_KEY_PAGE_UP : esc=esc*1.01;break; 
		case GLUT_KEY_PAGE_DOWN: esc=esc*0.99;break;
	}
	glutPostRedisplay();
}

