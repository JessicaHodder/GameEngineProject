/* \file inputPoller.cpp */
#include "engine_pch.h"
#include "core/inputPoller.h"

#ifdef NG_PLATFORM_WINDOWS
#include "platform/GLWF/GLFWInputPoller.h"

#endif

namespace Engine
{
#ifdef NG_PLATFORM_WINDOWS
	bool InputPoller::isKeyPressed(int32_t keyCode)
	{
		return GLFWInputPoller::isKeyPressed(keyCode);
	}

	bool InputPoller::isMouseButtonPressed(int32_t mouseButton)
	{
		return GLFWInputPoller::isMouseButtonPressed(mouseButton);
	}

	glm::vec2 InputPoller::getMousePosition()
	{
		return GLFWInputPoller::getMousePosition();
	}

	void InputPoller::setNativeWindow(void* nativWin)
	{
		GLFWInputPoller::setCurrentWindow(reinterpret_cast<GLFWwindow*>(nativWin));

	}
#endif
}