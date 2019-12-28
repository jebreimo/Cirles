//****************************************************************************
// Copyright © 2019 Jan Erik Breimo. All rights reserved.
// Created by Jan Erik Breimo on 2019-07-16.
//
// This file is distributed under the BSD License.
// License text is included with the source distribution.
//****************************************************************************
#include "CirclesShaderProgram.hpp"
#include "Circles-frag.glsl.hpp"
#include "Circles-vert.glsl.hpp"

void CirclesShaderProgram::setup()
{
    program = Tungsten::createProgram();
    auto vertexShader = Tungsten::createShader(GL_VERTEX_SHADER,
                                               Circles_vert);
    Tungsten::attachShader(program, vertexShader);

    auto fragmentShader = Tungsten::createShader(GL_FRAGMENT_SHADER,
                                                 Circles_frag);
    Tungsten::attachShader(program, fragmentShader);
    Tungsten::linkProgram(program);
    Tungsten::useProgram(program);

    positionAttribute = Tungsten::getVertexAttribute(program, "a_Position");
    centerPoint = Tungsten::getUniform<Xyz::Vector2f>(
            program, "u_CenterPoint");
    aspectRatio = Tungsten::getUniform<float>(program, "u_AspectRatio");
    phase = Tungsten::getUniform<float>(program, "u_Phase");
    threshold = Tungsten::getUniform<float>(program, "u_Threshold");
}
