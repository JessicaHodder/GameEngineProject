#pragma once
#include "reactphysics3d/reactphysics3d.h"

namespace Engine
{
	class CheckPointComponent
	{

	public:
		CheckPointComponent(rp3d::Vector3 pos)
		{
			checkPointPos = pos;
		}

		rp3d::Vector3 checkPointPos;

	};

}