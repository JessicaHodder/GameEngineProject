/* \ file OpenGLVertexBuffer.h */
#pragma once

#include "rendering/bufferLayout.h"

namespace Engine
{
	class OpenGLVertexBuffer
	{
	public:
		OpenGLVertexBuffer(void* vertices, uint32_t size, BufferLayout layout);  //!< constructor
		~OpenGLVertexBuffer();  //!< destructor
		void edit(void* vertices, uint32_t size, uint32_t offset);  //!< edit data
		inline uint32_t getRenderID() const { return m_OpenGL_ID; }  //!< return ID
		inline const BufferLayout& getLayout() const { return m_layout; }  //!< return layout
	private:
		uint32_t m_OpenGL_ID; //!< Render ID
		BufferLayout m_layout;

	};
}
