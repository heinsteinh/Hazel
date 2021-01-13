#version 460 core

layout(binding = 0) uniform sampler2D u_Texture0;
layout(binding = 1) uniform sampler2D u_Texture1;
layout(binding = 2) uniform sampler2D u_Texture2;
layout(binding = 3) uniform sampler2D u_Texture3;
layout(binding = 4) uniform sampler2D u_Texture4;
layout(binding = 5) uniform sampler2D u_Texture5;
layout(binding = 6) uniform sampler2D u_Texture6;
layout(binding = 7) uniform sampler2D u_Texture7;
layout(binding = 8) uniform sampler2D u_Texture8;
layout(binding = 9) uniform sampler2D u_Texture9;
layout(binding = 10) uniform sampler2D u_Texture10;
layout(binding = 11) uniform sampler2D u_Texture11;
layout(binding = 12) uniform sampler2D u_Texture12;
layout(binding = 13) uniform sampler2D u_Texture13;
layout(binding = 14) uniform sampler2D u_Texture14;
layout(binding = 15) uniform sampler2D u_Texture15;
layout(binding = 16) uniform sampler2D u_Texture16;
layout(binding = 17) uniform sampler2D u_Texture17;
layout(binding = 18) uniform sampler2D u_Texture18;
layout(binding = 19) uniform sampler2D u_Texture19;
layout(binding = 20) uniform sampler2D u_Texture20;
layout(binding = 21) uniform sampler2D u_Texture21;
layout(binding = 22) uniform sampler2D u_Texture22;
layout(binding = 23) uniform sampler2D u_Texture23;
layout(binding = 24) uniform sampler2D u_Texture24;
layout(binding = 25) uniform sampler2D u_Texture25;
layout(binding = 26) uniform sampler2D u_Texture26;
layout(binding = 27) uniform sampler2D u_Texture27;
layout(binding = 28) uniform sampler2D u_Texture28;
layout(binding = 29) uniform sampler2D u_Texture29;
layout(binding = 30) uniform sampler2D u_Texture30;
layout(binding = 31) uniform sampler2D u_Texture31;

layout(location = 0) in vec4 v_Color;
layout(location = 1) in vec2 v_TextureCoordinate;
layout(location = 2) in flat int v_TextureSlot;

layout(location = 0) out vec4 o_Color;

void main()
{
	switch (v_TextureSlot)
	{
		case 0:
			o_Color = v_Color * texture(u_Texture0, v_TextureCoordinate);
			break;
		case 1: 
			o_Color = v_Color * texture(u_Texture1, v_TextureCoordinate);
			break;
		case 2: 
			o_Color = v_Color * texture(u_Texture2, v_TextureCoordinate);
			break;
		case 3: 
			o_Color = v_Color * texture(u_Texture3, v_TextureCoordinate);
			break;
		case 4: 
			o_Color = v_Color * texture(u_Texture4, v_TextureCoordinate);
			break;
		case 5: 
			o_Color = v_Color * texture(u_Texture5, v_TextureCoordinate);
			break;
		case 6: 
			o_Color = v_Color * texture(u_Texture6, v_TextureCoordinate);
			break;
		case 7: 
			o_Color = v_Color * texture(u_Texture7, v_TextureCoordinate);
			break;
		case 8: 
			o_Color = v_Color * texture(u_Texture8, v_TextureCoordinate);
			break;
		case 9: 
			o_Color = v_Color * texture(u_Texture9, v_TextureCoordinate);
			break;
		case 10:
			o_Color = v_Color * texture(u_Texture10, v_TextureCoordinate);
			break;
		case 11:
			o_Color = v_Color * texture(u_Texture11, v_TextureCoordinate);
			break;
		case 12:
			o_Color = v_Color * texture(u_Texture12, v_TextureCoordinate);
			break;
		case 13:
			o_Color = v_Color * texture(u_Texture13, v_TextureCoordinate);
			break;
		case 14:
			o_Color = v_Color * texture(u_Texture14, v_TextureCoordinate);
			break;
		case 15:
			o_Color = v_Color * texture(u_Texture15, v_TextureCoordinate);
			break;
		case 16:
			o_Color = v_Color * texture(u_Texture16, v_TextureCoordinate);
			break;
		case 17:
			o_Color = v_Color * texture(u_Texture17, v_TextureCoordinate);
			break;
		case 18:
			o_Color = v_Color * texture(u_Texture18, v_TextureCoordinate);
			break;
		case 19:
			o_Color = v_Color * texture(u_Texture19, v_TextureCoordinate);
			break;
		case 20:
			o_Color = v_Color * texture(u_Texture20, v_TextureCoordinate);
			break;
		case 21:
			o_Color = v_Color * texture(u_Texture21, v_TextureCoordinate);
			break;
		case 22:
			o_Color = v_Color * texture(u_Texture22, v_TextureCoordinate);
			break;
		case 23:
			o_Color = v_Color * texture(u_Texture23, v_TextureCoordinate);
			break;
		case 24:
			o_Color = v_Color * texture(u_Texture24, v_TextureCoordinate);
			break;
		case 25:
			o_Color = v_Color * texture(u_Texture25, v_TextureCoordinate);
			break;
		case 26:
			o_Color = v_Color * texture(u_Texture26, v_TextureCoordinate);
			break;
		case 27:
			o_Color = v_Color * texture(u_Texture27, v_TextureCoordinate);
			break;
		case 28:
			o_Color = v_Color * texture(u_Texture28, v_TextureCoordinate);
			break;
		case 29:
			o_Color = v_Color * texture(u_Texture29, v_TextureCoordinate);
			break;
		case 30:
			o_Color = v_Color * texture(u_Texture30, v_TextureCoordinate);
			break;
		case 31:
			o_Color = v_Color * texture(u_Texture31, v_TextureCoordinate);
			break;
	}
}