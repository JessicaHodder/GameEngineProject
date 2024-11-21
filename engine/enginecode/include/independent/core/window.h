/* \file window.h */
#pragma once

#include "events/eventHandler.h"
#include "core/graphicsContext.h"
namespace Engine
{
	/** \class Window
	* Abstract windows nase class. All implemented windwos should code to this interface
	*/


	struct WindowProperties  //!< sets window properties
	{
		char* title;
		uint32_t width;
		uint32_t height;
		bool isFullScreen;
		bool isVSync;

		WindowProperties(char* title = "My Window", uint32_t width = 800, uint32_t height = 600, bool fullscreen = false) : title(title), width(width), height(height), isFullScreen(fullscreen) {}

	};

	class Window
	{
	public:
		virtual void init(const WindowProperties& properties) = 0;  //!< initalises the window
		virtual void close() = 0;  //!< closes the window
		virtual ~Window() {};  //!< destructor
		virtual void onUpdate(float timestep) = 0;  //!< on update
		virtual void setVSync(bool VSync) = 0;  //!< sets to enable or diable v sync
		virtual unsigned int getWidth() const = 0;  //!< gets width of window
		virtual unsigned int getHeight() const = 0;  //!< gets height of window
		virtual void* getNativeWindow() const = 0;  //!< gets native window
		virtual bool isFullScreenMode() const = 0;  //!< checks if window is full screen
		virtual bool isVSync() const = 0;  //!< gets if v sync is enabled

		inline EventHandler& getEventHandler() { return m_handler; };  //!< gets the event handler

		static Window* create(const WindowProperties& properties = WindowProperties());  //!< creats new window

	protected:

		EventHandler m_handler; //!< Event handler
		std::shared_ptr<GraphicsContext> m_graphicsContext;  //!< graphics context

	};
}
