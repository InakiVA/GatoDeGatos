#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;
class Tile
{
  private:
    char tile;
  public:
    Tile();
    char getTile();
    void setTile(char _c);
};