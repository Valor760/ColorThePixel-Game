#include "Program.h"

void Program::Start(int width, int height, int _target_framerate) {
            Program::ColorThePixel = new Game(width, height);
            Program::target_framerate = _target_framerate;

            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            GLFWwindow* window = glfwCreateWindow(width, height, "Breakout", nullptr, nullptr);
            glfwMakeContextCurrent(window);

            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
                printf("Failed to initalize GLAD!\n");
                return;
            }

            glfwSetKeyCallback(window, KeyCallback);
            glfwSetFramebufferSizeCallback(window, FrameBufferCallback);

            glViewport(0, 0, width, height);
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            ColorThePixel->Init();

            float delta_time = 0.0f;
            float last_frame = 0.0f;

            while(!glfwWindowShouldClose(window)) {
                float current_time = glfwGetTime();
                delta_time = current_time - last_frame;
                last_frame = current_time;

                float start_time = glfwGetTime();
                glfwPollEvents();

                ColorThePixel->ProcessInput(delta_time);
                ColorThePixel->Update(delta_time);
                
                // Black background by default
                glClearColor(0.3f, 0.5f, 0.2f, 1.0f);
                // glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT);
                ColorThePixel->Render();

                glfwSwapBuffers(window);
                delta_time = glfwGetTime() - start_time;
                _sleep(1000 / Program::target_framerate - delta_time);
            }

            Resources::ResourceManager::Clear();

            glfwTerminate();
            return;
}

void Program::KeyCallback(GLFWwindow* window, int key, int scan_code, int action, int mode) {

}
void Program::FrameBufferCallback(GLFWwindow* window, int width, int height) {

}
void Program::CursorPosCallback(GLFWwindow* window, double x_pos, double y_pos) {

}
