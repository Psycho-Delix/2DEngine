#pragma once

#include <vector>
#include <iostream>

#include "Engine/Entity.hpp"

class ApplicationContext
{
public:
    ApplicationContext() = default;

    void addEntity(Entity* entity) {
        _entities.push_back(entity);
        std::cout << entity->name() << " добавлен.\nПозиция: (" << entity->position.x << ", " << entity->position.y << ")";
    }
    
private:
    std::vector<Entity*> _entities;
};