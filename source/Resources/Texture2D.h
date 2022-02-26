#pragma once

#include <stdint.h>

#include <glad/glad.h>

namespace Resources {
    class Texture2D {
        public:
            uint32_t id;
            uint32_t width, height;
            uint32_t internal_format;
            uint32_t image_format;
            uint32_t wrap_S, wrap_T; // wrapping mode on S and T axis
            uint32_t filter_min, filter_max; // Filtering if texture > or < screen pixels

            Texture2D();
            void Generate(uint32_t width, uint32_t height, unsigned char* data);
            void Bind() const;
    };
}