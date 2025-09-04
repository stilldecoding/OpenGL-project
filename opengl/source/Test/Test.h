#pragma once
#include"glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace test {
	class Test
	{
	public :
		Test() {}
		virtual ~Test() {}

		virtual void OnUpdate() {}
		virtual void OnRender() {}
		virtual void OnImageGuiRender(){}

	protected:
		const glm::mat4 proj = glm::ortho(0.0f, 640.0f, 0.0f, 360.0f, -1.0f, 1.0f);
	};
}
