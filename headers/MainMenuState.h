#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "../headers/BaseGameState.h"
#include "../headers/Game.h"

class MainMenuState : public BaseGameState
{
public:
	MainMenuState(sf::RenderWindow* wnd);
	~MainMenuState();

	void init() override;
	void release() override;
	void render() override;
	void processEvents() override;
	
private:
	sf::RenderWindow* mWindow;
	sf::Font*         mFont;
	sf::Text*         mTitle;
	sf::Text*         mPlay;
	sf::Text*         mQuit;

	int               mSelected;
	bool              mUpKey;
	bool              mDownKey;
};

#endif