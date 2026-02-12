#pragma once

#include <string_view>

#include "Core/Types.hpp"

class Entity
{
public:
    virtual ~Entity() = default;

    virtual void update(float dt) = 0;
    virtual std::string_view name() const = 0; 

    Vec2 position;
};