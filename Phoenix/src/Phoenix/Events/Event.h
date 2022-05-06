#pragma once
#include "../Core.h";
enum EventType {
	None=0,
	WindowResize,WindowsMinimize,WindowMaximize,WindowMove,
	KeyPressed,KeyReleased,
	MouseButtonPressed,MouseButtonReleased,MouseMoved,MouseScrolled,
	AppTick,AppUpdate,AppRender
};

enum EventCategory {
	None = 0,
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
