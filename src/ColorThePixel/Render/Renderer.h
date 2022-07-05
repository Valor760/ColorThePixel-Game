#pragma once

#include <string>

namespace CTP::Render {
class Renderer {
public:
    Renderer(){};
    ~Renderer();

    void CompileShaders(const char* vertex_shader_path, const char* fragment_shader_path);
    inline uint32_t GetProgramID() const;    

private:
    uint32_t m_ProgramID;

private:
    void CheckErrors(uint32_t object, std::string object_name);
};
} //namespace CTP::Render