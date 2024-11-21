/* \ file inputPoller.h */

#include <glm/glm.hpp>
#pragma once


namespace Engine
{
	/* \ class InputPoller
	* API agnostic input poller for getting current keyboard and mouse state
	*/

	class InputPoller
	{
	public:
		static bool isKeyPressed(int32_t keyCode); //!< is the key pressed
		static bool isMouseButtonPressed(int32_t mouseButton); //!< is mouse button pressed
		static glm::vec2 getMousePosition(); //!< current mouse position
		static void setNativeWindow(void* nativWin);  //!< sets the native window
		inline static float getMouseX() { return getMousePosition().x; }  //!< returns the mouse x position
		inline static float getMousey() { return getMousePosition().y; }  //!< returns the mouse y position
	};

}
