#pragma once

#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

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
#define EG_TRACE(...)	Engine::Log::GetClientLogger()->trace(__VA_ARGS__)	//��ʾ
#define EG_INFO(...)	Engine::Log::GetClientLogger()->info(__VA_ARGS__)	//��Ϣ
#define EG_WARN(...)	Engine::Log::GetClientLogger()->warn(__VA_ARGS__)	//����
#define EG_ERROR(...)	Engine::Log::GetClientLogger()->error(__VA_ARGS__)	//����
#define EG_FATAL(...)	Engine::Log::GetClientLogger()->fatal(__VA_ARGS__)	//���ش���