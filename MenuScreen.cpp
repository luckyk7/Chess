#include "MenuScreen.h"
#include "stdafx.h"

MenuScreen::MenuResult MenuScreen::show(sf::RenderWindow& window)
{
	sf::Texture image;
	if (image.loadFromFile("images/menu.png") != true)
		return MenuResult::Play;

	sf::Sprite sprite(image);

	//need to check if any of the cords are overlapping still
	//now we create the buttons and set the boundaries
	MenuItem playButton;
	playButton.rect.top = 0;
	playButton.rect.left = 0;
	playButton.rect.width = 800;
	playButton.rect.height= 200;
	playButton.action = Play;

	//still a work in progress, option action does nothing
	MenuItem optionButton;
	optionButton.rect.top = 200;
	optionButton.rect.left = 0;
	optionButton.rect.width = 800;
	optionButton.rect.height = 200;
	optionButton.action = Options;

	MenuItem quitButton;
	quitButton.rect.top = 400;
	quitButton.rect.left = 0;
	quitButton.rect.width = 800;
	quitButton.rect.height = 200;
	quitButton.action = Exit;

	_menuItems.push_back(playButton);
	_menuItems.push_back(optionButton);
	_menuItems.push_back(quitButton);

	window.draw(sprite);
	window.display();

	return getMenuResponse(window);

}

MenuScreen::MenuResult MenuScreen::getMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;

	while (true)
	{
		while (window.pollEvent(menuEvent))
		{
			//if they click on the menu we return the cords of the click
			if (menuEvent.type == sf::Event::MouseButtonPressed)
				return handleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			
			// if they click on the window close button we close the window
			else if (menuEvent.type == sf::Event::Closed)
				return Exit;
		}
	}
}

MenuScreen::MenuResult MenuScreen::handleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;

	for (it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if (menuItemRect.contains(x,y))
		{
			return (*it).action;
		}
	}

	return Nothing;
}