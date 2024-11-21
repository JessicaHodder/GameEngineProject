/** \ file Renderer3D.h */
#pragma once

#include <glm/glm.hpp>
#include <unordered_map>
#include <memory>
#include "platform/OpenGL/OpenGLVertexArray.h"
#include "platform/OpenGL/OpenGLTexture.h"
#include "platform/OpenGL/OpenGLShader.h"
#include "rendering/shaderDataType.h"
#include "rendering/RenderAPI.h"
#include "rendering/RendererCommon.h"



namespace Engine

{
	//using SceneWideUniforms = std::unordered_map<const char *, std::pair<ShaderDataType, void *>>;


	/** \class Material
	* \brief Holds a shader and uniform daya assosiated with that data
	*/
	class Material
	{
	public:
		Material(const std::shared_ptr<OpenGLShader>& shader) :
			m_shader(shader), m_flags(0), m_texture(nullptr), m_tint(glm::vec4(0.f))
		{}  //!< default Material
		Material(const std::shared_ptr<OpenGLShader>& shader, const std::shared_ptr<OpenGLTexture>& texture, const glm::vec4& tint) :
			m_shader(shader), m_texture(texture), m_tint(tint)
		{
			setFlag(flag_texture | flag_tint);

		}  //!< material with texture and tint
		Material(const std::shared_ptr<OpenGLShader>& shader, const std::shared_ptr<OpenGLTexture>& texture) :
			m_shader(shader), m_texture(texture), m_tint(glm::vec4(0.f))
		{
			setFlag(flag_texture);

		}  //!< material with texture only
		Material(const std::shared_ptr<OpenGLShader>& shader, const glm::vec4& tint) :
			m_shader(shader), m_texture(nullptr), m_tint(tint)
		{
			setFlag(flag_tint);

		}  //!< material with tint only

		inline std::shared_ptr<OpenGLShader> getShader() const { return m_shader; }  //!< retuns the shader
		inline std::shared_ptr<OpenGLTexture> getTexture() const { return m_texture; }  //!< returns the texture
		inline glm::vec4 getTint() const { return m_tint; }  //!< retuns the tint
		bool isFlagSet(uint32_t flag) const { return m_flags & flag; }  //!< retuns the flag if set

		void setTexture(const std::shared_ptr<OpenGLTexture>& texture) { m_texture = texture; }  //!< sets the texture
		void setTint(const glm::vec4& tint) { m_tint = tint; }  //!< sets the tint

		constexpr static uint32_t flag_texture = 1 << 0; //!< 00000001
		constexpr static uint32_t flag_tint = 1 << 1; //!< 00000010

	private:
		uint32_t m_flags = 0; //!< Bitfield representation of the shader settings
		std::shared_ptr<OpenGLShader> m_shader;  //!< the materials shader
		std::shared_ptr<OpenGLTexture> m_texture; //!< texture to be applied to material
		glm::vec4 m_tint;  //!< colour tint to tbe applied to geometry
		void setFlag(uint32_t flag) { m_flags = m_flags | flag; }  //!< sets the flag


	};



	/** \class Renderer3D
	* \brief A class which render 3D geometry instantly
	*/
	class Renderer3D
	{
	public:
		static void init(); //!< Init the renderer
		static void begin(const SceneWideUniforms& sceneWideUniforms); //!< Begin a new 3D scene
		static void submit(const std::shared_ptr<OpenGLVertexArray>& geometry, const std::shared_ptr<Material>& material, const glm::mat4 model);  //!< subit a piece of geometry to be rendered
		static void end(); //!< End the current 3D scene
	private:

		struct InternalData
		{
			SceneWideUniforms sceneWideUniforms; //!< replace with UBO Eventualy
			std::shared_ptr<OpenGLTexture> defaultTexture;  //!< Empty white texture
			glm::vec4 defaultTint; //!< default white tint
		};

		static std::shared_ptr<InternalData> s_data;  //!< internal data to the renderer
	};
}


