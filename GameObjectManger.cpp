#include "GameObjectManger.h"

GameObjectManger::GameObjectManger()
{
}

GameObjectManger::~GameObjectManger()
{
	std::for_each(_gameObjects.begin(), _gameObjects.end(), GameObjectDeallocator());
}

void GameObjectManger::add(std::string str, VisibleGameObject * obj)
{
	_gameObjects.insert(std::pair<std::string, VisibleGameObject*>(str, obj));
}

void GameObjectManger::remove(std::string str)
{
	std::map<std::string, VisibleGameObject*>::iterator results = _gameObjects.find(str);
	if (results != _gameObjects.end())
	{
		delete results->second;
		_gameObjects.erase(results);
	}
}

int GameObjectManger::getObjectCount() const
{
	return _gameObjects.size();
}

VisibleGameObject * GameObjectManger::get(std::string str) const
{
	std::map<std::string, VisibleGameObject*>::const_iterator results = _gameObjects.find(str);
	if (results == _gameObjects.end())
		return nullptr;
	else
		return results->second;
}

void GameObjectManger::drawAll(sf::RenderWindow & window)
{
	std::map<std::string, VisibleGameObject*>::iterator itr = _gameObjects.begin();
	while (itr != _gameObjects.end())
	{
		itr->second->Draw(window);
		itr++;
	}
}
