#include <iostream>

#include "imgui.h"
#include "../lib/imgui_impl_glfw.h"
#include "../lib/imgui_impl_opengl3.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "graphics.h"

const int WIDTH = 640;
const int HEIGHT = 480;
int OPTION = 1;

void glfwErrorCallback(int error, const char *description);
void glfwKeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
void display();

int main()
{
	glfwSetErrorCallback(glfwErrorCallback);

	if (!glfwInit())
	{
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return EXIT_FAILURE;
	}

#if __APPLE__
	// GL 3.2 + GLSL 150
	const char *glsl_version = "#version 150";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);		   // Required on Mac
#else
	const char *glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
#endif

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

	int display_w, display_h;
	glfwGetFramebufferSize(window, &display_w, &display_h);
	glViewport(0, 0, display_w, display_h);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init();

	while (!glfwWindowShouldClose(window))
	{
		// Viewport
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);

		// Limpia la pantalla
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

		// Define el plano de proyeccion
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-WIDTH / 2, WIDTH / 2, -HEIGHT / 2, HEIGHT / 2, -1, 1);

		// Define la matriz de modelo y vista
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		// Dibuja
		display();

		// Inicia el nuevo frame de ImGui
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		// Crea la ventana de ImGui
		ImGui::Begin("Gráficos");
		ImGui::Text("Opciones:");
		ImGui::End();

		// Renderiza la ventana de ImGui
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		// Intercambia los buffers
		glfwSwapBuffers(window);
		// Poll for and process events
		glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

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
	if (key == GLFW_KEY_N && action == GLFW_PRESS)
	{
		std::cout << "Presionaste la tecla N" << std::endl;
		OPTION++;
		if (OPTION > 6)
		{
			OPTION = 1;
		}
	}
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void display()
{
	switch (OPTION)
	{
	case 1:
	{
		glColor3f(1.0f, 0.0f, 0.0f);
		PutPixel(0, 0);
		break;
	}
	case 2:
	{
		glColor3f(0.0f, 1.0f, 0.0f);
		DrawLineDDA(0, 0, 100, 100);
		break;
	}
	case 3:
	{
		glColor3f(0.0f, 0.0f, 1.0f);
		DrawLineDDA(0, 0, -100, -100);
		break;
	}
	case 4:
	{
		glColor3f(1.0f, 0.0f, 1.0f);
		DrawLineBresenham(0, 0, -100, 0);
		break;
	}
	case 5:
	{
		glColor3f(1.0f, 1.0f, 0.0f);
		DrawLineMidPoint(0, 0, 100, -100);
		break;
	}
	case 6:
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		DrawCircleMidPoint(0, 0, 100);
		break;
	}
	}
}