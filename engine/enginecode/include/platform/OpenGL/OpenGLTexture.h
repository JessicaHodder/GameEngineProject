/* \file OpenGLTexture.h*/
#pragma once

#include <cstdint>

namespace Engine
{
	class OpenGLTexture
	{
	public:
		OpenGLTexture(const char* filepath, uint32_t slot = 0);  //!< constructor for texture with file
		OpenGLTexture(uint32_t width, uint32_t height, uint32_t channels, unsigned char* data, uint32_t slot = 0);  //!< constructor for texture with passed data
		~OpenGLTexture();  //!< destructor
		void edit(uint32_t xOffset, uint32_t yOffset, uint32_t width, uint32_t height, unsigned char* data);  //!< edit texture
		inline uint32_t getID() { return m_OpenGL_ID; }  //!< return id
		inline uint32_t getWidth() { return m_width; }  //!< return width
		inline uint32_t getHeight() { return m_height; }  //!< return height
		inline uint32_t getChannels() { return m_channels; }  //!< return channels
		inline uint32_t getSlot() { return m_slot; }  //!< return channels
		void bindToSlot(uint32_t slot);

	private:
		uint32_t m_OpenGL_ID;
		uint32_t m_width;
		uint32_t m_height;
		uint32_t m_channels;
		uint32_t m_slot;

		void init(uint32_t width, uint32_t height, uint32_t channels, unsigned char* data, uint32_t slot);  //!< initaliser
	};


}
