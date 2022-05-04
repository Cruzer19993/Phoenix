#include "Log.h"
namespace Phoenix {
	HANDLE Log::hConsole;
	void Log::Init() {
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 8);
		std::cout << ">[INFO]Logger Initialized" << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
	}

	void Log::Error(const char* str) {
		SetConsoleTextAttribute(hConsole, 4);
		std::cout << ">>>[ERROR] " << str << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
	}

	void Log::Fatal(const char* str) {
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << ">>>>[FATAL]" << str << std::endl;\
		SetConsoleTextAttribute(hConsole, 15);
	}
	void Log::Warn(const char* str) {
		SetConsoleTextAttribute(hConsole, 6);
		std::cout << ">>[WARN]" << str << std::endl; \
		SetConsoleTextAttribute(hConsole, 15);
	}
	void Log::Info(const char* str) {
		SetConsoleTextAttribute(hConsole, 8);
		std::cout << ">[INFO]" << str << std::endl; \
		SetConsoleTextAttribute(hConsole, 15);
	}
	void Log::Debug(const char* str) {
		SetConsoleTextAttribute(hConsole, 11);
		std::cout << ">[DEBUG]" << str << std::endl; \
		SetConsoleTextAttribute(hConsole, 15);
	}

}