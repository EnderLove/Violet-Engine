#pragma once

#include <string>

namespace Violet {
	class Shader {
	public:
		Shader(const std::string& vertexSource, const std::string& fragmentSource);
		~Shader();

		void Bind();
		void Unbind();

	private:
		unsigned int renderID_;
	};
}