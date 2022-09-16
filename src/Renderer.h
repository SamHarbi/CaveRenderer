#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "DrawnObject.h"
#include "Layer.h"

class Renderer {

	private:
		int indexBoundCount;

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

		GLuint generateBuffer();

		void bindIBO(GLuint ibo, GLuint indices[], int size);

		//Draw all vertices in Buffer
		void draw(Layer& layer);

};

