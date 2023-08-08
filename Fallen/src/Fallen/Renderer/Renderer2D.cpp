#include "Renderer2D.h"
#include "Fallen/Logger.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/gtx/string_cast.hpp>

struct QuadVertex {
	glm::vec3 Position;
	glm::vec3 Scale;
	glm::vec4 Color;
};

struct Data {
	const int MaxQuads = 10000;
	const int MaxVertices = MaxQuads * 4;
	const int MaxIndices = MaxQuads * 6;

	VertexArray* QuadVertexArray;
	VertexBuffer* QuadVertexBuffer;
	IndexBuffer* QuadIndexBuffer;
	Shader* TextureShader;
	//Texture2D* WhiteTexture;

	int QuadIndexCount = 0;
	QuadVertex* QuadVertexBufferBase = nullptr;
	QuadVertex* QuadVertexBufferPtr = nullptr;
};

static Data data;

void Renderer2D::Init() {

	data.QuadVertexArray = new VertexArray();
	data.QuadVertexBuffer = new VertexBuffer(data.MaxVertices * sizeof(QuadVertex));
	data.QuadVertexBuffer->SetLayout({
		{ShaderDataType::Float3, "a_Position"},
		{ShaderDataType::Float3, "a_Scale"},
		{ShaderDataType::Float4, "a_Color"},
		//{ShaderDataType::Float2, "a_TexCoord"},
	});
	
	data.QuadVertexArray->AddVertexBuffer(*data.QuadVertexBuffer);

	data.QuadVertexBufferBase = new QuadVertex[data.MaxVertices];

	uint32_t* quadIndices = new uint32_t[data.MaxIndices];

	uint32_t offset = 0;
	for (uint32_t i = 0; i < data.MaxIndices; i += 6)
	{
		quadIndices[i + 0] = offset + 0;
		quadIndices[i + 1] = offset + 1;
		quadIndices[i + 2] = offset + 2;

		quadIndices[i + 3] = offset + 2;
		quadIndices[i + 4] = offset + 3;
		quadIndices[i + 5] = offset + 0;

		offset += 4;
	}

	IndexBuffer* quadIB = new IndexBuffer(quadIndices, data.MaxIndices);
	data.QuadVertexArray->SetIndexBuffer(*quadIB);

	delete[] quadIndices;

	data.TextureShader = new Shader("C:/Dev/Fallen/FeatureTester/assets/shaders/Default.vs", "C:/Dev/Fallen/FeatureTester/assets/shaders/Default.fs");
	data.TextureShader->Use();
}

void Renderer2D::Begin()
{
	data.QuadIndexCount = 0;
	data.QuadVertexBufferPtr = data.QuadVertexBufferBase;
}

void Renderer2D::End()
{
	uint32_t dataSize = (uint8_t*)data.QuadVertexBufferPtr - (uint8_t*)data.QuadVertexBufferBase;
	data.QuadVertexBuffer->SetData(data.QuadVertexBufferBase, dataSize);

	Draw();
}

void Renderer2D::Draw()
{
	glDrawElements(GL_TRIANGLES, data.QuadIndexCount, GL_UNSIGNED_INT, nullptr);
}

void Renderer2D::DrawQuad(glm::vec2 position, glm::vec2 size, glm::vec4 color)
{
	DrawQuad({ position.x, position.y, 0.0f }, { size.x, size.y, 0.0f }, color);
}

void Renderer2D::DrawQuad(glm::vec3 position, glm::vec3 size, glm::vec4 color)
{
	INFO("size x: %f", size.x);
	data.QuadVertexBufferPtr->Position = position;
	data.QuadVertexBufferPtr->Scale = size;
	data.QuadVertexBufferPtr->Color = color;
	//data.QuadVertexBufferPtr->TexCoord = { .0f, .0f };
	data.QuadVertexBufferPtr++;

	data.QuadVertexBufferPtr->Position = { position.x + size.x, position.y, 0.0f };
	data.QuadVertexBufferPtr->Scale = size;
	data.QuadVertexBufferPtr->Color = color;
	//data.QuadVertexBufferPtr->TexCoord = { 1.0f, .0f };
	data.QuadVertexBufferPtr++;

		data.QuadVertexBufferPtr->Position = { position.x + size.x, position.y + size.y, 0.0f };
	data.QuadVertexBufferPtr->Scale = size;
	data.QuadVertexBufferPtr->Color = color;
	//data.QuadVertexBufferPtr->TexCoord = { 1.0f, 1.0f };
	data.QuadVertexBufferPtr++;

	data.QuadVertexBufferPtr->Position = { position.x, position.y + size.y, 0.0f };
	data.QuadVertexBufferPtr->Scale = size;
	data.QuadVertexBufferPtr->Color = color;
	//data.QuadVertexBufferPtr->TexCoord = { .0f, 1.0f };
	data.QuadVertexBufferPtr++;

	data.QuadIndexCount += 6;

	//data.TextureShader->SetVec4("u_Color", color);
}
