#pragma once

#include "engine.h"
#include "entt/entt.hpp"




using namespace Engine;

class SceneLayer : public Layer
{
public:

	SceneLayer() : m_registry(Application::getInstance().m_registry) , m_entities(Application::getInstance().m_entities){} //, m_entities(Application::getInstance().m_entities

	virtual void onAttach() override;
	virtual void onDetach() override;
	virtual void onUpdate(float timestep) override;
	virtual void onRender() override;
	virtual void onKeypress(KeyPressedEvent& e) override;

private:
	std::shared_ptr<OpenGLVertexArray> cubeVAO;
	std::shared_ptr<OpenGLVertexArray> pyramidVAO;

	//std::shared_ptr<OpenGLShader> FCShader;
	std::shared_ptr<OpenGLShader> TPShader;

	std::shared_ptr<OpenGLTexture> letterTexture;  //!< creates new texture
	std::shared_ptr<OpenGLTexture> numberTexture;  //!< creates new texture
	std::shared_ptr<OpenGLTexture> plainWhiteTexture;  //!< creates new texture
	std::shared_ptr<OpenGLTexture> wallTexture;
	std::shared_ptr<OpenGLTexture> enemyTexture;
	std::shared_ptr<OpenGLTexture> checkpointTexture;
	std::shared_ptr<OpenGLTexture> goalTexture;
	std::shared_ptr<OpenGLTexture> doorTexture;
	std::shared_ptr<OpenGLTexture> playerTexture;


	std::shared_ptr<Material> pyramidMat;  //!< creates new material
	std::shared_ptr<Material> letterCubeMat;  //!< creates new material
	std::shared_ptr<Material> numberCubeMat;  //!< creates new material
	std::shared_ptr<Material> floorCubeMat;
	std::shared_ptr<Material> wallCubeMat;
	std::shared_ptr<Material> enemyCubeMat;
	std::shared_ptr<Material> checkpointCubeMat;
	std::shared_ptr<Material> goalCubeMat;
	std::shared_ptr<Material> doorCubeMat;
	std::shared_ptr<Material> playerCubeMat;

	SceneWideUniforms swu3D;  //!< screen wide uniforms

	glm::vec3 lightData[3] = { {1.f, 1.f, 1.f}, {1.f, 4.f, 6.f} ,{0.f, 0.f, 0.f} };  //!< vec3 for light data

	//glm::mat4 models[3];  //!< array for the cube models
	
	
	//ENTITIES

	entt::registry& m_registry;
	std::vector<entt::entity>& m_entities;
	entt::entity m_camera;

	//player
	
	entt::entity m_player;

	//enemies
	entt::entity m_cube1;
	entt::entity m_cube2;
	entt::entity m_pyramid;


	entt::entity m_enemy1;
	entt::entity m_enemy2;
	entt::entity m_enemy3;
	entt::entity m_enemy4;
	entt::entity m_enemy5;


	entt::entity m_enemy6;
	entt::entity m_enemy7;
	entt::entity m_enemy8;
	entt::entity m_enemy9;
	entt::entity m_enemy10;


	entt::entity m_enemy11;
	entt::entity m_enemy12;
	entt::entity m_enemy13;
	entt::entity m_enemy14;
	entt::entity m_enemy15;


	//level environments

	//Level 1 
	entt::entity m_floor;
	entt::entity m_wall1;
	entt::entity m_wall2;
	entt::entity m_wall3;
	entt::entity m_wall4;
	entt::entity m_wall5;
	entt::entity m_wall6;
	entt::entity m_wall7;

	entt::entity m_wall8;
	entt::entity m_wall9;
	entt::entity m_wall10;
	entt::entity m_wall11;
	entt::entity m_wall12;


	entt::entity m_wall13;
	entt::entity m_wall14;

	entt::entity m_wall15;
	entt::entity m_wall16;
	entt::entity m_wall17;
	entt::entity m_wall18;
	entt::entity m_wall19;
	entt::entity m_wall20;
	entt::entity m_wall21;

	entt::entity m_goal;

	entt::entity m_door;
	entt::entity m_button;

	//checkpoints
	entt::entity m_checkPoint1;
	entt::entity m_checkPoint2;
	entt::entity m_checkPoint3;
	entt::entity m_checkPoint4;

	//COLLISIONS

	GeneralEventListener m_eventListener;
	

	float timestep = 0.f;
	
	glm::mat4 m_view = glm::lookAt(  //!< sets the 3D view
		glm::vec3(0.f, 0.f, 0.f),
		glm::vec3(0.f, 0.f, -1.f),
		glm::vec3(0.f, 1.f, 0.f)
	);

	glm::mat4 m_projection = glm::perspective(glm::radians(45.f), 1024.f / 800.f, 0.1f, 100.f);
};


