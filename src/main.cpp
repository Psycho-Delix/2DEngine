#include <iostream>
#include <string>
#include <memory>

#include "Engine/Entity.hpp"
#include "Core/ApplicationContext.hpp"
#include "Core/Constants.hpp"

class Card : public Entity
{
public:
    Card(std::string_view rank, std::string_view suit) 
    : 
        _rank(rank), 
        _suit(suit)
    {
    }

    void update(float dt) override {
        std::cout << "Обновление состояния Card..\n";
    } 

    std::string_view name() const override { return "Card"; }

private:
    std::string _rank;
    std::string _suit;
};

int main() {

    std::cout << "\n";

    std::cout << "\n";

    ApplicationContext context;
    
    auto card = std::make_unique<Card>("Ace", "Spades");

    card->position = {50, 50};

    context.addEntity(std::move(card));

    while (true) {
        context.update(DELTA_TIME / FPS);
    }

    return 0;
}