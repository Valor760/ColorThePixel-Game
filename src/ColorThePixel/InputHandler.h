#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace ColorThePixel {
// No action is saved because we are only interested
// in GLFW_PRESS or GLFW_RELEASE. If GLFW_REPEAT occurs
// it will be considered as GLFW_PRESS.
typedef struct {
	bool is_pressed;
	int scan_code;
	int mode;
} input_t;

class InputHandler {
public:
	static input_t GetKey(int key);
	static void KeyCallback(GLFWwindow* window, int key, int scan_code, int action, int mode);
	static glm::vec2 GetMousePos(GLFWwindow* window);

private:
	static inline void SetKey(int key, int scan_code, int mode);
	static inline void ResetKey(int key);

private:
	static inline input_t m_Keys[1024] = {};
};
} //namespace ColorThePixel