#pragma once
#include "PxPCH.h"
#include "Core.h"
#include "Events\Event.h"
namespace Phoenix {

	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Phoenix Engine",
					unsigned int width = 1600,
					unsigned int height = 900)
			: Title(title), Width(width), Height(height)
		{
		}
	};
	class PX_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;
		virtual ~Window() {}

		virtual void OnUpdate() = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Windows attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;
		
		static Window* Create(const WindowProps& props = WindowProps());
	};
}