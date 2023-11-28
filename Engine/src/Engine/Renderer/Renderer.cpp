#include "Renderer.h"

#include <graphics.h>
#include "Engine/Log.h"
#include "Shader.h"

namespace Engine
{
	Renderer::SceneData* Renderer::m_SceneData = new Renderer::SceneData();		//��������

	// TODO: �������ж��㣬�������ж��㣬���д���ģ�ⶥ����ɫ��
	// TODO: �������ν��й�դ����ģ��ƬԪ��ɫ������������ƬԴ

	void Renderer::Init()
	{
		RenderCommand::BeginBatch();	// ��ʼ��������
	}

	void Renderer::BeginScene(Camera& camera)
	{
		m_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::ShutDown()
	{
		RenderCommand::EndBatch();		// ������������
	}

	void Renderer::EndScene()
	{
		RenderCommand::FlushBatch();	// ִ��δ��ɵĻ�ͼ����
	}

	void Renderer::SetClearColor(const glm::vec4& color)
	{
		RenderCommand::SetClearColor(color);
	}

	void Renderer::Clear()
	{
		cleardevice();
	}

	void Renderer::DrawFillRectangle(const glm::vec3& position, const glm::vec3& size, const glm::vec4& color)
	{
		Vertex vertices[4] =
		{
			{ { position.x - size.x / 2.0f, position.y + size.y / 2.0f, position.z, 1.0f}, color },	// ����
			{ { position.x - size.x / 2.0f, position.y - size.y / 2.0f, position.z, 1.0f}, color },	// ����
			{ { position.x + size.x / 2.0f, position.y - size.y / 2.0f, position.z, 1.0f}, color },	// ����
			{ { position.x + size.x / 2.0f, position.y + size.y / 2.0f, position.z, 1.0f}, color }	// ����
		};

		for (int i = 0; i < 4; i++) {
			vertices[i].position = RenderCommand::GetViewPortMatrix(1080, 720) * Shader::VertexHandle(m_SceneData->ViewProjectionMatrix, vertices[i]).position;
		}

		//CORE_TRACE("v0.x: {0}, v0.y: {1}, v0.z: {2}, v0.w: {3}", vertices[0].x, vertices[0].y, vertices[0].z, vertices[0].w);	 // ����
		//CORE_TRACE("v1.x: {0}, v1.y: {1}, v1.z: {2}, v1.w: {3}", vertices[1].x, vertices[1].y, vertices[1].z, vertices[1].w);	 // ����
		//CORE_TRACE("v2.x: {0}, v2.y: {1}, v2.z: {2}, v2.w: {3}", vertices[2].x, vertices[2].y, vertices[2].z, vertices[2].w);	 // ����
		//CORE_TRACE("v3.x: {0}, v3.y: {1}, v3.z: {2}, v3.w: {3}", vertices[3].x, vertices[3].y, vertices[3].z, vertices[3].w);	 // ����

		glm::vec4 positions[] =
		{
			vertices[0].position,
			vertices[1].position,
			vertices[2].position,
			vertices[3].position
		};

		uint32_t indices[] = 
		{
			0, 1, 2,
			0, 2, 3
		};
		RenderCommand::DrawIndexed(vertices, indices, 6);
	}
}