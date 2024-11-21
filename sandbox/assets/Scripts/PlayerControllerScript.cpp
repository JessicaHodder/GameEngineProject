#include "PlayerControllerScript.h"



void PlayerControllerScript::onUpdate(float timestep)
{

	

	auto& tc = m_registry.get<Engine::TransformComponent>(m_entity);
	glm::mat4& transform = tc.transform;
	rp3d::Vector3 right = { transform[0][0], transform[0][1], transform[0][2] };
	rp3d::Vector3 up = { transform[1][0], transform[1][1], transform[1][2] };
	rp3d::Vector3 forward = { -transform[2][0], -transform[2][1], transform[2][2] };

	auto& rb = m_registry.get<RigidBodyComponent>(m_entity);

	auto currentVel = rb.m_body->getLinearVelocity();
	rp3d::Vector3 desiredVel(0.f, 0.f, 0.f);

	bool applyLinearForce = false;

	//Forward and Backward
	if (InputPoller::isKeyPressed(NG_KEY_S))
	{
		desiredVel += (forward * m_FBspeed);
		applyLinearForce = true;
	}
	if (InputPoller::isKeyPressed(NG_KEY_W))
	{
		desiredVel -= (forward * m_FBspeed);
		applyLinearForce = true;
	}

	//Left and Right
	if (InputPoller::isKeyPressed(NG_KEY_A))
	{
		desiredVel -= (right * m_LRspeed);
		applyLinearForce = true;
	}
	if (InputPoller::isKeyPressed(NG_KEY_D))
	{
		desiredVel += (right * m_LRspeed);
		applyLinearForce = true;
	}
	

	if (applyLinearForce)
	{
		rp3d::Vector3 deltaVel = desiredVel - rb.m_body->getLinearVelocity();
		//F = MA
		rp3d::Vector3 force = deltaVel * (1.0f / timestep) * rb.m_body->getMass();
		rb.m_body->applyWorldForceAtCenterOfMass(force);

	}

	auto currentAngularVel = rb.m_body->getAngularVelocity();
	rp3d::Vector3 desiredAngularVel(0.f, 0.f, 0.f);

	bool applyTorque = false;

	if (InputPoller::isKeyPressed(NG_KEY_Q))
	{
		desiredAngularVel += up * m_rotSpeed;
		applyTorque = true;
	}
	if (InputPoller::isKeyPressed(NG_KEY_E))
	{
		desiredAngularVel -= up * m_rotSpeed;
		applyTorque = true;
	}

	if (applyTorque)
	{
		rp3d::Vector3 deltaAngularVel = desiredAngularVel - currentAngularVel;
		rp3d::Vector3 torque = deltaAngularVel * (1.0f / timestep) * rb.m_body->getMass();
		rb.m_body->applyWorldTorque(torque);
	}


	auto& pc = m_registry.get<Engine::PlayerComponent>(m_entity);

	if (pc.checkPointSet)
	{
		std::cout << "New checkpoint set" << std::endl;
		respawnPos = pc.newSpawnPos;
		pc.checkPointSet = false;
	}

	if (pc.enemyHit)
	{
		
		//tc.setPosition(glm::vec3(0.f, 0.f, 0.f));
		//rp3d::Vector3 rpPos(-25.0f, -1.0f, 20.0f);
		rp3d::Quaternion rpRot(tc.rotation.x, tc.rotation.y, tc.rotation.z, tc.rotation.w);
		rp3d::Transform rpt(respawnPos, rpRot);
		rb.m_body->setTransform(rpt);
		pc.enemyHit = false;
		deathCounter += 1;
		std::cout << "Current death total: " << deathCounter << std::endl;
	}

	if (pc.goalReached)
	{
		std::cout << "CONGRATULATIONS! goal reached :)" << std::endl;
		std::cout << "final deaths total: " << deathCounter << std::endl;
	}

	tc.recalc();


}