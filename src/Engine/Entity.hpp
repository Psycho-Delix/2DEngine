#pragma once

#include <string>

class Entity
{
public:
    virtual ~Entity() = default;

    virtual void update(float dt) = 0;
    virtual std::string name() const = 0; 
};