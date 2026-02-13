#pragma once

class Entity;

class IComponent
{
public:
    virtual ~IComponent() = default;
    virtual void update(float dt) {};

    void setOwner(Entity* entity) {
        owner = entity;
    }

protected:
    Entity* owner = nullptr;
};