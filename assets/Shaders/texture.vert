#version 330 core
layout (location = 0) in vec4 vertex;

out vec2 texture_coords;

// uniform mat4 model;
// uniform mat4 projection;

void main() {
    texture_coords = vertex.zw;
    gl_Position = vec4(vertex.xy, 0.0, 1.0);//projection * model * vec4(vertex.xy, 0.0, 1.0);
}