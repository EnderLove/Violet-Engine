#include "vtpch.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace Violet {
	OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, unsigned int size) {
		glCreateBuffers(1, (GLuint)renderID_);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer() { glDeleteBuffers(1, renderID_); }

	void OpenGLVertexBuffer::Bind() const {
		glBindBuffer(1, renderID_);
	}
}