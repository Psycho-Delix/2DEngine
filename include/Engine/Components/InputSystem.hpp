#pragma once

#include <SFML/Window.hpp>

#include "IComponent.hpp"

class InputSystem : public IComponent
{
public:
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;

    void update() override {
        up = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
        down = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
        left = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
        right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    }
};