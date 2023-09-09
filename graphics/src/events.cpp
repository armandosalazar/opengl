#include "events.h"
#include <iostream>

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(window, GL_TRUE);

}

void onClick()
{
	std::cout << "Clicked" << std::endl;
}
