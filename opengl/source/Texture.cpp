#include "Texture.h"
#include "stb_image.h"


Texture::Texture(const std::string& FilePath) :
	m_Renderer_ID(0),height(0),width(0),m_BPP(0),m_Filepath(FilePath)
{
	stbi_set_flip_vertically_on_load(1);
	LocalBuffer =  stbi_load(m_Filepath.c_str(), &width, &height, &m_BPP, 4);

	glGenTextures(1, &m_Renderer_ID);
	glBindTexture(GL_TEXTURE_2D, m_Renderer_ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, LocalBuffer);

	glBindTexture(GL_TEXTURE_2D, 0);
	std::cout << m_BPP;

	if (LocalBuffer)
		stbi_image_free(LocalBuffer);
}

Texture::~Texture()
{
}



void Texture::Bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_Renderer_ID);
}


void Texture::UnBind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
