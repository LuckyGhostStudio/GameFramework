#include "Application.h"
#include <chrono>

#include "Engine/Renderer/Renderer.h"
#include "Log.h"
#include "Time.h"

namespace Engine
{
	Application* Application::s_Instance = nullptr;	// 单例

	Application::Application()
	{
		CORE_ASSERT(!s_Instance, "Application already exisit!");	//Application已存在
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());	// 创建窗口

		Renderer::Init();
	}

	Application::~Application()
	{
		m_Running = false;

		Renderer::ShutDown();
	}

	void Application::PushLayer(Layer* layer)
	{
		m_Layers.push_back(layer);
		layer->OnAttach();
	}

	void Application::Run()
	{
		std::chrono::time_point<std::chrono::steady_clock> lastFrameTime;	// 上一帧时间点

		auto start = std::chrono::high_resolution_clock().now();			// 开始运行时间

		while (m_Running) {
			std::chrono::duration<float> tempTime = std::chrono::high_resolution_clock().now() - start;

			auto time = std::chrono::high_resolution_clock().now();			// 当前时间点
			std::chrono::duration<float> deltaTime = time - lastFrameTime;	// 帧间隔 = 当前时间点 - 上一帧时间点
			lastFrameTime = time;											// 更新上一帧时间点

			Time::time = tempTime.count();			// 当前时间（从程序运行开始计算）
			Time::deltaTime = deltaTime.count();	// 当前帧间隔(s)

			m_FramePerSecond = 1.0f / Time::deltaTime;	// 当前帧率

			//更新层栈中所有层
			for (Layer* layer : m_Layers) {
				layer->OnUpdate();
			}
		}
	}
}