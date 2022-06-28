#include "Cube.hpp"

Cube::Cube(int X, int Y)
{
    x = X;
    y = Y;
    visited = false;
    cubeNumber = (mazeWidth / cubeWidth * y) + x;
    numberOfWall = 4;
    for (int i = 0; i < numberOfWall; i++)
    {
        wall.push_back(Wall(X, Y));
    }
}

int Cube::GetX()
{
    return x;
}
int Cube::GetY()
{
    return y;
}
void Cube::SetVisited()
{
    visited = true;
}
bool Cube::GetVisited()
{
    return visited;
}
int Cube::GetCubeNumber()
{
    return cubeNumber;
}
int Cube::GetWallX(int side)
{
    return wall[side].WallGetX();
}
int Cube::GetWallY(int side)
{
    return wall[side].WallGetY();
}
void Cube::SetWallDestroyed(int side)
{
    wall[side].SetWallDestroyed();
}
bool Cube::GetWallDestroyed(int side)
{
    return wall[side].WallDestroyed();
}
