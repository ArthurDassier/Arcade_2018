#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <iostream>

int main()
{
    // setup window
    sf::Vector2i screenDimensions(800,600);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Animations!");
    window.setFramerateLimit(60);

    // load texture (spritesheet)
    sf::Texture texture;
    if (!texture.loadFromFile("pacman_spritesheet.png")) {
        std::cout << "Failed to load player spritesheet!" << std::endl;
        return 1;
    }

    // set up the animations for all four directions (set spritesheet and push frames)
    Animation MoveDownAnimation;
    MoveDownAnimation.setSpriteSheet(texture);
    MoveDownAnimation.addFrame(sf::IntRect(15, 48, 15, 15));
    MoveDownAnimation.addFrame(sf::IntRect(0, 48, 15, 15));
    MoveDownAnimation.addFrame(sf::IntRect(31, 0, 15, 15));

    Animation MoveLeftAnimation;
    MoveLeftAnimation.setSpriteSheet(texture);
    MoveLeftAnimation.addFrame(sf::IntRect(15, 15, 15, 15));
    MoveLeftAnimation.addFrame(sf::IntRect(0, 15, 15, 15));
    MoveLeftAnimation.addFrame(sf::IntRect(31, 0, 15, 15));

    Animation MoveRightAnimation;
    MoveRightAnimation.setSpriteSheet(texture);
    MoveRightAnimation.addFrame(sf::IntRect(15, 0, 15, 15));
    MoveRightAnimation.addFrame(sf::IntRect(0, 0, 15, 15));
    MoveRightAnimation.addFrame(sf::IntRect(31, 0, 15, 15));

    Animation MoveUpAnimation;
    MoveUpAnimation.setSpriteSheet(texture);
    MoveUpAnimation.addFrame(sf::IntRect(15, 32, 15, 15));
    MoveUpAnimation.addFrame(sf::IntRect(0, 32, 15, 15));
    MoveUpAnimation.addFrame(sf::IntRect(31, 0, 15, 15));

    Animation* currentAnimation = &MoveRightAnimation;

    // set up AnimatedSprite
    AnimatedSprite animatedSprite(sf::seconds(0.1), true, false);
    animatedSprite.setPosition(sf::Vector2f(screenDimensions / 2));

    sf::Clock frameClock;

    float speed = 150.f;
    bool noKeyWasPressed = true;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        sf::Time frameTime = frameClock.restart();
        // if a key was pressed set the correct animation and move correctly
        sf::Vector2f movement(0.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            currentAnimation = &MoveUpAnimation;
            movement.y -= speed;
            noKeyWasPressed = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            currentAnimation = &MoveDownAnimation;
            movement.y += speed;
            noKeyWasPressed = false;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            currentAnimation = &MoveLeftAnimation;
            movement.x -= speed;
            noKeyWasPressed = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            currentAnimation = &MoveRightAnimation;
            movement.x += speed;
            noKeyWasPressed = false;
        }
        animatedSprite.play(*currentAnimation);
        animatedSprite.move(movement * frameTime.asSeconds());

        // if no key was pressed stop the animation
        // if (noKeyWasPressed)
        //     animatedSprite.stop();
        // noKeyWasPressed = true;

        // update AnimatedSprite
        animatedSprite.update(frameTime);

        // draw
        window.clear();
        window.draw(animatedSprite);
        window.display();
    }

    return 0;
}
