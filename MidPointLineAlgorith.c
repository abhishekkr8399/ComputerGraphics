#include <GL/glut.h>
#include <stdio.h>
int x1, y1, x2, y2;
void init(){
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}
void writepixel(int x, int y){
    glPointSize(5);
    glBegin(GL_POINTS); // WRITE PIXEL
    glColor3f(0, 0, 0);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}
void display(){
    int i, j;
    float dx = x2 - x1, dy = y2 - y1;
    float d = 2 * dy - dx;
    float incrE = dy;
    float incrNE = dy - dx;
    int x = x1, y = y1;
    writepixel(x, y);
    while (x < x2){
        if (d <= 0){
            d = d + 2 * incrE;
            x++;
        }
        else{
            d = d + 2 * incrNE;
            x++;
            y++;
        }
        writepixel(x, y);
    }
}
int main(int argc, char *argv[]){
    printf("Enter the values \n");
    printf("x1=");
    scanf("%d", &x1);
    printf("y1=");
    scanf("%d", &y1);
    printf("x2=");
    scanf("%d", &x2);
    printf("y2=");
    scanf("%d", &y2);
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("MIDPOINT LINE ALGORITHM");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
