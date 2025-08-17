#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

class Camera
{
private:
	glm::vec3 m_position;
	glm::vec3 m_front;
	float m_yaw, m_pitch;

	glm::vec3 m_right, m_up;

	const glm::vec3 m_worldUp {0.0f, 1.0f, 0.0f};

	void m_UpdateCameraVector()
	{
		m_front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
		m_front.y = sin(glm::radians(m_pitch));
		m_front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
		m_front = glm::normalize(m_front);

		// Recalculate right and up vectors
		m_right = glm::normalize(glm::cross(m_front, m_worldUp));
		m_up = glm::normalize(glm::cross(m_right, m_front));
	}

public:

	Camera(glm::vec3 position = glm::vec3(0.0f)) : 
		m_position(position), m_yaw(0.0f), m_pitch(0.0f) {
			m_UpdateCameraVector();
		}

	// Future will be interfaced
	void Update()
	{
		m_UpdateCameraVector();
	}

	glm::mat4 GetViewMat()
	{
		return glm::lookAt(m_position, m_position + m_front, m_up);
	}
};

