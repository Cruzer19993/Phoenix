#pragma once
#include "Event.h"
#include "../Core.h"
namespace Phoenix {

	class PX_API KeyPressedEvent : public Phoenix::Event {
	public:
		virtual EventType GetEventType() const {
			return Phoenix::EventType::KeyPressed;
		};
		virtual const std::string GetName() const {
			std::stringstream ss;
			ss << m_keyPressed;
			std::string msg = "Key pressed event, keyCode: ";
			msg.append(ss.str());
			return msg;
		};
		virtual int GetCategory() const {
			return Phoenix::EventCategory::EventCategoryKeyboard;
		};
		virtual const std::string ToString() const { return GetName(); }

		KeyPressedEvent(int keyCode, int repeatCount=0) {
			m_keyPressed = keyCode;
			m_repeatCount = repeatCount;
		}

		inline int GetRepeatCount() { return m_repeatCount; };
	private:
		int m_keyPressed;
		int m_repeatCount;
	};

	class PX_API KeyReleasedEvent : public Phoenix::Event {
	public:
		virtual EventType GetEventType() const {
			return Phoenix::EventType::KeyReleased;
		};
		virtual const std::string GetName() const {
			std::stringstream ss;
			ss << m_keyReleased;
			std::string msg = "Key released event, keyCode: ";
			msg.append(ss.str());
			return msg;
		};
		virtual int GetCategory() const {
			return Phoenix::EventCategory::EventCategoryKeyboard;
		};
		virtual const std::string ToString() const { return GetName(); }

		KeyReleasedEvent(int key) {
			m_keyReleased = key;
		}
	private:
		int m_keyReleased;
	};
};