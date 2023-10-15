#pragma once

#include <graphics.h>
#include <glm/glm.hpp>

namespace Engine
{
	/// <summary>
	/// ��Ⱦ����
	/// </summary>
	class RenderCommand
	{
	private:
		inline static COLORREF ToRGB(const glm::vec4& color)
		{
			return RGB(color.x * 255, color.y * 255, color.z * 255);
		}
	public:
		inline static void BeginBatch()
		{
			BeginBatchDraw();	// ��ʼ�������ƣ���ͼ�����ݴ��ڻ�����
		}

		inline static void EndBatch()
		{
			EndBatchDraw();		// �����������ƣ�ִ��δ��ɵĻ�������
		}

		inline static void FlushBatch()
		{
			FlushBatchDraw();	// ִ��δ��ɵĻ�ͼ����ִ�л������Ļ�ͼ����
		}

		/// <summary>
		/// ����������ɫ
		/// </summary>
		/// <param name="color">������ɫ</param>
		inline static void SetClearColor(const glm::vec4& color)
		{
			setbkcolor(ToRGB(color));
		}

		inline static void SetLineColor(const glm::vec4& color)
		{
			setlinecolor(ToRGB(color));
		}

		inline static void SetFillColor(const glm::vec4& color)
		{
			setfillcolor(ToRGB(color));
		}

		/// <summary>
		/// ����
		/// </summary>
		inline static void Clear()
		{
			cleardevice();
		}

		// TODO:����Ϊ���������Ρ�ֱ�ߡ�Բ
		inline static void DrawFillRectangle(const glm::vec3& position, const glm::vec3& size, const glm::vec4& lineColor, const glm::vec4& fillColor)
		{
			SetLineColor(lineColor);
			SetFillColor(fillColor);

			fillrectangle(int(position.x - size.x / 2), int(position.y - size.y / 2), int(position.x + size.x / 2), int(position.y + size.y / 2));
		}
	};
}