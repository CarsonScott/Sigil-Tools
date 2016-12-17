#include "Tools.hpp"

PVector::PVector(float newX=0, float newY=0)
{
    x = newX;
    y = newY;
}

Color::Color(float red=1, float green=1, float blue=1, float alpha=1)
{
    r = red;
    g = green;
    b = blue;
    a = alpha;
}

void Color::setForeColor()
{
    slSetForeColor(r, g, b, a);
}

Shape::Shape(){}

void Shape::setPosition(PVector pos)
{
    position = pos;
}

void Shape::setPosition(float x, float y)
{
    position = PVector(x, y);
}

PVector Shape::getPosition()
{
    return position;
}

void Shape::setColor(Color c)
{
    color = c;
}

void Shape::setColor(float r, float g, float b, float a)
{
    color = Color(r, g, b, a);
}

Color Shape::getColor()
{
    return color;
}

CircleShape::CircleShape(float x=0, float y=0, float r=0)
{
    position = PVector(x, y);
    radius = r;
    color = Color();
}

float CircleShape::getRadius()
{
    return radius;
}

void CircleShape::drawFill()
{
    color.setForeColor();
    slCircleFill(position.x, position.y, radius, radius*2);
}

void CircleShape::drawOutline()
{
    color.setForeColor();
    slCircleOutline(position.x, position.y, radius, radius*2);
}


RectangleShape::RectangleShape(float x=0, float y=0, float w=0, float h=0)
{
    position = PVector(x, y);
    size = PVector(w, h);
    color = Color();
}

PVector RectangleShape::getSize()
{
    return size;
}

void RectangleShape::drawFill()
{
    color.setForeColor();
    slRectangleFill(position.x, position.y, size.x, size.y);
}

void RectangleShape::drawOutline()
{
    color.setForeColor();
    slRectangleOutline(position.x, position.y, size.x, size.y);
}