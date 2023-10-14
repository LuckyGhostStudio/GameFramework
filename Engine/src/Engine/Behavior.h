#pragma once

namespace Engine
{
	class Behavior
	{
	public:
		// 第一帧调用
		void virtual Start() {}

		// 渲染：每帧调用
		void virtual Render() {}

		// 更新：每帧调用
		void virtual Update() {}
	};
}