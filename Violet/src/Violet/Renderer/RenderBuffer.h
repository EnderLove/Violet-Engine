#pragma once


namespace Violet {
	
	class VertexBuffer {
	public:
		virtual ~VertexBuffer();

		virtual void Bind()   const = 0;
		virtual void Unbind() const = 0;

		virtual VertexBuffer* Create(float* vertices, unsigned int size);
	};

	class IndexBuffer {
		virtual ~IndexBuffer();

		virtual void Bind()   const = 0;
		virtual void Unbind() const = 0;

		virtual IndexBuffer* Create(unsigned int* indices, unsigned int size);
	};
}