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
