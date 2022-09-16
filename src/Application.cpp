#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Renderer.h"
#include "ErrorHandle.h"
#include "ShaderControl.h"
#include "DrawnObject.h"
#include "Layer.h"


int main(void)
{
    /*
        OPENGL / GLFW Window Setup
    */

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSwapInterval(1);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        std::cout << "Error with glewInit" << std::endl;
    }

    /*
        API Renderer Data Setup - i.e what to draw and where
    */

    Renderer renderer;

    Layer scene;
    DrawnObject a(8), b(8), c(8);

    a.SetSquareCordinates2D(-0.8f, 0.4f, 0.5f);

    //float apos[8] = {0.2f, 0.5f, -0.2f, 0.3f, -0.5f, -0.5f, 0.4f, 0.4f };
    //float apos2[2] = { -0.9f, -0.9f };
    //a.SetPositions(apos);
    //b.SetPositions(apos2);

    b.SetSquareCordinates2D(-0.6f, -0.6f, 0.5f);
    c.SetSquareCordinates2D(-0.1f, -0.1f, 0.2f);

    scene.AddObject(a);
    scene.AddObject(b);
    scene.AddObject(c);

    /*
        OPENGL Buffers + Shaders, still need to abstract / tidy
    */

    renderer.createVAO();

    GLuint buffer = renderer.generateBuffer();
    glBindBuffer(GL_ARRAY_BUFFER, buffer); //Single IBO Buffer

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

    GLuint elements;
    glGenBuffers(1, &elements);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elements);

    //Draw an Object 
    renderer.stage(scene);

    //Create and bind shader
    ShaderProgramSource source = ParseShader("res/shaders/Basic.shader");
    GLuint shader = CreateShader(source.VertexSource, source.FragmentSource);
    glUseProgram(shader);

    int location = glGetUniformLocation(shader, "u_Color");



    /*
        App Loop
    */
    
    float r = 0.0f;
    float increment = 0.05f;

    double currTime = glfwGetTime();
    double lastTime = currTime;
    float frames = 0;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        frames++;
        currTime = glfwGetTime();
        if (currTime - lastTime >= 1.0)
        {
            std::cout << double(frames) << std::endl;
            lastTime = currTime;
            frames = 0;
        }

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader);
        glUniform4f(location, r, 0.3f, 0.8f, 1.0f);

        GLClearError();
        //glDrawArrays(GL_LINE_LOOP, 0, 4);
        //glDrawArrays(GL_LINE_LOOP, 4, 4);
        //glDrawArrays(GL_LINE_LOOP, 8, 4);

        //glDrawElements(GL_POINTS, 8, GL_UNSIGNED_INT, nullptr);
        //glDrawElements(GL_POINTS, 8, GL_UNSIGNED_INT, nullptr);
        //glDrawElements(GL_POINTS, 8, GL_UNSIGNED_INT, nullptr);
     
        renderer.draw(scene);

        GLLogCall();

        if (r > 1.0f)
        {
            increment = -0.05f;
        }
        else if (r < 0.0f)
        {
            increment = 0.05f;
        }
            
        r = r + increment;

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        
        
    }

    glDeleteProgram(shader);

    glfwTerminate();
    return 0;
}