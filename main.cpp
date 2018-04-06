#include <iostream>
#include <unistd.h>
#include <time.h>
#include "cell.h"

using std::cout;
using std::cin;

void print(Cell ** grid, int n)
{
  for (int i = 0;i < n;i++)
  {
    for (int j = 0;j < n;j++)
    {
      cout << (grid[i][j].is_alive() ? '#' : ' ') << ' ';
    }
    cout << '\n';
  }
}

int main()
{
  int n = 0;
  bool alive;
  int cells_alive = 0;

  srand(time(NULL));

  cout << "Grid size: ";
  cin >> n;
  
  Cell ** grid = new Cell*[n];

  for (int i = 0;i < n;i++)
    grid[i] = new Cell[n];

  for (int i = 0;i < n;i++)
  {
    for (int j = 0;j < n;j++)
    {
      alive = (rand() % 2);
      cells_alive += static_cast<int>(alive);
      grid[i][j] = Cell(alive, j, i);
    }
  }

  print(grid, n);

  cout << '\n';

  while (cells_alive > 0)
  {
    cells_alive = 0;
    for (int i = 0;i < n;i++)
    {
      for (int j = 0;j < n;j++)
      {
        grid[i][j].update(grid, n);
        if (grid[i][j].is_alive())
          cells_alive ++;
      }
    }
    usleep(100000);
    print(grid, n);
    cout << '\n';
  }


  for (int i = 0;i < n;i++)
    delete [] grid[i];

  delete [] grid;

  return 0;
}
