#include "Shader.h"

namespace Resources {
    Shader& Shader::Use() {
        glUseProgram(this->id);
        return *this;
    }

    void Shader::Compile(const char* vertex_source, const char* fragment_source) {
        uint32_t sVertex, sFragment;

        // Create vertex shader
        sVertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(sVertex, 1, &vertex_source, 0);
        glCompileShader(sVertex);
        CheckCompileErrors(sVertex, "VERTEX");

        // Create fragment shader
        sFragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(sFragment, 1, &fragment_source, 0);
        glCompileShader(sFragment);
        CheckCompileErrors(sFragment, "FRAGMENT");

        this->id = glCreateProgram();
        glAttachShader(this->id, sVertex);
        glAttachShader(this->id, sFragment);
        glLinkProgram(this->id);
        CheckCompileErrors(this->id, "PROGRAM");

        // Delete shaders, because they are linked above
        glDeleteShader(sVertex);
        glDeleteShader(sFragment);
    }

    void Shader::CheckCompileErrors(uint32_t object, std::string type) {
        int success;
        char log[1024];

        if(type != "PROGRAM") {
            glGetShaderiv(object, GL_COMPILE_STATUS, &success);
            if(!success) {
                glGetShaderInfoLog(object, 1024, NULL, log);
                printf("%s SHADER compile error: %s\n", type.c_str(), log);
            }
        }
        else { 
            glGetProgramiv(object, GL_LINK_STATUS, &success);
            if(!success) {
                glGetProgramInfoLog(object, 1024, NULL, log);
                printf("%s link error: %s\n", type.c_str(), log);
            }
        }
    }

    // Functions to set uniform values
    void Shader::SetFloat(const char* name, float value, bool use_shader) {
        if(use_shader)
            this->Use();
        glUniform1f(glGetUniformLocation(this->id, name), value);
    }
    void Shader::SetInt(const char* name, int value, bool use_shader) {
        if(use_shader)
            this->Use();
        glUniform1i(glGetUniformLocation(this->id, name), value);
    }
    void Shader::SetVec2f(const char* name, float x, float y, bool use_shader) {
        if(use_shader)
            this->Use();
        glUniform2f(glGetUniformLocation(this->id, name), x, y);
    }
    void Shader::SetVec2f(const char* name, const glm::vec2& value, bool use_shader) {
        if(use_shader)
            this->Use();
        glUniform2f(glGetUniformLocation(this->id, name), value.x, value.y);
    }
    void Shader::SetVec3f(const char* name, float x, float y, float z, bool use_shader) {
        if(use_shader)
            this->Use();
        glUniform3f(glGetUniformLocation(this->id, name), x, y, z);
    }
    void Shader::SetVec3f(const char* name, const glm::vec3& value, bool use_shader) {
        if(use_shader)
            this->Use();
        glUniform3f(glGetUniformLocation(this->id, name), value.x, value.y, value.z);
    }
    void Shader::SetVec4f(const char* name, float x, float y, float z, float w, bool use_shader) {
        if(use_shader)
            this->Use();
        glUniform4f(glGetUniformLocation(this->id, name), x, y, z, w);
    }
    void Shader::SetVec4f(const char* name, const glm::vec4& value, bool use_shader) {
        if(use_shader)
            this->Use();
        glUniform4f(glGetUniformLocation(this->id, name), value.x, value.y, value.z, value.w);
    }
    void Shader::SetMat4(const char* name, const glm::mat4& matrix, bool use_shader) {
        if(use_shader)
            this->Use();
        glUniformMatrix4fv(glGetUniformLocation(this->id, name), 1, false, glm::value_ptr(matrix));
    }
}

