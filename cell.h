#ifndef CELL_H
#define CELL_H

class Cell
{
  int neighboors;
  int x;
  int y;
  bool alive;
  public:
    Cell();
    Cell(bool _alive, int _x, int _y);

    bool is_alive();

    void update(Cell ** grid, int n);
};

#include "cell.hpp"

#endif
