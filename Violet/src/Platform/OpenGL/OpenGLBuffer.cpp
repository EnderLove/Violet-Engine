#include "vtpch.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace Violet {
/////////////////////////////// VERTEX_BUFFER

	OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, unsigned int size) {
		glCreateBuffers(1, &renderID_); // OpenGL 4.5 feature :)
		glBindBuffer(GL_ARRAY_BUFFER, renderID_);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer() { glDeleteBuffers(1, &renderID_); }

	void OpenGLVertexBuffer::Bind()   const { glBindBuffer(GL_ARRAY_BUFFER, renderID_); }
	void OpenGLVertexBuffer::Unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0        ); }

//////////////////////////////// INDEX_BUFFER 

	OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int* indices, unsigned int count) : indexCount_(count) {
		glCreateBuffers(1, &renderID_); // OpenGL 4.5 feature :)
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderID_);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices, GL_STATIC_DRAW);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer() { glDeleteBuffers(1, &renderID_); }

	void OpenGLIndexBuffer::Bind()   const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderID_); }
	void OpenGLIndexBuffer::Unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
}