#pragma once

#include <vector>
#include <memory>
#include <iostream>

#include "Engine/Entity.hpp"

class ApplicationContext
{
public:
    ApplicationContext() = default;

    void addEntity(std::unique_ptr<Entity> entity) {
        std::cout << entity->name() << " добавлен.\nПозиция: (" << entity->position.x << ", " << entity->position.y << ")";
        _entities.push_back(std::move(entity));
    }
    
private:
    std::vector<std::unique_ptr<Entity>> _entities;
};