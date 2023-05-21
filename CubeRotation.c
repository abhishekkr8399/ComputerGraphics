#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
GLfloat vertices[][3] = {{-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1}, {-1, -1, 1}, {1, -1, 1}, {1,1,1,},{-1, 1, 1}};
GLfloat normals[][3] = {{-1, -1, -1}, {1, -1, 1}, {1, 1, -1}, {-1, 1, -1}, {-1, -1, 1}, {1, -1, 1}, {1, 1, 1}, {-1, 1, 1}};
GLfloat colors[][3] = {{0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0}, {0, 0, 1}, {1, 0, 1}, {1, 1, 1}, {0, 1, 1}};
static float theta[] = {0, 0, 0};
static int axis = 2;
void polygon(int a, int b, int c, int d){
    glBegin(GL_POLYGON);
    glColor3fv(colors[a]);
    glNormal3fv(normals[a]);
    glVertex3fv(vertices[a]);
    glColor3fv(colors[b]);
    glNormal3fv(normals[b]);
    glVertex3fv(vertices[b]);
    glColor3fv(colors[c]);
    glNormal3fv(normals[c]);
    glVertex3fv(vertices[c]);
    glColor3fv(colors[d]);
    glNormal3fv(normals[d]);
    glVertex3fv(vertices[d]);
    glEnd();
}
void colorcube(void){
    polygon(0, 3, 2, 1);
    polygon(2, 3, 7, 6);
    polygon(0, 4, 7, 3);
    polygon(1, 2, 5, 6);
    polygon(4, 5, 6, 7);
    polygon(0, 1, 5, 4);
}
void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(theta[0], 1, 0, 0);
    glRotatef(theta[1], 0, 1, 0);
    glRotatef(theta[2], 0, 0, 1);
    colorcube();
    glFlush();
}
void spinCube(){
    theta[axis] += 1;
    if (theta[axis] > 360)
        theta[axis] -= 360;
    glutPostRedisplay();
}
void mouse(int btn, int state, int x, int y){
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        axis = 0;
    if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
        axis = 1;
    if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        axis = 2;
}
void myReshape(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    if (w <= h)
        glOrtho(-2, 2, -2 * (float)h / (float)w, 2 * (float)h / (float)w, -10, 10);
    else
        glOrtho(-2 * (float)w / (float)h, 2 * (float)w / (float)h, -2, 2, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotating a color cube");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutIdleFunc(spinCube);
    glutMouseFunc(mouse);
    glutMainLoop();
}
