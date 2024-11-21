
/* \ file graphicsContext.h */
#pragma once


namespace
{
	class GraphicsContext
	{
	public:
		virtual void init() = 0; //!< Init the graphics context for the given window API
		virtual void swapBuffers() = 0;  //!< double buffering
	};
}