#include "VisibleGameObject.h"

VisibleGameObject::VisibleGameObject()
{
	_isLoaded = false;
}

VisibleGameObject::~VisibleGameObject()
{

}

void VisibleGameObject::Load(std::string filename)
{
	if (_texture.loadFromFile(filename) == false)
	{
		_filename = "";
		_isLoaded = false;
	}
	else
	{
		_filename = filename;
		_sprite.setTexture(_texture);
		_isLoaded = true;
	}
}

void VisibleGameObject::Draw(sf::RenderWindow & window)
{
	if (_isLoaded)
	{
		window.draw(_sprite);
	}
}

void VisibleGameObject::setPostion(float x, float y)
{
	if (_isLoaded)
	{
		_sprite.setPosition(x, y);
	}
}

sf::Vector2f VisibleGameObject::getPostition()
{
	return _sprite.getPosition();
}

bool VisibleGameObject::isLoaded() const
{
	return _isLoaded;
}
