#include "CameraScript.h"


void CameraScript::onCreate()
{
	Engine::PerspectiveCameraProps camProps;
	//camProps.size = Application::getInstance().getWindow()->getNativeWindow();

	m_registry.emplace<Engine::TransformComponent>(m_entity, m_spawnPos, glm::vec3(-0.5f, 0.0f, 0.0f), glm::vec3(1.f, 1.f, 1.f));
	auto& tc = m_registry.get<Engine::TransformComponent>(m_entity);
	m_registry.emplace<Engine::PerspectiveCameraComponent>(m_entity, tc.transform, camProps);

}

void CameraScript::onUpdate(float timestep)
{
	//move camera 
	auto& tc = m_registry.get<Engine::TransformComponent>(m_entity);
	glm::mat4& transform = tc.transform;
	glm::vec3 right = { transform[0][0], transform[0][1], transform[0][2] };
	glm::vec3 up = { transform[1][0], transform[1][1], transform[1][2] };
	glm::vec3 forward = { -transform[2][0], -transform[2][1], transform[2][2] };

	//strafe for camera 
	if (Engine::InputPoller::isKeyPressed(NG_KEY_LEFT)) tc.translation -= (right * m_speed * timestep);  //strafe left
	if (Engine::InputPoller::isKeyPressed(NG_KEY_RIGHT)) tc.translation += (right * m_speed * timestep);  //strafe right
	if (Engine::InputPoller::isKeyPressed(NG_KEY_UP)) tc.translation -= (forward * m_speed * timestep);  
	if (Engine::InputPoller::isKeyPressed(NG_KEY_DOWN)) tc.translation += (forward * m_speed * timestep);  

	tc.recalc();

	auto& cameraProp = m_registry.get<Engine::PerspectiveCameraComponent>(m_entity);
	cameraProp.view = glm::inverse(tc.transform);
}

