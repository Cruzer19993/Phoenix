#pragma once
#include "Event.h"
#include "../Core.h"

namespace Phoenix {
	enum MouseButton {
		Primary,
		Secondrary,
		Function,
		Scroll
	};

	class PX_API MousePressedEvent : public Phoenix::Event {
	public:
		virtual EventType GetEventType() const {
			return Phoenix::EventType::MouseButtonPressed;
		};

		virtual const std::string GetName() const {
			return "Mouse Button Pressed Event, Button: " + m_buttonPressed;
		};

		virtual int GetCategory() const {
			return Phoenix::EventCategory::EventCategoryMouseButton;
		};

		virtual const std::string ToString() const {
			return GetName();
		}
		MousePressedEvent(MouseButton button) {
			m_buttonPressed = button;
		}
	private:
		MouseButton m_buttonPressed;
	};
}