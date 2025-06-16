#include <GL/freeglut.h>

// 초기 카메라 위치
float camX = 1.0f;
float camY = 1.0f;
float camZ = 2.0f;

float angle = 0.0f;  // 주전자 회전 각도

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(camX, camY, camZ,  // 카메라 위치
        0.0, 0.0, 0.0,     // 바라보는 지점
        0.0, 1.0, 0.0);    // 위쪽 방향

    glRotatef(angle, 0.0f, 1.0f, 0.0f);  // 주전자 회전
    glutWireTeapot(0.5);

    glutSwapBuffers();
}

void timer(int value) {
    angle += 1.0f;
    if (angle >= 360.0f) angle -= 360.0f;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

// 방향키 입력 처리
void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        camX -= 0.1f; break;
    case GLUT_KEY_RIGHT:
        camX += 0.1f; break;
    case GLUT_KEY_UP:
        camY += 0.1f; break;
    case GLUT_KEY_DOWN:
        camY -= 0.1f; break;
    }
    glutPostRedisplay();  // 화면 다시 그리기
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / h, 1.0, 10.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("방향키로 시점 이동 - 회전 주전자");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);  // 방향키 콜백 등록
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}
