#pragma once
#include <SFML/Graphics.hpp>
class Circle {
private:
	sf::CircleShape circle;
public:
	Circle(float size){
		circle.setRadius(size);
		circle.setFillColor(sf::Color::Blue);
}

	void setPosition(float x, float y) {
		circle.move(x, y);
	}
	sf::CircleShape& getCircle() {
		return circle;
	}
};

