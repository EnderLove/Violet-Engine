#include "vtpch.h"
#include "Shader.h"

#include <glad/glad.h>

#include "Platform/OpenGL/GLShader.h"

namespace Violet {

	ShaderSource Shader::shaderSrc_ = ShaderSource::GLSL;

	Shader* Shader::Create(const std::string& vertexSource, const std::string& fragmentSource) {
		switch (Shader::GetSrc()) {
			case ShaderSource::NONE : VT_CORE_ASSERT(false, "ShaderSource::NONE is not supported!"); return nullptr;
			case ShaderSource::SPIRV: VT_CORE_ASSERT(false, "ShaderSource::SPIRV is not supported!"); return nullptr;
			case ShaderSource::HLSL : VT_CORE_ASSERT(false, "ShaderSource::HLSL is not supported!"); return nullptr;
			case ShaderSource::GLSL : return new GLShader(vertexSource, fragmentSource);
		}

		VT_CORE_ASSERT(false, "Unknow Shader Source File!!");
		return nullptr;
	}
}