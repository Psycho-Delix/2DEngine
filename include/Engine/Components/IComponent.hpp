#pragma once

class Entity;

class IComponent
{
public:
    virtual ~IComponent() = default;

    virtual void awake() {};
    virtual void update() {};

    void setOwner(Entity* entity) {
        owner = entity;
    }

protected:
    Entity* owner = nullptr;
};