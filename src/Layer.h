#pragma once
#include <vector>
#include "DrawnObject.h"
#include <iostream>
#include <stack>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


/*This class represents a collection of objects that rendered in a
single batch. This is done by having a list of all vertex points to be rendered
that is sent to the gpu at the same time
*/

class Layer {
	private:
		//int id;
		std::vector<float> positions; //Used by OpenGL as vertex positions -1.0 to 1.0
		std::vector<GLuint> indexPos;
		int indexOffset; //Index when adding multiple objects to same buffer
		std::vector<int> objectLength;

	public:
		Layer();
		void AddObject(DrawnObject& obj);
		int getVertexCount();
		int getIndexCount();
		float* getAllVertex();
		GLuint* getAllIndex();
		int getObjectCount();
		int getObjectLength(int index); 

};