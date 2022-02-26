#pragma once

#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Resources {
    class Shader {
        public:
            uint32_t id;

            Shader() {}
            Shader &Use();

            void Compile(const char* vertex_source, const char* fragment_source);
            void SetFloat   (const char* name, float value, bool use_shader = false);
            void SetInt     (const char* name, int value, bool use_shader = false);
            void SetVec2f   (const char* name, float x, float y, bool use_shader = false);
            void SetVec2f   (const char* name, const glm::vec2& value, bool use_shader = false);
            void SetVec3f   (const char* name, float x, float y, float z, bool use_shader = false);
            void SetVec3f   (const char* name, const glm::vec3& value, bool use_shader = false);
            void SetVec4f   (const char* name, float x, float y, float z, float w, bool use_shader = false);
            void SetVec4f   (const char* name, const glm::vec4& value, bool use_shader = false);
            void SetMat4    (const char* name, const glm::mat4& matrix, bool use_shader = false);

        private:
            void CheckCompileErrors(uint32_t object, std::string type);
    };
}