/* \file OpenGLShader.h*/

#pragma once

//#include "rendering/shader.h"

#include <cstdint>
#include <glm/glm.hpp>

namespace Engine{
	class OpenGLShader

	{
	public:
		OpenGLShader(const char* vertexFilepath, const char* fragmentFilepath);  //!< constructor for seperate fragment and vertex shader files
		OpenGLShader(const char* filepath);  //!< constructor for fragment and vertex shader in one file
		~OpenGLShader();
		uint32_t getID() const { return m_OpenGL_ID; }  //!< return ID

		void uploadInt(const char* name, int value) ;  //!< upload an int
		void uploadFloat(const char* name, float value);  //!< upload a float
		void uploadFloat2(const char* name, const glm::vec2& value);  //!< upload float 2
		void uploadFloat3(const char* name, const glm::vec3& value);  //!< upload float 3
		void uploadFloat4(const char* name, const glm::vec4& value);  //!< upload float 4
		void uploadMat4(const char* name, const glm::mat4& value);  //!< upload mat 4

	private:
		uint32_t m_OpenGL_ID;
		void compileAndLink(const char* vertexShaderSrc, const char* fragmentShaderSrc);  //!< compile and link the vertex and fragment shader
	};

}