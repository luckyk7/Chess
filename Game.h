#ifndef GAME_H
#define GAME_H
#include "stdafx.h"
#include "SplashScreen.h"
#include "MenuScreen.h"
#include "VisibleGameObject.h"
#include "Board.h"
#include "GameObjectManger.h"

//implement a way to handle clicks
class Game
{
public:
	static void start();

private:
	static bool isExiting();
	static void loop();
	static void showSplashScreen();
	static void showMenu();
	
	//game loop stops and waits for the user to select a piece
	static void waitForClick(sf::Event &currentEvent);
	

	enum GameState
	{ 
		Uninitialized, ShowingSplash, Paused,
		ShowingMenu, ShowingOptions, Playing, Exiting 
	};

	//the member variables
	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
	static GameObjectManger _gameObjectManager;

};

#endif