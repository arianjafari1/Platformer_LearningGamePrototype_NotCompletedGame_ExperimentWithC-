#pragma once
#include <iostream>


class BoundingBoxCollision
{
public:

    BoundingBoxCollision(float _x, float _y, float _w, float _h);

    bool isColliding(BoundingBoxCollision other);

private:
    float x;
    float y;
    float w;
    float h;

};





