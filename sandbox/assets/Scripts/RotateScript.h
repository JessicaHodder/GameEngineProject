#pragma once

#include "engine.h"

class RotateScript : public Engine::NativeScript
{
public:
	RotateScript(entt::entity entity, float s) : NativeScript(entity), speed(s) {};
	virtual void onUpdate(float timestep)
	{
		auto& tc = m_registry.get<Engine::TransformComponent>(m_entity);
		tc.addRotation(glm::vec3(0.f, speed * timestep, 0.f));
		tc.recalc();
	};
	virtual void onKeyPress(Engine::KeyPressedEvent& e) {};
private:
	float speed = 0;
};
