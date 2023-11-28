#pragma once

#include "RenderCommand.h"
#include "Camera.h"

namespace Engine
{
	class Renderer
	{
	private:
		/// <summary>
		/// 场景数据
		/// </summary>
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;	// vp矩阵
		};

		static SceneData* m_SceneData;	//场景数据
	public:
		static void Init();
		/// <summary>
		/// 开始场景
		/// </summary>
		static void BeginScene(Camera& camera);

		/// <summary>
		/// 关闭渲染器
		/// </summary>
		static void ShutDown();

		/// <summary>
		/// 结束场景
		/// </summary>
		static void EndScene();

		/// <summary>
		/// 设置清屏颜色
		/// </summary>
		/// <param name="color"></param>
		static void SetClearColor(const glm::vec4& color);

		/// <summary>
		/// 清屏
		/// </summary>
		static void Clear();

		/// <summary>
		/// 绘制填充矩形
		/// </summary>
		/// <param name="position">位置</param>
		/// <param name="size">尺寸</param>
		/// <param name="color">颜色</param>
		static void DrawFillRectangle(const glm::vec3& position, const glm::vec3& size, const glm::vec4& color);
	};
}