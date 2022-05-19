#pragma once

#include "Core.h"
#include "Log.h"
#include "Window.h"
#include "Events/WindowEvent.h"
#include "Events/MouseEvent.h"
namespace Phoenix {
	
	class PX_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event & e);

		bool OnWindowClose();
		void OnMouseMove(MouseMovedEvent & e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}

