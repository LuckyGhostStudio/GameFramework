#pragma once

#include "Projectile.h"

#include <iostream>

#include "Engine.h"

using namespace Engine;

class Player : public Behavior
{
private:
	Vector2 screenSize;

	Vector2 position;
	Vector2 muzzlePos;

	Vector2 vertices[3];
	float radius = 11.0f;

	float moveSpeed = 200.0f;
	float reloadTime = 0.15f;
	float lastAttackTime = -10.0f;

	std::vector<Projectile> projectiles;

	float horizontalInputValue;
	float verticalInputValue;
	bool attackInputValue;
public:
	void virtual Start() override
	{
		screenSize = Vector2(Application::GetInstance()->GetWidth(), Application::GetInstance()->GetHeight());
		position = screenSize / 2;
		muzzlePos = Vector2(position.x, position.y - radius * 2.0f);

		vertices[0] = Vector2(position.x, position.y - radius);
		vertices[1] = Vector2(position.x + sqrt(3) * 0.5f * radius, position.y + radius * 0.5f);
		vertices[2] = Vector2(position.x - sqrt(3) * 0.5f * radius, position.y + radius * 0.5f);
	}

	void virtual Render() override
	{
		// Render Player
		Renderer::DrawTriangle(vertices, Vector3(255, 255, 255), 4);

		// Render Projectiles
		for (int i = 0; i < projectiles.size(); i++) {
			projectiles[i].Render();
		}
	}

	void virtual Update() override
	{
		// 更新 Player Vertices
		vertices[0].x = position.x;
		vertices[0].y = position.y - radius;
		vertices[1].x = position.x + sqrt(3) * 0.5f * radius;
		vertices[2].y = position.y + radius * 0.5f;
		vertices[2].x = position.x - sqrt(3) * 0.5f * radius;
		vertices[1].y = position.y + radius * 0.5f;
		
		// 更新 Muzzle Position
		muzzlePos.x = position.x;
		muzzlePos.y = position.y - radius * 2.0f;

		std::cout << "position: " << position << std::endl;
		std::cout << "muzzle pos: " << muzzlePos << std::endl;

		// 更新 Projectiles
		for (int i = 0; i < projectiles.size(); i++) {
			projectiles[i].Update();
		}

		// Projectiles碰撞边界 从列表移除
		for (int i = 0; i < projectiles.size(); i++) {
			Vector2 position = projectiles[i].GetPosition();
			if (position.x < 0 || position.x > screenSize.x || position.y < 0 || position.y > screenSize.y) {
				projectiles.erase(projectiles.begin() + i);
			}
		}

		GetInput();

		Move();

		if (Time::time >= reloadTime + lastAttackTime) {
			Attack();
			lastAttackTime = Time::time;	// 更新上次攻击时间
		}
	}

	void GetInput()
	{
		horizontalInputValue = Input::GetAxis("Horizontal");	// 水平输入
		verticalInputValue = Input::GetAxis("Vertical");		// 垂直输入
		attackInputValue = Input::GetKey(KeyCode::Space);		// 攻击输入
	}

	void Move()
	{
		position = Vector2::Clamp(position, 0, screenSize);		// 限制移动范围

		position += Vector2(horizontalInputValue * moveSpeed * Time::deltaTime, verticalInputValue * -moveSpeed * Time::deltaTime);	// 移动
		
		// TODO: 对角线移动速度快bug
	}

	void Attack()
	{
		if (attackInputValue) {
			projectiles.push_back(Projectile(muzzlePos));	// 创建 Projectile 添加到列表
		}
	}
};