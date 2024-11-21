/* \file windowEvent.h */
#pragma once
#include "event.h"
#include <glm/glm.hpp>

namespace Engine
{
	class WindowCloseEvent : public Event  //!< window closed event
	{
	public:
		WindowCloseEvent() {}
		static EventType getStaticType() { return EventType::WindowClose; } //!< Return static type
		virtual inline EventType getEventType() const override { return EventType::WindowClose; }  //!< return event type
		virtual int32_t getCatagoryFlags() const override { return EventCatagoryWindow; }  //!< gets catagory flags
	};

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(int32_t width, int32_t height) : m_width(width), m_height(height) {}  //!< constructor
		static EventType getStaticType() { return EventType::WindowResize; } //!< Return static type
		virtual inline EventType getEventType() const override { return EventType::WindowResize; }  //!< return event type
		virtual int32_t getCatagoryFlags() const override { return EventCatagoryWindow; }  //!< gets catagory flags

		inline int32_t getWidth() const { return m_width; }  //!< gets width of window
		inline int32_t getHeight() const { return m_height; }  //!< gets height of window
		inline glm::ivec2 getSize() const { return { m_width, m_height }; }  //!< gets size of window
	private:
		int32_t m_width; //!< window width after resize
		int32_t m_height; //!< window height after resize
	};

	class WindowFocusEvent : public Event  //!< window focus event
	{
	public:
		WindowFocusEvent() {}  //!< constructor
		static EventType getStaticType() { return EventType::WindowFocus; }  //!< Retuns static type
		virtual inline EventType getEventType() const override { return EventType::WindowFocus; }  //!< returns event type
		virtual inline int32_t getCatagoryFlags() const override { return EventCatagoryWindow; }  //!< gets catagory flags
	};

	class WindowLostFocusEvent : public Event  //!< window lost focus event
	{
	public:
		WindowLostFocusEvent() {}  //!< constructor
		static EventType getStaticType() { return EventType::WindowLostFocus; }  //!< returns static type
		virtual inline EventType getEventType() const override { return EventType::WindowLostFocus; }  //!< returns event type
		virtual inline int32_t getCatagoryFlags() const override { return EventCatagoryWindow; }  //!< gets catagory flags
	};

	class WindowMovedEvent : public Event  //!< window moved event
	{
	public:
		WindowMovedEvent(int32_t x, int32_t y) : m_xPos(x), m_yPos(y) {}  //!< constructor
		static EventType getStaticType() { return EventType::WindowMoved; }  //!< returns static type
		virtual inline EventType getEventType() const override { return EventType::WindowMoved; }  //!< returns event type
		virtual inline int32_t getCatagoryFlags() const override { return EventCatagoryWindow; }  //!< gets catagory flags

		inline int32_t getXPos() const { return m_xPos; }  //!< retuns x position
		inline int32_t getYPos() const { return m_yPos; }  //!< returns y position
		inline glm::ivec2 getPos() const { return { m_xPos, m_yPos }; }  //!< returns position

	private:
		int32_t m_xPos;
		int32_t m_yPos;

	};
}
