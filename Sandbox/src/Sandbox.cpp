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
		Engine::Renderer::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });	// 设置背景颜色
		Engine::Renderer::Clear();										// 清屏

		Engine::Renderer::BeginScene();

		Engine::Renderer::DrawFillRectangle({ 400, 400, 0 }, { 100, 100, 0 }, { 0.2f, 0.8f, 0.6f, 1.0f });

		Engine::Renderer::EndScene();
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