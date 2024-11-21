/** \file GLFWWindowImpl.h */
#pragma once

#include "core/window.h"
#include <GLFW/glfw3.h>

namespace Engine
{
	/** \class GLFWWindowImpl
	* Implementation of a window using GLFW
	*/

	class GLFWWindowImpl : public Window
	{
	public:
		GLFWWindowImpl(const WindowProperties& properties); //!< constructor
		virtual void init(const WindowProperties& properties) override;  //!< initalises the window
		virtual void close() override;  //!< closes the window
		//virtual ~Window() {};
		virtual void onUpdate(float timestep) override;  //!< on update
		virtual void setVSync(bool VSync) override;  //!< set if v sync is used
		virtual inline unsigned int getWidth() const override { return m_props.width; };  //!< return width
		virtual inline unsigned int getHeight() const override { return m_props.height;  };  //!< return height
		virtual inline void* getNativeWindow() const override { return m_native; };  //!< return native
		virtual inline bool isFullScreenMode() const override { return m_props.isFullScreen;  };  //!< return if window is full screen
		virtual inline bool isVSync() const override { return m_props.isVSync;  };  //!< return if v sync used

		//virtual EventHandler& getEventHandler() override { return m_eventHandler; };

	private:
		WindowProperties m_props;  //!< Properties
		GLFWwindow * m_native;  //!< NAtive GLFW Window
		float m_apsectRatio; //!< Aspect Ratio

	};

}