#type vertex
#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec2 a_Color;
layout(location = 2) in vec2 a_TextureCoordinate;
layout(location = 3) in int a_TextureIndex;

out vec4 v_Color;
out vec2 v_TextureCoordinate;
out int v_TextureIndex;

uniform mat4 u_ViewProjection;

void main()
{
    v_Color = a_Color;
    v_TextureCoordinate = a_TextureCoordinate;
    v_TextureIndex = a_TextureIndex;
    gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
}

#type fragment
#version 330 core

layout(location = 0) out vec4 o_Color;

in vec4 v_Color;
in vec2 v_TextureCoordinate;
in int v_TextureIndex;

uniform sampler2D u_Textures[32];
uniform float u_Scale;

void main()
{
    o_Color = texture(u_Textures[v_TextureIndex], v_TextureCoordinate * u_Scale) * v_Color;
}