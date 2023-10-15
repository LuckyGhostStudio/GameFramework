#include <Engine.h>

/// <summary>
/// 示例层
/// </summary>
class ExampleLayer : public Engine::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		EG_TRACE("ExampleLayer::OnUpdate");
	}
};

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