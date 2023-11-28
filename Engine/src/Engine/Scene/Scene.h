#pragma once

#include "entt.hpp"
#include <string>

namespace Engine
{
	class Entity;

	/// <summary>
	/// ����
	/// </summary>
	class Scene
	{
	private:
		friend class Entity;		// ��Ԫ��Entity
		entt::registry m_Registry;	// ʵ��ע���ʵ��id���ϣ�unsigned int���ϣ�
	public:
		Scene();
		~Scene();

		/// <summary>
		/// ����ʵ��
		/// </summary>
		/// <param name="name">ʵ����</param>
		/// <returns>ʵ��</returns>
		Entity CreateEntity(const std::string& name = "Entity");

		/// <summary>
		/// ���£�ÿ֡����
		/// </summary>
		void OnUpdate();
	};
}