#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../headers/BaseGameState.h"
#include "../headers/Game.h"

class GameState : public BaseGameState
{
public:
	GameState(sf::RenderWindow* wnd);
	~GameState();

	void init() override;
	void release() override;
	void render() override;
	void processEvents() override;
	
private:
	sf::RenderWindow* mWindow;
};

#endif