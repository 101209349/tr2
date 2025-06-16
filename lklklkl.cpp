// rainbow_rect.c
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // 빨강
    glVertex2f(-0.5f, -0.5f);
    glColor3f(1.0f, 0.5f, 0.0f); // 주황
    glVertex2f(0.5f, -0.5f);
    glColor3f(0.0f, 1.0f, 0.0f); // 초록
    glVertex2f(0.5f, 0.5f);
    glColor3f(0.0f, 0.0f, 1.0f); // 파랑
    glVertex2f(-0.5f, 0.5f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("무지개 사각형");
    glutInitWindowSize(500, 500);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
