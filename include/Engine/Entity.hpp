#pragma once

#include <string_view>
#include <memory>
#include <unordered_map>
#include <typeindex>

#include "Core/Types.hpp"
#include "Engine/Components/IComponent.hpp"

class Entity
{
public:
    virtual ~Entity() = default;

    template<typename T, typename... Args>
    T& addComponent(Args&&... args) {
        auto component = std::make_unique<T>(std::forward<Args>(args)...);
        component->setOwner(this);
        T& ref = *component;

        _components[typeid(T)] = std::move(component);

        return ref;
    }

    template<typename T>
    T* getComponent() {
        auto it = _components.find(typeid(T));
        if (it != _components.end()) {
            return static_cast<T*>(it->second.get());
        }
        return nullptr;
    }

    void updateComponents(float dt) {
        for (auto& [_, components] : _components) {
            components->update(dt);
        }
    }

private:
    std::unordered_map<std::type_index, std::unique_ptr<IComponent>> _components;
};