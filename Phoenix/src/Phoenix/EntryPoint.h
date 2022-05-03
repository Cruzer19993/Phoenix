#pragma once

#ifdef PX_PLATFORM_WINDOWS
extern Phoenix::Application* Phoenix::CreateApplication();
int main(int argc, char** argv) {
	std::string test = "Test";
	Phoenix::Log::ERROR(test);
	auto app = Phoenix::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
#endif