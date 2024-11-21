/* \file mouseEvents.h */
#pragma once


#include "event.h"
#include <glm/glm.hpp>

namespace Engine {

	class MouseEvent : public Event  //!< mouse event
	{
		virtual inline int32_t getCatagoryFlags() const override { return EventCatagoryMouse | EventCatagoryInput; }  //!< gets catagory flags
	};
	class MouseMovedEvent : public MouseEvent  //!< mouse moved event
	{
	public:
		MouseMovedEvent(float x, float y) : m_mouseX(x), m_mouseY(y) {}  //!< constuctor

		static EventType getStaticType() { return EventType::MouseMoved; }  //!< gets type
		virtual inline EventType getEventType() const override { return getStaticType(); }  //!< gets event type
		inline float getX() const { return m_mouseX; }  //!< retuns mouse x position
		inline float getY() const { return m_mouseY; }  //!< returns mouse y position
		inline glm::vec2 getPos() const { return glm::vec2(m_mouseX, m_mouseY); }  //!< returns mouse position
	private:
		float m_mouseX, m_mouseY;
	};


	class MouseScrolledEvent : public MouseEvent  //!< mouse scrolled event
	{

	public:
		MouseScrolledEvent(float xOffset, float yOffset) : m_xOffset(xOffset), m_yOffset(yOffset) {}  //!< constuctor

		static EventType getStaticType() { return EventType::MouseScrolled; }  //!< gets static type
		virtual EventType getEventType() const override { return getStaticType(); }  //!< gets event type
		inline float getXOffset() const { return m_xOffset; }  //!< retuns x offset
		inline float getYOffset() const { return m_yOffset; }  //!< retuns y offset
	private:
		float m_xOffset, m_yOffset;
		
	};

	class MouseButtonPressedEvent : public MouseEvent  //!< mouse pressed event
	{
	public:
		MouseButtonPressedEvent(int32_t button) : m_button(button) {}  //!< constuctor

		static EventType getStaticType() { return EventType::MouseButtonPressed; }  //!< gets static type
		virtual EventType getEventType() const override { return getStaticType(); }  //!< gets event type
		inline int32_t getButton() const { return m_button; }  //!< retuns the button pressed

	private:
		int32_t m_button;
	};


	class MouseButtonReleasedEvent : public MouseEvent  //!< mouse button released event
	{
	public:
		MouseButtonReleasedEvent(int32_t button) : m_button(button) {}  //!< constuctor

		static EventType getStaticType() { return EventType::MouseButtonReleased; }  //!< get static type
		virtual EventType getEventType() const override { return getStaticType(); }  //!< gets event type
		inline int32_t getButton() const { return m_button; }  //!< retuns the button pressed

	private:
		int32_t m_button;
	};
}