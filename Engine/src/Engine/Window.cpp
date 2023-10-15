#include "Window.h"
#include "Log.h"

namespace Engine
{
	Window* Window::Create(const WindowProps& props)
	{
		return new Window(props);
	}

	Window::Window(const WindowProps& props)
	{
		Init(props);
	}

	Window::~Window()
	{
		closegraph();		// 关闭绘图窗口
	}

	void Window::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		m_Data.Flag = props.Flag;

		CORE_INFO("Cteating window {0} ({1}, {2})", props.Title, props.Width, props.Height);
		m_Window = initgraph((int)props.Width, (int)props.Height, props.Flag);	// 初始化绘图窗口

		// string to wchar_t*
		int pSize = MultiByteToWideChar(CP_OEMCP, 0, props.Title.c_str(), strlen(props.Title.c_str()) + 1, NULL, 0);
		wchar_t* title = new wchar_t[pSize];
		MultiByteToWideChar(CP_OEMCP, 0, props.Title.c_str(), strlen(props.Title.c_str()) + 1, title, pSize);
		
		SetWindowText(m_Window, title);	// 设置窗口标题
	}
}