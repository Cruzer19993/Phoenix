#include <Phoenix.h>
//Create a new application
class SandboxApp : public Phoenix::Application {
public:
	SandboxApp() {
	}
	~SandboxApp() {
	}
};

//send the app class to Phoenix engine to create.
Phoenix::Application* Phoenix::CreateApplication() {
	return new SandboxApp();
}