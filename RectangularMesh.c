#include <stdlib.h>
#include <GL/glut.h>
#define maxx 20
#define maxy 30
#define dx 10
#define dy 15
float x[maxx] = {0.0}, y[maxy] = {0.0};
float x0 = 50, y0 = 50;
int i, j;
void init(){
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}
void display(void){
    for (i = 0; i < maxx; i++)
        x[i] = x0 + i * dx;
    for (j = 0; j < maxy; j++)
        y[j] = y0 + j * dy;
    for (i = 0; i < maxx - 1; i++) // Filling mesh from bottom to top and left to right
        for (j = 0; j < maxy - 1; j++){
            glColor3f(0, 1, 0);
            glBegin(GL_LINE_LOOP);
            glVertex2f(x[i], y[j]);
            glVertex2f(x[i], y[j + 1]);
            glVertex2f(x[i + 1], y[j + 1]);
            glVertex2f(x[i + 1], y[j]);
            glEnd();
            glFlush();
        }
}
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitWindowSize(500, 400);
    glutCreateWindow("Rectangular Mesh");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}
