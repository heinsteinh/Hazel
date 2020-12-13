#version 460 core

layout(binding = 0) uniform Matrices
{
    mat4 u_ViewProjection;
};

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Color;
layout(location = 2) in vec2 a_TextureCoordinate;
layout(location = 3) in float a_TextureIndex;

layout(location = 0) out vec4 v_Color;
layout(location = 1) out vec2 v_TextureCoordinate;
layout(location = 2) out int v_TextureIndex;

void main()
{
    v_Color = a_Color;
    v_TextureCoordinate = a_TextureCoordinate;
    v_TextureIndex = int(a_TextureIndex);
    gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
}