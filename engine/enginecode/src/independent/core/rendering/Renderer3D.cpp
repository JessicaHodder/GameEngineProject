/** \file Renderer.cpp */

#include "engine_pch.h"
#include <glad/glad.h>
#include "rendering/Renderer3D.h"
#include "rendering/RendererCommon.h"
namespace Engine
{
	std::shared_ptr<Renderer3D::InternalData> Renderer3D::s_data = nullptr;
	void Renderer3D::init()
	{
		s_data.reset(new InternalData);

		unsigned char whitePx[4]{ 255,255,255,255 };
		s_data->defaultTexture.reset(new OpenGLTexture(1, 1, 4, whitePx));

		s_data->defaultTint = { 1.f, 1.f, 1.f, 1.f };
	}

	void Renderer3D::begin(const SceneWideUniforms& sceneWideUniforms)
	{
		s_data->sceneWideUniforms = sceneWideUniforms;
	}

	void Renderer3D::submit(const std::shared_ptr<OpenGLVertexArray>& geometry, const std::shared_ptr<Material>& material, const glm::mat4 model)
	{
		//Bind shader
		glUseProgram(material->getShader()->getID());

		//Appaly screenWideUiforms
		for (auto& dataPair : s_data->sceneWideUniforms)
		{
			const char* nameOfUniform = dataPair.first;
			ShaderDataType& sdt = dataPair.second.first;
			void* addressOfValue = dataPair.second.second;

			switch (sdt)
			{
			case ShaderDataType::Int: 
				material->getShader()->uploadInt(nameOfUniform, *(int *)addressOfValue);
				break;
			case ShaderDataType::Float3:
				material->getShader()->uploadFloat3(nameOfUniform, *(glm::vec3 *)addressOfValue);
				break;
			case ShaderDataType::Float4:
				material->getShader()->uploadFloat4(nameOfUniform, *(glm::vec4 *)addressOfValue);
				break;
			case ShaderDataType::Mat4:
				material->getShader()->uploadMat4(nameOfUniform, *(glm::mat4 *)addressOfValue);
				break;
			}
		}

		//Apply material uniforms
		material->getShader()->uploadMat4("u_model", model);
		if (material->isFlagSet(Material::flag_texture)) glBindTexture(GL_TEXTURE_2D, material->getTexture()->getID());
		else glBindTexture(GL_TEXTURE_2D, s_data->defaultTexture->getID());
		material->getShader()->uploadInt("u_textData", 0);

		if (material->isFlagSet(Material::flag_tint)) material->getShader()->uploadFloat4("u_tint", material->getTint());
		else material->getShader()->uploadFloat4("u_tint", s_data->defaultTint);



		//Bind geometry
		glBindVertexArray(geometry->getRenderID());
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, geometry->getIndexBuffer()->getRenderID());

		//submit draw call
		glDrawElements(GL_TRIANGLES, geometry->getDrawCount(), GL_UNSIGNED_INT, nullptr);
	}

	void Renderer3D::end()
	{
		s_data->sceneWideUniforms.clear();
	}
}