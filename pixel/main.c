#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GL_SILENCE_DEPRECATION 1

#include <GLFW/glfw3.h>
#include <OpenGL/gl.h>

const int window_width = 640;
const int window_height = 480;

// callback de teclado
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    // Cerrar la ventana al presionar ESC
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void put_pixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2f((GLfloat)x, (GLfloat)y);
    glEnd();
}

void line_dda(int x0, int y0, int x1, int y1)
{
    int dx = x1 - x0, dy = y1 - y0, steps, k;
    float xIncrement, yIncrement, x = x0, y = y0;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    xIncrement = (float)dx / (float)steps;
    yIncrement = (float)dy / (float)steps;

    put_pixel(round(x), round(y));
    for (k = 0; k < steps; k++)
    {
        x += xIncrement;
        y += yIncrement;
        put_pixel(round(x), round(y));
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2.0);
    line_dda(0, 0, 100, 100);
    glFlush();
}

int main()
{
    if (!glfwInit()) // Inicializar GLFW
    {
        fprintf(stderr, "Error al inicializar GLFW\n");
        return EXIT_FAILURE;
    }


    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); // No se puede cambiar el tamano de la ventana

    GLFWwindow *window = glfwCreateWindow(window_width, window_height, "Draw Pixel", NULL, NULL); // Crear ventana

    if (!window) // Si no se pudo crear la ventana
    {
        fprintf(stderr, "Error al crear ventana GLFW\n");
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window); // Establecer contexto de OpenGL

    glfwSetKeyCallback(window, key_callback); // Establecer callback de teclado

    while (!glfwWindowShouldClose(window)) // Ciclo de dibujo
    {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height); // Obtener tamano de ventana
        glViewport(0, 0, width, height);                 // Establecer viewport

        glMatrixMode(GL_PROJECTION); // Establecer matriz de proyeccion
        glLoadIdentity();           // Reiniciar matriz de proyeccion
        glOrtho(-window_width / 2, window_width / 2, -window_height / 2, window_height / 2, -1.0, 1.0); // Establecer proyeccion ortogonal
        glMatrixMode(GL_MODELVIEW); // Establecer matriz de modelo y vista

        display(); // Dibujar

        glfwSwapBuffers(window); // Intercambiar buffers

        glfwPollEvents(); // Revisar si hay eventos por procesar
    }

    glfwDestroyWindow(window); // Destruir ventana
    glfwTerminate();           // Terminar GLFW

    return EXIT_SUCCESS; // Terminar programa
}
