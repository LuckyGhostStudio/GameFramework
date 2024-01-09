#pragma once

#include "Engine.h"

using namespace Engine;

/// <summary>
/// 子弹
/// </summary>
class Projectile
{
private:
	Vector2 position;
	Vector2 size;
	Vector3 color;
	
	float damage = 1.0f;
	float moveSpeed = 400.0f;
public:
	Projectile(const Vector2& position, const Vector2& size = Vector2(4, 10), const Vector3& color = Vector3(255, 255, 255))
	{
		this->position = position;
		this->size = size;
		this->color = color;
	}

	void Render()
	{
		Renderer::DrawFillEllipse(position, size, color, color);
	}

	void Update()
	{
		position += Vector2(0, -moveSpeed * Time::deltaTime);	// 向上移动 -y
	}

	Vector2 GetPosition() { return position; }
};