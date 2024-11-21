#include "engine_pch.h"

#include "independent/core/layerStack.h"

namespace Engine
{

	void LayerStack::push(Layer* layer)
	{

		m_stack.push_back(layer);
		layer->onAttach();

	}

	void LayerStack::pop()
	{
		if (!m_stack.empty()) m_stack.erase(m_stack.end());

	}

	void LayerStack::onUpdate(float timestep)
	{
		for (auto& layer : m_stack)
		{
			layer->onUpdate(timestep);
		}
	}

	void LayerStack::onRender()
	{
		for (auto& layer : m_stack)
		{
			layer->onRender();
		}
	}

	void LayerStack::onKeypress(KeyPressedEvent& e)
	{
		for (auto it = m_stack.rbegin(); it != m_stack.rend(); it++)
		{
			if (e.handled()) break;
			(*it)->onKeypress(e);
		}


	}
}