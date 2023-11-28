#include <Engine.h>
#include <Engine/EntryPoint.h>

#include "ExampleLayer.h"

class Sandbox : public Engine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());	// 添加示例层
	}
	
	~Sandbox()
	{

	}
};

Engine::Application* Engine::CreateApplication()
{
	return new Sandbox();
}