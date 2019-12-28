//****************************************************************************
// Copyright © 2019 Jan Erik Breimo. All rights reserved.
// Created by Jan Erik Breimo on 2019-07-16.
//
// This file is distributed under the BSD License.
// License text is included with the source distribution.
//****************************************************************************
#include <iostream>
#include <chrono>
#include <Tungsten/Shapes.hpp>
#include "CirclesShaderProgram.hpp"

double getTime()
{
    using namespace std::chrono;
    duration<double> time = steady_clock::now().time_since_epoch();
    return time.count();
}

class CirclesApp : public Tungsten::SdlApplication
{
public:
    void setup() override
    {
        m_VertexArray = Tungsten::generateVertexArray();
        Tungsten::bindVertexArray(m_VertexArray);

        m_Buffers = Tungsten::generateBuffers(2);
        Tungsten::ArrayBufferBuilder builder(3);
        Tungsten::addRectangle(builder, Xyz::Rectangle<float>({-1, -1}, {2, 2}));
        setBuffers(m_Buffers[0], m_Buffers[1], builder);
        m_ElementCount = builder.elementCount();

        m_Program.setup();
        Tungsten::defineVertexAttributePointer(m_Program.positionAttribute, 3,
                                               GL_FLOAT, false, 0, 0);
        Tungsten::enableVertexAttribute(m_Program.positionAttribute);
    }

    void update() override
    {
        m_Program.phase.set(float(m_Phase * 0.01));
        if (++m_Phase > 628)
            m_Phase = 0;
    }

    void draw() override
    {
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_Program.aspectRatio.set(aspectRatio());

        auto time = getTime();
        m_Program.threshold.set(float(cos(time) * 0.299 + 0.7));
        auto p = Xyz::rotate3(time * 0.8) * Xyz::Vector3d{-0.5, 0.5, 1.0};
        m_Program.centerPoint.set(Xyz::Vector2f{float(p[0]), float(p[1])});
        Tungsten::drawElements(GL_TRIANGLES, m_ElementCount, GL_UNSIGNED_SHORT);
        p = Xyz::rotate3(time * 1.3) * Xyz::Vector3d{0.5, 0.0, 1.0};
        m_Program.centerPoint.set(Xyz::Vector2f{float(p[0]), float(p[1])});
        m_Program.threshold.set(float(cos(time * 0.5) * 0.299 + 0.7));
        Tungsten::drawElements(GL_TRIANGLES, m_ElementCount, GL_UNSIGNED_SHORT);
    }
private:
    std::vector<Tungsten::BufferHandle> m_Buffers;
    Tungsten::VertexArrayHandle m_VertexArray;
    CirclesShaderProgram m_Program;
    int m_Phase = 0;
    GLsizei m_ElementCount = 0;
};

int main()
{
    CirclesApp app;
    try
    {
        app.run();
    }
    catch (Tungsten::GlError& ex)
    {
        std::cout << ex.what() << "\n";
        return 1;
    }
    return 0;
}
