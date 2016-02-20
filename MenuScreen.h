#include "stdafx.h"
#ifndef MENUSCREEN_H
#define MENUSCREEN_H

class MenuScreen
{
public:
	enum MenuResult { Nothing, Exit, Play, Options };

	struct MenuItem
	{
	public:
		sf::Rect<int> rect;
		MenuResult action;
	};

	MenuResult show(sf::RenderWindow& window);

private:
	MenuResult getMenuResponse(sf::RenderWindow& window);
	MenuResult handleClick(int x, int y);
	std::list<MenuItem> _menuItems;
};

#endif
