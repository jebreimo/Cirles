//****************************************************************************
// Copyright © 2019 Jan Erik Breimo. All rights reserved.
// Created by Jan Erik Breimo on 2019-07-16.
//
// This file is distributed under the BSD License.
// License text is included with the source distribution.
//****************************************************************************
#version 100

uniform highp vec2 u_CenterPoint;
uniform highp float u_XFactor;
uniform highp float u_YFactor;
uniform highp float u_Phase;
uniform highp float u_Threshold;

void main()
{
    highp vec2 p = vec2(gl_FragCoord);
    p.x *= u_XFactor;
    p.y *= u_YFactor;
    p = u_CenterPoint - p;
    highp float value = sin(50.0 * sqrt(dot(p, p)) + u_Phase);
    if (value < u_Threshold)
        discard;
    gl_FragColor = vec4(1.0, 1.0, 1.0, 0.5);
}
