#pragma once

#include <string>

namespace Engine
{
	struct Component
	{
		virtual std::string GetTypeName() = 0;
	};
}