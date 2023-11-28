#pragma once

#include "Math/Vector3.h"
#include "Math/Vector2.h"

namespace Engine
{
	class Renderer
	{
	public:
		static Vector3 m_LineColor;		// ����ɫ
		static int m_LineWidth;			// �߿�
		static Vector3 m_FillColor;		// �����ɫ
		static Vector3 m_ClearColor;	// ������ɫ

		/// <summary>
		/// ��ʼ��
		/// </summary>
		/// <param name="width">������</param>
		/// <param name="height">������</param>
		/// <param name="flag">ģʽ</param>
		static void Initialize(float width, float height, int flag = 0);

		/// <summary>
		/// �ر���Ⱦ��
		/// </summary>
		static void ShutDown();

		/// <summary>
		/// ����Ⱦ
		/// </summary>
		static void FlushBatch();

		/// <summary>
		/// ����������ɫ
		/// </summary>
		/// <param name="color"></param>
		static void SetClearColor(const Vector3& color = Vector3(255, 255, 255));

		/// <summary>
		/// ����
		/// </summary>
		static void Clear();

		/// <summary>
		/// ���Ʊ߿����
		/// </summary>
		/// <param name="position">λ��</param>
		/// <param name="size">�ߴ�</param>
		/// <param name="color">��ɫ</param>
		static void DrawRectangle(const Vector2& position, const Vector2& size, const Vector3& color);

		/// <summary>
		/// ����������
		/// </summary>
		/// <param name="position">λ��</param>
		/// <param name="size">�ߴ�</param>
		/// <param name="color">��ɫ</param>
		static void DrawFillRectangle(const Vector2& position, const Vector2& size, const Vector3& color);

		/// <summary>
		/// ����������
		/// </summary>
		/// <param name="position">λ��</param>
		/// <param name="size">�ߴ�</param>
		/// <param name="lineColor">�߿���ɫ</param>
		/// <param name="fillColor">�����ɫ</param>
		static void DrawFillRectangle(const Vector2& position, const Vector2& size, const Vector3& lineColor, const Vector3& fillColor);

		static void DrawCircle(const Vector2& position, float radius, const Vector3& color, float lineWidth = 1.0f);
	};
}