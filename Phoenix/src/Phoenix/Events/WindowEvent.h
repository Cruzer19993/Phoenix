#pragma once
#include "Event.h"
#include "../Core.h"

namespace Phoenix {
	class PX_API WindowResizeEvent : public Phoenix::Event {
	public:
		virtual EventType GetEventType() const {
			return Phoenix::EventType::WindowResize;
		};
		virtual const std::string GetName() const {
			std::stringstream ss;
			ss << m_Width << "|" << m_Height;
			std::string msg = "Window Resize Event: New Width/Height: ";
			msg.append(ss.str());
			return msg;
		};
		virtual int GetCategory() const {
			return Phoenix::EventCategory::EventCategoryApplication;
		};
		virtual const std::string ToString() const {
			return GetName();
		};
		WindowResizeEvent(int width, int height) {
			m_Width = width;
			m_Height = height;
		}
	private:
		int m_Width;
		int m_Height;
	};

	class PX_API WindowCloseEvent : public Phoenix::Event {
	public:
		virtual EventType GetEventType() const {
			return Phoenix::EventType::WindowClose;
		};

		virtual const std::string GetName() const {
			return "Window Close Event.";
		};
		virtual int GetCategory() const {
			return Phoenix::EventCategory::EventCategoryApplication;
		};
		virtual const std::string ToString() const {
			return GetName();
		}
	};
	class PX_API WindowMinimizeEvent : public Phoenix::Event {
	public:
		virtual EventType GetEventType() const {
			return Phoenix::EventType::WindowsMinimize;
		};
		virtual const std::string GetName() const {
			return "Window Minimize Event";
		};
		virtual int GetCategory() const {
			return Phoenix::EventCategory::EventCategoryApplication;
		};
		virtual const std::string ToString() const {
			return GetName();
		}
	};
};