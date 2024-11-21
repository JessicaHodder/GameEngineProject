#include "EnemyScript.h"

void EnemyScript::onUpdate(float timestep)
{



	auto& tc = m_registry.get<Engine::TransformComponent>(m_entity);
	glm::mat4& transform = tc.transform;
	rp3d::Vector3 right = { transform[0][0], transform[0][1], transform[0][2] };
	rp3d::Vector3 up = { transform[1][0], transform[1][1], transform[1][2] };
	rp3d::Vector3 forward = { -transform[2][0], -transform[2][1], transform[2][2] };

	auto& rb = m_registry.get<RigidBodyComponent>(m_entity);

	

	if (m_FirstTimeSpawn == false)
	{
		m_FirstTimeSpawn = true;
		m_DefaultPosition = rp3d::Vector3(tc.translation.x, tc.translation.y, tc.translation.z);
		m_DefaultRotation = rp3d::Quaternion(tc.rotation.x, tc.rotation.y, tc.rotation.z, tc.rotation.w);
		
	}

	auto currentVel = rb.m_body->getLinearVelocity();
	rp3d::Vector3 desiredVel(0.f, 0.f, 0.f);

	//rb.m_body->setAngularLockAxisFactor(rp3d::Vector3(0.f, 0.f, 0.f));

	

	bool applyLinearForce = false;

	if (m_WallHit == true)
	{
		if (m_GoBack == true)
		{
			m_GoBack = false;
		}
		else if (m_GoBack == false)
		{
			m_GoBack = true;
		}

		m_WallHit = false;
	}

	//Forward and Backward

	auto& ec = m_registry.get<Engine::EnemyComponent>(m_entity);


	if (m_GoBack == false)
	{
		if (ec.upDown)
		{
			desiredVel += (forward * m_FBspeed);
			applyLinearForce = true;
		}
		else
		{
			desiredVel += (right * m_FBspeed);
			applyLinearForce = true;
		}
	}
	else if (m_GoBack == true)
	{
		if (ec.upDown)
		{
			desiredVel -= (forward * m_FBspeed);
			applyLinearForce = true;
		}
		else
		{
			desiredVel -= (right * m_FBspeed);
			applyLinearForce = true;
		}
	}


	if (applyLinearForce)
	{
		rp3d::Vector3 deltaVel = desiredVel - rb.m_body->getLinearVelocity();
		//F = MA
		rp3d::Vector3 force = deltaVel * (1.0f / timestep) * rb.m_body->getMass();
		rb.m_body->applyWorldForceAtCenterOfMass(force);

	}




	//auto& ec = m_registry.get<Engine::EnemyComponent>(m_entity);
	if (ec.wallHit)
	{
		//std::cout << "WallHit" << std::endl;

		m_WallHit = true;

		ec.wallHit = false;
	}

	if (ec.playerHit)
	{
		//std::cout << "playerHit" << std::endl;

		//rp3d::Vector3 rpPos(tc.translation.x, -1.0f, 0.0f);
		//rp3d::Quaternion rpRot(tc.rotation.x, tc.rotation.y, tc.rotation.z, tc.rotation.w);
		//rp3d::Transform rpt(rpPos, rpRot);
		rp3d::Transform rpt(m_DefaultPosition, m_DefaultRotation);
		rb.m_body->setTransform(rpt);

		ec.playerHit = false;
	}

	tc.recalc();

};