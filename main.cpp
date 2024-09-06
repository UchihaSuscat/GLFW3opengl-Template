#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
	// INITIALIZE GLFW
	glfwInit();

	// Tell glfw which version of opengl we are using
	// In this case we are using 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Tell glfw we are using the core profile (there are two compatibility and core)
	// So we will have more mordern functions/commands or something
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Creating a window using glfw
	GLFWwindow* window = glfwCreateWindow(800, 800, "Hello", NULL, NULL);

	// Error checking if window is being created or na!
	if (window == NULL) { std::cout << "Failed to create the window \n"; glfwTerminate(); return -1; }

	// Telling glfw that the variable window is our window we have to display or smth
	glfwMakeContextCurrent(window);

	// Initialize GLAD
	gladLoadGL();

	// Specify basically what ur seeing on the screen in the moment
	glViewport(0, 0, 800, 800);

	// Make the window color change
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

	// Clean/Clear the backbuffer and assign new color to it
	glClear(GL_COLOR_BUFFER_BIT);

	// Tell glfw to swap the buffers
	glfwSwapBuffers(window);

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// glfw takes care of all the events for eg closing of the window using this
		glfwPollEvents();
	}

	// The following is done to make it so that memory isnt leaked and the app doesnt crash

	// Delete the window before ending the program
	glfwDestroyWindow(window);

	// Terminate glfw before ending the program
	glfwTerminate();
	return 0;
}