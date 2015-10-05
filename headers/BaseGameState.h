#ifndef BASEGAMESTATE_H
#define BASEGAMESTATE_H

#include <SFML/Graphics.hpp>

enum GameStateID
{
	GameID,
	MainMenuID
};

class BaseGameState
{
public:
	virtual void init() = 0;
	virtual void release() = 0;

	virtual void render() = 0;
	virtual void processEvents() = 0;
};

#endif