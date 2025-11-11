#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

float input_scaling_factor() {
    float b;
    std::cout << "Please provide a scaling factor." << std::endl;
    std::cout << "This is a positive floating point integer." << std::endl;
    std::cout << "Please enter it here: " << std::endl;
    std::cin >> b;

    if (std::cin.fail() || b <= 0.f) {
        std::cout << "Invalid input. Setting Defauly scaling to 0.5f";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        b = 0.5f;
    }
    return b;
}

std::string build_title(float b) {
    std::ostringstream title;
    title << "Archimedean Spiral (b = " << b << ")";
    std::string window_title = title.str();
    return window_title;
}

int main() {

    //generates scaling factor for spiral in layer 2
    float b = input_scaling_factor();

    // Create window object and sets the frame limit to 60 FPS
    std::string window_title = build_title(b);
    sf::RenderWindow window(sf::VideoMode({ 750u, 750u }), window_title);
    window.setFramerateLimit(60);

    // Create Circle for Layer 1
    float radius = 250.f;
    sf::CircleShape circle(radius);
    circle.setPointCount(200);
    circle.setFillColor(sf::Color::Cyan);
    circle.setOrigin(
        sf::Vector2f{ circle.getRadius(), circle.getRadius() }
    );

    auto size = window.getSize();
    
    sf::Vector2f center{ (static_cast<float>(size.x) / 2.f), (static_cast<float>(size.x) / 2.f) };
    circle.setPosition(center);

    // Archimedean Spiral -- r = a + bθ
    // r = Radial Coordinate (distance from the center)
    // a = Initial radius
    // b = Pitch (growth rate)
    const float a = 0.f;
    float theta = 0.f;
    float r = 0.f;
    float x = 0.f;
    float y = 0.f;
    sf::VertexArray spiral(sf::PrimitiveType::LineStrip);

    // The while loop works while the Radial coordinate is less than the radius of the circle in layer 1
    // Using the formula for the radial coordinate, vectors for x and y are appended to the Vertex Array with cosine and sine
    // You are effectively scaling sine and cosine with a constantly increading radial coordinate
    while (r < radius) {
        r = a + (b * theta);
        x = center.x + (r * std::cos(theta));
        y = center.y + (r * std::sin(theta));
        
        sf::Vertex v;
        v.position = { x, y };
        v.color = sf::Color::Red;
        spiral.append(v);

        theta += 0.01f;
    }

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(circle);
        window.draw(spiral);
        window.display();
    }
}