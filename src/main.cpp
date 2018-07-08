#include <SFML/Graphics.hpp>

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    float thickness = 0;
    float numberToAdd = 0.001;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        shape.setOutlineThickness(thickness);
        shape.setOutlineColor(sf::Color(250, 150, 100));

        thickness += numberToAdd;

        if (thickness > 0) {
            numberToAdd = -0.01;
        } else if(thickness < -100) {
            numberToAdd = 0.01;
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}