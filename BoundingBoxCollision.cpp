#include "BoundingBoxCollision.h"

BoundingBoxCollision::BoundingBoxCollision(float _x, float _y, float _w, float _h)
{
    this->x = _x;
    this->y = _y;
    this->w = _w;
    this->h = _h;
};

bool BoundingBoxCollision::isColliding(BoundingBoxCollision other)
{
    return (x <= other.x + other.w &&

        x + w >= other.x &&

        y <= other.y + other.h &&

        h + y >= other.y); //cheking for collision on all sides
    std::cout << "It has collided" << std::endl;
};