#include "Log.h"
namespace Phoenix {
	HANDLE Log::hConsole;
	void Log::Init() {
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 8);
		std::time_t time_now = std::time(nullptr);
		std::cout << std::put_time(std::localtime(&time_now), "%OH:%OM:%OS") << ">[INFO]Logger Initialized" << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
	}

	void Log::Error(const char* str) {
		std::time_t time_now = std::time(nullptr);
		SetConsoleTextAttribute(hConsole, 4);
		std::cout << std::put_time(std::localtime(&time_now), "%OH:%OM:%OS") << ">>>[ERROR] " << str << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
	}

	void Log::Fatal(const char* str) {
		std::time_t time_now = std::time(nullptr);
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << std::put_time(std::localtime(&time_now), "%OH:%OM:%OS") << ">>>>[FATAL]" << str << std::endl;\
		SetConsoleTextAttribute(hConsole, 15);
	}
	void Log::Warn(const char* str) {
		std::time_t time_now = std::time(nullptr);
		SetConsoleTextAttribute(hConsole, 6);
		std::cout << std::put_time(std::localtime(&time_now), "%OH:%OM:%OS") << ">>[WARN]" << str << std::endl; \
		SetConsoleTextAttribute(hConsole, 15);
	}
	void Log::Info(const char* str) {
		std::time_t time_now = std::time(nullptr);
		SetConsoleTextAttribute(hConsole, 8);
		std::cout << std::put_time(std::localtime(&time_now), "%OH:%OM:%OS") << ">[INFO]" << str << std::endl; \
		SetConsoleTextAttribute(hConsole, 15);
	}
	void Log::Debug(const char* str) {
		std::time_t time_now = std::time(nullptr);
		SetConsoleTextAttribute(hConsole, 11);
		std::cout << std::put_time(std::localtime(&time_now), "%OH:%OM:%OS") << ">[DEBUG]" << str << std::endl; \
		SetConsoleTextAttribute(hConsole, 15);
	}

}