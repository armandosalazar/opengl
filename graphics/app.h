#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class app
{
private:
    /* data */
public:
    app(/* args */);
    ~app();
    void run();
};

app::app(/* args */)
{
}

app::~app()
{
}

inline void app::run()
{
    if (!glfwInit())
    {
        std::cerr << "glfwInit failed" << std::endl;
        return EXIT_FAILURE;
    }

    GLFWwindow *window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

    if (!window)
    {
        std::cerr << "glfwCreateWindow failed" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
}
