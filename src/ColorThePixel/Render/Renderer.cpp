#include "Renderer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <unordered_map>
#include <iostream>
#include <format>


namespace CTP::Render {
void Renderer::CompileShaders(const char* vertex_shader_path, const char* fragment_shader_path) {
    // Compile Vertex Shader
    uint32_t sVertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(sVertex, 1, &vertex_shader_path, 0);
    glCompileShader(sVertex); 
    CheckErrors(sVertex, "Vertex Shader");

    uint32_t sFragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(sFragment, 1, &fragment_shader_path, 0);
    glCompileShader(sFragment);
    CheckErrors(sFragment, "Fragment Shader");

    m_ProgramID = glCreateProgram();
    glAttachShader(m_ProgramID, sVertex);
    glAttachShader(m_ProgramID, sFragment);
    glLinkProgram(m_ProgramID);
    CheckErrors(m_ProgramID, "Program");

    // Cleanup shaders
    glDeleteShader(sVertex);
    glDeleteShader(sFragment);
}

Renderer::~Renderer() {
    glDeleteProgram(m_ProgramID);
}

void Renderer::CheckErrors(uint32_t object, std::string object_name) {
    int success;
    char log[1024];

    if(object_name == "Program") {
        glGetProgramiv(object, GL_LINK_STATUS, &success);
        if(!success) {
            glGetProgramInfoLog(object, sizeof(log), nullptr, log);
            std::cerr << "ERROR: Program link failed >> " << log << '\n';
        }
    }
    else {
        glGetShaderiv(object, GL_COMPILE_STATUS, &success);
        if(!success) {
            glGetShaderInfoLog(object, sizeof(log), nullptr, log);
            std::cerr << std::format("ERROR: {} compilation failed >> {}", object_name, log);
        }
    }
}

uint32_t Renderer::GetProgramID() const {
    return m_ProgramID;
}
} //namespace CTP::Render