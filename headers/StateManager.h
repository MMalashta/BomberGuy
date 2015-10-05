#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "../headers/BaseGameState.h"
#include "../headers/GameState.h"
#include "../headers/MainMenuState.h"

class StateManager
{
public:
	static StateManager* getInstance();

	BaseGameState* createState(GameStateID id, sf::RenderWindow* wnd);

protected:
	StateManager(){};
	~StateManager(){};

private:
	static StateManager*  instance;
};

#endif