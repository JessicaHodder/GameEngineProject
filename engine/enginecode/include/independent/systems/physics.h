#pragma once

#include <systems/system.h>
#include <glm/glm.hpp>
#include "components/transformComponent.h"
#include "core/application.h"

namespace Engine 
{
	class PhysicsSystem : public System 
	{
	public:

		void start(SystemSignal init = SystemSignal::None, ...) override 
		{
			//m_world = m_rp3dCommon.createPhysicsWorld();
		}

		void stop(SystemSignal close = SystemSignal::None, ...) override
		{
			//m_rp3dCommon.destroyPhysicsWorld(m_world);
		}

		//rp3d::PhysicsWorld* m_world; //!< World
		//rp3d::PhysicsCommon m_rp3dCommon;

	private:
		
	};

	//class GeneralEventListener : public rp3d::EventListener
	//{

	//	virtual void onContact(const CollisionCallback::CallbackData& callbackData) override
	//	{
	//		auto& registry = Application::getInstance().m_registry;
	//		auto& entities = Application::getInstance().m_entities;
	//		auto world = Application::getInstance().m_world;

	//		// For each contact pair 
	//		for (uint32_t p = 0; p < callbackData.getNbContactPairs(); p++)
	//		{
	//			CollisionCallback::ContactPair contactPair = callbackData.getContactPair(p);

	//			uint32_t index1 = reinterpret_cast<uint32_t>(contactPair.getBody1()->getUserData()); //maybe set user data
	//			uint32_t index2 = reinterpret_cast<uint32_t>(contactPair.getBody2()->getUserData());

	//			//might need a different strategy for getting entities or add current entities into the entities vector
	//			entt::entity entity1 = entities[index1];
	//			entt::entity entity2 = entities[index2];

	//			bool isPlayer1 = registry.all_of<TransformComponent>(entity1); //swap transform for playerComponent, emplace new components onto player and enemy objects respectivly
	//			bool isEnemy1 = registry.all_of<TransformComponent>(entity1); //swap transform for enemyComponent

	//			bool isPlayer2 = registry.all_of<TransformComponent>(entity2); //swap transform for playerComponent
	//			bool isEnemy2 = registry.all_of<TransformComponent>(entity2); //swap transform for enemyComponent


	//			if ((isPlayer1 && isEnemy2) || (isPlayer2 && isEnemy1))
	//			{
	//				std::cout << "Enemy detected!" << std::endl;
	//				//cause player to go back to respawn point
	//				//add 1 to deaths counter for UI display
	//			}

	//		}
	//	}



	//};

}