#pragma once

#include "Component.h"
#include <glm/glm.hpp>

namespace Engine
{
	struct TransformComponent : Component
	{
		glm::mat4 Transform{ 1.0f };

		TransformComponent() = default;
		TransformComponent(const TransformComponent&) = default;
		TransformComponent(const glm::mat4& transform) :Transform(transform) {}

		operator glm::mat4& () { return Transform; }
		operator const glm::mat4& () const { return Transform; }

		virtual inline std::string GetTypeName() override { return "Transform"; }

		bool operator=(const TransformComponent& other)
		{
			return Transform == other.Transform;
		}
	};
}