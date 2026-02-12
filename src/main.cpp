#include <iostream>
#include <string>

#include "Engine/Entity.hpp"
#include "Core/ApplicationContext.hpp"
#include "Core/Constants.hpp"

class Card : public Entity
{
public:
    Card(const std::string& rank, const std::string& suit) 
    : 
        _rank(rank), 
        _suit(suit)
    {
    }

    void update(float dt) override {

    } 

    std::string name() const override { return "Card"; }

private:
    std::string _rank;
    std::string _suit;
};

int main() {

    std::cout << "\n";

    ApplicationContext context;
    
    Card c("Ace", "Spades");

    c.position = {50, 50};

    context.addEntity(&c);

    return 0;
}