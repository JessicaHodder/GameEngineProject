#pragma once

#include "reactphysics3d/reactphysics3d.h"
#include <glm/glm.hpp>
#include "components/transformComponent.h"
#include "components/PlayerComponent.h"
#include "components/EnemyComponent.h"
#include "components/WallComponent.h"
#include "components/CheckPointComponent.h"
#include "components/buttonComponent.h"
#include "components/GoalComponent.h"
#include "core/application.h"

namespace Engine
{


	class RigidBodyComponent
	{
	public:
		RigidBodyComponent(entt::entity entity, rp3d::BodyType bodyType)
		{
			auto& tc = Application::getInstance().m_registry.get<TransformComponent>(entity);
			rp3d::Vector3 rpPos(tc.translation.x, tc.translation.y, tc.translation.z);
			rp3d::Quaternion rpRot(tc.rotation.x, tc.rotation.y, tc.rotation.z, tc.rotation.w);
			rp3d::Transform rpt(rpPos, rpRot);
			m_body = Application::getInstance().m_world->createRigidBody(rpt);
			m_body->setType(bodyType);
			m_body->setUserData((void*)entt::to_integral(entity));
		}
		rp3d::RigidBody* m_body;
	};


	class BoxColliderComponent
	{
	public:
		BoxColliderComponent(entt::entity entity, glm::vec3 halfExtents, bool isTrigger)
		{
			auto body = Application::getInstance().m_registry.get<RigidBodyComponent>(entity).m_body;
			shape = Application::getInstance().m_rp3dCommon.createBoxShape(rp3d::Vector3(halfExtents.x, halfExtents.y, halfExtents.z));
			collider = body->addCollider(shape, rp3d::Transform::identity());
			collider->setIsTrigger(isTrigger);
		}
		
		rp3d::BoxShape* shape;
		rp3d::Collider* collider = nullptr;
	};




	class GeneralEventListener : public rp3d::EventListener 
	{		

		virtual void onContact(const CollisionCallback::CallbackData& callbackData) override 
		{
			auto& registry = Application::getInstance().m_registry;
			auto& entities = Application::getInstance().m_entities;
			auto world = Application::getInstance().m_world;

			// For each contact pair 
			for (uint32_t p = 0; p < callbackData.getNbContactPairs(); p++) 
			{
				CollisionCallback::ContactPair contactPair = callbackData.getContactPair(p);

				uint32_t index1 = reinterpret_cast<uint32_t>(contactPair.getBody1()->getUserData()); 
				uint32_t index2 = reinterpret_cast<uint32_t>(contactPair.getBody2()->getUserData());

				//std::cout << index1 << " " << index2 << std::endl;

				
				entt::entity entity1 = entities[index1];
				entt::entity entity2 = entities[index2];

				bool isPlayer1 = registry.all_of<PlayerComponent>(entity1); 
				bool isEnemy1 = registry.all_of<EnemyComponent>(entity1); 
				bool isWall1 = registry.all_of<WallComponent>(entity1);
				bool isCheckPoint1 = registry.all_of<CheckPointComponent>(entity1);
				bool isGoal1 = registry.all_of<GoalComponent>(entity1);
				bool isButton1 = registry.all_of<buttonComponent>(entity1);

				bool isPlayer2 = registry.all_of<PlayerComponent>(entity2); 
				bool isEnemy2 = registry.all_of<EnemyComponent>(entity2); 
				bool isWall2 = registry.all_of<WallComponent>(entity2);
				bool isCheckPoint2 = registry.all_of<CheckPointComponent>(entity2);
				bool isGoal2 = registry.all_of<GoalComponent>(entity2);
				bool isButton2 = registry.all_of<buttonComponent>(entity2);


				
				//player hitting enemy detection
				if (isPlayer1 && isEnemy2) 
				{
					//std::cout << "Enemy detected!" << std::endl;
					auto& pc = registry.get<PlayerComponent>(entity1);
					pc.enemyHit = true;

					auto& ec = registry.get<EnemyComponent>(entity2);
					ec.playerHit = true;

					//add 1 to deaths counter for UI display

				}
				if (isPlayer2 && isEnemy1)
				{
					// entity 2 is player
					auto& pc = registry.get<PlayerComponent>(entity2);
					pc.enemyHit = true;

					auto& ec = registry.get<EnemyComponent>(entity1);
					ec.playerHit = true;
				}

				//enemy wall detection

				if (isEnemy1 && isWall2)
				{
					auto& ec = registry.get<EnemyComponent>(entity1);
					ec.wallHit = true;
				}

				if (isEnemy2 && isWall1)
				{
					auto& ec = registry.get<EnemyComponent>(entity2);
					ec.wallHit = true;
				}

				//player checkpoint detection

				if (isPlayer1 && isCheckPoint2)
				{
					auto& pc = registry.get<PlayerComponent>(entity1);
					pc.newSpawnPos = registry.get<CheckPointComponent>(entity2).checkPointPos;
					pc.checkPointSet = true;
					
				}
				
				if (isPlayer2 && isCheckPoint1)
				{
					auto& pc = registry.get<PlayerComponent>(entity2);
					pc.newSpawnPos = registry.get<CheckPointComponent>(entity1).checkPointPos;
					pc.checkPointSet = true;
				}

				//player goal detection

				if (isPlayer1 && isGoal2)
				{
					auto& pc = registry.get<PlayerComponent>(entity1);
					pc.goalReached = true;
					
				}

				if (isPlayer2 && isGoal1)
				{
					auto& pc = registry.get<PlayerComponent>(entity2);
					pc.goalReached = true;

				}

				if (isPlayer1 && isButton2)
				{
					auto& bc = registry.get<buttonComponent>(entity2);
					bc.isPressed = true;
					

				}

				if (isPlayer2 && isButton1)
				{
					auto& bc = registry.get<buttonComponent>(entity1);
					bc.isPressed = true;
					

				}


			}
		}

		

	};


}