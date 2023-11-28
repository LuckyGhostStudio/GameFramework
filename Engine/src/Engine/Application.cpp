#include "Application.h"
#include <chrono>

#include "Engine/Renderer/Renderer.h"
#include "Log.h"
#include "Time.h"

namespace Engine
{
	Application* Application::s_Instance = nullptr;	// ����

	Application::Application()
	{
		CORE_ASSERT(!s_Instance, "Application already exisit!");	//Application�Ѵ���
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());	// ��������

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
		std::chrono::time_point<std::chrono::steady_clock> lastFrameTime;	// ��һ֡ʱ���

		auto start = std::chrono::high_resolution_clock().now();			// ��ʼ����ʱ��

		while (m_Running) {
			std::chrono::duration<float> tempTime = std::chrono::high_resolution_clock().now() - start;

			auto time = std::chrono::high_resolution_clock().now();			// ��ǰʱ���
			std::chrono::duration<float> deltaTime = time - lastFrameTime;	// ֡��� = ��ǰʱ��� - ��һ֡ʱ���
			lastFrameTime = time;											// ������һ֡ʱ���

			Time::time = tempTime.count();			// ��ǰʱ�䣨�ӳ������п�ʼ���㣩
			Time::deltaTime = deltaTime.count();	// ��ǰ֡���(s)

			m_FramePerSecond = 1.0f / Time::deltaTime;	// ��ǰ֡��

			//���²�ջ�����в�
			for (Layer* layer : m_Layers) {
				layer->OnUpdate();
			}
		}
	}
}