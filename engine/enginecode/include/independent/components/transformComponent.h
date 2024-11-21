#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

namespace Engine 
{
	class TransformComponent 
	{
	public:
		glm::mat4 transform = glm::mat4(1.4f);
		glm::vec3 translation = glm::vec3(0.f);
		glm::quat rotation = glm::quat(glm::vec3(0.f));
		glm::vec3 scale = glm::vec3(1.f);

		TransformComponent() { transform = glm::mat4(1.0f); }

		TransformComponent(glm::vec3 t, glm::vec3 r, glm::vec3 s) 
		{
			translation = t;
			rotation = glm::quat(r);
			scale = s;

			recalc();
		}

		void recalc() 
		{
			glm::mat4 t = glm::translate(glm::mat4(1.f), translation);
			glm::mat4 r = glm::toMat4(rotation);
			glm::mat4 s = glm::scale(glm::mat4(1.f), scale);

			transform = t * r * s;
		}
		
		void recalc(glm::mat4 parent) 
		{
			glm::mat4 t = glm::translate(glm::mat4(1.f), translation);
			glm::mat4 r = glm::toMat4(rotation);
			glm::mat4 s = glm::scale(glm::mat4(1.f), scale);

			transform = parent * t * r * s;
		}

		void addRotation(glm::vec3 EulerAngles) 
		{
			rotation *= glm::quat(EulerAngles);
		}

		void setPosition(glm::vec3 newPos)
		{
			translation = newPos;
			recalc();
		}

		glm::mat4& getTransform() { return transform; }
	};
}