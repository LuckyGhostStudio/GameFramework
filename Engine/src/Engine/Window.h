#pragma once

#include <graphics.h>
#include <string>

namespace Engine
{
	/// <summary>
	/// ��������
	/// </summary>
	struct WindowProps
	{
		std::string Title;		// ����
		unsigned int Width;		// ��
		unsigned int Height;	// ��
		int Flag;				// ��־

		WindowProps(const std::string& title = "Engine", unsigned int width = 1280, unsigned int height = 720, int flag = 0)
			:Title(title), Width(width), Height(height), Flag(flag) {}
	};

	/// <summary>
	/// ����
	/// </summary>
	class Window
	{
	private:
		HWND m_Window;		// Win32����

		WindowProps m_Data;	// ��������
	public:
		/// <summary>
		/// ��������
		/// </summary>
		/// <param name="props">��������</param>
		/// <returns>����</returns>
		static Window* Create(const WindowProps& props = WindowProps());

		Window(const WindowProps& props);

		~Window();

		inline unsigned int GetWidth() const { return m_Data.Width; }
		inline unsigned int GetHeight() const { return m_Data.Height; }
	private:
		virtual void Init(const WindowProps& props);
	};
}