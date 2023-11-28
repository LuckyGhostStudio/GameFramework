#pragma once

#include "Component.h"

namespace Engine
{
	struct TagComponent : Component
	{
		std::string Tag;

		TagComponent() = default;
		TagComponent(const TagComponent&) = default;
		TagComponent(const std::string& tag) :Tag(tag) {}

		virtual inline std::string GetTypeName() override { return "Tag"; }

		bool operator=(const TagComponent& other)
		{
			return Tag == other.Tag;
		}
	};
}