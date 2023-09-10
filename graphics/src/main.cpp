#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Graphics.h"

const int WIDTH = 640;
const int HEIGHT = 480;
int opt = 1;

void glfwErrorCallback(int error, const char* description);
void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void display();

int main() {
	glfwSetErrorCallback(glfwErrorCallback);

	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return EXIT_FAILURE;
	}

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Graficos", NULL, NULL);

	if (!window) {
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, glfwKeyCallback);
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW" << std::endl;
		glfwTerminate();
		return EXIT_FAILURE;
	}

	while (!glfwWindowShouldClose(window)) {

		glClear(GL_COLOR_BUFFER_BIT);

		// Define el plano de proyeccion
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-WIDTH / 2, WIDTH / 2, -HEIGHT / 2, HEIGHT / 2, -1, 1);


		// Define la matriz de modelo y vista
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		// Dibuja
		display();


		glfwSwapBuffers(window);

		glfwPollEvents();

		// Cambiar opción

		// Imprimir fps
		std::cout << "FPS: " << 1 / glfwGetTime() << std::endl;	
		std::cout << "Opcion: " << opt << std::endl;
		system("cls");

	}
	return EXIT_SUCCESS;
}

void glfwErrorCallback(int error, const char* description)
{
	std::cerr << "GLFW Error: " << description << std::endl;
}

void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	if (key == GLFW_KEY_N) {
		std::cout << "N" << std::endl;
		opt++;
		if (opt > 2) opt = 1;
	}
}

void display()
{
	switch (opt) {
	case 1: {
		glColor3f(1.0f, 0.0f, 0.0f);
		PutPixel(0, 0);
		break;
	}
	case 2: {
		glColor3f(1.0f, 0.0f, 0.0f);
		PutPixel(0, 0);
		PutPixel(1, 0);
		PutPixel(0, 1);
		break;
	}
	}
}
