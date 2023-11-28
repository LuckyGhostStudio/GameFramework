#pragma once

#include "Scene.h"

#include "entt.hpp"
#include "Engine/Log.h"

namespace Engine
{
	class Entity
	{
	private:
		entt::entity m_EntityHandle{ 0 };	// ʵ��ID
		Scene* m_Scene = nullptr;			// ʵ����������
	public:
		Entity() {}
		Entity(entt::entity handle, Scene* scene);
		Entity(const Entity& other) = default;

		/// <summary>
		/// ���T�������
		/// </summary>
		/// <typeparam name="T">�������</typeparam>
		/// <typeparam name="...Args">�����������</typeparam>
		/// <param name="...args">�������</param>
		/// <returns>���</returns>
		template<typename T, typename... Args>
		T& AddComponent(Args&&... args)
		{
			CORE_ASSERT(!HasComponent<T>(), "Entity already has component!");	// ������Ѵ���

			return m_Scene->m_Registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)...);	// ��m_Scene������ʵ��ע������T�������
		}

		/// <summary>
		/// ����T�������
		/// </summary>
		/// <typeparam name="T">�������</typeparam>
		/// <returns>���</returns>
		template<typename T>
		T& GetComponent()
		{
			CORE_ASSERT(HasComponent<T>(), "Entity dose not have component!");	//�����������
		
			return m_Scene->m_Registry.get<T>(m_EntityHandle);	// ��m_Scene������ʵ��ע�����T�������
		}
		
		/// <summary>
		/// ��ѯ�Ƿ�ӵ��T�������
		/// </summary>
		/// <typeparam name="T">�������</typeparam>
		/// <returns>��ѯ���</returns>
		template<typename T>
		bool HasComponent()
		{
			return m_Scene->m_Registry.has<T>(m_EntityHandle);	// ����m_Scene������m_EntityHandle��T�������
		}

		/// <summary>
		/// �Ƴ�T�������
		/// </summary>
		/// <typeparam name="T">�������</typeparam>
		template<typename T>
		void RemoveComponent()
		{
			CORE_ASSERT(HasComponent<T>(), "Entity dose not have component!");	//�����������
		
			m_Scene->m_Registry.remove<T>(m_EntityHandle);	// �Ƴ�m_Scene������m_EntityHandle��T�������
		}

		//operator uint32_t() const { return m_EntityHandle; }
		//operator bool() const { return m_EntityID != 0; }
		bool operator=(const Entity& entity) { return m_EntityHandle == entity.m_EntityHandle; }
	};
}