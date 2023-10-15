#pragma once

#include <graphics.h>
#include <string>

namespace Engine
{
	/// <summary>
	/// 窗口属性
	/// </summary>
	struct WindowProps
	{
		std::string Title;		// 标题
		unsigned int Width;		// 宽
		unsigned int Height;	// 高
		int Flag;				// 标志

		WindowProps(const std::string& title = "Engine", unsigned int width = 1280, unsigned int height = 720, int flag = 0)
			:Title(title), Width(width), Height(height), Flag(flag) {}
	};

	/// <summary>
	/// 窗口
	/// </summary>
	class Window
	{
	private:
		HWND m_Window;		// Win32窗口

		WindowProps m_Data;	// 窗口数据
	public:
		/// <summary>
		/// 创建窗口
		/// </summary>
		/// <param name="props">窗口属性</param>
		/// <returns>窗口</returns>
		static Window* Create(const WindowProps& props = WindowProps());

		Window(const WindowProps& props);

		~Window();

		inline unsigned int GetWidth() const { return m_Data.Width; }
		inline unsigned int GetHeight() const { return m_Data.Height; }
	private:
		virtual void Init(const WindowProps& props);
	};
}