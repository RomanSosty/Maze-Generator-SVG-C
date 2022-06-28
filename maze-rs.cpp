#include "Cube.hpp"

vector<Cube> cube;
vector<Cube> edge[1000];
int numberOfCUbe = (mazeWidth / cubeWidth) * (mazeHeight / cubeHeight);


void create_cube() //Vytvoření seznamu kostek
{
    for (int i = 0, y = 0; i < numberOfCUbe; i++, y++)
    {
        for (int j = i, x = 0; x < mazeWidth / cubeWidth; j++, x++)
        {
            cube.push_back(Cube(x, y));
            i = j;
        }
    }
}

void DFS(int first) //Prohledávání do hloubky 
{
    if (cube[first].GetVisited())
        return;
    cube[first].SetVisited();

    for (auto t : edge[first])
    {
        if (!cube[t.GetCubeNumber()].GetVisited())
        {
            int dx = cube[first].GetX() - t.GetX();
            int dy = cube[first].GetY() - t.GetY();

            if (dx == -1)
            {
                cube[t.GetCubeNumber()].SetWallDestroyed(0);
                cube[first].SetWallDestroyed(2);
            }
            else if (dx == 1)
            {
                cube[t.GetCubeNumber()].SetWallDestroyed(2);
                cube[first].SetWallDestroyed(0);
            }
            else if (dy == -1)
            {
                cube[t.GetCubeNumber()].SetWallDestroyed(1);
                cube[first].SetWallDestroyed(3);
            }
            else if (dy == 1)
            {
                cube[t.GetCubeNumber()].SetWallDestroyed(3);
                cube[first].SetWallDestroyed(1);
            }

            DFS(t.GetCubeNumber());
        }
    }
}

void create_edge() //Vytvoření hran 
{
    for (int i = 0; i < numberOfCUbe; i++)
    {
        if (cube[i].GetX() + 1 < (mazeWidth / cubeWidth))
        {
            edge[i].push_back(Cube(cube[i].GetX() + 1, cube[i].GetY()));
        }

        if (cube[i].GetY() + 1 < (mazeHeight / cubeHeight))
        {
            edge[i].push_back(Cube(cube[i].GetX(), cube[i].GetY() + 1));
        }

        if (cube[i].GetX() - 1 >= 0)
        {
            edge[i].push_back(Cube(cube[i].GetX() - 1, cube[i].GetY()));
        }

        if (cube[i].GetY() - 1 >= 0)
        {
            edge[i].push_back(Cube(cube[i].GetX(), cube[i].GetY() - 1));
        }
    }
}

void shuffle_edge() //Prohození hran - pro náhodnost
{

    for (int i = 0; i < numberOfCUbe; i++)
    {
        unsigned int nahodne = rand();
        auto rng = default_random_engine{nahodne};
        shuffle(begin(edge[i]), end(edge[i]), rng);
    }
}

void draw() //Vykreslení obrázku v SVG
{
    ofstream maze;
    maze.open("obrazek.svg");

    maze << "<svg width=\" " << mazeWidth << "\" height=\"" << mazeHeight << "\">" << endl;
    for (int i = 0; i < numberOfCUbe; i++)
    {
        maze << "<rect x=\"" << cube[i].GetX() * cubeWidth
             << "\" y =\"" << cube[i].GetY() * cubeHeight
             << "\" width=\"" << cubeWidth
             << "\" height=\"" << cubeHeight
             << "\" fill=\"white\" />" << endl;
    }

    for (int i = 0; i < numberOfCUbe; i++)
    {
        if (!cube[i].GetWallDestroyed(0))
        {
            maze << "<line x1=\"" << cube[i].GetWallX(0) * cubeWidth
                 << "\" y1=\"" << cube[i].GetWallY(0) * cubeHeight
                 << "\" x2=\"" << (cube[i].GetWallX(0) * cubeWidth)
                 << "\" y2=\"" << (cube[i].GetWallY(0) * cubeHeight) + cubeHeight
                 << "\" stroke=\"black\" stroke-width=\"2\"  />" << endl;
        }
        if (!cube[i].GetWallDestroyed(1))
        {
            maze << "<line x1=\"" << cube[i].GetWallX(1) * cubeWidth
                 << "\" y1=\"" << cube[i].GetWallY(1) * cubeHeight
                 << "\" x2=\"" << (cube[i].GetWallX(1) * cubeWidth) + cubeWidth
                 << "\" y2=\"" << (cube[i].GetWallY(1) * cubeHeight)
                 << "\" stroke=\"black\" stroke-width=\"2\"  />" << endl;
        }
    }
    maze << "</svg>" << endl;
    maze.close();
}

int main()
{
    srand(time(NULL));

    create_cube();
    create_edge();
    shuffle_edge();

    DFS(0);

    draw();

    return 0;
}