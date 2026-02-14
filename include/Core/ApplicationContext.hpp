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
        _entities.push_back(std::move(entity));
    }

    void update() {
        for (auto& e : _entities) {
            e->updateComponents();
        }
    }
    
private:
    std::vector<std::unique_ptr<Entity>> _entities;
};