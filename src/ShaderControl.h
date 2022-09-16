#pragma once

#include <string>

#include <GL/glew.h>

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

ShaderProgramSource ParseShader(const std::string& filepath);

GLuint CompileShader(GLuint type, const std::string& source);

GLuint CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

