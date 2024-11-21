/** \file application.h
*/
#pragma once

#include "systems/log.h"
#include "timer.h"
//#include "systems/physics.h"
#include "reactphysics3d/reactphysics3d.h"
//#include "systems/GeneralEventListener.h"

#include "events/events.h"
//#include "events/eventHandler.h"

#include "core/window.h"
#include "core/inputPoller.h"
#include "core/layerStack.h"

#include "entt/entt.hpp"



namespace Engine {

	/**
	\class Application
	Fundemental class of the engine. A singleton which runs the game loop infinitely.
	Provides ...
	*/

	class Application
	{
	protected:
		Application(); //!< Constructor

		std::shared_ptr<Log> m_logSystem; //!< Log system
		std::shared_ptr<System> m_windowsSystem; //!< Windows system

		//std::shared_ptr<PhysicsSystem> m_physicsSystem; //!< Physics system
		//std::shared_ptr<GeneralEventListener> m_eventListener;
		

		std::shared_ptr<Window> m_window; //!< Window
		std::shared_ptr<Timer> m_timer; //!< Timer

		//EventHandler m_handler; //!< EventHandler

		

		//layerStack stuff

		LayerStack m_layerStack;


		bool onClose(WindowCloseEvent& e);
		bool onResize(WindowResizeEvent& e); //!< run when window resized
		bool onMove(WindowMovedEvent& e);
		bool onFocus(WindowFocusEvent& e);
		bool onLooseFocus(WindowLostFocusEvent& e);

		bool onKeyPressed(KeyPressedEvent& e);
		bool onKeyReleased(KeyReleasedEvent& e);
		bool onMousePressed(MouseButtonPressedEvent& e);
		bool onMouseRelease(MouseButtonReleasedEvent& e);
		bool onMouseMoved(MouseMovedEvent& e);

	private:
		static Application* s_instance; //!< Singleton instance of the application
		bool m_running = true; //!< Is the application running?
		
		
	public:
		virtual ~Application(); //!< Deconstructor
		inline static Application& getInstance() { return *s_instance; } //!< Instance getter from singleton pattern
		inline std::shared_ptr<Window>& getWindow() { return m_window; }
		void run(); //!< Main loop

		entt::registry m_registry;
		std::vector<entt::entity> m_entities;

		//reactphysics3d::PhysicsWorld* world;
		//reactphysics3d::PhysicsCommon* physCommon;

		rp3d::PhysicsWorld* m_world; //!< World
		rp3d::PhysicsWorld::WorldSettings m_WorldSettings;
		rp3d::PhysicsCommon m_rp3dCommon;
		
		//GeneralEventListener m_eventListener;

	};

	// To be defined in users code
	Application* startApplication(); //!< Function definition which provides an entry hook
}