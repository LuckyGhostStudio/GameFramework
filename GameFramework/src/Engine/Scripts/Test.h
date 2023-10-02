#pragma once

#include <iostream>

#include "Engine.h"

using namespace Engine;

class Test : public Behavior
{
public:
	// ��һ֡����
	void virtual Start() override
	{
		std::cout << "Start" << std::endl;
	}

	// ��Ⱦ��ÿ֡����
	void virtual Render() override
	{
		std::cout << "Render" << std::endl;

		Renderer::DrawFillRectangle(300, 200, Vector3(255, 255, 0));
	}

	// ���£�ÿ֡����
	void virtual Update() override
	{
		// ��������
		if (Input::GetKey(KeyCode::Up)) {		// �������Ϸ����
			std::cout << "Up" << std::endl;
		}
		if (Input::GetKey(KeyCode::Down)) {		// �������·����
			std::cout << "Down" << std::endl;
		}
		if (Input::GetKey(KeyCode::Left)) {		// �����������
			std::cout << "Left" << std::endl;
		}
		if (Input::GetKey(KeyCode::Right)) {	// �������ҷ����
			std::cout << "Right" << std::endl;
		}
	}
};