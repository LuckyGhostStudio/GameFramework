#pragma once

#include "Core.h"

#include <string>

namespace Engine
{
	/// <summary>
	/// ��
	/// </summary>
	class Layer
	{
	protected:
		std::string m_DebugName;	//Layer��Debugģʽ�е�����
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		/// <summary>
		/// ��ӵ���ջʱ����
		/// </summary>
		virtual void OnAttach() {}

		/// <summary>
		/// �Ƴ���ջʱ����
		/// </summary>
		virtual void OnDetach() {}

		/// <summary>
		/// �ò����ʱ���ã�ÿ֡����
		/// </summary>
		virtual void OnUpdate() {}

		inline const std::string& GetName() const { return m_DebugName; }
	};
}