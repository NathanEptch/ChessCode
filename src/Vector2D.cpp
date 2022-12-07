#include "Vector2D.h"

Vector2D::Vector2D()
{
    x = 0;
    y = 0;
}

Vector2D::~Vector2D()
{
}

int Vector2D::getX()
{
    return x;
}

int Vector2D::getY()
{
    return y;
}

void Vector2D::setX(int Xvalue)
{
    x = Xvalue;
}

void Vector2D::setY(int Yvalue)
{
    y = Yvalue;
}