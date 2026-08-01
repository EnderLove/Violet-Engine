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

		VT_CORE_INFO("OPENGL_INFO:");
		VT_CORE_INFO("VENDOR  : {0}", (char*)glGetString(GL_VENDOR));
		VT_CORE_INFO("VERSION : {0}", (char*)glGetString(GL_VERSION));
		VT_CORE_INFO("RENDERER: {0}", (char*)glGetString(GL_RENDERER));
	}

	void GLContext::SwapBuffers() {
		glfwSwapBuffers(windowHandle_);
	}

}
