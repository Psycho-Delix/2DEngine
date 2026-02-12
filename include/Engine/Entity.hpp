#pragma once

#include <string>

#include "Core/Types.hpp"

class Entity
{
public:
    virtual ~Entity() = default;

    virtual void update(float dt) = 0;
    virtual std::string name() const = 0; 

    Vec2 position;
};