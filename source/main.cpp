#include "../headers/Game.h"

int main()
{
	Game* game = Game::getInstance();
	game->init();	
	game->update();
	game->release();
}