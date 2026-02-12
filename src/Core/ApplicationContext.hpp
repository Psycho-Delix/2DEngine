#pragma once

#include <vector>

#include "Entity.hpp"

class ApplicationContext
{
public:
    ApplicationContext() = default;

    void addEntity(Entity* entity) {
        _entities.push_back(entity);
    }
    
private:
    std::vector<Entity*> _entities;
};