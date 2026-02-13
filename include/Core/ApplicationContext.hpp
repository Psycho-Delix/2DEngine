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
        std::cout << entity->name() << " добавлен.\nПозиция: (" << entity->transform().position.x << ", " << entity->transform().position.y << ")";
        _entities.push_back(std::move(entity));
    }

    void update(float dt) {
        for (auto& e : _entities) {
            e->update(dt);
        }
    }
    
private:
    std::vector<std::unique_ptr<Entity>> _entities;
};