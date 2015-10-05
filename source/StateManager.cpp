#include "../headers/StateManager.h"

StateManager*  StateManager::instance = NULL;

StateManager* StateManager::getInstance()
{
	if (instance == NULL)
		instance = new StateManager();

	return instance;
}

BaseGameState* StateManager::createState(GameStateID id, sf::RenderWindow* wnd)
{
	switch(id)
	{
	case MainMenuID:
		return new MainMenuState(wnd);
	
	case GameID:
		return new GameState(wnd);
	}

	return NULL;
}