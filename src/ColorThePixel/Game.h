#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <memory>
#include <unordered_map>

#include "InputHandler.h"
#include "Render/Renderer.h"


namespace CTP {
class Game {
public:


public:
	Game();
	~Game();

	void Start();
	GLFWwindow* GetWindow();

private:
	

private:
	GLFWwindow* m_Window = nullptr;

	// TODO: Make a config file and read resolution from it
	const uint32_t m_wWidth = 1600;
	const uint32_t m_wHeight = 900;

	std::unique_ptr<Render::Renderer> m_TextureRenderer;


};
}; //namespace CTP