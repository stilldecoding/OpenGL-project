#shader vertex
#version 460 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 i_color;

out vec3 o_color;

uniform mat4 m_MVP;
float time;

void main()
{
	
	o_color = i_color;
	gl_Position =  m_MVP * vec4(position,1.0f) ;
}

#shader fragment
#version 460 core

layout(location = 0) out vec4 color;

in vec3 o_color;

uniform vec4 u_Color;

void main()
{
	color = vec4(o_color,1.0f);
}