#include <Phoenix.h>
//Create a new application
class SandboxApp : public Phoenix::Application, Phoenix::IEventHandler {
public:
	SandboxApp() {
	}
	~SandboxApp() {
	}
	void OnEvent(const Phoenix::Event & e) {
	}
};

//send the app class to Phoenix engine to create.
Phoenix::Application* Phoenix::CreateApplication() {
	return new SandboxApp();
}