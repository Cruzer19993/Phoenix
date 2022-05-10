#pragma once

#ifdef PX_PLATFORM_WINDOWS
	#ifdef PX_BUILD_DLL
		#define PX_API __declspec(dllexport)
	#else
		$define PX_API __declspec(dllimport)
	#endif
#else
	#error Phoenix Engine doesn't support this OS.
#endif

#ifdef PX_ENABLE_ASSERTS
	#define PX_ASSERT(x, ...) {if(!(x)) {Phoenix::Log::Error("Assertion Failed"); __debugbreak();}}
	#define PX_CORE_ASSERT(x, ...) {if(!(x)) {Phoenix::Log::Error("Core Assertion Failed"); __debugbreak();}}
#else
	#define PX_ASSERT(x, ...)
	#define PX_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
