#pragma once

#include "IComponent.hpp"
#include "Core/Types.hpp"
#include "Transform.hpp"

struct Physics : public IComponent
{
    Vec2 velocity{};
    Vec2 acceleration{};

    void update(float dt) override {
        auto* transform = owner->getComponent<Transform>();
        if (!transform) {
            return;
        }
        velocity += acceleration * dt;
        transform->position += velocity * dt;
    }
};