#pragma once

#include <iostream>

#include <glad/glad.h>

namespace CTP::Render
{
class Texture {
public:
    Texture();
    Texture(GLuint _width, GLuint _height, GLuint _in_format, GLuint _im_format,
            GLuint _wrap_s, GLuint _wrap_t, GLuint _filter_min, GLuint _filter_max);
    void GenTexture(GLuint width, GLuint height, unsigned char* data);
    void Bind() const;

public:
    GLuint width, height;
    GLuint internal_format, image_format;
    GLuint wrap_s, wrap_t; // wrapping mode on S and T axis
    GLuint filter_min, filter_max; // Filtering if texture > or < screen pixels

private:
    GLuint TextureID;
};
} // namespace CTP::Render
