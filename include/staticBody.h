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
     */
    StaticBody(const float x, const float y);

    /**
     *  @brief Creates body in given game world
     *  @param b2World game world
     */
    virtual void createBody(b2World &world) override;
};
