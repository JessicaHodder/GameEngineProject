/** \file application.cpp
*/

#include "engine_pch.h"
#include <glad/glad.h>
#include "core/application.h"

#ifdef NG_PLATFORM_WINDOWS
#include "platform/GLWF/GLFWSystem.h"
#endif

//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "rendering/indexBuffer.h"
#include "platform/OpenGL/OpenGLVertexArray.h"
#include "platform/OpenGL/OpenGLShader.h"

#include "platform/OpenGL/OpenGLTexture.h"

#include "rendering/Renderer3D.h"
#include "rendering/Renderer2D.h"





namespace Engine {
	// Set static vars
	Application* Application::s_instance = nullptr;

	Application::Application()  //!< application constructor
	{
		if (s_instance == nullptr)
		{
			s_instance = this;  //!< sets the current instance to this instance
		}


		// start of log
		m_logSystem.reset(new Log);
		m_logSystem->start();  //!< starts the log system

		

		// start window system
#ifdef NG_PLATFORM_WINDOWS
		m_windowsSystem.reset(new GLFWSystem);

#endif
		m_windowsSystem->start(); //!< start window system

		//m_physicsSystem.reset(new PhysicsSystem);
		//m_physicsSystem->start();

		
		m_WorldSettings.gravity = rp3d::Vector3(0, -9.81f, 0);
		m_world = m_rp3dCommon.createPhysicsWorld(m_WorldSettings);
		
		
		//m_world->setEventListener(&m_eventListener);

		//reset timer
		m_timer.reset(new ChronoTimer);
		m_timer->start();  //!< start the timer

		WindowProperties props("My Game Engine", 1024, 800);  //!< sets the window properties
		m_window.reset(Window::create(props));

		m_window->getEventHandler().setOnCloseCallback(std::bind(&Application::onClose, this, std::placeholders::_1));  //!< Following lines of code sets veriouse event handler functions for window
		m_window->getEventHandler().setOnResizeCallback(std::bind(&Application::onResize, this, std::placeholders::_1));
		m_window->getEventHandler().setOnWindowMovedCallback(std::bind(&Application::onMove, this, std::placeholders::_1));
		m_window->getEventHandler().setOnFocusCallback(std::bind(&Application::onFocus, this, std::placeholders::_1));
		m_window->getEventHandler().setOnLostFocusCallback(std::bind(&Application::onLooseFocus, this, std::placeholders::_1));


		m_window->getEventHandler().setOnKeyPressedCallback(std::bind(&Application::onKeyPressed, this, std::placeholders::_1));  //!< Following lines of code sets veriouse event handler functions for input
		m_window->getEventHandler().setOnKeyReleasedCallback(std::bind(&Application::onKeyReleased, this, std::placeholders::_1));
		m_window->getEventHandler().setOnButtonPressedCallback(std::bind(&Application::onMousePressed, this, std::placeholders::_1));
		m_window->getEventHandler().setOnButtonReleasedCallback(std::bind(&Application::onMouseRelease, this, std::placeholders::_1));
		m_window->getEventHandler().setOnMouseMovedCallback(std::bind(&Application::onMouseMoved, this, std::placeholders::_1));
		
		InputPoller::setNativeWindow(m_window->getNativeWindow());  //!< sets the native pointer for the input pointer

		Renderer3D::init();  //!< initalises 3D renderer
		Renderer2D::init();  //!< initalises 2D renderer

		m_timer->reset();
	}

	bool Application::onClose(WindowCloseEvent & e)  //!< on close event
	{
		e.handle(true);
		m_running = false;
		return e.handled();
		//return true;
	}

	bool Application::onResize(WindowResizeEvent& e)  //!< on resize event
	{
		e.handle(true);
		auto& size = e.getSize();
		//Log::info("Window Resize event: ({0}, {1})", size.x, size.y);
		return e.handled();
	}

	bool Application::onMove(WindowMovedEvent& e)  //!< on move event
	{
		e.handle(true);
		auto& pos = e.getPos();
		//Log::info("Window Move event: ({0}, {1})", pos.x, pos.y);
		return e.handled();
	}

	bool Application::onFocus(WindowFocusEvent& e)  //!< on window focus event
	{
		e.handle(true);
		//Log::info("Window Focused");
		return e.handled();
	}

	bool Application::onLooseFocus(WindowLostFocusEvent& e)  //!< on window lost focus event
	{
		e.handle(true);
		//Log::info("Window Lost Focused");
		return e.handled();
	}

	bool Application::onKeyPressed(KeyPressedEvent& e)  //!< on key pressed event
	{
		e.handle(true);
		//Log::info("Key pressed event: key: {0}, repeat: {1}", e.getKeyCode(), e.getRepeatCount());
		if (e.getKeyCode() == NG_KEY_SPACE) Log::info("Key is Space");
		return e.handled();
	}

	bool Application::onKeyReleased(KeyReleasedEvent& e)  //!< on key pressed event
	{
		e.handle(true);
		//Log::info("Key pressed event: key: {0}", e.getKeyCode());
		if (e.getKeyCode() == NG_KEY_UP) Log::info("UP released");
		return e.handled();
	}

	bool Application::onMousePressed(MouseButtonPressedEvent& e)  //!< on mouse button pressed event
	{
		e.handle(true);
		//Log::info("Mouse pressed event: key: {0}", e.getButton());
		return e.handled();
	}

	bool Application::onMouseRelease(MouseButtonReleasedEvent& e)  //!< on mouse button released event
	{
		e.handle(true);
		//Log::info("Mouse Released event: key: {0}", e.getButton());
		return e.handled();
	}

	bool Application::onMouseMoved(MouseMovedEvent& e)  //!< on mouse moved event
	{
		e.handle(true);
		auto& pos = e.getPos();
		//Log::info("Mouse Move event: ({0}, {1})", pos.x, pos.y);
		return e.handled();
	}

	Application::~Application()  //!< application destructor
	{


		// stop physics system
		//m_physicsSystem->stop();
		m_rp3dCommon.destroyPhysicsWorld(m_world);

		// stop logger system
		m_logSystem->stop();
		// stop windows system
		m_windowsSystem->stop();
		
		
		
		
	}


	void Application::run()  //!< application run function
	{

		float m_timestep = 0.f;  //!< creats timestep float

		

		while (m_running)  //!< while the program is running
		{
			m_timestep = m_timer->getElapsedTime();  //!< sets time step as timer
			//Log::info("Hello world {0} {1}", 42, "A string");
			m_timer->reset();

			//m_physicsSystem->m_world->update(m_timestep);
			m_world->update(m_timestep);

			m_layerStack.onUpdate(m_timestep);
			m_layerStack.onRender();

			m_window->onUpdate(m_timestep);  //!< updates time step


			
		};

	}

}
