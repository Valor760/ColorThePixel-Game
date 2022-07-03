#include "InputHandler.h"


namespace ColorThePixel {
void InputHandler::SetKey(int key, int scan_code, int mode) {
	m_Keys[key] = {
		.is_pressed = true,
		.scan_code = scan_code,
		.mode = mode
	};
}

void InputHandler::ResetKey(int key) {
	m_Keys[key] = {
		.is_pressed = false,
		.scan_code = -1,
		.mode = -1
	};
}

input_t InputHandler::GetKey(int key) {
	return m_Keys[key];
}

glm::vec2 InputHandler::GetMousePos(GLFWwindow* window) {
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	return glm::vec2{xpos, ypos};
}

void InputHandler::KeyCallback(GLFWwindow* window, int key, int scan_code, int action, int mode) {
	if (key >= 0 && key < 1024) {
		if (action == GLFW_PRESS) {
			SetKey(key, scan_code, mode);
		}
		else if (action == GLFW_RELEASE) {
			ResetKey(key);
		}
	}
}
} //namespace ColorThePixel