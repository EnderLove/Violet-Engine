#include "vtpch.h"
#include "RenderBuffer.h"
#include "Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Violet {
	VertexBuffer* VertexBuffer::Create(float* vertices, unsigned int size) {
		switch (Renderer::GetAPI()) {
			case RenderAPI::NONE: VT_CORE_ASSERT(false, "RenderAPI::NONE is not supported!"); return nullptr;
			case RenderAPI::OPENGL: return new OpenGLVertexBuffer(vertices, size);
		}

		VT_CORE_ASSERT(flase, "Unknow render API!");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(unsigned int* indices, unsigned int count) {
		switch (Renderer::GetAPI()) {
		case RenderAPI::NONE: VT_CORE_ASSERT(false, "RenderAPI::NONE is not supported!"); return nullptr;
		case RenderAPI::OPENGL: return new OpenGLIndexBuffer(indices, count);
		}

		VT_CORE_ASSERT(flase, "Unknow render API!");
		return nullptr;
	}
}