#pragma once

#include <graphics.h>
#include <glm/glm.hpp>

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

		// TODO:更改为绘制三角形、直线、圆
		inline static void DrawFillRectangle(const glm::vec3& position, const glm::vec3& size, const glm::vec4& lineColor, const glm::vec4& fillColor)
		{
			SetLineColor(lineColor);
			SetFillColor(fillColor);

			fillrectangle(int(position.x - size.x / 2), int(position.y - size.y / 2), int(position.x + size.x / 2), int(position.y + size.y / 2));
		}
	};
}