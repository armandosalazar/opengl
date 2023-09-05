//
// Created by Armando Salazar on 05/09/23.
//

#include <GLFW/glfw3.h>
#include <math.h>

#ifndef OPEN_GL_PIXEL_GRAPHICS_H
#define OPEN_GL_PIXEL_GRAPHICS_H

void putPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2f((GLfloat) x, (GLfloat) y);
    glEnd();
}

void lineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps, k;
    float incrementX, incrementY, x = x1, y = y1;

    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    incrementX = (float) dx / (float) steps;
    incrementY = (float) dy / (float) steps;

    putPixel(round(x), round(y));
    for (k = 0; k < steps; k++) {
        x += incrementX;
        y += incrementY;
        putPixel(round(x), round(y));
    }
}

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

#endif //OPEN_GL_PIXEL_GRAPHICS_H
