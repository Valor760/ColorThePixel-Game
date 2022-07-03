#include "Game.h"


namespace ColorThePixel {
Game::Game() {}

Game::~Game() {
	glfwDestroyWindow(m_Window);
	glfwTerminate();
}

void Game::Start() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// FIXME: make window resizable or make resolution presets
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	m_Window = glfwCreateWindow(m_wWidth, m_wHeight, "Color The Pixel", nullptr, nullptr);
	glfwMakeContextCurrent(m_Window);

	// Load glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "ERROR: Failed to load glad!\n";
		return;
	}

	glViewport(0, 0, m_wWidth, m_wHeight);
	glfwSetKeyCallback(m_Window, InputHandler::KeyCallback);

	while (!glfwWindowShouldClose(m_Window)) {
		glfwPollEvents();
		glClearColor(0.5f, 0.1f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(m_Window);
	}
}

GLFWwindow* Game::GetWindow() {
	return m_Window;
}
} //namespace ColorThePixel