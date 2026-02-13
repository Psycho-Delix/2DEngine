#pragma once

#include <string_view>
#include <memory>

#include "Core/Types.hpp"
#include "Engine/Components/Transform.hpp"
#include "Engine/Components/Physics.hpp"

class Entity
{
public:
    virtual ~Entity() = default;

    virtual void update(float dt) = 0;
    virtual std::string_view name() const = 0; 

    Transform& transform() { return *_transform; }
    Physics* physics() { return _physics.get(); }

protected:
    Entity()
    :
        _transform(std::make_unique<Transform>())
    {
    }

    void addPhysics() {
        _physics = std::make_unique<Physics>();
    }

private:
    std::unique_ptr<Transform> _transform;
    std::unique_ptr<Physics> _physics;
};