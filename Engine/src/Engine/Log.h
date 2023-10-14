#pragma once

#include "spdlog/spdlog.h"

#include <memory>

namespace Engine
{
	/// <summary>
	/// ��־
	/// </summary>
	class Log
	{
	public:
		/// <summary>
		/// ��ʼ����־
		/// </summary>
		static void Init();

		/// <summary>
		/// �����ں���־
		/// </summary>
		/// <returns>�ں���־</returns>
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

		/// <summary>
		/// ���ؿͻ�����־
		/// </summary>
		/// <returns>�ͻ�����־</returns>
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;		// �ں���־
		static std::shared_ptr<spdlog::logger> s_ClientLogger;		// �ͻ�����־
	};
}

// �ں���־
#define CORE_TRACE(...) Engine::Log::GetCoreLogger()->trace(__VA_ARGS__)	//��ʾ ��
#define CORE_INFO(...)	Engine::Log::GetCoreLogger()->info(__VA_ARGS__)		//��Ϣ ��
#define CORE_WARN(...)	Engine::Log::GetCoreLogger()->warn(__VA_ARGS__)		//���� ��
#define CORE_ERROR(...) Engine::Log::GetCoreLogger()->error(__VA_ARGS__)	//���� ��
#define CORE_FATAL(...) Engine::Log::GetCoreLogger()->fatal(__VA_ARGS__)	//���ش���

// �ͻ�����־
#define TRACE(...)	Engine::Log::GetClientLogger()->trace(__VA_ARGS__)	//��ʾ
#define INFO(...)	Engine::Log::GetClientLogger()->info(__VA_ARGS__)	//��Ϣ
#define WARN(...)	Engine::Log::GetClientLogger()->warn(__VA_ARGS__)	//����
#define ERROR(...)	Engine::Log::GetClientLogger()->error(__VA_ARGS__)	//����
#define FATAL(...)	Engine::Log::GetClientLogger()->fatal(__VA_ARGS__)	//���ش���