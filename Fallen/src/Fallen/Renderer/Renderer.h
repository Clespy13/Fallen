#pragma once


class Renderer {
	public:

	static void ClearColor(float* color);
	static void ClearColor(float red, float green, float blue, float alpha);
	static void Clear(int code);

};