#pragma once

#ifdef PX_PLATFORM_WINDOWS
extern Phoenix::Application* Phoenix::CreateApplication();
int main(int argc, char** argv) { 
	Phoenix::Log::Init();
	auto app = Phoenix::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
#endif