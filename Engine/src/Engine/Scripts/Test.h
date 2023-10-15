#pragma once

//#include "Engine/Input/Input.h"
//#include "Engine/Renderer/Renderer.h"
#include "Engine/Behavior.h"

using namespace Engine;

class Test : public Behavior
{
public:
	// 第一帧调用
	void virtual Start() override
	{
		
	}

	// 渲染：每帧调用
	void virtual Render() override
	{
		//Renderer::DrawFillRectangle(300, 200, Vector3(255, 255, 0));
	}

	// 更新：每帧调用
	void virtual Update() override
	{

	}
};