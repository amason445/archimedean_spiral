#ifndef SPIRAL_H
#define SPIRAL_H

#include <SFML/Graphics.hpp>
#include <cmath>

class ArchimedeanSpiral {
public:
    explicit ArchimedeanSpiral(float b = 0.5f);

    void construct_spiral(float radius, sf::Vector2f center, float a = 0.f, float dtheta = 0.01f);

    const sf::VertexArray& get_vertices() const { return spiral_; }

private:
    // Archimedean Spiral -- r = a + bθ
    // r = Radial Coordinate (distance from the center)
    // a = Initial radius
    // b = Pitch (growth rate)   
    float a_ = 0.f;
    float b_ = 0.f;
    float theta_ = 0.f;
    sf::VertexArray spiral_; // holds the points
};

#endif




