#include "../headers/Game.h"
#include "../headers/StateManager.h"

Game*  Game::instance = NULL;

Game* Game::getInstance()
{
	if (instance == NULL)
		instance = new Game();

	return instance;
}

void Game::init()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "BomberGuy");
	quitGame = false;
	currentState = StateManager::getInstance()->createState(MainMenuID, window);
}

void Game::release()
{
	delete currentState;
	delete window;
}

void Game::setQuit(bool flag)
{
	quitGame = flag;
}

void Game::changeState(GameStateID newStateID)
{
	if (currentState != NULL)
		delete currentState;
	
	currentState = StateManager::getInstance()->createState(newStateID, window);

	if (currentState != NULL)
		currentState->init();
}

void Game::update()
{
	sf::Clock clock;
	while(window->isOpen() && !quitGame)
	{
		float time = static_cast<float>(clock.getElapsedTime().asMilliseconds());
		clock.restart();

		window->setVerticalSyncEnabled(true);		
		
		currentState->processEvents();
		currentState->render();
	}
}