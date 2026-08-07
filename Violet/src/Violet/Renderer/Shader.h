#pragma once

#include <string>

namespace Violet {
	enum class ShaderSource { NONE = 0, GLSL, HLSL, SPIRV };

	class Shader {
	public:
		//Shader(const std::string& vertexSource, const std::string& fragmentSource);
		~Shader() {};

		virtual void Bind()   const = 0;
		virtual void Unbind() const = 0;

		static Shader* Create(const std::string& vertexSource, const std::string& fragmentSource);
		static inline ShaderSource GetSrc() { return shaderSrc_; }

		// TODO
		/*
			Here prob I should add some setters for uniforms: SetMat4, SetFloat, Set.... 
		*/

	private:
		//unsigned int renderID_ = 0; // THIS WILL BE DEFINED INTO THE SPECIFIC SHADER SUBCLASS
		static ShaderSource shaderSrc_;
	};
}