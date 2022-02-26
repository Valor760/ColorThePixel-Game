#pragma once

#include <stdio.h>

#include <glad/glad.h>
#include <glfw3.h>

#include "Game/Game.h"


class Program {
    public:
        static inline Game* ColorThePixel;
        static inline int target_framerate;

        static void Start(int width, int height, int _target_framrate);
    
    private:
        static void KeyCallback(GLFWwindow* window, int key, int scan_code, int action, int mode);
        static void FrameBufferCallback(GLFWwindow* window, int width, int height);
        static void CursorPosCallback(GLFWwindow* window, double x_pos, double y_pos);

};