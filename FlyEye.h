#pragma once
#include <iostream>
#include<SFML/Graphics.hpp>
#include "Circle.h"
#include <vector>
#include "Vertex.h"

const float PI = 3.14159265358979323846;

class FlyEye
{
public:
	FlyEye() {
		setTotalVertex();
		setAngle();
		setVertex(originx, originy);
		printInstructions();
		renderWindow();
	}
	void renderWindow() {
		sf::RenderWindow window(sf::VideoMode(winsize * 2, winsize * 2), "Ojo de mosca");
		window.setFramerateLimit(60);
		Circle circle(winsize / 2);
		clock.restart();
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			receivePress(circle);
			updateLines();
			checkElapsedTime();
			window.clear();
			window.draw(circle.getCircle());
			drawLines(window);

			window.display();
		}
	}

	void checkElapsedTime() {
		time = clock.getElapsedTime();
		if (time.asSeconds() > 0.017) {
			clock.restart();
			rotateLines();
		}

	}

	void rotateLines() {
		rotation += rotationspeed * PI / 180;

	}

	void updateLines() {
		for (int i = 0; i < TotalVertex; i++) {
			vertexes[i].setPosx(angle, spritesize, i, originx, rotation);
			vertexes[i].setPosy(angle, spritesize, i, originy, rotation);

		}
	}

	void receivePress(Circle& circle) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			originy -= movement;
			circle.setPosition(0, -movement);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			originx -= movement;
			circle.setPosition(-movement, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			originy += movement;
			circle.setPosition(.0, movement);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			originx += movement;
			circle.setPosition(movement, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			rotationspeed = -abs(rotationspeed);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
			rotationspeed = abs(rotationspeed);
		}
	}

	void drawLines(sf::RenderWindow& target) {
		for (int i = 0; i < TotalVertex; i++) {
			for (int j = i + 1; j < TotalVertex; j++) {
				line[0].position = sf::Vector2f(vertexes[i].getPosx(), vertexes[i].getPosy());
				line[1].position = sf::Vector2f(vertexes[j].getPosx(), vertexes[j].getPosy());
				if(!checkcenter(i+1, j+1))
				target.draw(line, 2, sf::Lines);
			}
		}
	}

	bool checkcenter(int i, int j) {
		if (TotalVertex % 2 == 0) {
			if (abs(i - j) == TotalVertex / 2)
				return true;
		}
		return false;
	}

	void setVertex(int posx, int posy) {
		Vertex temp;
		for (int i = 0; i < TotalVertex; i++) {
			temp.setPosx(angle, spritesize, i, posx, rotation);
			temp.setPosy(angle, spritesize, i, posy, rotation);
			vertexes.push_back(temp);

		}
	}

	void setAngle() {
		angle = 2 * PI / TotalVertex;
	}

	void askVertex() {
		std::cout << "Digite el numero de vertices del ojo de mosca" << std::endl;
	}

	void setTotalVertex() {
		while (TotalVertex < 2) {
			askVertex();
			TotalVertex = getValidInt();
			if (TotalVertex < 2)
				std::cout << "El total de vertices debe ser mayor a 2" << std::endl;
		}
	}

	int getValidInt() {
		int number;

		while (!(std::cin >> number)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return 0;
		}

		return number;
	}

	void printInstructions() {
		std::cout << "Utilice WASD para mover, Q y E para cambiar sentido de rotacion" << std::endl;
	}
private:
	int TotalVertex = 0;
	float angle = 0;
	float winsize = 400;
	float spritesize = winsize / 2;
	sf::Vertex line[2];
	float originx = spritesize;
	float originy = spritesize;
	float movement = 3;
	float rotation = 0;
	float rotationspeed = 0.017 * 60;
	std::vector<Vertex> vertexes;
	sf::Clock clock;
	sf::Time time;
};
