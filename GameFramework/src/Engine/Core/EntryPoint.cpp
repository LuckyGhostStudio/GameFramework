#include "Application.h"

int main()
{
	Engine::Application* application = new Engine::Application();	// ��������
	
	application->Run();		// ����
	
	delete application;		// ����

	return 0;
}