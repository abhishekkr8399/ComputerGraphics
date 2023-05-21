#include <GL/glut.h>
#include <stdio.h>
float x, y, r;
void init(){
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}
void writepixel(float x, float y){
    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3f(1, 0, 0);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}
void midpointcircle(){
    x = 0;
    y = r;
    double d = 5.0 / 4.0 - r;
    writepixel(x, y);
    while (y > x){
        if (d < 0)
            d = d + 2.0 * x + 3.0;
        else{
            d = d + 2.0 * (x - y) + 5.0;
            y--;
        }
        x++;
        writepixel(x, y);
        writepixel(y, x);
        writepixel(y, -x);
        writepixel(x, -y);
        writepixel(-x, -y);
        writepixel(-y, -x);
        writepixel(-y, x);
        writepixel(-x, y);
        glFlush();
    }
}
int main(int argc, char *argv[]){
    printf("Enter the radius of the circle\n");
    scanf("%f", &r);
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Midpoint Circle Algorithm");
    init();
    glutDisplayFunc(midpointcircle);
    glutMainLoop();
    return 0;
}
