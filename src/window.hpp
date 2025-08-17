#include <glad/glad.h>
#include <glfw3.h>
#include <iostream>


class Window
{
private:
	int m_win_width;
	int m_win_height;
	const char* m_window_title;
	GLFWwindow* m_window;

	static void m_frameBufferCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

public:
	
	Window(unsigned int width, unsigned int height, const char* title) : 
		m_win_width(width), m_win_height(height), m_window_title(title) {}

	~Window()
	{
		glfwTerminate();
	}

	bool Init()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

		m_window = glfwCreateWindow(m_win_width, m_win_height, 
				m_window_title, nullptr, nullptr);
		if (!m_window) {
			std::cerr << 
				"Window::Init() Failed to create GLFW window" << std::endl;
			return false;
		}
		glfwMakeContextCurrent(m_window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cerr << 
				"Window::Init() Failed to init GLAD" << std::endl;
			return false;
		}
		glfwSetFramebufferSizeCallback(m_window, m_frameBufferCallback);

		return true;
	}

	int GetWindowWidth() { return m_win_width; }
	int GetWindowHeight() { return m_win_height; }

	void UpdateWindow()
	{
		glfwGetFramebufferSize(m_window, &m_win_width, &m_win_height);
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}
};

