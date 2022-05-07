#include "Event.h"
#include "../Log.h"

namespace Phoenix {
	IEventHandler* _nextHandler;
	EventDispatcher* EventDispatcher::singleton;
	EventDispatcher* EventDispatcher::GetInstance() {
		if (singleton == nullptr) {
			singleton = new EventDispatcher();

		return singleton;
		}
	}
	EventDispatcher::EventDispatcher() {
		EventDispatcher::listenersCount = 0;
		EventDispatcher::listeners_list_front = nullptr;
		Phoenix::Log::Info("Event Dispatcher singleton created");
	}

	void EventDispatcher::RegisterHandler(Phoenix::IEventHandler *device) {
		device->SetNextHandler(EventDispatcher::listeners_list_front);
		EventDispatcher::listeners_list_front = device;
		EventDispatcher::listenersCount++;
	}

	void EventDispatcher::PublishEvent(Event* e) {
		IEventHandler* currentDevice = EventDispatcher::listeners_list_front;
		for (; currentDevice; currentDevice = currentDevice->GetNextHandler()) {
			if (currentDevice != currentDevice->GetNextHandler())
				currentDevice->OnEvent(*e);
		}
	}

	void IEventHandler::SetNextHandler(IEventHandler* next) {
		_nextHandler = next;
	}
	IEventHandler* IEventHandler::GetNextHandler(void) {
		return _nextHandler;
	}
	IEventHandler::IEventHandler() : _nextHandler(0) {
		//Register the handler automatically.
		EventDispatcher::GetInstance()->RegisterHandler(this);
	}
}