#include <glad/glad.h>

#include "sceneLayer.h"
#include "glm/glm.hpp"
#include "CameraScript.h"
#include "PlayerControllerScript.h"
#include "EnemyScript.h"

void SceneLayer::onAttach()
{
#pragma region RAW_DATA


	float cubeVertices[8 * 24] = {  //!< sets cube vertices, normal and uv
		//	 <------ Pos ------>  <--- normal --->  <-- UV -->
			 0.5f,  0.5f, -0.5f,  0.f,  0.f, -1.f,  0.f,   0.f,
			 0.5f, -0.5f, -0.5f,  0.f,  0.f, -1.f,  0.f,   0.5f,
			-0.5f, -0.5f, -0.5f,  0.f,  0.f, -1.f,  0.33f, 0.5f,
			-0.5f,  0.5f, -0.5f,  0.f,  0.f, -1.f,  0.33f, 0.f,

			-0.5f, -0.5f, 0.5f,   0.f,  0.f,  1.f,  0.33f, 0.5f,
			 0.5f, -0.5f, 0.5f,   0.f,  0.f,  1.f,  0.66f, 0.5f,
			 0.5f,  0.5f, 0.5f,   0.f,  0.f,  1.f,  0.66f, 0.f,
			-0.5f,  0.5f, 0.5f,   0.f,  0.f,  1.f,  0.33,  0.f,

			-0.5f, -0.5f, -0.5f,  0.f, -1.f,  0.f,  1.f,   0.f,
			 0.5f, -0.5f, -0.5f,  0.f, -1.f,  0.f,  0.66f, 0.f,
			 0.5f, -0.5f, 0.5f,   0.f, -1.f,  0.f,  0.66f, 0.5f,
			-0.5f, -0.5f, 0.5f,   0.f, -1.f,  0.f,  1.0f,  0.5f,

			 0.5f,  0.5f, 0.5f,   0.f,  1.f,  0.f,  0.f,   0.5f,
			 0.5f,  0.5f, -0.5f,  0.f,  1.f,  0.f,  0.f,   1.0f,
			-0.5f,  0.5f, -0.5f,  0.f,  1.f,  0.f,  0.33f, 1.0f,
			-0.5f,  0.5f, 0.5f,   0.f,  1.f,  0.f,  0.3f,  0.5f,

			-0.5f,  0.5f, 0.5f,  -1.f,  0.f,  0.f,  0.66f, 0.5f,
			-0.5f,  0.5f, -0.5f, -1.f,  0.f,  0.f,  0.33f, 0.5f,
			-0.5f, -0.5f, -0.5f, -1.f,  0.f,  0.f,  0.33f, 1.0f,
			-0.5f, -0.5f, 0.5f,  -1.f,  0.f,  0.f,  0.66f, 1.0f,

			 0.5f, -0.5f, -0.5f,  1.f,  0.f,  0.f,  1.0f,  1.0f,
			 0.5f,  0.5f, -0.5f,  1.f,  0.f,  0.f,  1.0f,  0.5f,
			 0.5f,  0.5f, 0.5f,   1.f,  0.f,  0.f,  0.66f, 0.5f,
			 0.5f, -0.5f, 0.5f,   1.f,  0.f,  0.f,  0.66f, 1.0f
	};

	float pyramidVertices[8 * 16] = {  //!< sets pyramid vertices normal and uv
		//	 <------ Pos ------>  <--- normal --->  <-- UV -->
			-0.5f, -0.5f, -0.5f,  0.f, -1.f, 0.f,  0.f, 0.f,//re Magneta
			 0.5f, -0.5f, -0.5f,  0.f, -1.f, 0.f,  0.f, 0.5f,
			 0.5f, -0.5f,  0.5f,  0.f, -1.f, 0.f,  0.33f, 0.5f,
			-0.5f, -0.5f,  0.5f,  0.f, -1.f, 0.f,  0.33, 0.5f,

			-0.5f, -0.5f, -0.5f, -0.8944f, 0.4472f, 0.f,  0.33f, 1.0f,   //triangle Green
			-0.5f, -0.5f,  0.5f, -0.8944f, 0.4472f, 0.f,  0.66f, 1.0f,
			 0.0f,  0.5f,  0.0f, -0.8944f, 0.4472f, 0.f,  (0.33f + 0.66f) * 0.5f, 0.0f,

			-0.5f, -0.5f,  0.5f, 0.f, 0.4472f, 0.8944f,  0.f, 0.f,  //triangle Red
			 0.5f, -0.5f,  0.5f, 0.f, 0.4472f, 0.8944f,  0.f, 0.f,
			 0.0f,  0.5f,  0.0f, 0.f, 0.4472f, 0.8944f,  0.f, 0.f,

			 0.5f, -0.5f,  0.5f, 0.8944f, 0.4472f, 0.f, 0.f, 0.f,//  triangle Yellow
			 0.5f, -0.5f, -0.5f, 0.8944f, 0.4472f, 0.f, 0.f, 0.f,
			 0.0f,  0.5f,  0.0f, 0.8944f, 0.4472f, 0.f, 0.f, 0.f,

			 0.5f, -0.5f, -0.5f, 0.f, 0.4472f, -0.8944f, 0.f, 0.f,  //  triangle Blue
			-0.5f, -0.5f, -0.5f, 0.f, 0.4472f, -0.8944f, 0.f, 0.f,
			 0.0f,  0.5f,  0.0f, 0.f, 0.4472f, -0.8944f, 0.f, 0.f,
	};

	uint32_t pyramidIndices[3 * 6] =  //!< sets pyramid indices
	{
		0, 1, 2,
		2, 3, 0,
		4, 5, 6,
		7, 8, 9,
		10, 11, 12,
		13, 14, 15
	};

	uint32_t cubeIndices[3 * 12] = {  //!< sets cube indicies
		0, 1, 2,
		2, 3, 0,
		4, 5, 6,
		6, 7, 4,
		8, 9, 10,
		10, 11, 8,
		12, 13, 14,
		14, 15, 12,
		16, 17, 18,
		18, 19, 16,
		20, 21, 22,
		22, 23, 20
	};
#pragma endregion

#pragma region GL_BUFFERS

	//CUBE
	
	//std::shared_ptr<OpenGLVertexArray> cubeVAO;
	std::shared_ptr<OpenGLVertexBuffer> cubeVBO;
	std::shared_ptr<IndexBuffer> cubeIBO;

	cubeVAO.reset(new OpenGLVertexArray);  //!<  creates a new vertex array

	BufferLayout cubeBL = { ShaderDataType::Float3, ShaderDataType::Float3, ShaderDataType::Float2 };  //!< sets layout for buffer
	cubeVBO.reset(new OpenGLVertexBuffer(cubeVertices, sizeof(cubeVertices), cubeBL));  //!< creates new vertex buffer and passes data

	cubeIBO.reset(IndexBuffer::create(cubeIndices, 36));  //!< creates new index buffer

	cubeVAO->addVertexBuffer(cubeVBO);  //!< adds data from vbo to vao
	cubeVAO->setIndexBuffer(cubeIBO); //!< adds data from VAO to IBO

	//PYRAMID

	//std::shared_ptr<OpenGLVertexArray> pyramidVAO;
	std::shared_ptr<OpenGLVertexBuffer> pyramidVBO;
	std::shared_ptr<IndexBuffer> pyramidIBO;

	pyramidVAO.reset(new OpenGLVertexArray);

	//BufferLayout pyramididBL = { ShaderDataType::Float3, ShaderDataType::Float3 };
	//BufferLayout pyramididBL = { ShaderDataType::Float3, ShaderDataType::Float3, ShaderDataType::Float2 };
	pyramidVBO.reset(new OpenGLVertexBuffer(pyramidVertices, sizeof(pyramidVertices), cubeBL));

	pyramidIBO.reset(IndexBuffer::create(pyramidIndices, 18));

	pyramidVAO->addVertexBuffer(pyramidVBO);
	pyramidVAO->setIndexBuffer(pyramidIBO);



	// Unbind everything so we can't mess is up
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);  

#pragma endregion

#pragma region SHADERS

	std::shared_ptr<OpenGLShader> FCShader;
	FCShader.reset(new OpenGLShader("./assets/shaders/flatColour.glsl"));
	
	std::shared_ptr<OpenGLShader> TPShader;  //!< creates new shader
	TPShader.reset(new OpenGLShader("./assets/shaders/texturedPhong.glsl"));  //!< points to shader code

#pragma endregion

#pragma region TEXTURES

	std::shared_ptr<OpenGLTexture> letterTexture;  //!< creates new texture
	letterTexture.reset(new OpenGLTexture("assets/textures/letterCube.png", 0));  //!< points to required texture
	std::shared_ptr<OpenGLTexture> numberTexture;  //!< creates new texture
	numberTexture.reset(new OpenGLTexture("assets/textures/numberCube.png", 1));  //!< points to required texture

	unsigned char whitePx[4]{ 255,255,255,255 };  //!< creates unsigned char
	std::shared_ptr<OpenGLTexture> plainWhiteTexture;  //!< creates new texture
	plainWhiteTexture.reset(new OpenGLTexture(1, 1, 4, whitePx));  //!< sets to plain white texture

	unsigned char blackPx[4]{ 0,0,0,255 };  //!< creates unsigned char
	std::shared_ptr<OpenGLTexture> wallTexture;  //!< creates new texture
	wallTexture.reset(new OpenGLTexture(1, 1, 4, blackPx));  //!< sets to plain white texture


	unsigned char redPx[4]{ 225,0,0,225 };
	std::shared_ptr<OpenGLTexture> enemyTexture;  //!< creates new texture
	enemyTexture.reset(new OpenGLTexture(1, 1, 4, redPx));  //!< sets to plain white texture

	unsigned char greenPx[4]{ 0,225,0,225 };
	std::shared_ptr<OpenGLTexture> checkpointTexture;  //!< creates new texture
	checkpointTexture.reset(new OpenGLTexture(1, 1, 4, greenPx));  //!< sets to plain white texture

	unsigned char bluePx[4]{ 0,0,225,225 };
	std::shared_ptr<OpenGLTexture> doorTexture;  //!< creates new texture
	doorTexture.reset(new OpenGLTexture(1, 1, 4, bluePx));  //!< sets to plain white texture
	
	unsigned char yellowPx[4]{ 225,225,0,225 };
	std::shared_ptr<OpenGLTexture> goalTexture;  //!< creates new texture
	goalTexture.reset(new OpenGLTexture(1, 1, 4, yellowPx));  //!< sets to plain white texture

	unsigned char purplePx[4]{ 128,0,128,225 };
	std::shared_ptr<OpenGLTexture> playerTexture;  //!< creates new texture
	playerTexture.reset(new OpenGLTexture(1, 1, 4, purplePx));  //!< sets to plain white texture
	

#pragma endregion

#pragma region ENTITIES

	auto world = Application::getInstance().m_world;
	world->setEventListener(&m_eventListener);

	pyramidMat.reset(new Material(FCShader, { 0.4f, 0.7f, 0.3f, 1.f }));  //!< sets material to colour
	letterCubeMat.reset(new Material(TPShader, letterTexture));  //!< sets material to texture
	numberCubeMat.reset(new Material(TPShader, numberTexture));  //!< sets material to texture
	floorCubeMat.reset(new Material(TPShader, plainWhiteTexture));
	wallCubeMat.reset(new Material(TPShader, wallTexture));
	enemyCubeMat.reset(new Material(TPShader, enemyTexture));
	checkpointCubeMat.reset(new Material(TPShader, checkpointTexture));
	doorCubeMat.reset(new Material(TPShader, doorTexture));
	goalCubeMat.reset(new Material(TPShader, goalTexture));
	playerCubeMat.reset(new Material(TPShader, playerTexture));

	//player
	m_player = m_registry.create();
	m_registry.emplace<TransformComponent>(m_player, glm::vec3(-25.f, -1.f, 20.f), glm::vec3(0.f), glm::vec3(1.f));  //-25.f
	m_registry.emplace<RenderComponent>(m_player, TPShader, playerTexture, cubeVAO, playerCubeMat); 
	m_registry.emplace<RigidBodyComponent>(m_player, m_player, rp3d::BodyType::DYNAMIC);
	m_registry.emplace<BoxColliderComponent>(m_player, m_player, glm::vec3(0.5f), false);
	m_registry.emplace<NativeScriptComponent>(m_player);
	m_registry.get<NativeScriptComponent>(m_player).create<PlayerControllerScript>(m_player);
	m_registry.emplace<PlayerComponent>(m_player);
	m_entities.push_back(m_player);

	// Enemies

	m_pyramid = m_registry.create();
	m_registry.emplace<TransformComponent>(m_pyramid, glm::vec3(1.65f, -1.f, 1.f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_pyramid, FCShader, nullptr, pyramidVAO, pyramidMat);
	m_registry.emplace<RigidBodyComponent>(m_pyramid, m_pyramid, rp3d::BodyType::DYNAMIC);
	m_registry.emplace<BoxColliderComponent>(m_pyramid, m_pyramid, glm::vec3(0.5f), false);
	m_registry.emplace<NativeScriptComponent>(m_pyramid);
	m_registry.get<NativeScriptComponent>(m_pyramid).create<EnemyScript>(m_pyramid);
	m_registry.emplace<EnemyComponent>(m_pyramid, true);
	m_entities.push_back(m_pyramid);

	m_cube1 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_cube1, glm::vec3(-25.f, -1.f, 15.f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_cube1, TPShader, enemyTexture, cubeVAO, enemyCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_cube1, m_cube1, rp3d::BodyType::DYNAMIC);
	m_registry.emplace<BoxColliderComponent>(m_cube1, m_cube1, glm::vec3(0.5f), false);
	m_registry.emplace<NativeScriptComponent>(m_cube1);
	m_registry.get<NativeScriptComponent>(m_cube1).create<EnemyScript>(m_cube1);
	m_registry.emplace<EnemyComponent>(m_cube1, false);
	m_entities.push_back(m_cube1);

	m_cube2 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_cube2, glm::vec3(-27.5f, -1.f, 5.f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_cube2, TPShader, enemyTexture, cubeVAO, enemyCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_cube2, m_cube2, rp3d::BodyType::DYNAMIC);
	m_registry.emplace<BoxColliderComponent>(m_cube2, m_cube2, glm::vec3(0.5f), false);
	m_registry.emplace<NativeScriptComponent>(m_cube2);
	m_registry.get<NativeScriptComponent>(m_cube2).create<EnemyScript>(m_cube2);
	m_registry.emplace<EnemyComponent>(m_cube2, false);
	m_entities.push_back(m_cube2);


	// enemies continued

	m_enemy1 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_enemy1, glm::vec3(-22.5f, -1.f, -5.f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_enemy1, TPShader, enemyTexture, cubeVAO, enemyCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_enemy1, m_enemy1, rp3d::BodyType::DYNAMIC);
	m_registry.emplace<BoxColliderComponent>(m_enemy1, m_enemy1, glm::vec3(0.5f), false);
	m_registry.emplace<NativeScriptComponent>(m_enemy1);
	m_registry.get<NativeScriptComponent>(m_enemy1).create<EnemyScript>(m_enemy1);
	m_registry.emplace<EnemyComponent>(m_enemy1, false);
	m_entities.push_back(m_enemy1);


	m_enemy2 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_enemy2, glm::vec3(-11.5f, -1.f, -5.f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_enemy2, TPShader, enemyTexture, cubeVAO, enemyCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_enemy2, m_enemy2, rp3d::BodyType::DYNAMIC);
	m_registry.emplace<BoxColliderComponent>(m_enemy2, m_enemy2, glm::vec3(0.5f), false);
	m_registry.emplace<NativeScriptComponent>(m_enemy2);
	m_registry.get<NativeScriptComponent>(m_enemy2).create<EnemyScript>(m_enemy2);
	m_registry.emplace<EnemyComponent>(m_enemy2, false);
	m_entities.push_back(m_enemy2);

	m_enemy3 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_enemy3, glm::vec3(-15.5f, -1.f, 0.f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_enemy3, TPShader, enemyTexture, cubeVAO, enemyCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_enemy3, m_enemy3, rp3d::BodyType::DYNAMIC);
	m_registry.emplace<BoxColliderComponent>(m_enemy3, m_enemy3, glm::vec3(0.5f), false);
	m_registry.emplace<NativeScriptComponent>(m_enemy3);
	m_registry.get<NativeScriptComponent>(m_enemy3).create<EnemyScript>(m_enemy3);
	m_registry.emplace<EnemyComponent>(m_enemy3, false);
	m_entities.push_back(m_enemy3);


	m_enemy4 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_enemy4, glm::vec3(-18.5f, -1.f, 5.f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_enemy4, TPShader, enemyTexture, cubeVAO, enemyCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_enemy4, m_enemy4, rp3d::BodyType::DYNAMIC);
	m_registry.emplace<BoxColliderComponent>(m_enemy4, m_enemy4, glm::vec3(0.5f), false);
	m_registry.emplace<NativeScriptComponent>(m_enemy4);
	m_registry.get<NativeScriptComponent>(m_enemy4).create<EnemyScript>(m_enemy4);
	m_registry.emplace<EnemyComponent>(m_enemy4, false);
	m_entities.push_back(m_enemy4);


	m_enemy5 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_enemy5, glm::vec3(-16.5f, -1.f, 15.f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_enemy5, TPShader, enemyTexture, cubeVAO, enemyCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_enemy5, m_enemy5, rp3d::BodyType::DYNAMIC);
	m_registry.emplace<BoxColliderComponent>(m_enemy5, m_enemy5, glm::vec3(0.5f), false);
	m_registry.emplace<NativeScriptComponent>(m_enemy5);
	m_registry.get<NativeScriptComponent>(m_enemy5).create<EnemyScript>(m_enemy5);
	m_registry.emplace<EnemyComponent>(m_enemy5, false);
	m_entities.push_back(m_enemy5);


	// center enemies

	m_enemy6 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_enemy6, glm::vec3(-5.5f, -1.f, 14.f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_enemy6, TPShader, enemyTexture, cubeVAO, enemyCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_enemy6, m_enemy6, rp3d::BodyType::DYNAMIC);
	m_registry.emplace<BoxColliderComponent>(m_enemy6, m_enemy6, glm::vec3(0.5f), false);
	m_registry.emplace<NativeScriptComponent>(m_enemy6);
	m_registry.get<NativeScriptComponent>(m_enemy6).create<EnemyScript>(m_enemy6);
	m_registry.emplace<EnemyComponent>(m_enemy6, false);
	m_entities.push_back(m_enemy6);

	m_enemy7 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_enemy7, glm::vec3(-8.5f, -1.f, 11.f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_enemy7, TPShader, enemyTexture, cubeVAO, enemyCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_enemy7, m_enemy7, rp3d::BodyType::DYNAMIC);
	m_registry.emplace<BoxColliderComponent>(m_enemy7, m_enemy7, glm::vec3(0.5f), false);
	m_registry.emplace<NativeScriptComponent>(m_enemy7);
	m_registry.get<NativeScriptComponent>(m_enemy7).create<EnemyScript>(m_enemy7);
	m_registry.emplace<EnemyComponent>(m_enemy7, false);
	m_entities.push_back(m_enemy7);

	m_enemy8 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_enemy8, glm::vec3(-2.f, -1.f, 8.f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_enemy8, TPShader, enemyTexture, cubeVAO, enemyCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_enemy8, m_enemy8, rp3d::BodyType::DYNAMIC);
	m_registry.emplace<BoxColliderComponent>(m_enemy8, m_enemy8, glm::vec3(0.5f), false);
	m_registry.emplace<NativeScriptComponent>(m_enemy8);
	m_registry.get<NativeScriptComponent>(m_enemy8).create<EnemyScript>(m_enemy8);
	m_registry.emplace<EnemyComponent>(m_enemy8, false);
	m_entities.push_back(m_enemy8);

	m_enemy9 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_enemy9, glm::vec3(-7.f, -1.f, 3.f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_enemy9, TPShader, enemyTexture, cubeVAO, enemyCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_enemy9, m_enemy9, rp3d::BodyType::DYNAMIC);
	m_registry.emplace<BoxColliderComponent>(m_enemy9, m_enemy9, glm::vec3(0.5f), false);
	m_registry.emplace<NativeScriptComponent>(m_enemy9);
	m_registry.get<NativeScriptComponent>(m_enemy9).create<EnemyScript>(m_enemy9);
	m_registry.emplace<EnemyComponent>(m_enemy9, false);
	m_entities.push_back(m_enemy9);


	m_enemy10 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_enemy10, glm::vec3(-3.f, -1.f, -3.5f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_enemy10, TPShader, enemyTexture, cubeVAO, enemyCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_enemy10, m_enemy10, rp3d::BodyType::DYNAMIC);
	m_registry.emplace<BoxColliderComponent>(m_enemy10, m_enemy10, glm::vec3(0.5f), false);
	m_registry.emplace<NativeScriptComponent>(m_enemy10);
	m_registry.get<NativeScriptComponent>(m_enemy10).create<EnemyScript>(m_enemy10);
	m_registry.emplace<EnemyComponent>(m_enemy10, false);
	m_entities.push_back(m_enemy10);

	m_enemy11 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_enemy11, glm::vec3(-7.2f, -1.f, -7.f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_enemy11, TPShader, enemyTexture, cubeVAO, enemyCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_enemy11, m_enemy11, rp3d::BodyType::DYNAMIC);
	m_registry.emplace<BoxColliderComponent>(m_enemy11, m_enemy11, glm::vec3(0.5f), false);
	m_registry.emplace<NativeScriptComponent>(m_enemy11);
	m_registry.get<NativeScriptComponent>(m_enemy11).create<EnemyScript>(m_enemy11);
	m_registry.emplace<EnemyComponent>(m_enemy11, false);
	m_entities.push_back(m_enemy11);


	// right enemies

	m_enemy12 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_enemy12, glm::vec3(7.5f, -1.f, -7.f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_enemy12, TPShader, enemyTexture, cubeVAO, enemyCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_enemy12, m_enemy12, rp3d::BodyType::DYNAMIC);
	m_registry.emplace<BoxColliderComponent>(m_enemy12, m_enemy12, glm::vec3(0.5f), false);
	m_registry.emplace<NativeScriptComponent>(m_enemy12);
	m_registry.get<NativeScriptComponent>(m_enemy12).create<EnemyScript>(m_enemy12);
	m_registry.emplace<EnemyComponent>(m_enemy12, true);
	m_entities.push_back(m_enemy12);


	m_enemy13 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_enemy13, glm::vec3(9.f, -1.f, 0.f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_enemy13, TPShader, enemyTexture, cubeVAO, enemyCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_enemy13, m_enemy13, rp3d::BodyType::DYNAMIC);
	m_registry.emplace<BoxColliderComponent>(m_enemy13, m_enemy13, glm::vec3(0.5f), false);
	m_registry.emplace<NativeScriptComponent>(m_enemy13);
	m_registry.get<NativeScriptComponent>(m_enemy13).create<EnemyScript>(m_enemy13);
	m_registry.emplace<EnemyComponent>(m_enemy13, true);
	m_entities.push_back(m_enemy13);

	m_enemy14 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_enemy14, glm::vec3(12.f, -1.f, 3.2f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_enemy14, TPShader, enemyTexture, cubeVAO, enemyCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_enemy14, m_enemy14, rp3d::BodyType::DYNAMIC);
	m_registry.emplace<BoxColliderComponent>(m_enemy14, m_enemy14, glm::vec3(0.5f), false);
	m_registry.emplace<NativeScriptComponent>(m_enemy14);
	m_registry.get<NativeScriptComponent>(m_enemy14).create<EnemyScript>(m_enemy14);
	m_registry.emplace<EnemyComponent>(m_enemy14, true);
	m_entities.push_back(m_enemy14);

	m_enemy15 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_enemy15, glm::vec3(14.5f, -1.f, -1.2f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_enemy15, TPShader, enemyTexture, cubeVAO, enemyCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_enemy15, m_enemy15, rp3d::BodyType::DYNAMIC);
	m_registry.emplace<BoxColliderComponent>(m_enemy15, m_enemy15, glm::vec3(0.5f), false);
	m_registry.emplace<NativeScriptComponent>(m_enemy15);
	m_registry.get<NativeScriptComponent>(m_enemy15).create<EnemyScript>(m_enemy15);
	m_registry.emplace<EnemyComponent>(m_enemy15, true);
	m_entities.push_back(m_enemy15);


	//level 1 environment

	m_floor = m_registry.create();
	m_registry.emplace<TransformComponent>(m_floor, glm::vec3(0.f, -2.f, 0.f), glm::vec3(0.f), glm::vec3(60.f,1.f,50.f));
	m_registry.emplace<RenderComponent>(m_floor, TPShader, plainWhiteTexture, cubeVAO, floorCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_floor, m_floor, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_floor, m_floor, glm::vec3(30.f,0.5f,25.f), false);
	m_entities.push_back(m_floor);

	m_wall1 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_wall1, glm::vec3(30.f, -1.f, 0.f), glm::vec3(0.f), glm::vec3(1.f, 1.f, 50.f));
	m_registry.emplace<RenderComponent>(m_wall1, TPShader, wallTexture, cubeVAO, wallCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_wall1, m_wall1, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_wall1, m_wall1, glm::vec3(0.5f, 0.5f, 25.f), false);
	m_registry.emplace<WallComponent>(m_wall1);
	m_entities.push_back(m_wall1);

	m_wall2 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_wall2, glm::vec3(-30.f, -1.f, 0.f), glm::vec3(0.f), glm::vec3(1.f, 1.f, 50.f));
	m_registry.emplace<RenderComponent>(m_wall2, TPShader, wallTexture, cubeVAO, wallCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_wall2, m_wall2, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_wall2, m_wall2, glm::vec3(0.5f, 0.5f, 25.f), false);
	m_registry.emplace<WallComponent>(m_wall2);
	m_entities.push_back(m_wall2);

	m_wall3 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_wall3, glm::vec3(0.f, -1.f, 25.f), glm::vec3(0.f), glm::vec3(60.f, 1.f, 1.f));
	m_registry.emplace<RenderComponent>(m_wall3, TPShader, wallTexture, cubeVAO, wallCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_wall3, m_wall3, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_wall3, m_wall3, glm::vec3(30.f, 0.5f, 0.5f), false);
	m_registry.emplace<WallComponent>(m_wall3);
	m_entities.push_back(m_wall3);

	m_wall4 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_wall4, glm::vec3(0.f, -1.f, -25.f), glm::vec3(0.f), glm::vec3(60.f, 1.f, 1.f));
	m_registry.emplace<RenderComponent>(m_wall4, TPShader, wallTexture, cubeVAO, wallCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_wall4, m_wall4, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_wall4, m_wall4, glm::vec3(30.f, 0.5f, 0.5f), false);
	m_registry.emplace<WallComponent>(m_wall4);
	m_entities.push_back(m_wall4);

	// inner walls

	m_wall5 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_wall5, glm::vec3(-20.f, -1.f, 5.f), glm::vec3(0.f), glm::vec3(1.f, 1.f, 40.f));
	m_registry.emplace<RenderComponent>(m_wall5, TPShader, wallTexture, cubeVAO, wallCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_wall5, m_wall5, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_wall5, m_wall5, glm::vec3(0.5f, 0.5f, 20.f), false);
	m_registry.emplace<WallComponent>(m_wall5);
	m_entities.push_back(m_wall5);

	m_wall6 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_wall6, glm::vec3(-10.f, -1.f, -5.f), glm::vec3(0.f), glm::vec3(1.f, 1.f, 40.f));
	m_registry.emplace<RenderComponent>(m_wall6, TPShader, wallTexture, cubeVAO, wallCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_wall6, m_wall6, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_wall6, m_wall6, glm::vec3(0.5f, 0.5f, 20.f), false);
	m_registry.emplace<WallComponent>(m_wall6);
	m_entities.push_back(m_wall6);

	m_wall7 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_wall7, glm::vec3(0.f, -1.f, 5.f), glm::vec3(0.f), glm::vec3(1.f, 1.f, 40.f));
	m_registry.emplace<RenderComponent>(m_wall7, TPShader, wallTexture, cubeVAO, wallCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_wall7, m_wall7, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_wall7, m_wall7, glm::vec3(0.5f, 0.5f, 20.f), false);
	m_registry.emplace<WallComponent>(m_wall7);
	m_entities.push_back(m_wall7);



	// left side walls

	m_wall8 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_wall8, glm::vec3(3.f, -1.f, -15.f), glm::vec3(0.f), glm::vec3(1.f, 1.f, 20.f));
	m_registry.emplace<RenderComponent>(m_wall8, TPShader, wallTexture, cubeVAO, wallCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_wall8, m_wall8, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_wall8, m_wall8, glm::vec3(0.5f, 0.5f, 10.f), false);
	m_registry.emplace<WallComponent>(m_wall8);
	m_entities.push_back(m_wall8);

	m_wall9 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_wall9, glm::vec3(4.5f, -1.f, -5.f), glm::vec3(0.f), glm::vec3(4.f, 1.f, 1.f));
	m_registry.emplace<RenderComponent>(m_wall9, TPShader, wallTexture, cubeVAO, wallCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_wall9, m_wall9, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_wall9, m_wall9, glm::vec3(2.f, 0.5f, 0.5f), false);
	m_registry.emplace<WallComponent>(m_wall9);
	m_entities.push_back(m_wall9);

	m_wall10 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_wall10, glm::vec3(6.f, -1.f, 0.f), glm::vec3(0.f), glm::vec3(1.f, 1.f, 10.f));
	m_registry.emplace<RenderComponent>(m_wall10, TPShader, wallTexture, cubeVAO, wallCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_wall10, m_wall10, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_wall10, m_wall10, glm::vec3(0.5f, 0.5f, 5.f), false);
	m_registry.emplace<WallComponent>(m_wall10);
	m_entities.push_back(m_wall10);

	m_wall11 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_wall11, glm::vec3(4.5f, -1.f, 5.f), glm::vec3(0.f), glm::vec3(4.f, 1.f, 1.f));
	m_registry.emplace<RenderComponent>(m_wall11, TPShader, wallTexture, cubeVAO, wallCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_wall11, m_wall11, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_wall11, m_wall11, glm::vec3(2.f, 0.5f, 0.5f), false);
	m_registry.emplace<WallComponent>(m_wall11);
	m_entities.push_back(m_wall11);

	m_wall12 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_wall12, glm::vec3(3.f, -1.f, 10.f), glm::vec3(0.f), glm::vec3(1.f, 1.f, 10.f));
	m_registry.emplace<RenderComponent>(m_wall12, TPShader, wallTexture, cubeVAO, wallCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_wall12, m_wall12, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_wall12, m_wall12, glm::vec3(0.5f, 0.5f, 5.f), false);
	m_registry.emplace<WallComponent>(m_wall12);
	m_entities.push_back(m_wall12);


	// other cavity walls

	m_wall13 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_wall13, glm::vec3(9.f, -1.f, 15.f), glm::vec3(0.f), glm::vec3(1.f, 1.f, 20.f));
	m_registry.emplace<RenderComponent>(m_wall13, TPShader, wallTexture, cubeVAO, wallCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_wall13, m_wall13, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_wall13, m_wall13, glm::vec3(0.5f, 0.5f, 10.f), false);
	m_registry.emplace<WallComponent>(m_wall13);
	m_entities.push_back(m_wall13);

	m_wall14 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_wall14, glm::vec3(9.f, -1.f, -15.f), glm::vec3(0.f), glm::vec3(1.f, 1.f, 20.f));
	m_registry.emplace<RenderComponent>(m_wall14, TPShader, wallTexture, cubeVAO, wallCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_wall14, m_wall14, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_wall14, m_wall14, glm::vec3(0.5f, 0.5f, 10.f), false);
	m_registry.emplace<WallComponent>(m_wall14);
	m_entities.push_back(m_wall14);


	m_wall15 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_wall15, glm::vec3(13.5f, -1.f, -5.f), glm::vec3(0.f), glm::vec3(10.f, 1.f, 1.f));
	m_registry.emplace<RenderComponent>(m_wall15, TPShader, wallTexture, cubeVAO, wallCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_wall15, m_wall15, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_wall15, m_wall15, glm::vec3(5.f, 0.5f, 0.5f), false);
	m_registry.emplace<WallComponent>(m_wall15);
	m_entities.push_back(m_wall15);

	m_wall16 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_wall16, glm::vec3(13.5f, -1.f, 5.f), glm::vec3(0.f), glm::vec3(10.f, 1.f, 1.f));
	m_registry.emplace<RenderComponent>(m_wall16, TPShader, wallTexture, cubeVAO, wallCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_wall16, m_wall16, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_wall16, m_wall16, glm::vec3(5.f, 0.5f, 0.5f), false);
	m_registry.emplace<WallComponent>(m_wall16);
	m_entities.push_back(m_wall16);


	// exit walls

	m_wall17 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_wall17, glm::vec3(21.f, -1.f, 2.5f), glm::vec3(0.f), glm::vec3(5.f, 1.f, 1.f));
	m_registry.emplace<RenderComponent>(m_wall17, TPShader, wallTexture, cubeVAO, wallCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_wall17, m_wall17, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_wall17, m_wall17, glm::vec3(2.5f, 0.5f, 0.5f), false);
	m_registry.emplace<WallComponent>(m_wall17);
	m_entities.push_back(m_wall17);

	m_wall18 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_wall18, glm::vec3(21.f, -1.f, -2.5f), glm::vec3(0.f), glm::vec3(5.f, 1.f, 1.f));
	m_registry.emplace<RenderComponent>(m_wall18, TPShader, wallTexture, cubeVAO, wallCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_wall18, m_wall18, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_wall18, m_wall18, glm::vec3(2.5f, 0.5f, 0.5f), false);
	m_registry.emplace<WallComponent>(m_wall18);
	m_entities.push_back(m_wall18);

	m_wall19 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_wall19, glm::vec3(18.5f, -1.f, -3.75f), glm::vec3(0.f), glm::vec3(1.f, 1.f, 3.75f));
	m_registry.emplace<RenderComponent>(m_wall19, TPShader, wallTexture, cubeVAO, wallCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_wall19, m_wall19, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_wall19, m_wall19, glm::vec3(0.5f, 0.5f, 1.875f), false);
	m_registry.emplace<WallComponent>(m_wall19);
	m_entities.push_back(m_wall19);

	m_wall20 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_wall20, glm::vec3(18.5f, -1.f, 3.75f), glm::vec3(0.f), glm::vec3(1.f, 1.f, 3.75f));
	m_registry.emplace<RenderComponent>(m_wall20, TPShader, wallTexture, cubeVAO, wallCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_wall20, m_wall20, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_wall20, m_wall20, glm::vec3(0.5f, 0.5f, 1.875f), false);
	m_registry.emplace<WallComponent>(m_wall20);
	m_entities.push_back(m_wall20);

	m_wall21 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_wall21, glm::vec3(23.5f, -1.f, 0.f), glm::vec3(0.f), glm::vec3(1.f, 1.f, 6.f));
	m_registry.emplace<RenderComponent>(m_wall21, TPShader, wallTexture, cubeVAO, wallCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_wall21, m_wall21, rp3d::BodyType::STATIC);
	m_registry.emplace<BoxColliderComponent>(m_wall21, m_wall21, glm::vec3(0.5f, 0.5f, 3.f), false);
	m_registry.emplace<WallComponent>(m_wall21);
	m_entities.push_back(m_wall21);


	//checkPoints

	m_checkPoint1 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_checkPoint1, glm::vec3(-28.f, -1.f, 20.f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_checkPoint1, TPShader, checkpointTexture, cubeVAO, checkpointCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_checkPoint1, m_checkPoint1, rp3d::BodyType::KINEMATIC);
	m_registry.emplace<BoxColliderComponent>(m_checkPoint1, m_checkPoint1, glm::vec3(0.5f), false);
	m_registry.emplace<CheckPointComponent>(m_checkPoint1, rp3d::Vector3(-25.f, -1.f, 20.f));
	m_entities.push_back(m_checkPoint1);

	m_checkPoint2 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_checkPoint2, glm::vec3(-18.f, -1.f, -20.f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_checkPoint2, TPShader, checkpointTexture, cubeVAO, checkpointCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_checkPoint2, m_checkPoint2, rp3d::BodyType::KINEMATIC);
	m_registry.emplace<BoxColliderComponent>(m_checkPoint2, m_checkPoint2, glm::vec3(0.5f), false);
	m_registry.emplace<CheckPointComponent>(m_checkPoint2, rp3d::Vector3(-14.f, -1.f, -20.f));
	m_entities.push_back(m_checkPoint2);

	m_checkPoint3 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_checkPoint3, glm::vec3(-8.f, -1.f, -20.f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_checkPoint3, TPShader, checkpointTexture, cubeVAO, checkpointCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_checkPoint3, m_checkPoint3, rp3d::BodyType::KINEMATIC);
	m_registry.emplace<BoxColliderComponent>(m_checkPoint3, m_checkPoint3, glm::vec3(0.5f), false);
	m_registry.emplace<CheckPointComponent>(m_checkPoint3, rp3d::Vector3(-4.f, -1.f, -20.f));
	m_entities.push_back(m_checkPoint3);

	m_checkPoint4 = m_registry.create();
	m_registry.emplace<TransformComponent>(m_checkPoint4, glm::vec3(4.f, -1.f, 20.f), glm::vec3(0.f), glm::vec3(1.f));
	m_registry.emplace<RenderComponent>(m_checkPoint4, TPShader, checkpointTexture, cubeVAO, checkpointCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_checkPoint4, m_checkPoint4, rp3d::BodyType::KINEMATIC);
	m_registry.emplace<BoxColliderComponent>(m_checkPoint4, m_checkPoint4, glm::vec3(0.5f), false);
	m_registry.emplace<CheckPointComponent>(m_checkPoint4, rp3d::Vector3(5.5f, -1.f, 20.f));
	m_entities.push_back(m_checkPoint4);

	//goal position
	m_goal = m_registry.create();
	m_registry.emplace<TransformComponent>(m_goal, glm::vec3(22.0f, -1.f, 0.f), glm::vec3(0.f), glm::vec3(1.f)); 
	m_registry.emplace<RenderComponent>(m_goal, TPShader, goalTexture, cubeVAO, goalCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_goal, m_goal, rp3d::BodyType::KINEMATIC);
	m_registry.emplace<BoxColliderComponent>(m_goal, m_goal, glm::vec3(0.5f), false);
	m_registry.emplace<GoalComponent>(m_goal);
	m_entities.push_back(m_goal);

	//door and button objects
	m_button = m_registry.create();
	m_registry.emplace<TransformComponent>(m_button, glm::vec3(4.f, -1.f, -20.f), glm::vec3(0.f), glm::vec3(1.f)); // set position
	m_registry.emplace<RenderComponent>(m_button, TPShader, doorTexture, cubeVAO, doorCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_button, m_button, rp3d::BodyType::KINEMATIC);
	m_registry.emplace<BoxColliderComponent>(m_button, m_button, glm::vec3(0.5f), false);
	m_registry.emplace<buttonComponent>(m_button);
	m_entities.push_back(m_button);

	m_door = m_registry.create();
	m_registry.emplace<TransformComponent>(m_door, glm::vec3(18.5f, -1.f, 0.f), glm::vec3(0.f), glm::vec3(1.f,1.f,3.f)); // set position
	m_registry.emplace<RenderComponent>(m_door, TPShader, doorTexture, cubeVAO, doorCubeMat);
	m_registry.emplace<RigidBodyComponent>(m_door, m_door, rp3d::BodyType::KINEMATIC);
	m_registry.emplace<BoxColliderComponent>(m_door, m_door, glm::vec3(0.5f,0.5f,2.5f), false);
	m_registry.emplace<buttonComponent>(m_door);
	m_entities.push_back(m_door);


	auto win = Application::getInstance().getWindow();
	PerspectiveCameraProps settings;
	settings.aspectRatio = (float)win->getWidth() / (float)win->getHeight();

	//m_camera = m_registry.create();
	//m_registry.emplace<TransformComponent>(m_camera, glm::vec3(0.f), glm::vec3(0.f), glm::vec3(1.f));
	//m_registry.emplace<PerspectiveCameraComponent>(m_camera, m_registry.get<TransformComponent>(m_camera).transform, settings);

	glEnable(GL_DEPTH_TEST);  //!< enable gl depth test
	glClearColor(1.f, 0.f, 1.f, 1.f);

	//view and projection initialisation previous location


	//camera
	m_camera = m_registry.create();
	{
		auto& nsc = m_registry.emplace<NativeScriptComponent>(m_camera);
		nsc.create<CameraScript>(m_camera, glm::vec3(0.f, 3.f, 13.f));

	}

	auto& cameraComp = m_registry.get<PerspectiveCameraComponent>(m_camera);

	//swu3D["u_model"] = std::pair<ShaderDataType, void*>(ShaderDataType::Mat4, static_cast<void*>(glm::value_ptr(models[0])));
	  //!< creates scene wide pointers for passing to shader
	//m_view
	swu3D["u_view"] = std::pair<ShaderDataType, void*>(ShaderDataType::Mat4, static_cast<void*>(glm::value_ptr(cameraComp.view)));
	//m_projection
	swu3D["u_projection"] = std::pair<ShaderDataType, void*>(ShaderDataType::Mat4, static_cast<void*>(glm::value_ptr(cameraComp.projection)));
	auto& Camtc = m_registry.get<TransformComponent>(m_camera);
	//swu3D["u_viewPos"] = std::pair<ShaderDataType, void*>(ShaderDataType::Float3, static_cast<void*>(glm::value_ptr(cameraComp.translation)));
	lightData[2] = Camtc.translation;
	swu3D["u_lightColour"] = std::pair<ShaderDataType, void*>(ShaderDataType::Float3, static_cast<void*>(glm::value_ptr(lightData[0])));
	swu3D["u_lightPos"] = std::pair<ShaderDataType, void*>(ShaderDataType::Float3, static_cast<void*>(glm::value_ptr(lightData[1])));
	swu3D["u_viewPos"] = std::pair<ShaderDataType, void*>(ShaderDataType::Float3, static_cast<void*>(glm::value_ptr(lightData[2])));

#pragma endregion
}

void SceneLayer::onDetach()
{
}

void SceneLayer::onUpdate(float timestep)
{
	Application::getInstance().m_world->update(timestep);

	

	//grab all entities with rigid bodies
	//grab all transforms from entities with rigid bodies
	//set the translation and rotation to match rigid body
	//recalc

	auto view = m_registry.view<RigidBodyComponent, TransformComponent>();
	for (auto& entity : view)
	{
		auto& rb = m_registry.get<RigidBodyComponent>(entity);
		auto& tc = m_registry.get<TransformComponent>(entity);

		const rp3d::Transform& transform = rb.m_body->getTransform();
		const rp3d::Vector3& position = transform.getPosition();
		const rp3d::Quaternion& rotation = transform.getOrientation();
		glm::vec3 sillyConversion = glm::vec3(position.x, position.y, position.z);
		glm::quat goofyConversion = glm::quat(rotation.w, rotation.x, rotation.y, rotation.z);

		tc.translation = sillyConversion;
		//tc.rotation = goofyConversion;
		tc.recalc();
	}

	


	//camera update
	auto NSCview = m_registry.view<NativeScriptComponent>();
	for (auto& entity : NSCview)
	{
		auto& nsc = m_registry.get<NativeScriptComponent>(entity);
		nsc.onUpdate(timestep);
	}

	if (m_registry.get<buttonComponent>(m_button).isPressed)
	{
		auto& ttc = m_registry.get<Engine::TransformComponent>(m_door);
		glm::mat4& transform = ttc.transform;

		auto& trb = m_registry.get<RigidBodyComponent>(m_door);
		rp3d::Quaternion tRot(ttc.rotation.x, ttc.rotation.y, ttc.rotation.z, ttc.rotation.w);
		rp3d::Vector3 tTl(ttc.translation.x, ttc.translation.y = 10, ttc.translation.x);
		rp3d::Transform rpt(tTl, tRot);
		trb.m_body->setTransform(rpt);
		std::cout << "Test" << std::endl;
	}

	//refresh camera view

	m_registry.get<TransformComponent>(m_camera).translation.x = m_registry.get<TransformComponent>(m_player).translation.x;
	m_registry.get<TransformComponent>(m_camera).translation.z = m_registry.get<TransformComponent>(m_player).translation.z +10;
	auto& camTC = m_registry.get<TransformComponent>(m_camera);
	swu3D["u_viewPos"] = std::pair<ShaderDataType, void*>(ShaderDataType::Float3, static_cast<void*>(glm::value_ptr(camTC.translation)));
}

void SceneLayer::onRender()
{	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	

	auto view = m_registry.view<TransformComponent, RenderComponent>();
	for (auto entity : view) 
	{
		auto& tc = m_registry.get<TransformComponent>(entity);
		auto& rc = m_registry.get<RenderComponent>(entity);
		
		glUseProgram(rc.shader->getID());
		glBindVertexArray(rc.geometry->getRenderID());

		Renderer3D::begin(swu3D);  //!< begins renderer with scene wide data
		Renderer3D::submit(rc.geometry, rc.material, tc.transform);
		Renderer3D::end();  //!< closes renderer
	}	
}

void SceneLayer::onKeypress(KeyPressedEvent& e)
{
}
