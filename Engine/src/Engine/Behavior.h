#pragma once

namespace Engine
{
	class Behavior
	{
	public:
		// ��һ֡����
		void virtual Start() {}

		// ��Ⱦ��ÿ֡����
		void virtual Render() {}

		// ���£�ÿ֡����
		void virtual Update() {}
	};
}