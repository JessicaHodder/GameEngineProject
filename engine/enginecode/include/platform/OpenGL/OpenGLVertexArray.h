/* \file OpenGLVertexArray.h*/
#pragma once

#include <vector>
#include <memory>
#include "OpenGLVertexBuffer.h"
#include "OpenGLIndexBuffer.h"

namespace Engine
{
	class OpenGLVertexArray
	{
	public:
		OpenGLVertexArray();  //!< default constructor
		~OpenGLVertexArray();  //!< destructor
		void addVertexBuffer(const std::shared_ptr<OpenGLVertexBuffer>& vertexBuffer);  //!< add a vertex buffer
		//void setIndexBuffer(const std::shared_ptr<OpenGLIndexBuffer>& indexBuffer);
		void setIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer);  //!< set the index buffer
		
		std::shared_ptr<IndexBuffer> getIndexBuffer() const { return m_indexBuffer; }  //!< return the index buffer

		inline uint32_t getRenderID() const { return m_OpenGL_ID; }  //!< return Id
		uint32_t getDrawCount() {if (m_indexBuffer) { return m_indexBuffer->getCount(); } else { return 0; }  //!< return the count from index buffer
		}
	private:
		uint32_t m_OpenGL_ID; //!< Render ID
		uint32_t m_attributeIndex = 0; //!< Attribute index
		std::vector<std::shared_ptr<OpenGLVertexBuffer>> m_vertexBuffer;
		//std::shared_ptr<OpenGLIndexBuffer> m_indexBuffer;
		std::shared_ptr<IndexBuffer> m_indexBuffer;
	};
}