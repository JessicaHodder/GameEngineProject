#pragma once
#include "reactphysics3d/reactphysics3d.h"

namespace Engine
{
	class PlayerComponent
	{
	public:
		PlayerComponent()
		{
			newSpawnPos = rp3d::Vector3(-25.f, -1.f, 15.f);
		}

		bool enemyHit = false;
		bool checkPointSet = false;
		bool goalReached = false;
		rp3d::Vector3 newSpawnPos;
	};

}