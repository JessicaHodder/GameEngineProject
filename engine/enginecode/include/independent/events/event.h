/* \file event.h */
#pragma once

#include <intTypes.h>
namespace Engine
{
	/** \enum EventType
	* An enum for event types */

	enum class EventType  //!< list of event types
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved, 
		KeyPressed, KeyRelease, KeyTyped, MouseButtonPressed, MouseButtonReleased, 
		MouseMoved, MouseScrolled
	};

	/** \enum EventCatagory
	* Enum for type catagory flags
	*/
	enum EventCatagory  
	{
		// bit patterns
		None = 0,
		EventCatagoryWindow = 1 << 0, // 00000001
		EventCatagoryInput = 1 << 1, // 00000010
		EventCatagoryKeyboard = 1 << 2, // 00000100
		EventCatagoryMouse = 1 << 3, // 00001000
		EventCatagoryMouseButton = 1 << 4 // 00010000
	};

	/**
	* \class Event
	* Event base class
	*/

	class Event
	{
	public:
		virtual EventType getEventType() const = 0; //!< Get the event type
		virtual int32_t getCatagoryFlags() const = 0; //!< get catagory flags
		inline bool handled() const { return m_handled; }  //!< has the event been handled
		inline void handle(bool isHandled) { m_handled = isHandled; }  //!< Handle the event
		inline bool isInCatagory(EventCatagory catagory) const { return getCatagoryFlags() & catagory; }  //!< Event in catagory

	protected:
		bool m_handled = false;  //!< has the event been handled
	};
}