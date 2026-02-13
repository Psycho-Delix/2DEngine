#include <iostream>
#include <string>
#include <memory>

#include "Engine/Entity.hpp"
#include "Core/ApplicationContext.hpp"
#include "Core/Constants.hpp"
#include "Engine/Components/Transform.hpp"
#include "Engine/Components/Physics.hpp"

/*
 * test
 */
class CardComponent : public IComponent
{
public:
    CardComponent(std::string_view rank, std::string_view suit) 
    : 
        _rank(rank), 
        _suit(suit)
    {
    }

    void update(float dt) override {
        auto* transform = owner->getComponent<Transform>();
        auto* physics = owner->getComponent<Physics>();

        if (transform->position.x > 100) {
            return;
        }
        else {
            std::cout << "(" << transform->position.x << ", " << transform->position.y << ")\n";
        }
    } 

private:
    std::string _rank;
    std::string _suit;
};

class CardEntity : public Entity
{
public:
    CardEntity(std::string_view rank, std::string_view suit) {
        auto& transform = addComponent<Transform>();
        auto& physics = addComponent<Physics>();
        physics.velocity = {2, 0};

        addComponent<CardComponent>(rank, suit);
    }
};

int main() {

    std::cout << "\n";

    ApplicationContext context;
    
    auto card = std::make_unique<CardEntity>("Ace", "Spades");

    context.addEntity(std::move(card));

    while (true) {
        context.update(DELTA_TIME);
    }

    return 0;
}