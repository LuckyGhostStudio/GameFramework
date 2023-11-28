#include "Shader.h"

namespace Engine
{
	Vertex Shader::VertexHandle(const glm::mat4& mvpMat, const Vertex& vertex)
	{
		Vertex v;
		v.position = mvpMat * vertex.position;	// mvp 变换

		// 透视除法
		v.position.x /= v.position.w;
		v.position.y /= v.position.w;
		v.position.z /= v.position.w;
		v.position.w /= v.position.w;

		// 计算光照公式生成逐顶点颜色
		// 生成 / 变换纹理坐标
		// 光栅化：遍历

		return v;
	}

	//std::vector<Fragment> Shader::Rasterize(const Vertex vertices[3])
	//{
	//	// 遍历每个三角形：进行光栅化
	//
	//	return std::vector<Fragment>();
	//}
	//
	//Fragment Shader::FragmentHandle(const Fragment& fragment)
	//{
	//	// 遍历光栅化后的三角形，逐片元调用
	//
	//	return Fragment();
	//}
}