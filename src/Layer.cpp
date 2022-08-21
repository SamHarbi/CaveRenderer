#include "Layer.h"


Layer::Layer()
{
	
}

void Layer::AddObject(DrawnObject& obj)
{
	std::vector<float> objPos = obj.GetPositions();
	for (int i = 0; i < obj.getVertexSize(); i++)
	{
		positions.push_back(objPos[i]);
		std::cout << objPos[i] << std::endl;
	}
}

float Layer::getVertexCount()
{
	return positions.size();
}

float* Layer::getAllVertex()
{
	return &positions[0]; //This doesn't feel great, make sure it's safe
}