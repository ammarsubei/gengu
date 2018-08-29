/**
 *  @file Body class header file
 *
 *  @author Ammar Subei
 */

#pragma once

#include <SFML/Graphics.hpp>

/**
 *  @brief Class for visualizing interactive bodies in the game
 *
 *  Two main types of bodies:
 *      Static:   immovable objects that are collidable
 *      Dynamic:  movable objects that are collidable
 */
class Body
{
  public:
    /**
     *  @brief Enum for type of body
     */
    enum class Type
    {
      DYNAMIC,  ///< Movable body (e.g props & player)
      STATIC    ///< Immovable body (e.g ground & walls)
    };

    /**
     *  @brief Default constructor
     *  @param float x position
     *  @param float y position
     *  @param Type body type
     */
    Body(const float xPos, const float yPos, Type t) : type(t), position(xPos, yPos) {}

    /**
     *  @brief Getter for body type
     *  @return Type type of body
     */
    Type getType()                            const { return type; }

    /**
     *  @brief Getter for body density
     *  @return float density of body
     */
    float getDensity()                        const { return density; }

    /**
     *  @brief Getter for body friction
     *  @return float friction of body
     */
    float getFriction()                       const { return friction; }

    /**
     *  @brief Getter for body shape
     *  @return sf::Shape shape of body
     */
    sf::Shape& getShape()                     const { return *shape; }

    /**
     *  @brief Getter for body size
     *  @return sf::Vector2f size
     */
    sf::Vector2f getSize()                    const { return size; }

    /**
     *  @brief Getter for body position
     *  @return sf::Vector2f position
     */
    sf::Vector2f getPosition()                const { return position; }

    /**
     *  @brief Setter for body type
     *  @param Type type of body
     */
    void setType(const Type value)                  { type = value; }

    /**
     *  @brief Setter for body density
     *  @param float density of body
     */
    void setDensity(const float value)              { density = value; }

    /**
     *  @brief Setter for body friction
     *  @param float friction of body
     */
    void setFriction(const float value)             { friction = value; }

    /**
     *  @brief Setter for body size
     *  @param sf::Vector2f size
     */
    void setSize(sf::Vector2f value)                { size = value; }

    /**
     *  @brief Setter for body size
     *  @param float width
     *  @param float height
     */
    void setSize(const float x, const float y)      { size.x = x; size.y = y; }

    /**
     *  @brief Setter for body position
     *  @param sf::Vector2f position
     */
    void setPosition(sf::Vector2f value)            { position = value; }

    /**
     *  @brief Setter for body position
     *  @param float xPos
     *  @param float yPos
     */
    void setPosition(const float x, const float y)  { position.x = x; position.y = y; }

    /**
     *  @brief Updates body position, rotation, and state
     */
    virtual void update();

  protected:
    Type type;              ///< Body type
    float density;          ///< Body density
    float friction;         ///< Body friction
    sf::Shape *shape;       ///< Body shape
    sf::Vector2f size;      ///< Body size
    sf::Vector2f position;  ///< Body position

    static float scale;     ///< World scale
};
