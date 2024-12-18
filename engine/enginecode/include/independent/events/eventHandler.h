/* \file events.h */
#pragma once
#include "events.h"
#include <functional>

//  
//KeyPressed, KeyRelease, KeyTyped, MouseButtonPRessed, MouseButtonReleased,
//MouseMoved, MouseScrolled

namespace Engine
{

	class EventHandler  //!< sets each event for event handler
	{
	public:
		void setOnCloseCallback(const std::function<bool(WindowCloseEvent&)>& fn) { m_onCloseFunction = fn; };
		void setOnResizeCallback(const std::function<bool(WindowResizeEvent&)>& fn) { m_onResizeFunction = fn; };
		void setOnFocusCallback(const std::function<bool(WindowFocusEvent&)>& fn) { m_onFocusFunction = fn; };
		void setOnLostFocusCallback(const std::function<bool(WindowLostFocusEvent&)>& fn) { m_onLostFocusFunction = fn; };
		void setOnWindowMovedCallback(const std::function<bool(WindowMovedEvent&)>& fn) { m_onWindowMovedFunction = fn; };
		void setOnKeyPressedCallback(const std::function<bool(KeyPressedEvent&)>& fn) { m_onKeyPressedFunction = fn; };
		void setOnKeyReleasedCallback(const std::function<bool(KeyReleasedEvent&)>& fn) { m_onKeyReleasedFunction = fn; };
		void setOnKeyTypedCallback(const std::function<bool(KeyTypedEvent&)>& fn) { m_onKeyTypedFunction = fn; };
		void setOnButtonPressedCallback(const std::function<bool(MouseButtonPressedEvent&)>& fn) { m_onMouseDownFunction = fn; };
		void setOnButtonReleasedCallback(const std::function<bool(MouseButtonReleasedEvent&)>& fn) { m_onMouseUpFunction = fn; };
		void setOnMouseMovedCallback(const std::function<bool(MouseMovedEvent&)>& fn) { m_onMouseMovedFunction = fn; };
		void setOnMouseWheelCallback(const std::function<bool(MouseScrolledEvent&)>& fn) { m_onMouseWheelFunction = fn; };
		

		std::function<bool(WindowCloseEvent&)>& getOnCloseFunction() { return m_onCloseFunction; }
		std::function<bool(WindowResizeEvent&)>& getOnResizeFunction() { return m_onResizeFunction; }
		std::function<bool(WindowFocusEvent&)>& getOnFocusFunction() { return m_onFocusFunction; }
		std::function<bool(WindowLostFocusEvent&)>& getOnLostFocusFunction() { return m_onLostFocusFunction; }
		std::function<bool(WindowMovedEvent&)>& getOnWindowMovedFunction() { return m_onWindowMovedFunction; }
		std::function<bool(KeyPressedEvent&)>& getOnKeyPressedFunction() { return m_onKeyPressedFunction; }
		std::function<bool(KeyReleasedEvent&)>& getOnKeyReleasedFunction() { return m_onKeyReleasedFunction; }
		std::function<bool(KeyTypedEvent&)>& getOnKeyTypedFunction() { return m_onKeyTypedFunction; }
		std::function<bool(MouseButtonPressedEvent&)>& getOnButtonPressedFunction() { return m_onMouseDownFunction; }
		std::function<bool(MouseButtonReleasedEvent&)>& getOnButtonReleasedFunction() { return m_onMouseUpFunction; }
		std::function<bool(MouseMovedEvent&)>& getOnMouseMovedFunction() { return m_onMouseMovedFunction; }
		std::function<bool(MouseScrolledEvent&)>& getOnMouseWheelFunction() { return m_onMouseWheelFunction; }

	private:
		std::function<bool(WindowCloseEvent&)> m_onCloseFunction = std::bind(&EventHandler::defaultOnClose, this, std::placeholders::_1);
		std::function<bool(WindowResizeEvent&)> m_onResizeFunction = std::bind(&EventHandler::defaultOnResize, this, std::placeholders::_1);
		std::function<bool(WindowFocusEvent&)> m_onFocusFunction = std::bind(&EventHandler::defaultOnFocus, this, std::placeholders::_1);
		std::function<bool(WindowLostFocusEvent&)> m_onLostFocusFunction = std::bind(&EventHandler::defaultOnLostFocus, this, std::placeholders::_1);
		std::function<bool(WindowMovedEvent&)> m_onWindowMovedFunction = std::bind(&EventHandler::defaultOnWindowMoved, this, std::placeholders::_1);
		std::function<bool(KeyPressedEvent&)> m_onKeyPressedFunction = std::bind(&EventHandler::defaultOnKeyPressed, this, std::placeholders::_1);
		std::function<bool(KeyReleasedEvent&)> m_onKeyReleasedFunction = std::bind(&EventHandler::defaultOnKeyReleased, this, std::placeholders::_1);
		std::function<bool(KeyTypedEvent&)> m_onKeyTypedFunction = std::bind(&EventHandler::defaultOnKeyTyped, this, std::placeholders::_1);
		std::function<bool(MouseButtonPressedEvent&)> m_onMouseDownFunction = std::bind(&EventHandler::defaultOnMouseDown, this, std::placeholders::_1);
		std::function<bool(MouseButtonReleasedEvent&)> m_onMouseUpFunction = std::bind(&EventHandler::defaultOnMouseUp, this, std::placeholders::_1);
		std::function<bool(MouseMovedEvent&)> m_onMouseMovedFunction = std::bind(&EventHandler::defaultOnMouseMoved, this, std::placeholders::_1);
		std::function<bool(MouseScrolledEvent&)> m_onMouseWheelFunction = std::bind(&EventHandler::defaultOnMouseWheel, this, std::placeholders::_1);

		bool defaultOnClose(WindowCloseEvent& e) { return false; }
		bool defaultOnResize(WindowResizeEvent& e) { return false; }
		bool defaultOnFocus(WindowFocusEvent& e) { return false; }
		bool defaultOnLostFocus(WindowLostFocusEvent& e) { return false; }
		bool defaultOnWindowMoved(WindowMovedEvent& e) { return false; }
		bool defaultOnKeyPressed(KeyPressedEvent& e) { return false; }
		bool defaultOnKeyReleased(KeyReleasedEvent& e) { return false; }
		bool defaultOnKeyTyped(KeyTypedEvent& e) { return false; }
		bool defaultOnMouseDown(MouseButtonPressedEvent& e) { return false; }
		bool defaultOnMouseUp(MouseButtonReleasedEvent& e) { return false; }
		bool defaultOnMouseMoved(MouseMovedEvent& e) { return false; }
		bool defaultOnMouseWheel(MouseScrolledEvent& e) { return false; }
	};
}