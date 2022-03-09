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

    this->window->setFramerateLimit(60);
}

// Init enemies function
void Game::initEnemies()
{
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(50.f, 50.f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
    this->initEnemies();
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

// Return mouse position function
void Game::updateMousePositions()
{
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

// Update function
void Game::update()
{
    // Call poll event function
    this->pollEvents();

    // Call mouse update function
    this->updateMousePositions();

}

// Render function
void Game::render()
{
    this->window->clear();

    // Draw game objects
    this->window->draw(this->enemy);

    this->window->display();
}