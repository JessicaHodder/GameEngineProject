#pragma once

namespace Engine 
{
	class EnemyComponent
	{
	public:
		EnemyComponent(bool b_upDown)
		{
			
			upDown = b_upDown;
		}	

		bool upDown = false;

		bool wallHit = false;

		bool playerHit = false;

		
	};

}