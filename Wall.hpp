class Wall
{

private:
    int x, y;
    bool destroyed;

public:
    Wall(int x, int y);
    int WallGetX();
    int WallGetY();
    void SetWallDestroyed();
    bool WallDestroyed();
};
