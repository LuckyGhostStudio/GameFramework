#include "Renderer.h"

#include <graphics.h>

namespace Engine
{
	Vector3 Renderer::m_LineColor = Vector3::Vector3(255, 255, 255);
	int Renderer::m_LineWidth = 1;
	Vector3 Renderer::m_FillColor = Vector3::Vector3(255, 255, 255);
	Vector3 Renderer::m_ClearColor = Vector3::Vector3(255, 255, 255);

	void Renderer::Initialize(float width, float height, int flag)
	{
		initgraph((int)width, (int)height, flag);	// ��ʼ����ͼ����

		BeginBatchDraw();							// ��ʼ�������ƣ���ͼ�����ݴ��ڻ�����
	}

	void Renderer::ShutDown()
	{
		EndBatchDraw();		// �����������ƣ�ִ��δ��ɵĻ�������
		closegraph();		// �رջ�ͼ����
	}

	void Renderer::FlushBatch()
	{
		FlushBatchDraw();	// ִ��δ��ɵĻ�ͼ����ִ�л������Ļ�ͼ����
	}

	void Renderer::SetClearColor(const Vector3& color)
	{
		m_ClearColor = color;
		setbkcolor(RGB(color.x, color.y, color.z));
	}

	void Renderer::Clear()
	{
		cleardevice();
	}

	void Renderer::DrawRectangle(const Vector2& position, const Vector2& size, const Vector3& color)
	{
		m_LineColor = color;

		setlinecolor(RGB(color.x, color.y, color.z));

		rectangle(position.x - size.x / 2, position.y - size.y / 2, position.x + size.x / 2, position.y + size.y / 2);
	}

	void Renderer::DrawFillRectangle(const Vector2& position, const Vector2& size, const Vector3& color)
	{
		m_LineColor = color;
		m_FillColor = color;

		setlinecolor(RGB(color.x, color.y, color.z));
		setfillcolor(RGB(color.x, color.y, color.z));

		fillrectangle(position.x - size.x / 2, position.y - size.y / 2, position.x + size.x / 2, position.y + size.y / 2);
	}

	void Renderer::DrawFillRectangle(const Vector2& position, const Vector2& size, const Vector3& lineColor, const Vector3& fillColor)
	{
		m_LineColor = lineColor;
		m_FillColor = fillColor;

		setlinecolor(RGB(lineColor.x, lineColor.y, lineColor.z));
		setfillcolor(RGB(fillColor.x, fillColor.y, fillColor.z));

		fillrectangle(position.x - size.x / 2, position.y - size.y / 2, position.x + size.x / 2, position.y + size.y / 2);
	}

	void Renderer::DrawCircle(const Vector2& position, float radius, const Vector3& color, float lineWidth)
	{
		m_LineColor = color;
		m_LineWidth = lineWidth;

		setlinecolor(RGB(color.x, color.y, color.z));
		setlinestyle(PS_SOLID, lineWidth);

		circle(position.x, position.y, radius);
	}

	void Renderer::DrawTriangle(const Vector2 vertices[3], const Vector3& color, float lineWidth)
	{
		m_LineColor = color;
		m_LineWidth = lineWidth;

		setlinecolor(RGB(color.x, color.y, color.z));
		setlinestyle(PS_SOLID, lineWidth);

		for (int i = 0; i < 3; i++) {
			line(vertices[i].x, vertices[i].y, vertices[(i + 1) % 3].x, vertices[(i + 1) % 3].y);
		}
	}

	void Renderer::DrawFillEllipse(const Vector2& position, const Vector2& size, const Vector3& lineColor, const Vector3& fillColor)
	{
		m_LineColor = lineColor;
		m_FillColor = fillColor;

		setlinecolor(RGB(lineColor.x, lineColor.y, lineColor.z));
		setfillcolor(RGB(fillColor.x, fillColor.y, fillColor.z));

		fillellipse(position.x - size.x / 2, position.y - size.y / 2, position.x + size.x / 2, position.y + size.y / 2);
	}
}