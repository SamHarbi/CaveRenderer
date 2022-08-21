#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "DrawnObject.h"
#include "Layer.h"

class Renderer {

	public:
		Renderer();

		int getInitState();

		GLFWwindow* getWindow();
		
		//Clear all errors from OpenGL
		void GLClearError();

		//Print errors if any
		void GLLogCall();

		//Create a single Vertex Array Object and bind it
		void createVAO();

		//Send data to gpu for drawing
		void stage(DrawnObject& DO);
		void stage(Layer& layer);

		unsigned int generateBuffer();

		void bindIBO(unsigned int ibo, unsigned int indices[], int size);

		//Creates and binds a buffer 
		void createBuffer();

};

