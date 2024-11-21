#pragma once


#include "events/windowEvent.h"
#include "events/keyboardEvents.h"

namespace Engine
{
	class Layer
	{
	public:

		virtual void onAttach() {};
		virtual void onDetach() {};
		virtual void onUpdate(float timestep) {};
		virtual void onRender() {};
		virtual void onKeypress(KeyPressedEvent& e) {};
	protected:



	};
}