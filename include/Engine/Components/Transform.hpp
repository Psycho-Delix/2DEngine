#pragma once

#include "IComponent.hpp"
#include "Core/Types.hpp"

class Transform : public IComponent
{
public:
    Vec2 position{};
    float rotation = 0;
    Vec2 scale{1, 1};
};