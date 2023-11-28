#pragma once

#ifdef EG_DEBUG
	#define EG_ENABLE_ASSERTS
#endif

#ifdef EG_ENABLE_ASSERTS	// 启用断言
	// 断言：x为假 则显示ERROR日志信息 并中断调试
	#define ASSERT(x, ...) { if(!(x)) { EG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	// 断言：x为假 则显示ERROR日志信息 并中断调试
	#define CORE_ASSERT(x, ...) { if(!(x)) { CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ASSERT(x, ...)
	#define CORE_ASSERT(x, ...)
#endif