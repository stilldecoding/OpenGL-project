#shader vertex
#version 460 core

layout(location = 0) in vec3 position;


uniform mat4 m_MVP;



void main()
{

	gl_Position =  m_MVP * vec4(position,1.0f) ;
}

#shader fragment
#version 460 core

layout(location = 0) out vec4 color;


uniform vec4 u_Color;

void main()
{
	color = u_Color;
}