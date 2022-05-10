#pragma once
#include "PxPCH.h"
#include "Phoenix/Core.h"

namespace Phoenix {
	class PX_API Log{
	public:
		static void Init();
		static void Fatal(std::string str);
		static void Error(std::string str);
		static void Warn(std::string str);
		static void Info(std::string str);
		static void Debug(std::string str);
		static HANDLE hConsole;
	};
}

