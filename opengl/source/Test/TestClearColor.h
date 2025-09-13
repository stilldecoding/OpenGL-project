#pragma once
#include"Test.h"


namespace test {
	class ClearColor : public Test
	{
	public:
		ClearColor();
		~ClearColor();

		void OnRender(float DeltaTime) override;
		void OnUpdate() override;

		void OnImageGuiRender(std::string string) override;

	private:
		float clear_color[4];
	};
}
