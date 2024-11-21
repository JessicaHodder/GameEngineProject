/** \file Renderer2D */

#pragma once

#include "rendering/RendererCommon.h"

namespace Engine
{

	class Quad
	{
	public:
		Quad() = default;
		static Quad createCenterHalfExtents(const glm::vec2& centre, const glm::vec2& halfExtents);  //!< creates quad with passed paramiters
	private:
		glm::vec3 m_translate = glm::vec3(0.f); //!< Transflation vector
		glm::vec3 m_scale = glm::vec3(1.f); //!< Scale vector
		friend class Renderer2D;
	};

	/* \class Renderer2D
	** \brief Class that allows the rendering of simple 2D primatives
	*/

	class Renderer2D
	{
	public:
		static void init(); //!< Init the internal data of the renderer
		static void begin(const SceneWideUniforms& swu); //!< Begin 2D scene
		static void submit(const Quad& quad, const glm::vec4& tint); //!< Render a tinted quad
		static void submit(const Quad& quad, const std::shared_ptr<OpenGLTexture>& texture); //!< Render a textured quad
		static void submit(const Quad& quad, const glm::vec4& tint, const std::shared_ptr<OpenGLTexture>& texture); //!< Render a textured and tinted quad
		static void submit(const Quad& quad, const glm::vec4& tint, float angle, bool degrees = false); //!< Render a textured and tinted quad
		static void submit(const Quad& quad, const std::shared_ptr<OpenGLTexture>& texture, float angle, bool degrees = false); //!< Render a textured and tinted quad
		static void submit(const Quad& quad, const glm::vec4& tint, const std::shared_ptr<OpenGLTexture>& texture, float angle, bool degrees = false); //!< Render a textured and tinted quad

		static void end();
	private:
		struct InternalData  //!< struct for data
		{
			std::shared_ptr<OpenGLTexture> defaultTexture;
			glm::vec4 defaultTint;
			std::shared_ptr<OpenGLShader> shader;
			std::shared_ptr<OpenGLVertexArray> VAO;
			glm::mat4 model;
		};

		static std::shared_ptr<InternalData> s_data;

	};

}
