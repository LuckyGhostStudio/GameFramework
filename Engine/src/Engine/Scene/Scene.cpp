#include "Scene.h"

#include "Engine/Renderer/Renderer.h"

#include "Entity.h"

#include "TagComponent.h"
#include "TransformComponent.h"

namespace Engine
{


	Scene::Scene()
	{

	}

	Scene::~Scene()
	{

	}

	Entity Scene::CreateEntity(const std::string& name)
	{
		Entity entity = { m_Registry.create(), this };		// 创建实体到注册表

		entity.AddComponent<TagComponent>(name);	// 添加Tag组件（默认组件）
		entity.AddComponent<TransformComponent>();	// 添加Transform组件（默认组件）

		CORE_TRACE("Entity: {0}", entity);

		return entity;
	}

	void Scene::OnUpdate()
	{
		//auto group = m_Registry.group<TransformComponent>(entt::get<SpriteRendererComponent>);
		//
		//for (auto entity : group) {
		//	auto& [transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(entity);
		//
		//	//Engine::Renderer::DrawFillRectangle({ 300, 300, 0 }, { 320, 180, 0 }, { 0.2f, 0.8f, 0.6f, 1.0f });
		//	
		//}
	}
}