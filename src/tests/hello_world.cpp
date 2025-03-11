#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Hello World Window");

    glClearColor(0.96f, 0.96f, 0.86f, 1.0f); // Beige color
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}

