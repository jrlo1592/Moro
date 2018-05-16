#include <iostream>
#include "prototypes.hpp"

using namespace std;

int main()
{
  Position p;
  Entity e;
  Object o;
  Vector2 v;
  Texture t;

  Vector2 v1(10.0, 10.0);
  Vector2 v2;

  v2 = v2 + (v1 * v1);

  cout << v2.m_x << "\t" << v2.m_y << endl;

  v2 -= v1;

  cout << v2.m_x << "\t" << v2.m_y << endl;

  return 0;
}
