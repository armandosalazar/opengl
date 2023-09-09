#include <iostream>

#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLFW/glfw3.h>
#include <imgui.h>

int main() {
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	GLFWwindow* window = glfwCreateWindow(800, 400, "ImGui Demo", nullptr, nullptr);

	if (!window) {
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	IMGUI_CHECKVERSION();
	// ImGui::CreateContext();
	// ImGuiIO& io = ImGui::GetIO();
	// (void)io;

	// ImGui::StyleColorsDark();
	// ImGuiStyle& style = ImGui::GetStyle();

	// ImGui_ImplGlfw_InitForOpenGL(window, true);


	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
