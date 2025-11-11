#include "spiral/ArchimedeanSpiral.h"
 
ArchimedeanSpiral::ArchimedeanSpiral(float b) : b_(b), theta_(0.f), spiral_(sf::PrimitiveType::LineStrip) {}

void ArchimedeanSpiral::construct_spiral(float radius, sf::Vector2f center, float dtheta)
{
    // The while loop works while the Radial coordinate is less than the radius of the circle in layer 1
    // Using the formula for the radial coordinate, vectors for x and y are appended to the Vertex Array with cosine and sine
    // You are effectively scaling sine and cosine with a constantly increasing radial coordinate
    spiral_.clear();
    theta_ = 0.f;
    float r = 0.f;

    while (r < radius) {
        r = a_ + (b_ * theta_);
        float x = center.x + (r * std::cos(theta_));
        float y = center.y + (r * std::sin(theta_));

        sf::Vertex v;
        v.position = { x, y };
        v.color = sf::Color::Red;
        spiral_.append(v);

        theta_ += 0.01f;
    }
}