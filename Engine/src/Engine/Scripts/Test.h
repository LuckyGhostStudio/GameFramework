#pragma once

//#include "Engine/Input/Input.h"
//#include "Engine/Renderer/Renderer.h"
#include "Engine/Behavior.h"

using namespace Engine;

class Test : public Behavior
{
public:
	// ��һ֡����
	void virtual Start() override
	{
		
	}

	// ��Ⱦ��ÿ֡����
	void virtual Render() override
	{
		//Renderer::DrawFillRectangle(300, 200, Vector3(255, 255, 0));
	}

	// ���£�ÿ֡����
	void virtual Update() override
	{

	}
};