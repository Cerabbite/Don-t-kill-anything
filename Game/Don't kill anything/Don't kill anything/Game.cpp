#include "Game.h"

// Init variables funtion
void Game::initVariables()
{
	this->window = nullptr;
}

// Init window function
void Game::initWindow()
{
	this->videoMode.width = 1080;
	this->videoMode.height = 608;
	this->window = new sf::RenderWindow(this->videoMode, "Don't Kill Anything", sf::Style::Titlebar | sf::Style::Close);
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

// Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}

// Poll events function
void Game::pollEvents()
{
    // Event polling
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        }
    }
}

// Update function
void Game::update()
{
    this->pollEvents();
}

// Render function
void Game::render()
{
    this->window->clear(sf::Color(255, 0, 0, 255));

    // Draw game objects

    this->window->display();
}