#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>
#include <ctime>
#include "Wall.hpp"

using namespace std;

const int mazeWidth = 600;
const int mazeHeight = 600;
const int cubeWidth = 30;
const int cubeHeight = 30;

class Cube
{

private:
    int x, y;
    bool visited;
    int cubeNumber;
    vector<Wall> wall;
    int numberOfWall;

public:
    Cube(int X, int Y);
    int GetX();
    int GetY();
    void SetVisited();
    bool GetVisited();
    int GetCubeNumber();
    int GetWallX(int strana);
    int GetWallY(int strana);
    void SetWallDestroyed(int strana);
    bool GetWallDestroyed(int strana);
};
