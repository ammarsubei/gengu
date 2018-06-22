/**
 *  @file Static body class header file
 *
 *  @author Ammar Subei
 */

#pragma once

#include "body.h"

class StaticBody : public Body
{
  public:
    /**
     *  @brief Default constructor
     *  @param x position
     *  @param y position
     */
    StaticBody(const float xPos, const float yPos);

    /**
     *  @brief Creates body in given game world
     *  @param b2World game world
     */
    virtual void createBody(b2World &world) override;
};
