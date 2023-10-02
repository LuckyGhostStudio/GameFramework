#include "Renderer.h"

#include <graphics.h>

namespace Engine
{
	Vector3 Renderer::m_LineColor = Vector3::Vector3(255, 255, 255);
	Vector3 Renderer::m_FillColor = Vector3::Vector3(255, 255, 255);
	Vector3 Renderer::m_ClearColor = Vector3::Vector3(255, 255, 255);

	void Renderer::Initialize(float width, float height, int flag)
	{
		initgraph((int)width, (int)height, flag);	// 初始化绘图窗口

		BeginBatchDraw();							// 开始批量绘制：绘图操作暂存在缓冲区
	}

	void Renderer::ShutDown()
	{
		EndBatchDraw();		// 结束批量绘制：执行未完成的绘制任务
		closegraph();		// 关闭绘图窗口
	}

	void Renderer::FlushBatch()
	{
		FlushBatchDraw();	// 执行未完成的绘图任务：执行缓冲区的绘图操作
	}

	void Renderer::SetClearColor(Vector3 color)
	{
		m_ClearColor = color;
		setbkcolor(RGB(color.x, color.y, color.z));
	}

	void Renderer::Clear()
	{
		cleardevice();
	}

	void Renderer::DrawRectangle(Vector2 position, Vector2 size, Vector3 color)
	{
		m_LineColor = color;

		setlinecolor(RGB(color.x, color.y, color.z));

		rectangle(position.x - size.x / 2, position.y - size.y / 2, position.x + size.x / 2, position.y + size.y / 2);
	}

	void Renderer::DrawFillRectangle(Vector2 position, Vector2 size, Vector3 color)
	{
		m_LineColor = color;
		m_FillColor = color;

		setlinecolor(RGB(color.x, color.y, color.z));
		setfillcolor(RGB(color.x, color.y, color.z));

		fillrectangle(position.x - size.x / 2, position.y - size.y / 2, position.x + size.x / 2, position.y + size.y / 2);
	}

	void Renderer::DrawFillRectangle(Vector2 position, Vector2 size, Vector3 lineColor, Vector3 fillColor)
	{
		m_LineColor = lineColor;
		m_FillColor = fillColor;

		setlinecolor(RGB(lineColor.x, lineColor.y, lineColor.z));
		setfillcolor(RGB(fillColor.x, fillColor.y, fillColor.z));

		fillrectangle(position.x - size.x / 2, position.y - size.y / 2, position.x + size.x / 2, position.y + size.y / 2);
	}
}