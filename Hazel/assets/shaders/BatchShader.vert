#version 420 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Color;
layout(location = 2) in vec2 a_TextureCoordinate;
layout(location = 3) in float a_TextureIndex;

layout(std140, binding = 0) uniform MATRICES
{
    mat4 u_ViewProjection;
};

out vec4 v_Color;
out vec2 v_TextureCoordinate;
out float v_TextureIndex;

void main()
{
    v_Color = a_Color;
    v_TextureCoordinate = a_TextureCoordinate;
    v_TextureIndex = a_TextureIndex;
    gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
}