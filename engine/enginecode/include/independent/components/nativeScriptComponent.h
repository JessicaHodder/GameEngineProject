#pragma once

#include <memory>
#include <entt/entt.hpp>
#include "events/events.h"
#include "core/application.h"

namespace Engine 
{
	class NativeScript 
	{
	public:
		NativeScript() : m_entity(entt::null), m_registry(Application::getInstance().m_registry) {}
		NativeScript(entt::entity entity) : m_entity(entity), m_registry(Application::getInstance().m_registry) {}
		virtual void onUpdate(float timestep) = 0;
		virtual void onKeyPress(KeyPressedEvent& e) = 0;
		virtual void onCreate() {};
		virtual void onDestroy() {}; 

	protected:
		entt::registry& m_registry;
		entt::entity m_entity;
	};

	class NativeScriptComponent 
	{
	public:
		NativeScriptComponent() = default;
		~NativeScriptComponent() = default;
		void onUpdate(float timestep) { m_instance->onUpdate(timestep); }
		void onKeyPress(KeyPressedEvent& e) { m_instance->onKeyPress(e); }
		template <typename G, typename ...Args> void create(Args&& ... args)
		{
			G* ptr = new G(std::forward<Args>(args) ...);
			m_instance.reset(static_cast<NativeScript*>(ptr));
			m_instance->onCreate();
		}


	protected:
		std::shared_ptr<NativeScript> m_instance;
	};
}