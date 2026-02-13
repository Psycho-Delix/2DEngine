#pragma once

#include "IComponent.hpp"
#include "Core/Types.hpp"

struct Transform : public IComponent
{
    Vec2 position{};
    float rotation = 0;
    Vec2 scale{1, 1};
};