#pragma once
#include"Test.h"


namespace test {
	class ClearColor : public Test
	{
	public:
		ClearColor();
		~ClearColor();

		void OnRender() override;
		void OnUpdate() override;

		void OnImageGuiRender() override;

	private:
		float clear_color[4];
	};
}
