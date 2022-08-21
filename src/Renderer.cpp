#pragma once

#include "Renderer.h"

Renderer::Renderer()
{

}

void Renderer::createVAO()
{
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
}

void Renderer::stage(DrawnObject& DO)
{
    //glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), DO.GetPositions(), GL_STATIC_DRAW);
}

void Renderer::stage(Layer& layer)
{
    glBufferData(GL_ARRAY_BUFFER, layer.getVertexCount() * sizeof(float), layer.getAllVertex(), GL_STATIC_DRAW);
}

unsigned int Renderer::generateBuffer()
{
    //Create Buffer ID
    unsigned int ibo;
    glGenBuffers(1, &ibo);

    return ibo;
}

void Renderer::bindIBO(unsigned int ibo, unsigned int indices[], int size)
{
    //Bind Buffer and set it
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(unsigned int), indices, GL_STATIC_DRAW);
}

void Renderer::createBuffer()
{

}