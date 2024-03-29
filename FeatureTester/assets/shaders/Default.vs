#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec3 a_Scale;
layout(location = 2) in vec4 a_Color;
//layout(location = 2) in vec2 a_TexCoord;

//uniform mat4 u_ViewProjection;

out vec4 v_Color;
//out vec2 v_TexCoord;

void main() {
	//v_TexCoord = a_TexCoord;
	v_Color = a_Color;
	gl_Position = vec4(a_Position * a_Scale, 1.0f);
}