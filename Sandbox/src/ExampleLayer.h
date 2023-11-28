#pragma once

#include "Engine.h"

using namespace Engine;

/// <summary>
/// ʾ����
/// </summary>
class ExampleLayer : public Layer
{
private:
	Camera m_Camera;	// ���
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 1.0f;
	
	//std::shared_ptr<Scene> m_ActiveScene;	// �����
	//Entity m_Square;						// ������
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	/// <summary>
	/// ���ò���ӵ���ջʱ����
	/// </summary>
	virtual void OnAttach() override;

	/// <summary>
	/// ���ò�Ӳ�ջ�Ƴ�ʱ����
	/// </summary>
	virtual void OnDetach() override;

	virtual void OnUpdate() override;
};