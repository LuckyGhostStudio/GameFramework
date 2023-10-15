#pragma once

#include "RenderCommand.h"

namespace Engine
{
	class Renderer
	{
	public:
		/// <summary>
		/// ��ʼ���� TODO: Camera...
		/// </summary>
		static void BeginScene();

		/// <summary>
		/// �ر���Ⱦ��
		/// </summary>
		static void ShutDown();

		/// <summary>
		/// ��������
		/// </summary>
		static void EndScene();

		/// <summary>
		/// ����������ɫ
		/// </summary>
		/// <param name="color"></param>
		static void SetClearColor(const glm::vec4& color);

		/// <summary>
		/// ����
		/// </summary>
		static void Clear();

		/// <summary>
		/// ����������
		/// </summary>
		/// <param name="position">λ��</param>
		/// <param name="size">�ߴ�</param>
		/// <param name="color">��ɫ</param>
		static void DrawFillRectangle(const glm::vec3& position, const glm::vec3& size, const glm::vec4& color);
	};
}