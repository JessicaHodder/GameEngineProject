#pragma once

#include <vector>
#include "independent/core/layer.h"

namespace Engine
{
	class LayerStack
	{
	public:
		void push(Layer* layer);
		void pop();
		void onUpdate(float timestep);
		void onRender();
		void onKeypress(KeyPressedEvent& e);
	private:
		std::vector<Layer*> m_stack;


	};
}