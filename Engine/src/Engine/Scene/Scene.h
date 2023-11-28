#pragma once

#include "entt.hpp"
#include <string>

namespace Engine
{
	class Entity;

	/// <summary>
	/// 场景
	/// </summary>
	class Scene
	{
	private:
		friend class Entity;		// 友元类Entity
		entt::registry m_Registry;	// 实体注册表：实体id集合（unsigned int集合）
	public:
		Scene();
		~Scene();

		/// <summary>
		/// 创建实体
		/// </summary>
		/// <param name="name">实体名</param>
		/// <returns>实体</returns>
		Entity CreateEntity(const std::string& name = "Entity");

		/// <summary>
		/// 更新：每帧调用
		/// </summary>
		void OnUpdate();
	};
}