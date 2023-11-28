#include "ExampleLayer.h"

ExampleLayer::ExampleLayer() : Layer("Example"), m_Camera(-640, 640, -360, 360), m_CameraPosition(0.0f)
{

}

void ExampleLayer::OnAttach()
{
	//m_Square = m_ActiveScene->CreateEntity("Square");	//创建正方形实体

	//m_Square.AddComponent<SpriteRendererComponent>(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));	//添加SpriteRenderer组件
}

void ExampleLayer::OnDetach()
{

}

void ExampleLayer::OnUpdate()
{
	if (Input::GetKey(KeyCode::Left)) {			//左键
		m_CameraPosition.x -= m_CameraMoveSpeed;
	}
	else if (Input::GetKey(KeyCode::Right)) {	//右键
		m_CameraPosition.x += m_CameraMoveSpeed;
	}
	if (Input::GetKey(KeyCode::Up)) {			//上键
		m_CameraPosition.y += m_CameraMoveSpeed;
	}
	else if (Input::GetKey(KeyCode::Down)) {	//下键
		m_CameraPosition.y -= m_CameraMoveSpeed;
	}

	Renderer::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });	// 设置背景颜色
	Renderer::Clear();										// 清屏

	m_Camera.SetPosition(m_CameraPosition);		//设置相机位置

	Renderer::BeginScene(m_Camera);	// TODO: to scene
	//m_ActiveScene->OnUpdate();	//更新场景
	Renderer::EndScene();
}