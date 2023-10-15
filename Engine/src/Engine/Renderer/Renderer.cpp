#include "Renderer.h"

#include <graphics.h>

namespace Engine
{
	void Renderer::BeginScene()
	{
		RenderCommand::BeginBatch();	// 开始批量绘制
	}

	void Renderer::ShutDown()
	{
		
	}

	void Renderer::EndScene()
	{
		RenderCommand::FlushBatch();	// 执行未完成的绘图任务
		RenderCommand::EndBatch();		// 结束批量绘制
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