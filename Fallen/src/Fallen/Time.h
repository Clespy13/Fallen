#pragma once
#include <GLFW/glfw3.h>

class Time {
	public:

	static double GetTime() { return glfwGetTime(); }
};

class TimeStep {
	public:
	TimeStep(double time = 0.0f) : m_Time(time) {}

	operator double() const { return m_Time; }

	private:
	double m_Time;
};