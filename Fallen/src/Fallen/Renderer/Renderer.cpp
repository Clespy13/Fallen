#include "Renderer.h"

#include <glad/glad.h>

void Renderer::ClearColor(float* color)
{
	glClearColor(color[0], color[1], color[2], color[3]);
}

void Renderer::ClearColor(float red, float green, float blue, float alpha)
{
	glClearColor(red, green, blue, alpha);
}

void Renderer::Clear(int code)
{
	glClear(code);
}
