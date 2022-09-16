#pragma once

#include "Renderer.h"

Renderer::Renderer()
{
    indexBoundCount = 0;
}

void Renderer::createVAO()
{
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
}

void Renderer::stage(DrawnObject& DO)
{
    glBufferData(GL_ARRAY_BUFFER, DO.getVertexSize() * sizeof(float), &DO.GetPositions()[0], GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, DO.getVertexSize()/2 * sizeof(GLuint), &DO.GetIndexPositions()[0], GL_STATIC_DRAW);
}

void Renderer::stage(Layer& layer)
{   
    glBufferData(GL_ARRAY_BUFFER, layer.getVertexCount() * sizeof(float), layer.getAllVertex(), GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, layer.getIndexCount() * sizeof(GLuint), layer.getAllIndex(), GL_STATIC_DRAW);
}

GLuint Renderer::generateBuffer()
{
    //Create Buffer ID
    GLuint ibo;
    glGenBuffers(1, &ibo);

    return ibo;
}

void Renderer::bindIBO(GLuint ibo, GLuint indices[], int size)
{
    //Bind Buffer and set it
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(GLuint), indices, GL_STATIC_DRAW);
}

void Renderer::draw(Layer& layer)
{
    for (int i = 0; i < layer.getObjectCount(); i++)
    {
        glDrawElements(GL_POINTS, layer.getObjectLength(i), GL_UNSIGNED_INT, nullptr);
    }
}