#pragma once

#include "Core/Types.hpp"

struct Physics
{
    Vec2 velocity{};
    Vec2 acceleration{};

    void update(float dt, Vec2& position) {
        velocity += acceleration * dt;
        position += velocity * dt;
    }
};