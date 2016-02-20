#include "stdafx.h"
#include "VisibleGameObject.h"
#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

class GameObjectManger
{
public:
	GameObjectManger();
	~GameObjectManger();

	void add(std::string str, VisibleGameObject *object);
	void remove(std::string str);
	int getObjectCount() const;
	VisibleGameObject *get(std::string str) const;

	void drawAll(sf::RenderWindow& window);

private:
	std::map<std::string, VisibleGameObject*> _gameObjects;

	struct GameObjectDeallocator
	{
		void operator() (const std::pair<std::string, VisibleGameObject*> &p) const
		{
			delete p.second;
		}
	};


};

#endif