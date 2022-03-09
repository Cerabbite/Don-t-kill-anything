#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
private:
	// Variables
	// Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	// Mouse positions
	sf::Vector2i mousePosWindow;

	// Game objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;


	// Private functions
	void initVariables();
	void initWindow();
	void initEnemies();
public:
	// Constructors / Destructors
	Game();
	virtual ~Game();

	// Accessors
	const bool running() const;

	// Functions
	void pollEvents();
	void updateMousePositions();
	void update();
	void render();
};

