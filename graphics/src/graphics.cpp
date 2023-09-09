#include <GL/glew.h>
#include "graphics.h"

void putPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
void lineDDA(int x1, int y1, int x2, int y2)
{
}
