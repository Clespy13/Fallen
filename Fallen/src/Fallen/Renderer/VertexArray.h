#pragma once

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Buffer.h"

#include <vector>

class VertexArray {
	public:
	VertexArray();
	~VertexArray();

	void Bind();
	void Unbind();
	
	void AddVertexBuffer(VertexBuffer& buffer);
	void SetIndexBuffer(IndexBuffer& buffer);

	private:
	unsigned int m_ID;
	IndexBuffer m_IndexBuffer;
	uint32_t m_VertexBufferIndex = 0;
	std::vector<VertexBuffer> m_VertexBuffers;
};