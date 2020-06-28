#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Color;
layout(location = 2) in vec2 a_TextureCoordinate;
layout(location = 3) in int a_TextureIndex;

uniform mat4 u_ViewProjection;

out vec4 v_Color;
out vec2 v_TextureCoordinate;
out int v_TextureIndex;

void main()
{
    v_Color = a_Color;
    v_TextureCoordinate = a_TextureCoordinate;
    v_TextureIndex = a_TextureIndex;
    gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
}