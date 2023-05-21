#include <stdio.h>
#include <GL/glut.h>
float x1, y1, x2, y2;
void init(){
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 500, 0);
}
void drawpoint(int x, int y){
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(0, 0, 0);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}
void drawline(int x, int y){
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2i(x, y);
    glVertex2i(x + 100, y + 100);
    glEnd();
    glFlush();
}
void mymouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        drawpoint(x, y);
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        drawline(x, y);
    }
}
void draw_pentagon(int x, int y){
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 1);
    glVertex2f(x, y);
    glVertex2f(x + 200, y);
    glVertex2f(x + 200, y + 200);
    glVertex2f(x + 100, y + 300);
    glVertex2f(x, y + 200);
    glEnd();
    glFlush();
}
void draw_triangle(int x, int y){
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex2f(x, y);
    glVertex2f(x + 200, y);
    glVertex2f(x + 100, y + 200);
    glEnd();
    glFlush();
}
void draw_square(int x, int y){
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex2f(x, y);
    glVertex2f(x + 200, y);
    glVertex2f(x + 200, y + 200);
    glVertex2f(x, y + 200);
    glEnd();
    glFlush();
}
void mykey(unsigned char key, int x, int y){
    if (key == 't' || key == 'T')
        draw_triangle(x, y);
    if (key == 's' || key == 'S')
        draw_square(x, y);
    if (key == 'p' || key == 'P')
        draw_pentagon(x, y);
}
void display(){
}
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Mouse and keyboard window");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mymouse);
    glutKeyboardFunc(mykey);
    glutMainLoop();
    return 0;
}
