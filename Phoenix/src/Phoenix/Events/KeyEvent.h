#pragma once
#include "Event.h"
#include "../Core.h"
namespace Phoenix {

	enum KeyCode {
		Q,W,E,R,T,Y,U,I,O,P,A,S,D,F,G,H,J,K,L,Z,X,C,V,B,N,M
	};

	class PX_API KeyPressedEvent : public Phoenix::Event {
	public:
		virtual EventType GetEventType() const {
			return Phoenix::EventType::KeyPressed;
		};
		virtual const char* GetName() const {
			return "Key Pressed Event, KeyCode:" + m_keyPressed;
		};
		virtual int GetCategory() const {
			return Phoenix::EventCategory::EventCategoryKeyboard;
		};
		virtual const char* ToString() const { return GetName(); }

		KeyPressedEvent(KeyCode key) {
			m_keyPressed = key;
		}
	private:
		KeyCode m_keyPressed;
	};
};