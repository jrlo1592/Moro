#include <iostream>
#include "prototypes.hpp"

using namespace std;

int main()
{
  Vector2 v;
  Texture t;

  RigidBody rb(Vector2(0, 0), Vector2(10, 10), 10.5);
  Rectangle rc(10, 10, 10, Vector2(), Vector2());
  Circle cr(4, 5, Vector2(22, 2), Vector2());

  Vector2 v1(10.0, 10.0);
  Vector2 v2;

  v2 = v2 + (v1 * v1);

  cout << v2.m_x << "\t" << v2.m_y << endl;

  v2 -= v1;

  cout << v2.m_x << "\t" << v2.m_y << endl;

  return 0;
}
