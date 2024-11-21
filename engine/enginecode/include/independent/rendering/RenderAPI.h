/* \file RenderAPI.h */
#pragma once

namespace Engine
{
	class RenderAPI {
	public:
		enum class API { none = 0, OpenGL = 1, Direct3D = 2, Vulkan = 3};  //!< for selecting system
		inline static API getAPI() { return s_API; }  //!< gets the selected API
	public:
		static API s_API; //!< The current API

	};
}