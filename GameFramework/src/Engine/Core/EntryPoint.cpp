#include "Application.h"

int main()
{
	Engine::Application* application = new Engine::Application();	// 创建程序
	
	application->Run();		// 运行
	
	delete application;		// 销毁

	return 0;
}