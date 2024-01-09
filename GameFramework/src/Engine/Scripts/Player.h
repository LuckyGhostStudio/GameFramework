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
		// ���� Player Vertices
		vertices[0].x = position.x;
		vertices[0].y = position.y - radius;
		vertices[1].x = position.x + sqrt(3) * 0.5f * radius;
		vertices[2].y = position.y + radius * 0.5f;
		vertices[2].x = position.x - sqrt(3) * 0.5f * radius;
		vertices[1].y = position.y + radius * 0.5f;
		
		// ���� Muzzle Position
		muzzlePos.x = position.x;
		muzzlePos.y = position.y - radius * 2.0f;

		std::cout << "position: " << position << std::endl;
		std::cout << "muzzle pos: " << muzzlePos << std::endl;

		// ���� Projectiles
		for (int i = 0; i < projectiles.size(); i++) {
			projectiles[i].Update();
		}

		// Projectiles��ײ�߽� ���б��Ƴ�
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
			lastAttackTime = Time::time;	// �����ϴι���ʱ��
		}
	}

	void GetInput()
	{
		horizontalInputValue = Input::GetAxis("Horizontal");	// ˮƽ����
		verticalInputValue = Input::GetAxis("Vertical");		// ��ֱ����
		attackInputValue = Input::GetKey(KeyCode::Space);		// ��������
	}

	void Move()
	{
		position = Vector2::Clamp(position, 0, screenSize);		// �����ƶ���Χ

		position += Vector2(horizontalInputValue * moveSpeed * Time::deltaTime, verticalInputValue * -moveSpeed * Time::deltaTime);	// �ƶ�
		
		// TODO: �Խ����ƶ��ٶȿ�bug
	}

	void Attack()
	{
		if (attackInputValue) {
			projectiles.push_back(Projectile(muzzlePos));	// ���� Projectile ��ӵ��б�
		}
	}
};