#include "PxPCH.h"
#include "WindowsWindow.h"
#include "Phoenix/Core.h"
#include "Phoenix/Events/WindowEvent.h"
#include "Phoenix/Events/MouseEvent.h"
#include "Phoenix/Events/KeyEvent.h"
#include "Phoenix/Log.h"
#include "glad/glad.h"

namespace Phoenix {
	static bool s_GLFWInitialized = false; //is GLFW initialized?

	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		Init(props);
	}

	WindowsWindow::~WindowsWindow() {
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props) {
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		std::stringstream ss;
		ss << "Creating a window: " << props.Title << " W: " << props.Width << " H: " << props.Height;
		Phoenix::Log::Info(ss.str());

		if (!s_GLFWInitialized) {
			int success = glfwInit();
			PX_CORE_ASSERT(success, "Could not initialize GLFW!");
			s_GLFWInitialized = true;
		}

		m_window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			Phoenix::Log::Fatal("Failed to initialize GLAD");
		}
		else {
			Phoenix::Log::Info("Initialized GLAD");
		}
		glfwSetWindowUserPointer(m_window, &m_Data);
		SetVSync(true);

		//ImGui::CreateContext();
		//ImGui_ImplGlfw_InitForOpenGL(m_window, true);

		//Set glfw callbacks
		glfwSetWindowSizeCallback(m_window, [](GLFWwindow * window, int width, int height) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowResizeEvent event(width, height);
			data.Width = width;
			data.Height = height;
			data.EventCallback(event);
		});

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow * window){
			WindowCloseEvent event;
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseMovedEvent event(xpos,ypos);
			data.EventCallback(event);
		});
		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action) {
				case GLFW_PRESS:
				{
					KeyPressedEvent	event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
			}
		});
		glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action) {
				case GLFW_PRESS:
				{
					MousePressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
			}
		});
	}

	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(m_window);
	}

	void WindowsWindow::OnUpdate() {
		//Test UI
		//ImGui::Begin("Test Window");
		//ImGui::End();
		//ImGui::NewFrame();
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	bool WindowsWindow::IsVSync() const {
		return m_Data.VSync;
	}

	void WindowsWindow::SetVSync(bool enabled) {
		if (enabled) {
			glfwSwapInterval(1);
		}
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}
};