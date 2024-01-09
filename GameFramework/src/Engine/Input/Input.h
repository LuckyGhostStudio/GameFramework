#pragma once

#include "KeyCode.h"

#include <string>

namespace Engine
{
	class Input
	{
	public:
		/// <summary>
		/// �����Ƿ��£�KeyCode -> Win32����
		/// </summary>
		/// <param name="key">��������</param>
		/// <returns>����״̬</returns>
		static inline bool GetKey(KeyCode key)
		{
			return GetAsyncKeyState((int)key) & 0x8000;
		}

		/// <summary>
		/// ��ȡˮƽ��ֱ���� ���� �� ��-1 0 �� ��1
		/// </summary>
		/// <param name="input"></param>
		/// <returns>���뷽��ֵ</returns>
		static inline float GetAxis(const std::string& input)
		{
			if (input == "Horizontal") {		// ˮƽ����
				if (Input::GetKey(KeyCode::A) || Input::GetKey(KeyCode::Left)) {
					return -1;
				}
				else if (Input::GetKey(KeyCode::D) || Input::GetKey(KeyCode::Right)) {
					return 1;
				}
			}
			else if (input == "Vertical") {	// ��ֱ����
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