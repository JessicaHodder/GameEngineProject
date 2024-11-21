#pragma once

#include "reactphysics3d/reactphysics3d.h"
#include <glm/glm.hpp>
#include "components/transformComponent.h"
#include "core/application.h"

namespace Engine
{
	//class GeneralEventListener : public rp3d::EventListener
	//{

	//public:

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



	};
}