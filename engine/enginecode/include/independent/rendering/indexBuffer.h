/* \file indexBuffer.h */
#pragma once

#include <cstdint>

namespace Engine
{
	/** \class IndexBuffer
	* API agnostic index buffer
	*/
	class IndexBuffer {

	public:
		virtual ~IndexBuffer() = default;  //!< deconstructor
		virtual inline uint32_t getRenderID() const = 0;  //!< empty get renderid
		virtual inline uint32_t getCount() const = 0;  //!< empty get count

		static IndexBuffer* create(uint32_t* indices, uint32_t count);  //!< create with params
	};
}
