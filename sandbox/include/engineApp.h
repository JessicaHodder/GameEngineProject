#pragma once

// entry point
#include "include/independent/core/entrypoint.h"
#include "engine.h"
#include "sceneLayer.h"

class engineApp : public Engine::Application
{
public:
	engineApp();
	~engineApp() override;
private:
	SceneLayer m_sceneLayer;
};
