/* \file OpenGLIndexBuffer.h */
#pragma once

#include "rendering/indexBuffer.h"

namespace Engine
{
	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);  //!< constructor
		virtual ~OpenGLIndexBuffer();  //!< destructor
		virtual inline uint32_t getRenderID() const override{ return m_OpenGL_ID; }  //!< return render id
		virtual inline uint32_t getCount() const override{ return m_count; }  //!< return count
	private:
		uint32_t m_count; //!< Effective draw count
		uint32_t m_OpenGL_ID; //!< Render ID


	};
}
