#include "Renderer.h"

#include <graphics.h>

namespace Engine
{
	Vector3 Renderer::m_LineColor = Vector3::Vector3(255, 255, 255);
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