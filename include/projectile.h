/**
 *  @file Projectile class header file
 *
 *  @author Ammar Subei
 */

#pragma once

#include "dynamicBody.h"

class Projectile : public DynamicBody
{
  public:
    /**
     *  @brief Default constructor
     */
    Projectile();

    /**
     *  @brief Getter for damage
     *  @return int damage
     */
    int getDamage()           const { return damage; }

    /**
     *  @brief Setter for damage
     *  @param int damage
     */
    void setDamage(const int value) { damage = value; }

  private:
    int damage; ///< Projectile's damage
};

