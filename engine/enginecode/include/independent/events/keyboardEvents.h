/* \file keyboardEvents.h */

#pragma once

#include "event.h"

namespace Engine {

	class KeyEvent : public Event  //!< key event class
	{
	protected:
		KeyEvent(int32_t keycode) : m_keyCode(keycode) {}  //!< constuctor
		int32_t m_keyCode;
	public:
		inline int32_t getKeyCode() const { return m_keyCode;  }  //!< gets key code
		virtual inline int32_t getCatagoryFlags() const override { return EventCatagoryKeyboard | EventCatagoryInput; }  //!< gets keyboard events
	};

	class KeyPressedEvent : public KeyEvent  //!< key pressd event class
	{
	private:
		int32_t m_repeatCount;

	public:
		KeyPressedEvent(int32_t keycode, int32_t repeatCount) : KeyEvent(keycode), m_repeatCount(repeatCount) {}  //!< constuctor

		inline int32_t getRepeatCount() const { return m_repeatCount; }  //!< retuns if repeating
		static EventType getStaticType() { return EventType::KeyPressed; }  //!< gets static type
		virtual inline EventType getEventType() const override { return getStaticType(); }  //!< gets event type
	};

	class KeyReleasedEvent : public KeyEvent  //!< key released event class
	{
	public:
		KeyReleasedEvent(int32_t keycode) : KeyEvent(keycode) {}  //!< constuctor

		static EventType getStaticType() { return EventType::KeyRelease; }  //!< gets static type
		virtual inline EventType getEventType() const override { return getStaticType(); }  //!< gets event type
	};

	class KeyTypedEvent : public KeyEvent  //!< key typed event
	{
	public:
		KeyTypedEvent(int32_t keycode) : KeyEvent(keycode) {}

		static EventType getStaticType() { return EventType::KeyTyped; }  //!< gets static type
		virtual inline EventType getEventType() const override { return getStaticType(); }  //!< gets event type
	};

}


