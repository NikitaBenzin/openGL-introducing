#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

using namespace std;

int main() {
// initialising glfw (иницализировать)
	glfwInit();

// Hint for glfw which versions(3.3) and profiles should use (подсказка версии)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
// with CORE profile we use the modern functions 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

// creating a GLFWwindow object (width, height, "name", fullscreen or not, share)
	GLFWwindow *window = glfwCreateWindow(800, 800, "White window", NULL, NULL);
// if window fails to create
	if (window == NULL) {
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}
// introduce the window into the current context(представляем текущий контекст)
	glfwMakeContextCurrent(window);

// loading the configs to openGL
	gladLoadGL();

// specify the viewport of openGL in the window (указываем)
	glViewport(0, 0, 800, 800);

/* Specify(указываем) цвет of the background*/
	glClearColor(0.7f, 0.13f, 0.15f, 1.0f);
// clear the back buffer and assign(назначаем) the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
// swap the back buffer with the front buffer
	glfwSwapBuffers(window);

// main while loop
	while(!glfwWindowShouldClose(window)){
		// take care of all GLFW events
		glfwPollEvents();
	}

// delete window before ending the program
	glfwDestroyWindow(window);
// terminate the window (закрыть окно)
	glfwTerminate();
	return 0;
}