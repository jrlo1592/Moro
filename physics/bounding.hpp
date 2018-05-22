#pragma once

#include "rigid_body.hpp"

class AABB : public RigidBody //Axis-Aligned Bounding Box
{
  private:
    double m_length, m_width;
  public:
    AABB(double length, double width, double mass, Vector2 & position, Vector2 & velocity) : RigidBody(position, velocity, mass)
    {
      if (length < 0)
        m_length = (length * -1);
      else if (length == 0)
        m_length = 0.1;
      else
        m_length = length;

      if (width < 0)
        m_width = (width * -1);
      else if (width == 0)
        m_width = 0.1;
      else
        m_width = width;
      
      setCenter(Vector2((getX() + m_length / 2), (getY() + m_width / 2)));
    }

    Vector2 DetectCollision(AABB & rb)
    {
      if ((getPosition().m_x > (rb.getPosition().m_x + rb.m_length)) || (rb.getPosition().m_x > (getPosition().m_x + m_length)))
        return Vector2();

      // (0,0) is the top-left so I'm still using > for this
      if ((getPosition().m_y > (rb.getPosition().m_y + rb.m_width)) || (rb.getPosition().m_y > (getPosition().m_y + m_width)))
        return Vector2();

      return Vector2(1, 1);
    }

};

class OBB : public RigidBody {}; // Oriented Bounding Box