#pragma once

#ifdef EG_PLATFORM_WINDOWS

extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
	Engine::Log::Init();	// 初始化日志
	CORE_INFO("Init Log！");

	Engine::Application* app = Engine::CreateApplication();	// 创建程序
	app->Run();
	delete app;
}

#endif