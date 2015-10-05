#include "../headers/GameState.h"

GameState::GameState(sf::RenderWindow* wnd) : mWindow(wnd)
{
	init();
}

GameState::~GameState()
{
	release();
}

void GameState::init()
{

}

void GameState::release()
{

}

void GameState::render()
{
	mWindow->clear(sf::Color::Yellow);
	mWindow->display();
}

void GameState::processEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		Game::getInstance()->changeState(MainMenuID);
}