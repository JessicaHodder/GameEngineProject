#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Engine 
{

	struct PerspectiveCameraProps 
	{
		glm::vec2 size = { 800.f,600.f } ;
		float aspectRatio = 800.f / 600.f;
		float fovY = 45.f;
		float nearClip = 0.1f;
		float farClip = 100.f;
	};

	class PerspectiveCameraComponent 
	{
	public:
		PerspectiveCameraComponent(const glm::mat4& transform, const PerspectiveCameraProps& s) : 
			settings(s)
		{
			view = glm::inverse(transform);
			projection = glm::perspective(settings.fovY, settings.aspectRatio, settings.nearClip, settings.farClip);
		};
		glm::mat4 view; //!< View matrix of the camera
		glm::mat4 projection; //!<Projection matrix of the camera
		PerspectiveCameraProps settings;
	};

	

}