#pragma once

#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector3.h"

namespace Engine
{
	class Renderer
	{
	public:
		static Vector3 m_LineColor;		// ����ɫ
		static Vector3 m_FillColor;		// �����ɫ
		static Vector3 m_ClearColor;	// ������ɫ

		/// <summary>
		/// ��ʼ��
		/// </summary>
		static void Initialize();

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
		static void SetClearColor(Vector3 color = Vector3(255, 255, 255));

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
		static void DrawRectangle(Vector2 position, Vector2 size, Vector3 color);

		/// <summary>
		/// ����������
		/// </summary>
		/// <param name="position">λ��</param>
		/// <param name="size">�ߴ�</param>
		/// <param name="color">��ɫ</param>
		static void DrawFillRectangle(Vector2 position, Vector2 size, Vector3 color);

		/// <summary>
		/// ����������
		/// </summary>
		/// <param name="position">λ��</param>
		/// <param name="size">�ߴ�</param>
		/// <param name="lineColor">�߿���ɫ</param>
		/// <param name="fillColor">�����ɫ</param>
		static void DrawFillRectangle(Vector2 position, Vector2 size, Vector3 lineColor, Vector3 fillColor);
	};
}