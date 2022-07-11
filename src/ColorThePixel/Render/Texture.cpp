#include "Texture.h"

namespace CTP::Render
{
Texture::Texture() :
    width{0}, height{0}, internal_format{GL_RGB}, image_format{GL_RGB},
    wrap_s{GL_REPEAT}, wrap_t{GL_REPEAT}, filter_min{GL_LINEAR}, filter_max{GL_LINEAR}
    {
        glGenTextures(1, &TextureID);
    }

Texture::Texture(
    GLuint _width, 
    GLuint _height, 
    GLuint _in_format, 
    GLuint _im_format,
    GLuint _wrap_s, 
    GLuint _wrap_t, 
    GLuint _filter_min, 
    GLuint _filter_max) 
    :
    width{_width}, height{_height}, internal_format{_in_format}, image_format{_im_format},
    wrap_s{_wrap_s}, wrap_t{_wrap_t}, filter_min{_filter_min}, filter_max{_filter_max}
    {
        glGenTextures(1, &TextureID);
    }

void Texture::GenTexture(GLuint _width, GLuint _height, unsigned char* data) {
    width = _width;
    height = _height;
}
} // namespace CTP::Render
