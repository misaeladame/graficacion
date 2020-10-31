#include <GL/glut.h>
#define ancho 500
const int alto = 500;
#define profundidad 400

void dibuja();
void ejes();
void tecladoNormal(unsigned char tecla, int x, int y);
void tecladoEspecial(int tecla, int x, int y);
void texto(int x, int y, char *palabra);

int posx=0, posy=0;// TX,  TY
int angulo=35;
float esc=1;
unsigned int figura=1;
float colorr=1, colorg=0, colorb=0;

int main(int argc, char** argv) {
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(100, 0);
	glutInitWindowSize(ancho, alto);
	glutCreateWindow("Figuras GLUT");
	glOrtho(-(ancho/2), (ancho/2), -(alto/2), (alto/2), -profundidad, profundidad);
	glClearColor(1, 1, 1, 0);
	glutDisplayFunc(dibuja);
	glutKeyboardFunc(tecladoNormal);
	glutSpecialFunc(tecladoEspecial);
	glutMainLoop(); // CICLO INFINITO QUE TERMINA CUANDO EL USUARIO DECIDE
	return 0;
}

void dibuja() {
	glClear(GL_COLOR_BUFFER_BIT);
	ejes();
	glPushMatrix(); // METE EN LA PILA LOS ELEMENTOS A UTILIZAR
	   glTranslatef(posx, posy, 0);
	   glRotatef(angulo, 1, 1, 1);
	   glRotatef(45, 1, 1, 1);
	   glScalef(esc, esc, esc);
	   glColor3f(colorr, colorg, colorb);
	   switch(figura) { //FIGURAS ALAMBRICAS
	      case 1: glutWireTorus(20, 80, 18, 18);break;
	      case 2: glutWireSphere(100, 18, 18);break;
	      case 3: glutWireCone(50, 200, 18, 18);break;
	      case 4: glutWireCube(100);break;
	      case 5: glutWireTeapot(100);break;
	      
	   }
	glPopMatrix();
	texto(-ancho/2+10,alto/2-20,"[F1: Toroide] [F2: Esfera] [F3: Cono] [F4: Cubo] [F5: Tetera]");
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
	   case 'S':angulo--;break;
	   case 27: exit(0);break; //27 = esc
	   case 'g':  // -
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
	   case GLUT_KEY_PAGE_DOWN : esc=esc*0.99;break;
	   case GLUT_KEY_F1 : figura=1;colorr=1,colorg=0;colorb=0;break;
	   case GLUT_KEY_F2 : figura=2;colorr=0,colorg=1;colorb=0;break;
	   case GLUT_KEY_F3 : figura=3;colorr=0,colorg=0;colorb=1;break;
	   case GLUT_KEY_F4 : figura=4;colorr=0.749,colorg=0.541;colorb=0.125;break;
	   case GLUT_KEY_F5 : figura=5;colorr=0.459,colorg=0.341;colorb=0.5;break;
	}
	glutPostRedisplay();
}

void texto(int x, int y, char *palabra) {
	int i;
	glColor3f(0,0,0);
	glRasterPos2f(x, y); //SIMULAR EL MOVIMIENTO DEL CURSOR  gotoXY,  pos.x,  pos.y
	for (i = 0; palabra[i]; i++)
	   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, palabra[i]);
	   		// INVESTIGAR LOS TIPOS DE LETRA DISPONIBLES EN OPENGL
}
