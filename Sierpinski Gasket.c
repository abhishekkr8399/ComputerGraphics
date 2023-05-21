#include <GL/glut.h>
#include <stdio.h>
int n;
void init(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 10, 0, 10);
}
void triangle(float *a, float *b, float *c){
    glVertex2f(a[0], a[1]);
    glVertex2f(b[0], b[1]);
    glVertex2f(c[0], c[1]);
}
void draw_triangle(float *a, float *b, float *c, int n){
    float ab[2], ac[2], bc[2];
    int i;
    if (n > 0){
        for (i = 0; i < 2; i++){
            ab[i] = (a[i] + b[i]) / 2;
            bc[i] = (b[i] + c[i]) / 2;
            ac[i] = (a[i] + c[i]) / 2;
        }
        draw_triangle(a, ab, ac, n - 1);
        draw_triangle(b, bc, ab, n - 1);
        draw_triangle(c, ac, bc, n - 1);
    }
    else{
        triangle(a, b, c);
    }
}
void display(){
    float a[2] = {1, 1};
    float b[2] = {6, 1};
    float c[2] = {3.5, 5};
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    draw_triangle(a, b, c, n);
    glEnd();
    glFlush();
}
int main(int argc, char **argv){
    printf("enter n value");
    scanf("%d", &n);
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Sierpinski Gasket");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
