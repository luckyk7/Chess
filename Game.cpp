#include "Game.h"


void Game::start(void)
{
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(800, 600, 32),"Chess");
	_mainWindow.setPosition(sf::Vector2i(0, 0));

	//Where we will load all objects then place in gameobjectmanager
	VisibleGameObject *boardImage = new VisibleGameObject();
	boardImage->Load("images/Board.png");
	boardImage->setPostion(0, 0);

	VisibleGameObject *Rook = new VisibleGameObject();
	Rook->Load("images/WhiteRook.png");
	Rook->setPostion(15, 15);

	_gameObjectManager.add("Board", boardImage);
	_gameObjectManager.add("WR1", Rook);
	_gameState = Game::ShowingSplash;

	while (!isExiting())
	{
		loop();
	}

	_mainWindow.close();
}

bool Game::isExiting()
{
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

void Game::loop()
{
	switch (_gameState)
	{
		case Game::ShowingSplash:
		{
			showSplashScreen();
			break;
		}
		case Game::ShowingMenu:
		{
			showMenu();
			break;
		}
		case Game::ShowingOptions:
		{
			//showOptions();
			break;
		}
		case Game::Playing:
		{
			sf::Event currentEvent;
			while (_mainWindow.pollEvent(currentEvent))
			{
				_mainWindow.clear(sf::Color(0,0,0));
				_gameObjectManager.drawAll(_mainWindow);
				_mainWindow.display();
			
				//add a loop here that waits for a click
				//then launch the handle click function

				waitForClick(currentEvent);
				
			}
			break;
		}
	}
}

void Game::showSplashScreen()
{
	SplashScreen splash;
	splash.show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

void Game::showMenu()
{
	MenuScreen mainMenu;
	MenuScreen::MenuResult result = mainMenu.show(_mainWindow);
	switch (result)
	{
	case MenuScreen::Exit:
		_gameState = Game::Exiting;
		break;
	case MenuScreen::Play:
		_gameState = Game::Playing;
		break;
	case MenuScreen::Options:
		_gameState = Game::ShowingOptions;
		break;
	}
}

void Game::waitForClick(sf::Event &currentEvent)
{
	//closes window if user chooses to quit
	if (currentEvent.type == sf::Event::Closed)
	{
		_gameState = Game::Exiting;
	}
	else if (currentEvent.type == sf::Event::MouseButtonPressed)
	{
		//get the coordinate that were clicked on
		float x = currentEvent.mouseButton.x; 
		float y = currentEvent.mouseButton.y;
		//check if they are on the board

		//check if they are on a chesspiece
	}
	

}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManger Game::_gameObjectManager;