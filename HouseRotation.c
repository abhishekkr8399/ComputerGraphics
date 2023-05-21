#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
float house[2][9] = {{100, 100, 175, 250, 250, 150, 150, 200, 200}, {100, 300, 400, 300, 100, 100, 150, 150, 100}};
float theta;
float h = 100;
float k = 100;
void init(){
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 499, 0, 499);
}
void drawhouse(){
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(house[0][0], house[1][0]);
    glVertex2f(house[0][1], house[1][1]);
    glVertex2f(house[0][3], house[1][3]);
    glVertex2f(house[0][4], house[1][4]);
    glEnd();
    glColor3f(1, 0, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(house[0][5], house[1][5]);
    glVertex2f(house[0][6], house[1][6]);
    glVertex2f(house[0][7], house[1][7]);
    glVertex2f(house[0][8], house[1][8]);
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(house[0][1], house[1][1]);
    glVertex2f(house[0][2], house[1][2]);
    glVertex2f(house[0][3], house[1][3]);
    glEnd();
}
void display(){
    int i;
    GLfloat m[16], p, q;
    p = -h * (cos(theta) - 1) + k * (sin(theta));
    q = -k * (cos(theta) - 1) - h * (sin(theta));
    for (i = 0; i < 15; i++)
        m[i] = 0;
    m[0] = cos(theta);
    m[1] = sin(theta);
    m[4] = -sin(theta);
    m[5] = cos(theta);
    m[12] = p;
    m[13] = q;
    m[10] = 1;
    m[15] = 1;
    drawhouse();
    glMultMatrixf(m);
    drawhouse();
    glFlush();
}
int main(int argc, char **argv){
    printf("enter the rotation angle\n");
    scanf("%f", &theta);
    theta = theta * 3.141 / 180;
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("rotated house");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
