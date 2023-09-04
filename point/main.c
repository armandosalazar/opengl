#include <stdio.h>

// Incluir la librería de GLFW
#define GL_SILENCE_DEPRECATION 1
#include <GLFW/glfw3.h>
// Incluir la librería de OpenGL
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

void error_callback(__attribute__((unused)) int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}

void key_callback(GLFWwindow *window, int key, __attribute__((unused)) int scancode, int action,
                  __attribute__((unused)) int mods) {
    // Cerrar la ventana si el usuario presiona ESC
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }

    // Imprimir GL_SILENCE
    printf("%d\n", GL_SILENCE_DEPRECATION);

    // Imprimir el código de la tecla presionada
    printf("Tecla presionada: %d\n", key);
}


void draw_pixel(float x, float y) {
    glColor3f(1.0f, 0, 0); // Color blanco
    glPointSize(5.0f); // Tamaño del píxel
    glBegin(GL_POINTS);
    glVertex2f(x, y);  // Coordenadas del píxel
    glEnd();
}

int main() {
    // Inicialización de GLFW
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(500, 400, "Dibujo de píxel con OpenGL", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Obtener la versión de OpenGL
    int major, minor, revision;
    glfwGetVersion(&major, &minor, &revision);

    // Imprimir la versión de OpenGL
    printf("OpenGL Version: %d.%d.%d\n", major, minor, revision);

    // Establecer la función de callback de error
    glfwSetErrorCallback(error_callback);

    // Establecer la función de callback de teclado
    glfwSetKeyCallback(window, key_callback);

    // Establecer el contexto de OpenGL
    glfwMakeContextCurrent(window);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    // Ciclo principal
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Dibujar el píxel
        draw_pixel(0.0f, 0.0f);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminar GLFW
    glfwTerminate();

    return 0;
}

