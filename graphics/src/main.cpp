#include <iostream>
#include <cmath>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "graphics.h"

const int WIDTH = 640;
const int HEIGHT = 480;
int x = 0, y = 0;

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
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

// void DisplayFunction()
// {
//     static int frame = 0;
//     glPointSize(1.5f);

//     // Calcula las nuevas coordenadas para la traslación
//     x = 100 * sin(frame * 0.1); // Ajusta el valor 0.1 según la velocidad de traslación deseada
//     y = 100 * cos(frame * 0.1);

//     // Dibuja las formas trasladadas
//     // glColor3f(1.0f, 0.0f, 0.0f);
//     // FillCircleInundation(0, 0, 100);
//     // glColor3f(0.0f, 0.0f, 1.0f);
//     // FillRectangleScanline(-50, -50, 50, 50);
//     // glColor3f(0.0f, 1.0f, 0.0f);
//     // FillEllipseScanline(0, 0, 50, 20);

//     // Dibuja la forma trasladada con las coordenadas modificadas
//     glColor3f(1.0f, 1.0f, 1.0f);
//     FillCircleInundation(x, y, 100);

//     frame++; // Incrementa el contador de frames

//     // Vuelve a dibujar
//     // glfwSwapBuffers(glfwGetCurrentContext());
// }


void DisplayFunction()
{
    static int frame = 0;
    glPointSize(1.5f);

    // Dibuja las formas originales en su posición original
    // glColor3f(1.0f, 0.0f, 0.0f);
    // FillCircleInundation(0, 0, 100);
    // glColor3f(0.0f, 0.0f, 1.0f);
    // FillRectangleScanline(-50, -50, 50, 50);
    // glColor3f(0.0f, 1.0f, 0.0f);
    // FillEllipseScanline(0, 0, 50, 20);

    // Aplica la traslación a las coordenadas solo en la dirección X (izquierda a derecha)
    TranslatePoint(x, y, 1, 0);

    // Dibuja la forma trasladada con las coordenadas modificadas
    glColor3f(1.0f, 1.0f, 1.0f);
    FillCircleInundation(x, 0, 100);

    // Restringe la traslación en el eje X a un valor máximo (por ejemplo, 200)
    if (x > 200)
    {
        x = -200; // Reinicia la posición en la izquierda cuando llega al límite derecho
    }

    frame++; // Incrementa el contador de frames

    // Vuelve a dibujar
    // glfwSwapBuffers(glfwGetCurrentContext());
}


// void DisplayFunction()
// {
// 	glPointSize(1.5f);
//     glColor3f(1.0f, 0.0f, 0.0f);
//     FillCircleInundation(0, 0, 100);
//     glColor3f(0.0f, 0.0f, 1.0f);
//     FillRectangleScanline(-50, -50, 50, 50);
//     glColor3f(0.0f, 1.0f, 0.0f);
//     FillEllipseScanline(0, 0, 50, 20);

//     // TODO:  use void TranslatePoint(int &x, int &y, int tx, int ty) for translate the shapes
//     glColor3f(1.0f, 1.0f, 1.0f);
//     FillCircleInundation(0, 0, 100 + x);
//     TranslatePoint(x, y, 1, 1);
// }
