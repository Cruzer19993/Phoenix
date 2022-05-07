#include "Application.h"
#include "Events\Event.h"
#include "Events/KeyEvent.h"

namespace Phoenix {
	Application::Application()
	{
	}
	Application::~Application()
	{
	}

	void Application::Run() {
		Phoenix::KeyPressedEvent t(Phoenix::KeyCode::A);
		Phoenix::EventDispatcher::GetInstance()->PublishEvent(t);
		while (true);
	}
}