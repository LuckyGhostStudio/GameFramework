#pragma once

#include <glm/glm.hpp>
#include <vector>

namespace Engine
{
	struct Vertex
	{
		glm::vec4 position;
		glm::vec4 color;
	};

	//struct Fragment
	//{
	//	glm::vec4 position;
	//	glm::vec4 color;
	//	// TODO: 
	//};

	class Shader
	{
	public:
		static Vertex VertexHandle(const glm::mat4& mvpMat, const Vertex& vertex);

		//// 每个三角形调用
		//std::vector<Fragment> Rasterize(const Vertex vertices[3]);
		//// 每个三角形的像素调用
		//Fragment FragmentHandle(const Fragment& fragment);
	};
}