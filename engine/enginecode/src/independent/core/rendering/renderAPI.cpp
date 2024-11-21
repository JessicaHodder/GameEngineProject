/* \file renderAPI.h*/

#include "engine_pch.h"
#include "rendering/RenderAPI.h"
#include "systems/log.h"

#include "rendering/indexBuffer.h"
//#include "rendering/shader.h"


#include "platform/OpenGL/OpenGLIndexBuffer.h"
//#include "platform/OpenGL/OpenGLShader.h"

namespace Engine
{
	RenderAPI::API RenderAPI::s_API = RenderAPI::API::OpenGL;

	IndexBuffer* IndexBuffer::create(uint32_t* indices, uint32_t count)
	{
		switch (RenderAPI::getAPI())
		{
		case RenderAPI::API::none :
			Log::error("Rendering API required");
			break;

		case RenderAPI::API::OpenGL:
			return new OpenGLIndexBuffer(indices, count);
			break;

		case RenderAPI::API::Direct3D:
			Log::error("Not supported");
			break;

		case RenderAPI::API::Vulkan:
			Log::error("Not supported");
			break;

		}

		return nullptr;
	}

	//Shader* Shader::create(const char* vertexFilepath, const char* fragmentFilepath)
	//{
	//	switch (RenderAPI::getAPI())
	//	{
	//	case RenderAPI::API::none:
	//		Log::error("Rendering API required");
	//		break;

	//	case RenderAPI::API::OpenGL:
	//		return new OpenGLShader(vertexFilepath, fragmentFilepath);
	//		break;

	//	case RenderAPI::API::Direct3D:
	//		Log::error("Not supported");
	//		break;

	//	case RenderAPI::API::Vulkan:
	//		Log::error("Not supported");
	//		break;

	//	}

	//	return nullptr;
	//}

	//Shader* Shader::create(const char* filepath)
	//{
	//	switch (RenderAPI::getAPI())
	//	{
	//	case RenderAPI::API::none:
	//		Log::error("Rendering API required");
	//		break;

	//	case RenderAPI::API::OpenGL:
	//		return new OpenGLShader(filepath);
	//		break;

	//	case RenderAPI::API::Direct3D:
	//		Log::error("Not supported");
	//		break;

	//	case RenderAPI::API::Vulkan:
	//		Log::error("Not supported");
	//		break;

	//	}

	//	return nullptr;
	//}
}