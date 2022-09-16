#pragma once
#include "DrawnObject.h"


DrawnObject::DrawnObject(int size)
{
	vertexSize = size;
	
	for (int i = 0; i < vertexSize; i++)
	{
		positions.push_back(0);
	}

	float cordinates [3] = { 0, 0, 0 };

}

void DrawnObject::SetPositions(float newPos[])
{
	for (int i = 0; i < vertexSize; i++)
	{
		positions[i] = newPos[i];
	}

	genIndexData();
}
std::vector<float> DrawnObject::GetPositions()
{
	return positions;
}

std::vector<GLuint> DrawnObject::GetIndexPositions()
{
	return indexPos;
}

int DrawnObject::getVertexSize()
{
	return vertexSize;
}


void DrawnObject::SetSquareCordinates2D(float x, float y, float size)
{
	positions[0] = x;
	positions[1] = y;

	positions[2] = x + size;
	positions[3] = y;

	positions[4] = x + size;
	positions[5] = y + size;

	positions[6] = x;
	positions[7] = y + size;

	genIndexData();

}

void DrawnObject::genIndexData()
{
	std::unordered_map<std::string, int> indices;

	for (int i = 0; i < vertexSize-1; i=i+2)
	{
		//Create a single Key value for map
		std::string key = std::to_string(positions[i]) + std::to_string(positions[i + 1]);

		auto insert = indices.insert({ key, i });
		if (insert.second == true)
		{
			indexPos.push_back(i/2);
		}
		else
		{
			int index = indices[key];
			indexPos.push_back(index/2);
			
		}
	}
}


