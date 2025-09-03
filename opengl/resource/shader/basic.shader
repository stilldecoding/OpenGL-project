#shader vertex
#version 460 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 text_coord;

out vec2 v_Texture_Coord;

uniform mat4 m_MVP;

void main()
{
	v_Texture_Coord =  text_coord;
	gl_Position = m_MVP * position ;
}

#shader fragment
#version 460 core

layout(location = 0) out vec4 color;

in vec2 v_Texture_Coord;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
	vec4 texColor = texture(u_Texture,v_Texture_Coord);
	color = u_Color;
}