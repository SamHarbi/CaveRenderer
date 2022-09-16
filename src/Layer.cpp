#include "Layer.h"


Layer::Layer()
{
	indexOffset = 0;
}

//reallocating memory here, would be better to just point to the address saved by DrawnObject
void Layer::AddObject(DrawnObject& obj)
{
	std::vector<float> objPos = obj.GetPositions();
	std::vector<GLuint> objInd = obj.GetIndexPositions();

	for (int i = 0; i < obj.getVertexSize(); i++)
	{
		positions.push_back(objPos[i]);
		if (i < (obj.getVertexSize() / 2))
		{
			indexPos.push_back(objInd[i] + indexOffset);
			
		}
	}

	indexOffset += obj.getVertexSize() / 2;
	objectLength.push_back(indexOffset);
}

int Layer::getVertexCount()
{
	return positions.size();
}

int Layer::getIndexCount()
{
	return indexPos.size();
}

float* Layer::getAllVertex()
{
	return &positions[0]; 
}

GLuint* Layer::getAllIndex()
{
	return &indexPos[0]; 
}

int Layer::getObjectLength(int index)
{
	return objectLength[index];
}

int Layer::getObjectCount()
{
	return objectLength.size();
}