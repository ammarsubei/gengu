/**
 *  @file Dynamic body class header file
 *
 *  @author Ammar Subei
 */

#pragma once

#include "body.h"

class DynamicBody : public Body
{
  public:
    /**
     *  @brief Default constructor
     *  @param float x position
     *  @param float y position
     */
    DynamicBody(const float xPos, const float yPos);

    /**
     *  @brief Getter for health
     *  @return int current health
     */
    int getHealth()           const { return health; }

    /**
     *  @brief Setter for health
     *  @param int new health
     */
    void setHealth(const int value) { health = value; }

    /**
     *  @brief Creates body in given game world
     *  @param b2World game world
     */
    virtual void createBody(b2World &world) override;

    /**
     *  @brief Updates body position, rotation, and state
     */
    virtual void update() override;

  private:
    int health; ///< Body's health
};

