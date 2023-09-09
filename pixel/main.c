//
// Created by Armando Salazar on 05/09/23.
//

#include <stdio.h>
#include <stdlib.h>

#define GL_SILENCE_DEPRECATION 1

// #include <OpenGL/gl.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "graphics.h"

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpiar pantalla

    glColor3f(1.0f, 0.0f, 0.0f); // Establecer color rojo
    lineDDA(0, 0, 245, 0);   // Dibujar linea

    glColor3f(0.0f, 1.0f, 0.0f); // Establecer color verde
    lineDDA(0, 0, 0, -100);  // Dibujar linea

    glColor3f(0.0f, 0.0f, 1.0f); // Establecer color azul
    lineDDA(0, 0, 150, 100); // Dibujar linea
	
	glColor3f(1.0f, 1.0f, 0.0f); // Establecer color amarillo
	lineBresenham(0, 0, 150, 150);   // Dibujar linea

    glFlush(); // Enviar a dibujar
}

int main() {
    if (!glfwInit()) // Inicializar GLFW
    {
        fprintf(stderr, "Error al inicializar GLFW\n");
        return EXIT_FAILURE;
    }

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); // No se puede cambiar el tamaño de la ventana

    GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Draw Pixel", NULL, NULL); // Crear ventana

    if (!window) // Si no se pudo crear la ventana
    {
        fprintf(stderr, "Error al crear ventana GLFW\n");
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window); // Establecer contexto de OpenGL

    glfwSetKeyCallback(window, keyCallback); // Establecer callback de teclado

    while (!glfwWindowShouldClose(window)) // Ciclo de dibujo
    {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height); // Obtener tamaño de ventana
        glViewport(0, 0, width, height); // Establecer viewport

        glMatrixMode(GL_PROJECTION); // Establecer matriz de proyección
        glLoadIdentity(); // Reiniciar matriz de proyección
        glOrtho(-WINDOW_WIDTH / 2,WINDOW_WIDTH / 2,-WINDOW_HEIGHT / 2,WINDOW_HEIGHT / 2,-1.0,1.0); // Establecer proyección ortogonal
        glMatrixMode(GL_MODELVIEW); // Establecer matriz de modelo y vista

        display(); // Dibujar

        glfwSwapBuffers(window); // Intercambiar buffers

        glfwPollEvents(); // Revisar si hay eventos por procesar
    }

    glfwDestroyWindow(window); // Destruir ventana
    glfwTerminate(); // Terminar GLFW

    return EXIT_SUCCESS; // Terminar programa
}
