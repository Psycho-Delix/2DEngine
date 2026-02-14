#pragma once

#include "IComponent.hpp"
#include "Core/Types.hpp"
#include "Transform.hpp"

class Physics : public IComponent
{
public:
    Vec2 velocity{};
    Vec2 acceleration{};

    bool use_gravity = false;

    void update() override {
        auto* transform = owner->getComponent<Transform>();
        if (!transform) {
            return;
        }

        if (use_gravity) {
            acceleration += GRAVIRY;
        }

        velocity += acceleration * DELTA_TIME;
        transform->position += velocity * DELTA_TIME;
    }
};