/** \file engineApp.cpp
*/
#include "engineApp.h"
#include "engine.h"


engineApp::engineApp()
{
	m_layerStack.push(&m_sceneLayer);
	

}

engineApp::~engineApp()
{

}

Engine::Application* Engine::startApplication()
{
	return new engineApp();
}