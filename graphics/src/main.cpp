#include <iostream>

#include <GL/glew.h>
// #define NANOVG_GL3_IMPLEMENTATION
// #include "nanovg.h"
// #include "nanovg_gl.h"
#include <GLFW/glfw3.h>

#include "graphics.h"

const int WIDTH = 640;
const int HEIGHT = 480;
const int NUM_OPTIONS = 7;
int OPTION = 1;

void glfwErrorCallback(int error, const char *description);
void glfwKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
void displayFunction();
void setWindowTitle(GLFWwindow *window, const char *title);

int main()
{
	glfwSetErrorCallback(glfwErrorCallback);

	if (!glfwInit())
	{
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return EXIT_FAILURE;
	}

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

	// int display_w, display_h;
	// glfwGetFramebufferSize(window, &display_w, &display_h);
	// glViewport(0, 0, display_w, display_h);

	// NVGcontext *vg = nvgCreateGL3(NVG_ANTIALIAS | NVG_STENCIL_STROKES);

	while (!glfwWindowShouldClose(window))
	{
		// Viewport
		// glfwGetFramebufferSize(window, &display_w, &display_h);
		// glViewport(0, 0, display_w, display_h);

		// Limpia la pantalla
		glClear(GL_COLOR_BUFFER_BIT);

		// // Comienza un nuevo marco de NanoVG
        // nvgBeginFrame(vg, 800, 600, 1.0f);

        // // Establece el tamaño de la fuente y el color
        // nvgFontSize(vg, 48.0f);
        // nvgFontFace(vg, "sans");
        // nvgFillColor(vg, nvgRGBA(255, 255, 255, 255)); // Color blanco

        // // Renderiza texto en la posición (100, 100)
        // nvgText(vg, 100, 100, "Hello, NanoVG!", NULL);

        // // Finaliza el marco de NanoVG
        // nvgEndFrame(vg);

		// Define el plano de proyeccion
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-WIDTH / 2, WIDTH / 2, -HEIGHT / 2, HEIGHT / 2, -1, 1);

		// Define la matriz de modelo y vista
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		// Dibuja
		displayFunction();

		// Intercambia los buffers
		glfwSwapBuffers(window);
		// Poll for and process events
		glfwPollEvents();
	}

	// nvgDeleteGL3(vg);

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
		OPTION++;
		if (OPTION > NUM_OPTIONS)
		{
			OPTION = 1;
		}
	}
	if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
	{
		OPTION--;
		if (OPTION < 1)
		{
			OPTION = NUM_OPTIONS;
		}
	}
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void displayFunction()
{
	switch (OPTION)
	{
	case 1:
	{
		setWindowTitle(glfwGetCurrentContext(), "Gráficos - Punto");
		glColor3f(1.0f, 0.0f, 0.0f);
		glPointSize(2.0f);
		PutPixel(0, 0);
		break;
	}
	case 2:
	{
		setWindowTitle(glfwGetCurrentContext(), "Gráficos - Línea DDA: (0, 0), (100, 100)");
		glColor3f(0.0f, 1.0f, 0.0f);
		DrawLineDDA(0, 0, 100, 100);
		break;
	}
	case 3:
	{
		setWindowTitle(glfwGetCurrentContext(), "Gráficos - Línea DDA: (0, 0), (-100, -100)");
		glColor3f(0.0f, 0.0f, 1.0f);
		DrawLineDDA(0, 0, -100, -100);
		break;
	}
	case 4:
	{
		setWindowTitle(glfwGetCurrentContext(), "Gráficos - Línea Bresenham: (0, 0), (-100, 0)");
		glColor3f(1.0f, 0.0f, 1.0f);
		DrawLineBresenham(0, 0, -100, 0);
		break;
	}
	case 5:
	{
		setWindowTitle(glfwGetCurrentContext(), "Gráficos - Línea Punto Medio: (0, 0), (100, -100)");
		glColor3f(1.0f, 1.0f, 0.0f);
		DrawLineMidPoint(0, 0, 100, -100);
		break;
	}
	case 6:
	{
		setWindowTitle(glfwGetCurrentContext(), "Gráficos - Círculo Punto Medio: (0, 0), (100, 100)");
		glColor3f(1.0f, 1.0f, 1.0f);
		DrawCircleMidPoint(0, 0, 100);
		break;
	}
	case 7:
	{
		setWindowTitle(glfwGetCurrentContext(), "Gráficos - Círculo Básico: (100, 100), (0, 0)");
		glColor3f(1.0f, 0.0f, 0.0f);
		DrawCircleBasic(100, 100, 0, 0);
		break;
	}
	}
}

void setWindowTitle(GLFWwindow *window, const char *title)
{
	glfwSetWindowTitle(window, title);
}
