#pragma once

#include <iostream>

#include "Engine.h"

using namespace Engine;

class Test : public Behavior
{
public:
	// 第一帧调用
	void virtual Start() override
	{
		std::cout << "Start" << std::endl;
	}

	// 渲染：每帧调用
	void virtual Render() override
	{
		std::cout << "Render" << std::endl;

		Renderer::DrawFillRectangle(300, 200, Vector3(255, 255, 0));
	}

	// 更新：每帧调用
	void virtual Update() override
	{
		// 处理输入
		if (Input::GetKey(KeyCode::Up)) {		// 按下向上方向键
			std::cout << "Up" << std::endl;
		}
		if (Input::GetKey(KeyCode::Down)) {		// 按下向下方向键
			std::cout << "Down" << std::endl;
		}
		if (Input::GetKey(KeyCode::Left)) {		// 按下向左方向键
			std::cout << "Left" << std::endl;
		}
		if (Input::GetKey(KeyCode::Right)) {	// 按下向右方向键
			std::cout << "Right" << std::endl;
		}
	}
};