#pragma once

#include <iostream>

#include "Engine.h"

using namespace Engine;

class Player : public Behavior
{
private:
	Vector2 position;
	float radius = 11.0f;
	float moveSpeed = 200.0f;
public:
	void virtual Start() override
	{
		position = Vector2(Application::GetInstance()->GetWidth() / 2, Application::GetInstance()->GetHeight() / 2);
		std::cout << position << std::endl;
	}

	void virtual Render() override
	{
		Renderer::DrawCircle(position, radius, Vector3(255, 255, 255), 4);
	}

	void virtual Update() override
	{
		std::cout << "position: " << position << std::endl;

		if (Input::GetKey(KeyCode::Up) || Input::GetKey(KeyCode::W)) {
			position += Vector2(0.0f, -moveSpeed * Time::deltaTime);
		}
		if (Input::GetKey(KeyCode::Down) || Input::GetKey(KeyCode::S)) {
			position += Vector2(0.0f, moveSpeed * Time::deltaTime);
		}
		if (Input::GetKey(KeyCode::Left) || Input::GetKey(KeyCode::A)) {
			position += Vector2(-moveSpeed * Time::deltaTime, 0.0f);
		}
		if (Input::GetKey(KeyCode::Right) || Input::GetKey(KeyCode::D)) {
			position += Vector2(moveSpeed * Time::deltaTime, 0.0f);
		}
	}
};