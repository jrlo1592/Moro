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
    Vector2 operator - (Vector2 & rhs)
    {
      Vector2 temp(m_x, m_y);
      temp.m_x -= rhs.m_x;
      temp.m_y -= rhs.m_y;
      return temp;
    }
    Vector2 operator * (Vector2 & rhs)
    {
      Vector2 temp(m_x, m_y);
      temp.m_x *= rhs.m_x;
      temp.m_y *= rhs.m_y;
      return temp;
    }
    Vector2 operator / (Vector2 & rhs)
    {
      Vector2 temp(m_x, m_y);
      temp.m_x /= rhs.m_x;
      temp.m_y /= rhs.m_y;
      return temp;
    }
};

class Position //Container for the position of objects
{
  public:
    double m_x, m_y;
    Position() {m_x = m_y = 0;}
    Position(double x, double y) : m_x(x), m_y(y) {}
    void move(Position & p, const Vector2 & velocity)
    {
      p.m_x += velocity.m_x;
      p.m_y += velocity.m_y;
    }
};

class Texture {}; //Will remain empty until we have what we need for textures to be introduced



class Object //Base class for objects, i.e., things that are in-animate
{
  private:
    Texture m_texture;
  public:
    Position m_location;
    Object()
    {
      m_location = Position();
      m_texture = Texture();
    }
    Object(Position & location) : m_location(location)
    {
      m_texture = Texture();
    }
    Object(Texture & texture) : m_texture(texture)
    {
      m_location = Position();
    }
    Object(Position & location, Texture & texture) : m_location(location), m_texture(texture) {}
};


class Entity //Base class for entities, i.e., things that are animate
{
  private:
    Texture m_texture;
  public:
    Position m_location;
    Entity()
    {
      m_location = Position();
      m_texture = Texture();
    }
    Entity(Position & location) : m_location(location)
    {
      m_texture = Texture();
    }
    Entity(Texture & texture) : m_texture(texture)
    {
      m_location = Position();
    }
    Entity(Position & location, Texture & texture) : m_location(location), m_texture(texture) {}
};

