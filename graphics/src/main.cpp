#include <iostream>
#include <cmath>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "graphics.h"

const int WIDTH = 640;
const int HEIGHT = 480;
int x = 0, y = 0, center = 0, option = 0;
const int OPTIONS = 2;
bool flag = false;

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
    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
    {
        option++;
        if (option > OPTIONS)
        {
            option = 1;
        }
    }
    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
    {
        option--;
        if (option < 1)
        {
            option = OPTIONS;
        }
    }
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void T()
{
    static int frame = 0;
    glPointSize(1.5f);

    if (frame % 400 < 200)
    {
        TranslatePoint(x, y, 1, 0);
    }
    else
    {
        TranslatePoint(x, y, -1, 0);
    }

    glColor3f(0.0f, 1.0f, 0.0f);
    FillRectangleScanline(x, y, 100 + x, 100 + y);

    frame++;
}

void R()
{
    /**
     * Use this function here with triangle
     void RotatePoint(int &x, int &y, int xc, int yc, float angle)
    {
        int matrix[3][3] = {
            {(int)round(cos(angle)), (int)round(sin(angle)), 0},
            {(int)round(-sin(angle)), (int)round(cos(angle)), 0},
            {0, 0, 1}};

        int result[3] = {0, 0, 0};

        for (int i = 0; i < 3; i++)
        {
            result[i] = matrix[i][0] * (x - xc) + matrix[i][1] * (y - yc) + matrix[i][2];
        }

        x = result[0] + xc;
        y = result[1] + yc;
    }
    */

    static int frame = 0;
    glPointSize(1.5f);
}

void S()
{
    ScalePoint(center, center, x, y);
    glColor3f(1.0f, 1.0f, 0.0f);
    FillCircleInundation(center, center, x);
    if (x == -100 && y == -100)
        flag = false;
    if (x == 100 && y == 100)
        flag = true;
    if (flag)
    {
        x--;
        y--;
    }
    else
    {
        x++;
        y++;
    }
}

void DisplayFunction()
{
    glPointSize(1.5f);
    glColor3f(1.0f, 1.0f, 0.4f);

    R();
}
