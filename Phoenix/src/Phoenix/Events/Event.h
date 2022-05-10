#pragma once
#include "PxPCH.h"
#include "../Core.h"

namespace Phoenix {
	enum EventType {
		None = 0,
		WindowResize, WindowsMinimize, WindowMaximize, WindowMove,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
		AppTick, AppUpdate, AppRender
	};

	enum EventCategory {
		NoCategory = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	class PX_API Event {
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategory() const = 0;
		virtual const char* ToString() const { return GetName(); }
		bool IsCategory(EventCategory cat) const { return GetCategory() & cat;}
	protected:
		bool m_EventHandled = false;
	};

	class PX_API IEventHandler {
	public:
		virtual void OnEvent(const Event & e) = 0;
		void SetNextHandler(IEventHandler* next);
		IEventHandler* GetNextHandler(void);
		IEventHandler();
	protected:
		virtual void PushEvent(const Event& e);
	private:
		IEventHandler* _next;
	};

	class PX_API EventDispatcher {
	public:
		EventDispatcher(EventDispatcher& other) = delete;
		void operator =(const EventDispatcher&) = delete;
		void RegisterHandler(IEventHandler* device);
		void PublishEvent(const Event & e);
		static EventDispatcher* GetInstance();
	private:
		EventDispatcher();
		static EventDispatcher* singleton;
		IEventHandler* start;
		IEventHandler* end;
		int listenersCount; 
	};
}