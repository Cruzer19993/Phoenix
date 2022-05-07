#include "Event.h"
#include "../Log.h"

namespace Phoenix {
	EventDispatcher* EventDispatcher::singleton;
	IEventHandler* start;
	IEventHandler* end;
	EventDispatcher* EventDispatcher::GetInstance() {
		if (EventDispatcher::singleton == nullptr) {
			EventDispatcher::singleton = new EventDispatcher();

		return EventDispatcher::singleton;
		}
	}
	EventDispatcher::EventDispatcher() {
		EventDispatcher::start = nullptr;
		EventDispatcher::end = nullptr;
		EventDispatcher::listenersCount = 0;
		Phoenix::Log::Info("Event Dispatcher singleton created");
	}

	void EventDispatcher::RegisterHandler(Phoenix::IEventHandler *device) {
		if (EventDispatcher::listenersCount == 0) {
			EventDispatcher::start = device;
			EventDispatcher::end = device;
			device->SetNextHandler(nullptr);
		}
		else if (EventDispatcher::listenersCount == 1) {
			EventDispatcher::end == device;
			EventDispatcher::start->SetNextHandler(device);
		}
		else {
			EventDispatcher::end->SetNextHandler(device);
			EventDispatcher::end = device;
		}
		EventDispatcher::listenersCount++;
		Phoenix::Log::Info("Registered a new listener.");
	}

	void EventDispatcher::PublishEvent(const Event & e) {
		//Phoenix::Log::Debug("" + EventDispatcher::GetInstance()->GetListenersCount());
		if (EventDispatcher::singleton->listenersCount != 0) {
			IEventHandler* currentDevice = EventDispatcher::singleton->start;
			for (; currentDevice; currentDevice = currentDevice->GetNextHandler()) {
				if (currentDevice != currentDevice->GetNextHandler())
					currentDevice->OnEvent(e);
			}
		}
	}

	void IEventHandler::SetNextHandler(IEventHandler* next) {
		_next = next;
	}
	IEventHandler* IEventHandler::GetNextHandler(void) {
		return _next;
	}
	IEventHandler::IEventHandler() {
		//Register the handler automatically.
		EventDispatcher::GetInstance()->RegisterHandler(this);
	}
	
	void IEventHandler::PushEvent(const Event& e) {
		EventDispatcher::GetInstance()->PublishEvent(e);
	}
}