#include "circle\CircleHandler.h"

CircleHandler::CircleHandler(float radius, sf::Color fill, unsigned int pointCount)
    : radius_(radius), circle_(radius_)              
{
    circle_.setPointCount(pointCount);
    circle_.setFillColor(fill);
    centerOrigin();
}

void CircleHandler::setRadius(float r) {
    radius_ = r;
    circle_.setRadius(radius_);
    centerOrigin();
}

void CircleHandler::setFillColor(sf::Color c) {
    circle_.setFillColor(c);
}

void CircleHandler::setPointCount(unsigned int n) {
    circle_.setPointCount(n);
}

void CircleHandler::setPosition(sf::Vector2f p) {
    circle_.setPosition(p);
}

void CircleHandler::centerOrigin() {
    float r = circle_.getRadius();
    circle_.setOrigin({ r, r });
}

