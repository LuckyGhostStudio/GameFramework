#include "ExampleLayer.h"

ExampleLayer::ExampleLayer() : Layer("Example"), m_Camera(-640, 640, -360, 360), m_CameraPosition(0.0f)
{

}

void ExampleLayer::OnAttach()
{
	//m_Square = m_ActiveScene->CreateEntity("Square");	//����������ʵ��

	//m_Square.AddComponent<SpriteRendererComponent>(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));	//���SpriteRenderer���
}

void ExampleLayer::OnDetach()
{

}

void ExampleLayer::OnUpdate()
{
	if (Input::GetKey(KeyCode::Left)) {			//���
		m_CameraPosition.x -= m_CameraMoveSpeed;
	}
	else if (Input::GetKey(KeyCode::Right)) {	//�Ҽ�
		m_CameraPosition.x += m_CameraMoveSpeed;
	}
	if (Input::GetKey(KeyCode::Up)) {			//�ϼ�
		m_CameraPosition.y += m_CameraMoveSpeed;
	}
	else if (Input::GetKey(KeyCode::Down)) {	//�¼�
		m_CameraPosition.y -= m_CameraMoveSpeed;
	}

	Renderer::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });	// ���ñ�����ɫ
	Renderer::Clear();										// ����

	m_Camera.SetPosition(m_CameraPosition);		//�������λ��

	Renderer::BeginScene(m_Camera);	// TODO: to scene
	//m_ActiveScene->OnUpdate();	//���³���
	Renderer::EndScene();
}