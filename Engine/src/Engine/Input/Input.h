#pragma once

#include "KeyCode.h"

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
		inline static bool GetKey(KeyCode key)
		{
			return GetAsyncKeyState((int)key) & 0x8000;
		}
	};
}