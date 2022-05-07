#include <Phoenix.h>
//Create a new application
class SandboxApp : public Phoenix::Application, Phoenix::IEventHandler {
public:
	SandboxApp() {
	}
	~SandboxApp() {
	}
	void OnEvent(const Phoenix::Event & e) {
		if(e.GetCategory() == Phoenix::EventCategoryMouseButton)
		Phoenix::Log::Debug("Detected an event, nice.");
	}
};

//send the app class to Phoenix engine to create.
Phoenix::Application* Phoenix::CreateApplication() {
	return new SandboxApp();
}