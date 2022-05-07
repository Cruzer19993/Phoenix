#pragma once
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

		inline bool IsCategory(EventCategory cat) {
			return GetCategory() & cat;
		}
	protected:
		bool m_EventHandled = false;
	};

	class PX_API IEventHandler {
	public:
		virtual void OnEvent(const Event & e) = 0;
		virtual void PushEvent(const Event & e);
		void SetNextHandler(IEventHandler* next);
		IEventHandler* GetNextHandler(void);
		IEventHandler();
	private:
		IEventHandler* _nextHandler;
	};

	class PX_API EventDispatcher {
	public:
		EventDispatcher(EventDispatcher& other) = delete;
		void operator =(const EventDispatcher&) = delete;
		void RegisterHandler(IEventHandler* device);
		void PublishEvent(Event* e);
		static EventDispatcher* GetInstance();

	protected:
		EventDispatcher();
		static EventDispatcher* singleton;
		IEventHandler* listeners_list_front;
		int listenersCount; 
	};
}