#pragma once
#include "engine.h"
#include "components/nativeScriptComponent.h"
#include "components/perspectiveCameraComponent.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "core/inputPoller.h"

using namespace Engine;

class CameraScript : public Engine::NativeScript
{
public:
	CameraScript(entt::entity& entity, const glm::vec3& spawnPos) :
		NativeScript(entity), m_spawnPos(spawnPos), m_lastMousePos(Engine::InputPoller::getMousePosition())
	{}
	void onCreate() override;
	void onUpdate(float timestep) override;
	void onKeyPress(KeyPressedEvent& e) {};
protected:
	glm::vec3 m_spawnPos;
	glm::vec2 m_lastMousePos;
	float m_speed = 2.5f;

};
