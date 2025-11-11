#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>

class CircleHandler
{
public:
	explicit CircleHandler(float radius = 1.f,
		sf::Color fill = sf::Color::White,
		unsigned int pointCount = 30u);
	
	void setRadius(float r);
	void setFillColor(sf::Color c);
	void setPointCount(unsigned int n);
	void setPosition(sf::Vector2f p);      
	void centerOrigin();

	sf::CircleShape& shape() { return circle_; }
	const sf::CircleShape& shape() const { return circle_; }


private:
	float radius_ = 1.f;
	sf::CircleShape circle_;

};

#endif


