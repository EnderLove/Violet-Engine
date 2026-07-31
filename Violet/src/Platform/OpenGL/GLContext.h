#pragma once

#include "Violet/Renderer/RenderContext.h"

struct GLFWwindow; // Just to avoid including the hole lib :)

namespace Violet {
	class GLContext : public RenderContext {
	public:
		GLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:
		GLFWwindow* windowHandle_;
	};
}