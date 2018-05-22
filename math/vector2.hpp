#pragma once

class Vector2 //Container for the current x and y velocities of objects or entities
{
  public:
    double m_x, m_y;
    Vector2() {m_x = m_y = 0;}
    Vector2(double x, double y) : m_x(x), m_y(y) {}
    /*
      Vector <operator> Vector
      These operations are scalar
    */
    Vector2 operator + (Vector2 & rhs) //rhs = right-hand side
    {
      Vector2 temp(m_x, m_y);
      temp.m_x += rhs.m_x;
      temp.m_y += rhs.m_y;
      return temp;
    }
    void operator += (Vector2 & rhs)
    {
      m_x += rhs.m_x;
      m_y += rhs.m_x;
    }
    Vector2 operator - (Vector2 & rhs)
    {
      Vector2 temp(m_x, m_y);
      temp.m_x -= rhs.m_x;
      temp.m_y -= rhs.m_y;
      return temp;
    }
    void operator -= (Vector2 & rhs)
    {
      m_x -= rhs.m_x;
      m_y -= rhs.m_y;
    }
    Vector2 operator * (Vector2 & rhs)
    {
      Vector2 temp(m_x, m_y);
      temp.m_x *= rhs.m_x;
      temp.m_y *= rhs.m_y;
      return temp;
    }
    void operator *= (Vector2 & rhs)
    {
      m_x *= rhs.m_x;
      m_y *= rhs.m_y;
    }
    Vector2 operator / (Vector2 & rhs)
    {
      Vector2 temp(m_x, m_y);
      temp.m_x /= rhs.m_x;
      temp.m_y /= rhs.m_y;
      return temp;
    }
    void operator /= (Vector2 & rhs)
    {
      m_x /= rhs.m_x;
      m_y /= rhs.m_y;
    }

    //Non-scalar
    double dot(Vector2 & rhs) //Dot product
    {
      return (m_x * rhs.m_x) + (m_y * rhs.m_y);
    }

    /*
      Vector <operator> Scalar
      These operations are scalar
    */

    Vector2 operator + (double scalar)
    {
      Vector2 temp(m_x, m_y);
      temp.m_x += scalar;
      temp.m_y += scalar;
      return temp;
    }
    void operator += (double scalar)
    {
      m_x += scalar;
      m_y += scalar;
    }
    Vector2 operator - (double scalar)
    {
      Vector2 temp(m_x, m_y);
      temp.m_x -= scalar;
      temp.m_y -= scalar;
      return temp;
    }
    void operator -= (double scalar)
    {
      m_x -= scalar;
      m_y -= scalar;
    }
    Vector2 operator * (double scalar)
    {
      Vector2 temp(m_x, m_y);
      temp.m_x *= scalar;
      temp.m_y *= scalar;
      return temp;
    }
    void operator *= (double scalar)
    {
      m_x *= scalar;
      m_y *= scalar;
    }
    Vector2 operator / (double scalar)
    {
      Vector2 temp(m_x, m_y);
      temp.m_x /= scalar;
      temp.m_y /= scalar;
      return temp;
    }
    void operator /= (double scalar)
    {
      m_x /= scalar;
      m_y /= scalar;
    }
};