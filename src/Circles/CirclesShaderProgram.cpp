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
    using namespace Tungsten;
    program = createProgram();
    auto vertexShader = createShader(GL_VERTEX_SHADER, Circles_vert);
    attachShader(program, vertexShader);

    auto fragmentShader = createShader(GL_FRAGMENT_SHADER, Circles_frag);
    attachShader(program, fragmentShader);
    linkProgram(program);
    useProgram(program);

    positionAttribute = getVertexAttribute(program, "a_Position");
    centerPoint = getUniform<Xyz::Vector2f>(program, "u_CenterPoint");
    xParams = getUniform<Xyz::Vector2f>(program, "u_XParams");
    yParams = getUniform<Xyz::Vector2f>(program, "u_YParams");
    phase = getUniform<float>(program, "u_Phase");
    threshold = getUniform<float>(program, "u_Threshold");
}
