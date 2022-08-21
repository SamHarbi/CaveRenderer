#pragma once
#include <vector>
#include "DrawnObject.h"
#include <iostream>


/*This class represents a collection of objects that rendered in a
single batch. This is done by having a list of all vertex points to be rendered
that is sent to the gpu at the same time
*/

class Layer {
	private:
		//int id;
		std::vector<float> positions; //Used by OpenGL as vertex positions -1.0 to 1.0

	public:
		Layer();
		void AddObject(DrawnObject& obj);
		float getVertexCount();
		float* getAllVertex();

};