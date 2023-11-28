#pragma once

#include "Behavior.h"

#include <vector>

namespace Engine
{
	class Application
	{
	private:
		static Application* s_Instance;

		float m_Width = 640.0f;
		float m_Height = 640.0f;

		float m_FramePerSecond = 0.0f;	// 帧率

		bool m_Running = true;

		std::vector<Behavior*> m_Behaviors;
	public:
		Application();
		~Application();

		inline float GetWidth() const { return m_Width; }
		inline float GetHeight() const { return m_Height; }

		static Application* GetInstance() { return s_Instance; }

		/// <summary>
		/// 运行
		/// </summary>
		void Run();
	private:
		/// <summary>
		/// 初始化
		/// </summary>
		void Initialize();

		/// <summary>
		/// 更新：每帧
		/// </summary>
		void Update();
	};
}