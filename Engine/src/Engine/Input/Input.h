#pragma once

#include "KeyCode.h"

namespace Engine
{
	class Input
	{
	public:
		/// <summary>
		/// 按键是否按下：KeyCode -> Win32代码
		/// </summary>
		/// <param name="key">按键代码</param>
		/// <returns>按键状态</returns>
		inline static bool GetKey(KeyCode key)
		{
			return GetAsyncKeyState((int)key) & 0x8000;
		}
	};
}