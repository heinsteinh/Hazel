#version 330 core

layout(location = 0) out vec4 o_Color;

in vec4 v_Color;
in vec2 v_TextureCoordinate;
in int v_TextureIndex;

uniform sampler2D u_Textures[48];

void main()
{
    o_Color = texture(u_Textures[v_TextureIndex], v_TextureCoordinate) * v_Color;
}