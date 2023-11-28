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

		//// ÿ�������ε���
		//std::vector<Fragment> Rasterize(const Vertex vertices[3]);
		//// ÿ�������ε����ص���
		//Fragment FragmentHandle(const Fragment& fragment);
	};
}