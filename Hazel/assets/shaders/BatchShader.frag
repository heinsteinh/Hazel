#version 420 core

layout(location = 0) out vec4 o_Color;

in vec4 v_Color;
in vec2 v_TextureCoordinate;
in float v_TextureIndex;

uniform sampler2D u_Textures[32];

void main()
{
    o_Color = texture(u_Textures[int(v_TextureIndex)], v_TextureCoordinate) * v_Color;
}