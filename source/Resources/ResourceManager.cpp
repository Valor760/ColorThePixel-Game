#include <sstream>
#include <fstream>

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#endif

#include "ResourceManager.h"


// std::map<std::string, Shader> ResourceManager::shaders;
// std::map<std::string, Texture2D> ResourceManager::textures;
namespace Resources {
    Shader ResourceManager::LoadShader(const char* vertex_shader_file, const char* fragment_shader_file, std::string name) {
        ResourceManager::shaders[name] = LoadShaderFromFile(vertex_shader_file, fragment_shader_file);
        return ResourceManager::shaders[name];
    }

    Shader ResourceManager::GetShader(std::string name) {
        return ResourceManager::shaders[name];
    }

    Texture2D ResourceManager::LoadTexture(const char* texture_file, bool alpha, std::string name) {
        ResourceManager::textures[name] = LoadTextureFromFile(texture_file, alpha);
        return ResourceManager::textures[name];
    }

    Texture2D ResourceManager::GetTexture(std::string name) {
        return ResourceManager::textures[name];
    }

    void ResourceManager::Clear() {
        for(auto shader : ResourceManager::shaders)
            glDeleteProgram(shader.second.id);
        for(auto texture : ResourceManager::textures)
            glDeleteTextures(1, &texture.second.id);
    }

    Shader ResourceManager::LoadShaderFromFile(const char* vertex_shader_file, const char* fragment_shader_file) {
        std::string vertex_code, fragment_code;

        try {
            std::ifstream vertexShaderFile(vertex_shader_file);
            std::ifstream fragmentShaderFile(fragment_shader_file);

            std::stringstream vShaderStream, fShaderStream;
            vShaderStream << vertexShaderFile.rdbuf();
            fShaderStream << fragmentShaderFile.rdbuf();

            vertexShaderFile.close();
            fragmentShaderFile.close();

            vertex_code = vShaderStream.str();
            fragment_code = fShaderStream.str();
        }
        catch(std::exception e) {
            printf("ERROR: Failed to read shader files!\n");
        }

        Shader shader;
        shader.Compile(vertex_code.c_str(), fragment_code.c_str());

        return shader;
    }

    Texture2D ResourceManager::LoadTextureFromFile(const char* texture_file, bool alpha) {
        Texture2D texture;
        if (alpha) {
            texture.internal_format = GL_RGBA;
            texture.image_format = GL_RGBA;
        }

        // FIXME: play around with GL_RGBA and GL_RGB
        // if problems with .jpg files load occurs
        int width, height, channels_num;
        unsigned char* data = stbi_load(texture_file, &width, &height, &channels_num, 0);
        texture.Generate(width, height, data);

        stbi_image_free(data);

        return texture;
    }
}