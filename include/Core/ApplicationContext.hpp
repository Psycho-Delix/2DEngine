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
        std::cout << entity->name() << " добавлен.";
    }
    
private:
    std::vector<Entity*> _entities;
};