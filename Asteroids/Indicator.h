///////////////////////////////////////////////////////////////////////////////
//
// Asteroids - A clone of the immensely popular game by the same title
//				mixed with an equally popular game Galaga.
// version 0.0.1
// author: Silas Agnew <agnewsilas@gmail.com>
//
// Created for a Showcase Project for CACC Programming and Mobile Applications
// class with SFML - Simple and Fast Multimedia Library
//
// This software can be used freely as open-source software with proper
// representation of the author and following SFML's terms of use.
//
// Improper representation may result in the following
//
//	- Disembowelment / forced Seppuku
//	- Smashing of the culprit's knees, ankles, or other vital joints
//	- Severing of the culprit's limb(s)
//	- RKO
//  - 360 no-scope(s)
//
// Beware: These punishments will be enforced 95% of the time 35% of the time
//
///////////////////////////////////////////////////////////////////////////////
#ifndef INDICATOR_H
#define INDICATOR_H

#include <SFML\Graphics.hpp>
#include <memory>

#include "Resources.h"
#include "GUIObject.h"
#include "Label.h"

// Summary:
// 
class Indicator : public GUIObject
{
private:
    std::unique_ptr<sf::RectangleShape> m_bar;

    std::unique_ptr<Label> m_minimum;
    std::unique_ptr<Label> m_maximum;

    double m_min;
    double m_max;
    double m_maxWidth;
    sf::IntRect m_location;

    double m_value;

public:
    Indicator(const std::string& id, sf::IntRect location, double min, double max, sf::Color color = sf::Color::Red);
    ~Indicator();

    void Update(std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game) override;
    void Draw(std::shared_ptr<sf::RenderWindow> window) override;

    double Get();
    void Set(double value);
    void SetProportion(double value);
};

#endif // INDICATOR_H
