#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>

#include "spiral/ArchimedeanSpiral.h"
#include "circle/CircleHandler.h"

float input_scaling_factor() {
    float b;
    std::cout << "Please provide a scaling factor." << std::endl;
    std::cout << "This is a positive floating point integer." << std::endl;
    std::cout << "Please enter it here: ";
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
    float radius = 250.f;

    // Create window object and sets the frame limit to 60 FPS
    std::string window_title = build_title(b);
    sf::RenderWindow window(sf::VideoMode({ 750u, 750u }), window_title);
    window.setFramerateLimit(60);
    auto size = window.getSize();
    sf::Vector2f center{ (static_cast<float>(size.x) / 2.f), (static_cast<float>(size.x) / 2.f) };

    // Create Circle to place spiral on
    CircleHandler circle(radius, sf::Color::Cyan, 200);
    circle.centerOrigin();
    circle.setPosition(center);

    ArchimedeanSpiral spiral(b);
    spiral.construct_spiral(radius, center);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear();
        window.draw(circle.shape());
        window.draw(spiral.get_vertices());
        window.display();
    }
}