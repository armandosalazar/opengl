#include <GLFW/glfw3.h>

// Incluir la librería de OpenGL
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

void drawPixel(float x, float y) {
    glPointSize(1); // Tamaño del píxel
    glBegin(GL_POINTS);
    glVertex2f(x, y);  // Coordenadas del píxel
    glEnd();
}

int main() {
    // Inicialización de GLFW
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(500, 400, "Dibujo de píxel con OpenGL", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    // Ciclo principal
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Dibujar el píxel
        glLoadIdentity();
        glColor3f(1.0f, 1.0f, 1.0f); // Color blanco
        drawPixel(0.0f, 0.0f);      // Coordenadas del píxel

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminar GLFW
    glfwTerminate();

    return 0;
}

