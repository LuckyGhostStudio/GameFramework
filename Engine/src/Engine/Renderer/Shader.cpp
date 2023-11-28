#include "Shader.h"

namespace Engine
{
	Vertex Shader::VertexHandle(const glm::mat4& mvpMat, const Vertex& vertex)
	{
		Vertex v;
		v.position = mvpMat * vertex.position;	// mvp �任

		// ͸�ӳ���
		v.position.x /= v.position.w;
		v.position.y /= v.position.w;
		v.position.z /= v.position.w;
		v.position.w /= v.position.w;

		// ������չ�ʽ�����𶥵���ɫ
		// ���� / �任��������
		// ��դ��������

		return v;
	}

	//std::vector<Fragment> Shader::Rasterize(const Vertex vertices[3])
	//{
	//	// ����ÿ�������Σ����й�դ��
	//
	//	return std::vector<Fragment>();
	//}
	//
	//Fragment Shader::FragmentHandle(const Fragment& fragment)
	//{
	//	// ������դ����������Σ���ƬԪ����
	//
	//	return Fragment();
	//}
}