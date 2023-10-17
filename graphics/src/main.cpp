#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "graphics.h"

const int WIDTH = 640;
const int HEIGHT = 480;

void glfwErrorCallback(int error, const char *description);
void glfwKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
void DisplayFunction();

int main()
{
    glfwSetErrorCallback(glfwErrorCallback);

    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return EXIT_FAILURE;
    }

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Gráficos", NULL, NULL);

    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, glfwKeyCallback);
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }

    while (!glfwWindowShouldClose(window))
    {
        // Viewport
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);

        // Limpia la pantalla
        glClear(GL_COLOR_BUFFER_BIT);

        // Define el plano de proyeccion
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-WIDTH / 2, WIDTH / 2, -HEIGHT / 2, HEIGHT / 2, -1, 1);

        // Define la matriz de modelo y vista
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Dibuja
        DisplayFunction();

        // Intercambia los buffers
        glfwSwapBuffers(window);
        // Poll for and process events
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return EXIT_SUCCESS;
}

void glfwErrorCallback(int error, const char *description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}

void glfwKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE)
    {
        // Cierra la ventana
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void DisplayFunction()
{
    glColor3f(1.0f, 0.0f, 0.0f);
    FillCircleInundation(0, 0, 100);
    glColor3f(0.0f, 0.0f, 1.0f);
    FillRectangleScanline(-50, -50, 50, 50);
}
