#include <iostream>
#include <string>
#include <memory>
#include <thread>

#include "Engine/Entity.hpp"
#include "Core/ApplicationContext.hpp"
#include "Core/Constants.hpp"
#include "Engine/Components/Transform.hpp"
#include "Engine/Components/Physics.hpp"
#include "Engine/Components/InputSystem.hpp"

/*
 * test
 * сравнимо с монобех классом в юнити
 */
class PlayerComponent : public IComponent
{
public:
    PlayerComponent(float speed) 
    :
        _speed(speed)
    {
    }

    void awake() override {
        if (!transform) transform = owner->getComponent<Transform>();
        if (!input) input = owner->getComponent<InputSystem>();
    }

    void update() override {
        move();
    } 

    void move() {
        if (!transform || !input) {
            return;
        }
        
        if (input->up) {
            transform->position.y += _speed * DELTA_TIME;
        }
        if (input->down) {
            transform->position.y -= _speed * DELTA_TIME;
        }
        if (input->left) {
            transform->position.x -= _speed * DELTA_TIME;
        }
        if (input->right) {
            transform->position.x += _speed * DELTA_TIME;
        }

        std::cout << "(" << transform->position.x << ", " << transform->position.y << ")\n";
    }

private:
    float _speed;

    Transform* transform = nullptr;
    InputSystem* input = nullptr;
};

/*
 * добавление компанентов к объекту, 
 * так сказать имитация добавления компонента в юнити через инспектор
 */
class PlayerEntity : public Entity
{
public:
    PlayerEntity(float speed) {
        auto& transform = addComponent<Transform>();
        auto& input = addComponent<InputSystem>();

        addComponent<PlayerComponent>(speed);
    }
};

int main() {

    std::cout << "\n";

    ApplicationContext context;
    
    auto player = std::make_unique<PlayerEntity>(50.0);

    context.addEntity(std::move(player));

    while (true) {
        context.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    return 0;
}