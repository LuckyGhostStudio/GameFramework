#pragma once

#include "KeyCode.h"

#include <string>

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
		static inline bool GetKey(KeyCode key)
		{
			return GetAsyncKeyState((int)key) & 0x8000;
		}

		/// <summary>
		/// 获取水平或垂直输入 返回 左 下-1 0 右 上1
		/// </summary>
		/// <param name="input"></param>
		/// <returns>输入方向值</returns>
		static inline float GetAxis(const std::string& input)
		{
			if (input == "Horizontal") {		// 水平输入
				if (Input::GetKey(KeyCode::A) || Input::GetKey(KeyCode::Left)) {
					return -1;
				}
				else if (Input::GetKey(KeyCode::D) || Input::GetKey(KeyCode::Right)) {
					return 1;
				}
			}
			else if (input == "Vertical") {	// 垂直输入
				if (Input::GetKey(KeyCode::W) || Input::GetKey(KeyCode::Up)) {
					return 1;
				}
				else if (Input::GetKey(KeyCode::S) || Input::GetKey(KeyCode::Down)) {
					return -1;
				}
			}

			return 0;
		}
	};
}