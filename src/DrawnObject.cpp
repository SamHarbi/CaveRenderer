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
	for (int i = 0; i < 8; i++)
	{
		positions[i] = newPos[i];
	}
}
std::vector<float> DrawnObject::GetPositions()
{
	return positions;
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

}


