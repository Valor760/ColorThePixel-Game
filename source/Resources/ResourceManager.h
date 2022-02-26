#pragma once

#include <map>
#include <string>

#include <glad/glad.h>

#include "Texture2D.h"
#include "Shader.h"

namespace Resources {
    class ResourceManager {
        public:
            static inline std::map<std::string, Shader> shaders;
            static inline std::map<std::string, Texture2D> textures;

            static Shader LoadShader(const char* vertex_shader_file, const char* fragment_shader_file, std::string name);
            static Shader GetShader(std::string name);
            static Texture2D LoadTexture(const char* texture_file, bool alpha, std::string name);
            static Texture2D GetTexture(std::string name);
            static void Clear();

        private:
            // Private constuctor so no objects of Resource Manager
            ResourceManager() {}

            static Shader LoadShaderFromFile(const char* vertex_shader_file, const char* fragment_shader_file);
            static Texture2D LoadTextureFromFile(const char* texture_file, bool alpha);
    };
}