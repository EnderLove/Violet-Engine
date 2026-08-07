#pragma once

#include "Violet/Renderer/Shader.h"

namespace Violet {
	class GLShader : public Shader {
	public:
		GLShader(const std::string& vertexSource, const std::string& fragmentSource);
		~GLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;

	private:
		unsigned int renderID_ = 0;
	};
}