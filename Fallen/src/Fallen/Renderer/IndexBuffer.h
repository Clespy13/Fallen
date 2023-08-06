#pragma once

class IndexBuffer {
	public:
	IndexBuffer();
	IndexBuffer(unsigned int* indices, unsigned int size);
	~IndexBuffer();

	void Bind();
	void Unbind();

	unsigned int GetCount() { return m_Count; }

	private:
	unsigned int m_ID;
	unsigned int m_Count;

};