#pragma once

#include "Buffer.h"
#include <cstdint>

class VertexBuffer {
	public:
	VertexBuffer(int size);
	VertexBuffer(float* vertices, int size);
	~VertexBuffer();

	void Bind();
	void Unbind();
	void SetData(const void* data, uint32_t size);

	BufferLayout& GetLayout() { return m_Layout; };
	void SetLayout(const BufferLayout& layout) { m_Layout = layout; };
	
	private:
	unsigned int m_ID;
	BufferLayout m_Layout;
};