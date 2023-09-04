#include <stdio.h>
#include <stdlib.h>

#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

int main() {
	// Inicializar GLFW
	if (!glfwInit()) {
		fprintf(stderr, "Error al inicializar GLFW\n");
		return 1;
	} else {
		fprintf(stdout, "Inicialización de GLFW exitosa\n");
	}

	// Crear ventana
	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

	if (!window) {
		fprintf(stderr, "Error al crear ventana GLFW\n");
		glfwTerminate();
		return 1;
	} else {
		fprintf(stdout, "Creación de ventana GLFW exitosa\n");
	}

	// Seleccionar ventana
	glfwMakeContextCurrent(window);

	// Ciclo de dibujado
	while (!glfwWindowShouldClose(window)) {
		// Limpiar el buffer de color
		glClear(GL_COLOR_BUFFER_BIT);

		// Dibujar primitivas
		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.5f, -0.5f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(0.5f, -0.5f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.0f, 0.5f);
		glEnd();

		// Intercambiar buffers
		glfwSwapBuffers(window);

		// Detectar eventos
		glfwPollEvents();
	}

	// Terminar GLFW
	// Esto libera los recursos asociados con GLFW
	// Debe llamarse al finalizar el programa
	// Antes de llamar a esta función, debe cerrarse la ventana
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
