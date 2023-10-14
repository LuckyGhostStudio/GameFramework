#pragma once

#include "Engine/Math/Vector2.h"
#include "Engine/Math/Vector3.h"

namespace Engine
{
	class Renderer
	{
	public:
		static Vector3 m_LineColor;		// 线颜色
		static Vector3 m_FillColor;		// 填充颜色
		static Vector3 m_ClearColor;	// 清屏颜色

		/// <summary>
		/// 初始化
		/// </summary>
		/// <param name="width">画布宽</param>
		/// <param name="height">画布高</param>
		/// <param name="flag">模式</param>
		static void Initialize(float width, float height, int flag = 0);

		/// <summary>
		/// 关闭渲染器
		/// </summary>
		static void ShutDown();

		/// <summary>
		/// 批渲染
		/// </summary>
		static void FlushBatch();

		/// <summary>
		/// 设置清屏颜色
		/// </summary>
		/// <param name="color"></param>
		static void SetClearColor(Vector3 color = Vector3(255, 255, 255));

		/// <summary>
		/// 清屏
		/// </summary>
		static void Clear();

		/// <summary>
		/// 绘制边框矩形
		/// </summary>
		/// <param name="position">位置</param>
		/// <param name="size">尺寸</param>
		/// <param name="color">颜色</param>
		static void DrawRectangle(Vector2 position, Vector2 size, Vector3 color);

		/// <summary>
		/// 绘制填充矩形
		/// </summary>
		/// <param name="position">位置</param>
		/// <param name="size">尺寸</param>
		/// <param name="color">颜色</param>
		static void DrawFillRectangle(Vector2 position, Vector2 size, Vector3 color);

		/// <summary>
		/// 绘制填充矩形
		/// </summary>
		/// <param name="position">位置</param>
		/// <param name="size">尺寸</param>
		/// <param name="lineColor">边框颜色</param>
		/// <param name="fillColor">填充颜色</param>
		static void DrawFillRectangle(Vector2 position, Vector2 size, Vector3 lineColor, Vector3 fillColor);
	};
}