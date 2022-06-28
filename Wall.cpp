#include "Wall.hpp"

Wall::Wall(int X, int Y)
{
    x = X;
    y = Y;
    destroyed = false;
}

int Wall::WallGetX()
{
    return x;
}
int Wall::WallGetY()
{
    return y;
}

void Wall::SetWallDestroyed()
{
    destroyed = true;
}
bool Wall::WallDestroyed()
{
    return destroyed;
}