#include "PxPCH.h"
#include "Application.h"
#include "Events\Event.h"
#include "Events/KeyEvent.h"

namespace Phoenix {
#define BIND_EVENT(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT(OnEvent));
	}
	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e) {
		if (e.IsCategory(Phoenix::EventCategory::EventCategoryApplication))
			if (e.GetEventType() == Phoenix::EventType::WindowClose)
				OnWindowClose();
		if(e.IsCategory(Phoenix::EventCategory::EventCategoryMouse))
			if (e.GetEventType() == Phoenix::EventType::MouseMoved) {
				MouseMovedEvent* tempe = dynamic_cast<MouseMovedEvent*>(&e);
				OnMouseMove(*tempe);
			}
	}

	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}

	void Application::OnMouseMove(MouseMovedEvent& e) {
		Phoenix::Log::Debug(e.ToString());
	}

	bool Application::OnWindowClose() {
		m_Running = false;
		Phoenix::Log::Info("Application terminated");
		return true;
	}
}