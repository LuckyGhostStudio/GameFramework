#pragma once

#include "Core.h"

#include "Window.h"
#include "Layer.h"

#include <memory>
#include <vector>

namespace Engine
{
	class Application
	{
	private:
		static Application* s_Instance;		// 实例
		std::unique_ptr<Window> m_Window;	// 窗口

		float m_FramePerSecond = 0.0f;		// 帧率

		bool m_Running = true;

		std::vector<Layer*> m_Layers;		// 层列表
	public:
		Application();
		virtual ~Application();

		/// <summary>
		/// 添加层到层列表
		/// </summary>
		/// <param name="layer"></param>
		void PushLayer(Layer* layer);

		/// <summary>
		/// 运行
		/// </summary>
		void Run();
	private:
		/// <summary>
		/// 返回Application的实例
		/// </summary>
		/// <returns>实例</returns>
		inline static Application& GetInstance() { return *s_Instance; }

		/// <summary>
		/// 返回Application的窗口
		/// </summary>
		/// <returns></returns>
		inline Window& GetWindow() { return *m_Window; }
	};

	Application* CreateApplication();
}