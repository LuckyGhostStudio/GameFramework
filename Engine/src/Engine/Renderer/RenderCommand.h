#pragma once

#include <graphics.h>
#include <glm/glm.hpp>

#include "Shader.h"

namespace Engine
{
	/// <summary>
	/// 渲染命令
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
		/// 返回Viewport矩阵
		/// </summary>
		/// <param name="viewPortWidth">视口宽</param>
		/// <param name="viewPortHeight">视口高</param>
		/// <returns>Viewport矩阵</returns>
		inline static glm::mat4 GetViewPortMatrix(int viewPortWidth, int viewPortHeight)
		{
			// 视口变换矩阵
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
			BeginBatchDraw();	// 开始批量绘制：绘图操作暂存在缓冲区
		}

		inline static void EndBatch()
		{
			EndBatchDraw();		// 结束批量绘制：执行未完成的绘制任务
		}

		inline static void FlushBatch()
		{
			FlushBatchDraw();	// 执行未完成的绘图任务：执行缓冲区的绘图操作
		}

		/// <summary>
		/// 设置清屏颜色
		/// </summary>
		/// <param name="color">清屏颜色</param>
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
		/// 清屏
		/// </summary>
		inline static void Clear()
		{
			cleardevice();
		}

		inline static void FillTriangle(const Vertex vertices[3])
		{
			// 重心坐标
			int x = (vertices[0].position.x + vertices[1].position.x + vertices[2].position.x) / 3;
			int y = (vertices[0].position.y + vertices[1].position.y + vertices[2].position.y) / 3;

			floodfill(x, y, ToRGB(vertices[0].color));	// 填充区域
		}

		/// <summary>
		/// 根据索引绘制（三角形索引）
		/// </summary>
		/// <param name="positions">顶点位置</param>
		/// <param name="indices">顶点索引</param>
		/// <param name="count">索引个数</param>
		inline static void DrawIndexed(const Vertex* vertices, uint32_t* indices, uint32_t count)
		{
			// TODO: to shader 光栅化
			SetLineColor(vertices[0].color);
			SetFillColor(vertices[0].color);

			int triangleCount = count / 3;
			// 遍历三角形
			for (int j = 0; j < triangleCount; j++){
				Vertex tempVertices[3];
				// 根据索引绘制三角形
				for (int i = j * 3; i < (j + 1) * 3; i++) {
					int index1 = indices[i];
					int index2 = indices[(i + 1) % ((j + 1) * 3)];
					// 绘制直线
					line(vertices[index1].position.x, vertices[index1].position.y, vertices[index2].position.x, vertices[index2].position.y);
					// 记录三角形信息
					tempVertices[i % 3].position = vertices[index1].position;
					tempVertices[i % 3].color = vertices[index1].color;
				}

				FillTriangle(tempVertices);	// 填充三角形
			}

		}
	};
}