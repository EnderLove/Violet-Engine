#include "vtpch.h"
#include "GLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Violet {
	GLContext::GLContext(GLFWwindow* windowHandle) : windowHandle_(windowHandle) {
		VT_CORE_ASSERT(windowHandle_, "Window handle is null!")
	}

	void GLContext::Init() {
		glfwMakeContextCurrent(windowHandle_);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		VT_CORE_ASSERT(status, "Failed to initialize Glad!");
	}

	void GLContext::SwapBuffers() {
		glfwSwapBuffers(windowHandle_);
	}

}
