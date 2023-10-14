#pragma once

#include "spdlog/spdlog.h"

#include <memory>

namespace Engine
{
	/// <summary>
	/// 日志
	/// </summary>
	class Log
	{
	public:
		/// <summary>
		/// 初始化日志
		/// </summary>
		static void Init();

		/// <summary>
		/// 返回内核日志
		/// </summary>
		/// <returns>内核日志</returns>
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

		/// <summary>
		/// 返回客户端日志
		/// </summary>
		/// <returns>客户端日志</returns>
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;		// 内核日志
		static std::shared_ptr<spdlog::logger> s_ClientLogger;		// 客户端日志
	};
}

// 内核日志
#define CORE_TRACE(...) Engine::Log::GetCoreLogger()->trace(__VA_ARGS__)	//提示 白
#define CORE_INFO(...)	Engine::Log::GetCoreLogger()->info(__VA_ARGS__)		//信息 绿
#define CORE_WARN(...)	Engine::Log::GetCoreLogger()->warn(__VA_ARGS__)		//警告 红
#define CORE_ERROR(...) Engine::Log::GetCoreLogger()->error(__VA_ARGS__)	//错误 黄
#define CORE_FATAL(...) Engine::Log::GetCoreLogger()->fatal(__VA_ARGS__)	//严重错误

// 客户端日志
#define TRACE(...)	Engine::Log::GetClientLogger()->trace(__VA_ARGS__)	//提示
#define INFO(...)	Engine::Log::GetClientLogger()->info(__VA_ARGS__)	//信息
#define WARN(...)	Engine::Log::GetClientLogger()->warn(__VA_ARGS__)	//警告
#define ERROR(...)	Engine::Log::GetClientLogger()->error(__VA_ARGS__)	//错误
#define FATAL(...)	Engine::Log::GetClientLogger()->fatal(__VA_ARGS__)	//严重错误