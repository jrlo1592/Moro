#pragma once

#include "../math/vector2.hpp"

class RigidBody
{
  private:
    Vector2 m_position;
    Vector2 m_velocity;
    Vector2 m_center;
    double m_mass;
  public:
    RigidBody(Vector2 & position, Vector2 & velocity, double mass)
    {
      m_position = position;
      m_velocity = velocity;
      if (mass < 0)
        m_mass = (mass * -1);
      else
        m_mass = mass;
    }
    Vector2 getPosition() const
    {
      return m_position;
    }
    void setPosition(Vector2 & position)
    {
      m_position = position;
    }
    double getX() const
    {
      return m_position.m_x;
    }
    void setX(double x)
    {
      m_position.m_x = x;
    }
    double getY() const
    {
      return m_position.m_y;
    }
    void setY(double y)
    {
      m_position.m_y = y;
    }
    Vector2 getVelocity() const
    {
      return m_velocity;
    }
    void setVelocity(Vector2 & velocity)
    {
      m_velocity = velocity;
    }
    double getMass() const
    {
      return m_mass;
    }
    void setMass(double mass)
    {
      m_mass = mass;
    }
    Vector2 getCenter() const
    {
      return m_center;
    }
    void setCenter(Vector2 & center)
    {
      m_center = center;
    }
};

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

class KDOP : public RigidBody {}; // I forgot what DOP stands for

class ConvexHull : public RigidBody {};