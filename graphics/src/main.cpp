#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define NANOVG_GL2_IMPLEMENTATION
#include "nanovg.h"
#include "nanovg_gl.h"

#include "graphics.h"

const int WIDTH = 640;
const int HEIGHT = 480;
const int numOptions = 11;
int option = 1;

NVGcontext *vg;

void glfwErrorCallback(int error, const char *description);
void glfwKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
void displayFunction();
bool loadFonts();
void setTitle(const char *title);

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

	vg = nvgCreateGL2(NVG_STENCIL_STROKES);

	if (vg == NULL)
	{
		std::cerr << "Failed to initialize NanoVG" << std::endl;
		glfwTerminate();
		return EXIT_FAILURE;
	}

	if (!loadFonts())
	{
		std::cerr << "Failed to load fonts" << std::endl;
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
		displayFunction();

		// Intercambia los buffers
		glfwSwapBuffers(window);
		// Poll for and process events
		glfwPollEvents();
	}

	nvgDeleteGL2(vg);

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
		if (option > numOptions)
		{
			option = 1;
		}
	}
	if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
	{
		option--;
		if (option < 1)
		{
			option = numOptions;
		}
	}
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void displayFunction()
{
	nvgBeginFrame(vg, WIDTH, HEIGHT, 1.0f);
	switch (option)
	{
	case 1:
	{
		setTitle("Punto");
		glColor3f(1.0f, 0.0f, 0.0f);
		PutPixel(0, 0);
		break;
	}
	case 2:
	{
		setTitle("Línea DDA - ID");
		glColor3f(0.0f, 1.0f, 0.0f);
		DrawLineDDA(0, 0, 100, 100);
		break;
	}
	case 3:
	{
		setTitle("Línea DDA - DI");
		glColor3f(0.0f, 0.0f, 1.0f);
		DrawLineDDA(0, 0, -100, -100);
		break;
	}
	case 4:
	{
		setTitle("Línea Bresenham");
		glColor3f(1.0f, 0.0f, 1.0f);
		DrawLineBresenham(0, 0, -100, 0);
		break;
	}
	case 5:
	{
		setTitle("Línea Punto Medio");
		glColor3f(1.0f, 1.0f, 0.0f);
		DrawLineMidPoint(0, 0, 100, -100);
		break;
	}
	case 6:
	{
		setTitle("Círculo Punto Medio");
		glColor3f(1.0f, 1.0f, 1.0f);
		DrawCircleMidPoint(0, 0, 100);
		break;
	}
	case 7:
	{
		setTitle("Círculo Básico");
		glColor3f(1.0f, 0.0f, 0.0f);
		DrawCircleBasic(100, 100, 0, 0);
		break;
	}
	case 8:
	{
		setTitle("Círculo Coordenadas Polares");
		glColor3f(0.0f, 1.0f, 0.0f);
		DrawCirclePolarCoordinates(0, 0, 100);
		break;
	}
	case 9:
	{
		setTitle("Elipse Punto Medio");
		glColor3f(0.0f, 0.0f, 1.0f);
		DrawEllipseMidPoint(0, 0, 100, 50);
		break;
	}
	case 10:
	{
		setTitle("Rectángulo");
		glColor3f(1.0f, 0.0f, 1.0f);
		DrawRectangle(0, 0, 100, 50);
		break;
	}
	case 11:
	{
		setTitle("Figuras");
		glColor3f(1.0f, 1.0f, 1.0f);
		DrawLineBresenham(-310, 190, -220, 100);
		glColor3f(1.0f, 0.0f, 0.0f);
		DrawLineDDA(-210, 100, 0, 100);
		glColor3f(0.0f, 1.0f, 0.0f);
		DrawLineMidPoint(10, 100, 100, 230);
		glColor3f(0.0f, 0.0f, 1.0f);
		DrawLineMidPoint(110, 100, 300, 100);
		glColor3f(0.0f, 1.0f, 1.0f);
		DrawCircleBasic(10, 10, 0, 0);
		glColor3f(1.0f, 0.0f, 1.0f);
		DrawCirclePolarCoordinates(0, 0, 20);
		glColor3f(1.0f, 0.0f, 0.0f);
		DrawCircleMidPoint(0, 0, 30);
		glColor3f(0.0f, 1.0f, 0.0f);
		DrawRectangle(100, 0, 200, 50);
		glColor3f(0.0f, 0.0f, 1.0f);
		DrawRectangle(110, 10, 190, 40);
		glColor3f(0.0f, 1.0f, 1.0f);
		DrawEllipseMidPoint(-200, 0, 100, 50);
		glColor3f(1.0f, 1.0f, 0.0f);
		DrawEllipseMidPoint(-200, 0, 50, 25);
		glColor3f(1.0f, 0.0f, 1.0f);
		DrawEllipseMidPoint(-200, 0, 25, 12);
		glColor3f(0.0f, 0.0f, 1.0f);
		DrawEllipseMidPoint(-200, 0, 12, 6);
	}
	}
	nvgEndFrame(vg);
}

void setWindowTitle(GLFWwindow *window, const char *title)
{
	glfwSetWindowTitle(window, title);
}

bool loadFonts()
{
	if (nvgCreateFont(vg, "retro", "assets/retro-gaming.ttf") == -1)
		return false;
	else if (nvgCreateFont(vg, "sans", "assets/droidsans.ttf") == -1)
		return false;
	else if (nvgCreateFont(vg, "mono", "assets/bmonofont-i18n.ttf") == -1)
		return false;
	else
		return true;
}

void setTitle(const char *title)
{
	nvgFontSize(vg, 18.0f);
	nvgFontFace(vg, "retro");
	nvgTextAlign(vg, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
	nvgFillColor(vg, nvgRGBA(255, 255, 255, 255));
	nvgText(vg, 320, 20, title, NULL);
}
