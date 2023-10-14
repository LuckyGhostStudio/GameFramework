#pragma once

namespace Engine
{
	struct Time
	{
		static float time;		// 当前时间（s）：从程序开始运行计算
		static float deltaTime;	// 当前帧间隔（s）
	};
}