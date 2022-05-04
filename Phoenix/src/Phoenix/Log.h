#pragma once

#include "Core.h"
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <Windows.h>

namespace Phoenix {
	class PX_API Log
	{
	public:
		static void Init();
		static void Fatal(const char* str);
		static void Error(const char* str);
		static void Warn(const char* str);
		static void Info(const char* str);
		static void Debug(const char* str);
		static HANDLE hConsole;
	};
}

