#include "../headers/MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* wnd) : mWindow(wnd), mSelected(0)
{
	init();
}

MainMenuState::~MainMenuState()
{
	release();
}

void MainMenuState::init()
{
	mFont = new sf::Font();
	mFont->loadFromFile("media/fonts/remodula.ttf");

	mTitle = new sf::Text("BomberGuy", *mFont, 128U);
	mTitle->setOrigin(mTitle->getGlobalBounds().width / 2.f, mTitle->getGlobalBounds().height / 2.f);
	mTitle->setColor(sf::Color::Green);
	mTitle->setPosition(mWindow->getSize().x / 2.f, mWindow->getSize().y / 8.f);

	mPlay = new sf::Text("Play", *mFont, 64U);
	mPlay->setOrigin(mPlay->getGlobalBounds().width / 2.f, mPlay->getGlobalBounds().height / 2.f);	
	mPlay->setPosition(mWindow->getSize().x / 2.f, mWindow->getSize().y / 2.f);

	mQuit = new sf::Text("Quit", *mFont, 64U);
	mQuit->setOrigin(mQuit->getGlobalBounds().width / 2.f, mQuit->getGlobalBounds().height / 2.f);	
	mQuit->setPosition(mWindow->getSize().x / 2.f, mWindow->getSize().y / 2.f + 1.5f * mPlay->getGlobalBounds().height);
}

void MainMenuState::release()
{
	delete mFont;
	delete mTitle;
	delete mPlay;
	delete mQuit;
}

void MainMenuState::render()
{
	mPlay->setColor(sf::Color::White);
	mQuit->setColor(sf::Color::White);

	switch(mSelected)
	{
	case 0:
		mPlay->setColor(sf::Color::Yellow);
		break;

	case 1:
		mQuit->setColor(sf::Color::Yellow);
		break;
	}

	mWindow->clear(sf::Color::Black);
	mWindow->draw(*mTitle);
	mWindow->draw(*mPlay);
	mWindow->draw(*mQuit);
	mWindow->display();
}

void MainMenuState::processEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !mUpKey)
		++mSelected;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !mDownKey)
		--mSelected;
	
	if (mSelected > 1)
		mSelected = 0;

	if (mSelected < 0)
		mSelected = 1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		switch(mSelected)
		{
		case 0:
			Game::getInstance()->changeState(GameID);
			return;

		case 1:
			Game::getInstance()->setQuit(true);
			return;
		}
	}
	
	mUpKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	mDownKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
}