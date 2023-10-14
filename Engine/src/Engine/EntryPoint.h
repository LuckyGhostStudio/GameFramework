#pragma once

#ifdef EG_PLATFORM_WINDOWS

extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
	Engine::Log::Init();	// ��ʼ����־
	CORE_INFO("Init Log��");

	Engine::Application* app = Engine::CreateApplication();	// ��������
	app->Run();
	delete app;
}

#endif