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

#define BIT(x) (1 << x)
