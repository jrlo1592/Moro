#include <iostream>
#include "prototypes.hpp"

using namespace std;

int main()
{
  Vector2 v;
  Texture t;

  RigidBody rb(Vector2(0, 0), Vector2(10, 10), 10.5);
  AABB rc(10, 10, 10, Vector2(), Vector2());

  Vector2 v1(10.0, 10.0);
  Vector2 v2;

  v2 = v2 + (v1 * v1);

  cout << v2.m_x << "\t" << v2.m_y << endl;

  v2 -= v1;

  cout << v2.m_x << "\t" << v2.m_y << endl;

  v1 /= 2;

  cout << v1.m_x << "\t" << v1.m_y << endl;

  cout << "V1 dot V2: " << v1.dot(v2) << endl;
  cout << "V2 dot V1: " << v2.dot(v1) << endl;

  return 0;
}
