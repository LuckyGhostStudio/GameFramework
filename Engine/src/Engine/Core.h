#pragma once

#ifdef EG_DEBUG
	#define EG_ENABLE_ASSERTS
#endif

#ifdef EG_ENABLE_ASSERTS	// ���ö���
	// ���ԣ�xΪ�� ����ʾERROR��־��Ϣ ���жϵ���
	#define ASSERT(x, ...) { if(!(x)) { EG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	// ���ԣ�xΪ�� ����ʾERROR��־��Ϣ ���жϵ���
	#define CORE_ASSERT(x, ...) { if(!(x)) { CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ASSERT(x, ...)
	#define CORE_ASSERT(x, ...)
#endif