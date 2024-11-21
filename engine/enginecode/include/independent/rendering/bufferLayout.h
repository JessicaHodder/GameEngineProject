/** \file bufferLayout.h */
#pragma once

#include "shaderDataType.h"
#include <vector>

namespace Engine
{
	/**
	\class BufferElement
	A class which holds data about a single element in a buffer layout
	*/


	
	class BufferElement
	{
	public:
		ShaderDataType m_dataType;  
		uint32_t m_size;
		uint32_t m_offset;
		bool m_normalised;

		BufferElement() {} //!< Defualt constructor
		BufferElement(ShaderDataType dataType, bool normalised = false) :
			m_dataType(dataType),
			m_size(STD::size(dataType)),
			m_normalised(normalised)
		{} //!< Constructor with params

	};


	/** \class BufferLayout
	* Abstraction of the notion of a buffer layout
	*/

	class BufferLayout
	{
	public:
		BufferLayout() {};  //!< default constructor
		BufferLayout(const std::initializer_list<BufferElement>& element) : m_elements(element) {calcStrideAndOffsets(); }  //!< constructor with paramiters
		inline uint32_t getStride() const { return m_stride; }  //!< retuns the stride
		void addElement(BufferElement element);  //!< adds element
		inline std::vector<BufferElement>::iterator begin() { return m_elements.begin(); }
		inline std::vector<BufferElement>::iterator end() { return m_elements.end(); }
		inline std::vector<BufferElement>::const_iterator begin() const{ return m_elements.begin(); }
		inline std::vector<BufferElement>::const_iterator end() const{ return m_elements.end(); }

	private:
		std::vector<BufferElement> m_elements; //!< Buffer elements
		uint32_t m_stride; //!< Width is bytes of the buffer line
		void calcStrideAndOffsets(); //!< Calc stride and offsets based on elements
	};



}