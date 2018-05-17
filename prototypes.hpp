#pragma once

/*
  This is a temporary file containing the prototypes of potential
  classes, that may or may not be in the final version
*/

class Vector2 //Container for the current x and y velocities of objects or entities
{
  public:
    double m_x, m_y;
    Vector2() {m_x = m_y = 0;}
    Vector2(double x, double y) : m_x(x), m_y(y) {}
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
};

class Texture //Will remain empty until we have what we need for textures to be introduced
{
  private:
    std::string src;
  public:
    Texture() {src = "";} //Preferably, a default texture
};

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

class Rectangle : public RigidBody
{
  private:
    double m_length, m_width;
  public:
    Rectangle(double length, double width, double mass, Vector2 & position, Vector2 & velocity) : RigidBody(position, velocity, mass)
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

    Vector2 DetectCollision(Rectangle & rb)
    {
      if ((getPosition().m_x > (rb.getPosition().m_x + rb.m_length)) || (rb.getPosition().m_x > (getPosition().m_x + m_length)))
        return Vector2();

      // (0,0) is the top-left so I'm still using > for this
      if ((getPosition().m_y > (rb.getPosition().m_y + rb.m_width)) || (rb.getPosition().m_y > (getPosition().m_y + m_width)))
        return Vector2();

      return Vector2(1, 1);
    }

};

class Circle : public RigidBody
{
  private:
    double m_radius;
  public:
    Circle(double radius, double mass, Vector2 & position, Vector2 & velocity) : RigidBody(position, velocity, mass)
    {
      if (radius < 0)
        m_radius = (radius * -1);
      else if (radius == 0)
        m_radius = 0.1;
      else
        m_radius = radius;

      setCenter(position);
    }
    Vector2 DetectCollision(Circle & rb)
    {
      double distanceSquared = 0;
      double radiiSquared = 0;

      distanceSquared = ((getX() - rb.getX()) * (getX() - rb.getX())) + ((getY() - rb.getY()) * (getY() - rb.getY()));
      radiiSquared = (m_radius + rb.m_radius) * (m_radius + rb.m_radius);

      if (distanceSquared == radiiSquared) //Touching
        return Vector2();
      else if (distanceSquared > radiiSquared) //Not touching
        return Vector2();
      else //intersecting
        return Vector2(1, 1);
    }
};

