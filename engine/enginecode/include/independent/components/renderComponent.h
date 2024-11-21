#pragma once

#include "platform/OpenGL/OpenGLVertexArray.h"
#include "platform/OpenGL/OpenGLShader.h"
#include "platform/OpenGL/OpenGLTexture.h"
#include <memory>

namespace Engine 
{

	class RenderComponent 
	{
	public:
		RenderComponent(std::shared_ptr<OpenGLShader> s, std::shared_ptr<OpenGLTexture> t, std::shared_ptr<OpenGLVertexArray> g, std::shared_ptr<Material> m):
			shader(s),
			texture(t),
			geometry(g),
			material(m)
		{}

		std::shared_ptr<OpenGLShader> shader;
		std::shared_ptr<OpenGLTexture> texture;
		std::shared_ptr<OpenGLVertexArray> geometry;
		std::shared_ptr<Material> material;

		//possibly add tint
	};
}