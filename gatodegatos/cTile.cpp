#include "cTile.h"

Tile::Tile()
{
  tile='-';
}
char Tile::getTile()
{
  return tile;
}
void Tile::setTile(char _c)
{
  tile=_c;
}