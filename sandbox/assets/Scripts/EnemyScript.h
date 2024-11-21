#pragma once
#include "engine.h"
#include "components/nativeScriptComponent.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "core/inputPoller.h"

using namespace Engine;

class EnemyScript : public Engine::NativeScript
{
public:
	EnemyScript(entt::entity& entity) : NativeScript(entity) {}

	void onUpdate(float timestep) override;
	void onKeyPress(KeyPressedEvent& e) {};

protected:
	float m_FBspeed = 2.5f;
	float m_LRspeed = 1.7f;
	float m_rotSpeed = 1.5f;

	bool m_WallHit = false;
	bool m_GoBack = false;

	bool m_FirstTimeSpawn = false;

	bool m_upDown;

	rp3d::Vector3 m_DefaultPosition;
	rp3d::Quaternion m_DefaultRotation;



	//rp3d::Transform m_DefaultTransform;

};