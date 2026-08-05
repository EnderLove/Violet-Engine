#pragma once

#include "Violet/Renderer/RenderBuffer.h"

namespace Violet {
	class OpenGLVertexBuffer : public VertexBuffer {
	public:
		OpenGLVertexBuffer(float* vertices, unsigned int size);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;

	private:
		unsigned int renderID_;
	};
}