#include "Application.h"

#include <chrono>
#include <iostream>

#include "Renderer/Renderer.h"
#include "Input/Input.h"
#include "Time.h"

#include "Scripts/Test.h"

namespace Engine
{
	Application::Application()
	{
		Renderer::Initialize(m_Width, m_Height);	// 初始化渲染器

		Initialize();

		// 处理所有Behavior的Start方法
		for (auto it = m_Behaviors.begin(); it != m_Behaviors.end(); it++) {
			(*it)->Start();
		}
	}

	Application::~Application()
	{
		m_Running = false;

		Renderer::ShutDown();	// 关闭渲染器
	}
	
	void Application::Initialize()
	{
		m_Behaviors.push_back(new Test());
	}
	
	void Application::Update()
	{
		Renderer::SetClearColor(Vector3(0, 0, 0));	// 设置背景颜色
		Renderer::Clear();							// 清屏

		// 处理所有Behavior的Render方法
		for (auto it = m_Behaviors.begin(); it != m_Behaviors.end(); it++) {
			(*it)->Render();
		}

		Renderer::FlushBatch();		// 渲染未完成的图形

		// 处理所有Behavior的Render方法
		for (auto it = m_Behaviors.begin(); it != m_Behaviors.end(); it++) {
			(*it)->Update();
		}
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

			Update();	// 逻辑更新
		}
	}
}