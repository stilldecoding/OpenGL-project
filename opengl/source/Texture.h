#pragma once
#include"Renderer.h"


class Texture
{
private:
	unsigned int m_Renderer_ID;
	int height;
	int width;
	int m_BPP;
	std::string m_Filepath;
	unsigned char* LocalBuffer;

public:
	Texture(const std::string& FilePath);
	~Texture();

	void Bind(unsigned int slot) const;
	void UnBind() const;
};
