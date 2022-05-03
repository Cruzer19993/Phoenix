#pragma once

#include "Core.h"
#include "Log.h"
namespace Phoenix {
	
	class PX_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

