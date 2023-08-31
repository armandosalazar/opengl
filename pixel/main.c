#include <stdio.h>
#include <stdlib.h>

#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include <OpenGL/gl.h>

int main() {
	// Inicializar GLFW
	if (!glfwInit()) {
		fprintf(stderr, "Error al inicializar GLFW\n");
		return 1;
	}

	// Crear ventana
	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

	if (!window) {
		fprintf(stderr, "Error al crear ventana GLFW\n");
		glfwTerminate();
		return 1;
	}

	// Seleccionar ventana
	glfwMakeContextCurrent(window);

	// Ciclo de dibujado
	while (!glfwWindowShouldClose(window)) {
		// Establecer color de fondo
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

		// Limpiar el buffer de color
		glClear(GL_COLOR_BUFFER_BIT);

		// Dibujar un píxel rojo en el centro de la ventana (320, 240)
		glPointSize(1.0f);
		glBegin(GL_POINTS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.0f, 0.0f);
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
