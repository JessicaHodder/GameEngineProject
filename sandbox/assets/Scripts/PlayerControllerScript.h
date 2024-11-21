#pragma once
#include "engine.h"
#include "components/nativeScriptComponent.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "core/inputPoller.h"

using namespace Engine;

class PlayerControllerScript : public Engine::NativeScript
{
public:
	PlayerControllerScript(entt::entity& entity) : NativeScript(entity) 
	{
		respawnPos = rp3d::Vector3(-25.0f, -1.0f, 20.0f);
	}

	void onUpdate(float timestep) override;
	void onKeyPress(KeyPressedEvent& e) {};

	rp3d::Vector3 respawnPos;

protected:
	float m_FBspeed = 2.5f;
	float m_LRspeed = 1.7f;
	float m_rotSpeed = 1.5f;

	int deathCounter = 0;

};