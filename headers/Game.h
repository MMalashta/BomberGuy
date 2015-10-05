#ifndef GAME_H
#define GAME_H

#include "../headers/BaseGameState.h"

class Game
{
public:
	static Game* getInstance();

	void init();
	void release();
	void update();
	void changeState(GameStateID newStateID);
	void setQuit(bool flag);

protected:
	Game(){};
	~Game(){};

private:
	static Game*	  instance;

	sf::RenderWindow* window;
	BaseGameState*	  currentState;
	bool              quitGame;
};

#endif