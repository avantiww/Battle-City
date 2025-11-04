#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//Вывод ошибок в консоль
void errorLog(std::string str) 
{
    std::cout << "ERROR: " << str << "!" << std::endl;
}

//Рзарешение окна
int g_windowSizeX = 640;
int g_windowSizeY = 480;

void glfwWindowSizeCallback(GLFWwindow* pWindow, int width, int height) 
{
    g_windowSizeX = width;
    g_windowSizeY = height;

    glViewport(0, 0, g_windowSizeX, g_windowSizeY);
}

//
void glfwKeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mode) 
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) 
    {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}

int main(void)
{
    //Инициализация GLFW
    if (!glfwInit()) 
    {
        errorLog("glfwInit failed");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Создание окна и контекста OpenGL
    GLFWwindow* pWindow = glfwCreateWindow(g_windowSizeX, g_windowSizeY, "Battle-City", nullptr, nullptr);

    if (!pWindow)
    {
        errorLog("glfwCreateWindow failed");
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallback);
    glfwSetKeyCallback(pWindow, glfwKeyCallback);

    //Создание контекста окна
    glfwMakeContextCurrent(pWindow);

    if (!gladLoadGL()) 
    {
        errorLog("can't load GLAD");
        return -1;
    }

    //Вывод информации о видеокарте и версии OpenGL
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL: " << glGetString(GL_VERSION) << std::endl;

    glClearColor(1, 0, 0, 1);

    //Главный цикл пока окно отрыто
    while (!glfwWindowShouldClose(pWindow))
    {
        //Рэндер
        glClear(GL_COLOR_BUFFER_BIT);

        //Свап переднего и заднего буфферов
        glfwSwapBuffers(pWindow);

        //Пул событий
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}