#pragma once

#include "Engine.h"

using namespace Engine;

/// <summary>
/// 示例层
/// </summary>
class ExampleLayer : public Layer
{
private:
	Camera m_Camera;	// 相机
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 1.0f;
	
	//std::shared_ptr<Scene> m_ActiveScene;	// 活动场景
	//Entity m_Square;						// 正方形
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	/// <summary>
	/// 将该层添加到层栈时调用
	/// </summary>
	virtual void OnAttach() override;

	/// <summary>
	/// 将该层从层栈移除时调用
	/// </summary>
	virtual void OnDetach() override;

	virtual void OnUpdate() override;
};