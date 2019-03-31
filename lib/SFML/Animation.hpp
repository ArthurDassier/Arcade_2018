/*
** EPITECH PROJECT, 2019
** Animation.hpp
** File description:
** Animation
*/

#pragma once

#include <SFML/Graphics.hpp>

class Animation
{
    public:
        Animation();
        ~Animation();

        void addFrame(sf::IntRect);

        void setSpriteSheet(const sf::Texture&);
        const sf::Texture *getSpriteSheet() const;
        std::size_t getSize() const;
        const sf::IntRect& getFrame(std::size_t) const;

    private:
        std::vector<sf::IntRect> _frames;
        const sf::Texture* _texture;    
};
