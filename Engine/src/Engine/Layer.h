#pragma once

#include "Core.h"

#include <string>

namespace Engine
{
	/// <summary>
	/// 层
	/// </summary>
	class Layer
	{
	protected:
		std::string m_DebugName;	//Layer在Debug模式中的名字
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		/// <summary>
		/// 添加到层栈时调用
		/// </summary>
		virtual void OnAttach() {}

		/// <summary>
		/// 移除层栈时调用
		/// </summary>
		virtual void OnDetach() {}

		/// <summary>
		/// 该层更新时调用：每帧调用
		/// </summary>
		virtual void OnUpdate() {}

		inline const std::string& GetName() const { return m_DebugName; }
	};
}