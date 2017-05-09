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
