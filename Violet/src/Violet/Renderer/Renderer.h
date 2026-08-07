#pragma once

namespace Violet {
	enum class RenderAPI { NONE = 0, OPENGL, DIRECT3D, VULKAN };

	class Renderer {
	public:
		static inline RenderAPI GetAPI() { return renderAPI_; }
	private:
		static RenderAPI renderAPI_;
	};


}