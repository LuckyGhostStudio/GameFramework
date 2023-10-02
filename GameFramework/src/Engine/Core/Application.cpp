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
		Renderer::Initialize(m_Width, m_Height);	// ��ʼ����Ⱦ��

		Initialize();

		// ��������Behavior��Start����
		for (auto it = m_Behaviors.begin(); it != m_Behaviors.end(); it++) {
			(*it)->Start();
		}
	}

	Application::~Application()
	{
		m_Running = false;

		Renderer::ShutDown();	// �ر���Ⱦ��
	}
	
	void Application::Initialize()
	{
		m_Behaviors.push_back(new Test());
	}
	
	void Application::Update()
	{
		Renderer::SetClearColor(Vector3(0, 0, 0));	// ���ñ�����ɫ
		Renderer::Clear();							// ����

		// ��������Behavior��Render����
		for (auto it = m_Behaviors.begin(); it != m_Behaviors.end(); it++) {
			(*it)->Render();
		}

		Renderer::FlushBatch();		// ��Ⱦδ��ɵ�ͼ��

		// ��������Behavior��Render����
		for (auto it = m_Behaviors.begin(); it != m_Behaviors.end(); it++) {
			(*it)->Update();
		}
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

			Update();	// �߼�����
		}
	}
}