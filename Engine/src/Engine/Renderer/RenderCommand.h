#pragma once

#include <graphics.h>
#include <glm/glm.hpp>

#include "Shader.h"

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
		/// <summary>
		/// ����Viewport����
		/// </summary>
		/// <param name="viewPortWidth">�ӿڿ�</param>
		/// <param name="viewPortHeight">�ӿڸ�</param>
		/// <returns>Viewport����</returns>
		inline static glm::mat4 GetViewPortMatrix(int viewPortWidth, int viewPortHeight)
		{
			// �ӿڱ任����
			glm::mat4 viewportMatrix = {
				{ viewPortWidth / 2.0f, 0, 0, viewPortWidth / 2.0f },
				{ 0, viewPortHeight / 2.0f, 0, viewPortHeight / 2.0f },
				{ 0, 0, 1, 0 },
				{ 0, 0, 0, 1 },
			};

			return viewportMatrix;
		}

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

		inline static void FillTriangle(const Vertex vertices[3])
		{
			// ��������
			int x = (vertices[0].position.x + vertices[1].position.x + vertices[2].position.x) / 3;
			int y = (vertices[0].position.y + vertices[1].position.y + vertices[2].position.y) / 3;

			floodfill(x, y, ToRGB(vertices[0].color));	// �������
		}

		/// <summary>
		/// �����������ƣ�������������
		/// </summary>
		/// <param name="positions">����λ��</param>
		/// <param name="indices">��������</param>
		/// <param name="count">��������</param>
		inline static void DrawIndexed(const Vertex* vertices, uint32_t* indices, uint32_t count)
		{
			// TODO: to shader ��դ��
			SetLineColor(vertices[0].color);
			SetFillColor(vertices[0].color);

			int triangleCount = count / 3;
			// ����������
			for (int j = 0; j < triangleCount; j++){
				Vertex tempVertices[3];
				// ������������������
				for (int i = j * 3; i < (j + 1) * 3; i++) {
					int index1 = indices[i];
					int index2 = indices[(i + 1) % ((j + 1) * 3)];
					// ����ֱ��
					line(vertices[index1].position.x, vertices[index1].position.y, vertices[index2].position.x, vertices[index2].position.y);
					// ��¼��������Ϣ
					tempVertices[i % 3].position = vertices[index1].position;
					tempVertices[i % 3].color = vertices[index1].color;
				}

				FillTriangle(tempVertices);	// ���������
			}

		}
	};
}