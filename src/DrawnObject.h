#pragma once
#include <vector>

/*This class represents an object that is rendered to the screen. This object consists of
8 Vertex Points exactly (TODO allow any number of vertex points)*/

class DrawnObject {
	private:
		int vertexSize; //How many vertices this object is made of
		std::vector<float> positions; //Used by OpenGL as vertex positions -1.0 to 1.0
		float cordinates[3]; //Cordinates that are converted to position

	public:
		DrawnObject(int vertexSize); 
		void SetPositions(float newPos[]); //Set Cords of this Object that will be drawn
		std::vector<float> GetPositions(); //Get Cords to then draw or otherwise
		int getVertexSize();

		void SetSquareCordinates2D(float x, float y, float size); //Shortcut for a square
		
};
