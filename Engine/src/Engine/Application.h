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
		static Application* s_Instance;		// ʵ��
		std::unique_ptr<Window> m_Window;	// ����

		float m_FramePerSecond = 0.0f;		// ֡��

		bool m_Running = true;

		std::vector<Layer*> m_Layers;		// ���б�
	public:
		Application();
		virtual ~Application();

		/// <summary>
		/// ��Ӳ㵽���б�
		/// </summary>
		/// <param name="layer"></param>
		void PushLayer(Layer* layer);

		/// <summary>
		/// ����
		/// </summary>
		void Run();
	private:
		/// <summary>
		/// ����Application��ʵ��
		/// </summary>
		/// <returns>ʵ��</returns>
		inline static Application& GetInstance() { return *s_Instance; }

		/// <summary>
		/// ����Application�Ĵ���
		/// </summary>
		/// <returns></returns>
		inline Window& GetWindow() { return *m_Window; }
	};

	Application* CreateApplication();
}