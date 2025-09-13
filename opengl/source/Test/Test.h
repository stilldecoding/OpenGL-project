#pragma once
#include"glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include"Imgui/imgui.h"
#include<string>

namespace test {
	class Test
	{
	public :
		Test() {}
		virtual ~Test() {}

		virtual void OnUpdate() {}
		virtual void OnRender(float DeltaTIme) {}
		virtual void OnImageGuiRender(std::string string){}

	protected:
		const glm::mat4 proj = glm::ortho(0.0f, 1600.0f, 0.0f, 900.0f, -1.0f, 1.0f);

		static const int width = 1600;
		static const int height = 900;
	};
}
