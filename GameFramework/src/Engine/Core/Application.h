#pragma once

#include "Behavior.h"

#include <vector>

namespace Engine
{
	class Application
	{
	private:
		float m_Width = 1080.0f;
		float m_Height = 640.0f;

		float m_FramePerSecond = 0.0f;	// ֡��

		bool m_Running = true;

		std::vector<Behavior*> m_Behaviors;
	public:
		Application();
		~Application();

		/// <summary>
		/// ����
		/// </summary>
		void Run();
	private:
		/// <summary>
		/// ��ʼ��
		/// </summary>
		void Initialize();

		/// <summary>
		/// ���£�ÿ֡
		/// </summary>
		void Update();
	};
}