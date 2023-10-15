#include "Renderer.h"

#include <graphics.h>

namespace Engine
{
	void Renderer::BeginScene()
	{
		RenderCommand::BeginBatch();	// ��ʼ��������
	}

	void Renderer::ShutDown()
	{
		
	}

	void Renderer::EndScene()
	{
		RenderCommand::FlushBatch();	// ִ��δ��ɵĻ�ͼ����
		RenderCommand::EndBatch();		// ������������
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
		RenderCommand::DrawFillRectangle(position, size, color, color);
	}
}