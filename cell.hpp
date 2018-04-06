Cell::Cell()
    {
      neighboors = 0;
      x = -1;
      y = -1;
      alive = false;
    }

Cell::Cell(bool _alive, int _x, int _y)
    {
      neighboors = 0;
      alive = _alive;
      x = _x;
      y = _y;
    }

bool Cell::is_alive()
    {
      return alive;
    }

void Cell::update(Cell ** grid, int n)
    {
      neighboors = 0;
      //Checking cell to the right
      if (x < (n - 1))
      {
        neighboors += static_cast<int>(grid[y][x + 1].is_alive());
      }
      //Checking cell to the left
      if (x > 0)
      {
        neighboors += static_cast<int>(grid[y][x - 1].is_alive());
      }
      //Checking cell under current cell
      if (y < (n - 1))
      {
        neighboors += static_cast<int>(grid[y + 1][x].is_alive());
      }
      //Checking cell above current cell
      if (y > 0)
      {
        neighboors += static_cast<int>(grid[y - 1][x].is_alive());
      }
      //Checking cell to the top-right
      if ((x < (n - 1)) && (y > 0))
      {
        neighboors += static_cast<int>(grid[y - 1][x + 1].is_alive());
      }
      //Checking cell to the bottom-right
      if ((x < (n - 1)) && (y < (n - 1)))
      {
        neighboors += static_cast<int>(grid[y + 1][x + 1].is_alive());
      }
      //Checking cell to the top-left
      if ((x > 0) && (y > 0))
      {
        neighboors += static_cast<int>(grid[y - 1][x - 1].is_alive());
      }
      //Checking cell to the bottom-left
      if ((x > 0) && (y < (n - 1)))
      {
        neighboors += static_cast<int>(grid[y + 1][x - 1].is_alive());
      }

      if (neighboors < 2 && alive)
        alive = false;
      if (neighboors > 3 && alive)
        alive = false;
      if (neighboors == 3 && !alive)
        alive = true;
    }
