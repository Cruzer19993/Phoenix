#include "PxPCH.h"
#include "WindowsWindow.h"
#include "Phoenix/Core.h"
#include "Phoenix/Events/WindowEvent.h"

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
		glfwSetWindowUserPointer(m_window, &m_Data);
		SetVSync(true);

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

	}

	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(m_window);
	}

	void WindowsWindow::OnUpdate() {
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