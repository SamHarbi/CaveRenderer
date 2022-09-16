#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Util {
	private:
		int frames;
		double lastTime;

	public:
		Util();
		int getFramesSince();

};

