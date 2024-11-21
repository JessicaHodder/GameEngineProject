/* \file GLFWWindowImpl.cpp*/


#include "engine_pch.h"

#include "platform/GLWF/GLFWWindowImpl.h"
#include "platform/GLWF/GLFW_OpenGL_GC.h"
#include "systems/log.h"

namespace Engine {

#ifdef NG_PLATFORM_WINDOWS
	Window* Window::create(const WindowProperties& properties)
	{
		return new GLFWWindowImpl(properties);
	}
#endif

	GLFWWindowImpl::GLFWWindowImpl(const WindowProperties& properties)
	{
		init(properties);
	}
	void GLFWWindowImpl::init(const WindowProperties& properties)
	{
		m_props = properties;

		m_apsectRatio = static_cast<float>(m_props.width) / static_cast<float>(m_props.height);

		if (m_props.isFullScreen)
		{
			Log::error("Fullscreen not yet implemented");
		}
		else
		{
			m_native = glfwCreateWindow(m_props.width, m_props.height, m_props.title, nullptr, nullptr);
		}

		m_graphicsContext.reset(new GLFW_OpenGL_GC(m_native));
		m_graphicsContext->init();

		glfwSetWindowUserPointer(m_native, static_cast<void*>(&m_handler));

		glfwSetWindowCloseCallback(m_native,
			[](GLFWwindow * window)
			{
				EventHandler* handler = static_cast<EventHandler*>(glfwGetWindowUserPointer(window));
				auto& onClose = handler->getOnCloseFunction();

				WindowCloseEvent e;
				onClose(e);
			}
			);

		glfwSetWindowSizeCallback(m_native,
			[](GLFWwindow * window, int newWidth, int newHeight)
			{
				EventHandler* handler = static_cast<EventHandler*>(glfwGetWindowUserPointer(window));
				auto& onResize = handler->getOnResizeFunction();

				WindowResizeEvent e(newWidth, newHeight);
				onResize(e);
			}
			);


		glfwSetWindowPosCallback(m_native,
			[](GLFWwindow* window, int newPosX, int newPosY)
			{
				EventHandler* handler = static_cast<EventHandler*>(glfwGetWindowUserPointer(window));
				auto& onMove = handler->getOnWindowMovedFunction();

				WindowMovedEvent e(newPosX, newPosY);
				onMove(e);
			}
			);

		glfwSetWindowFocusCallback(m_native,
			[](GLFWwindow* window, int focus)
			{
				EventHandler* handler = static_cast<EventHandler*>(glfwGetWindowUserPointer(window));

				if (focus == GLFW_FOCUSED)
				{
					auto& onFocus = handler->getOnFocusFunction();

					WindowFocusEvent e;
					onFocus(e);
				}
				else if (focus != GLFW_FOCUSED)
				{
					auto& onLooseFocus = handler->getOnLostFocusFunction();

					WindowLostFocusEvent e;
					onLooseFocus(e);
				}
			}
			);





		glfwSetKeyCallback(m_native,
			[](GLFWwindow* window, int keyCode, int scancode, int action, int mods)
			{
				EventHandler* handler = static_cast<EventHandler*>(glfwGetWindowUserPointer(window));

				if (action == GLFW_PRESS)
				{
					auto& onKeyPress = handler->getOnKeyPressedFunction();

					KeyPressedEvent e(keyCode, 0);
					onKeyPress(e);
				}
				else if (action == GLFW_REPEAT)
				{
					auto& onKeyPress = handler->getOnKeyPressedFunction();

					KeyPressedEvent e(keyCode, 1);
					onKeyPress(e);
				}
				else if (action == GLFW_RELEASE)
				{
					auto& onKeyRelease = handler->getOnKeyReleasedFunction();

					KeyReleasedEvent e(keyCode);
					onKeyRelease(e);
				}
			}
		
			);

		glfwSetMouseButtonCallback(m_native,
			[](GLFWwindow* window, int keycode, int scancode, int action)
			{
				EventHandler* handler = static_cast<EventHandler*>(glfwGetWindowUserPointer(window));

				if (action == GLFW_PRESS)
				{
					auto& onMouseClick = handler->getOnButtonPressedFunction();

					MouseButtonPressedEvent e(keycode);
					onMouseClick(e);
				}
				else if (action == GLFW_RELEASE)
				{
					auto& onMouseRelease = handler->getOnButtonReleasedFunction();

					MouseButtonReleasedEvent e(keycode);
					onMouseRelease(e);
				}
			}
			);

		glfwSetCursorPosCallback(m_native,
			[](GLFWwindow* window, double newPosX, double newPosY)
			{
				EventHandler* handler = static_cast<EventHandler*>(glfwGetWindowUserPointer(window));
				auto& onMouseMove = handler->getOnMouseMovedFunction();

				MouseMovedEvent e(newPosX, newPosY);
				onMouseMove(e);
			}

		);






	}
	void GLFWWindowImpl::close()
	{
		glfwDestroyWindow(m_native);
	}
	void GLFWWindowImpl::onUpdate(float timestep)
	{
		glfwPollEvents();
		m_graphicsContext->swapBuffers();
	}
	void GLFWWindowImpl::setVSync(bool VSync)
	{
		m_props.isVSync = VSync;
		if (VSync)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}

		
	}
}