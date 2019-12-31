//****************************************************************************
// Copyright © 2019 Jan Erik Breimo. All rights reserved.
// Created by Jan Erik Breimo on 2019-07-16.
//
// This file is distributed under the BSD License.
// License text is included with the source distribution.
//****************************************************************************
#pragma once
#include "Tungsten/Tungsten.hpp"

class CirclesShaderProgram
{
public:
    void setup();

    Tungsten::ProgramHandle program;
    Tungsten::Uniform<float> xFactor;
    Tungsten::Uniform<float> yFactor;
    Tungsten::Uniform<Xyz::Vector2f> centerPoint;
    Tungsten::Uniform<float> phase;
    Tungsten::Uniform<float> threshold;

    GLuint positionAttribute;
};
