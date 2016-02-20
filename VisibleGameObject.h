#include "stdafx.h"
#ifndef VISIBLEGAMEOBJECT_H
#define VISIBLEGAMEOBJECT_H

class VisibleGameObject
{
public:
	VisibleGameObject();
	virtual ~VisibleGameObject();

	virtual void Load(std::string filename);
	virtual void Draw(sf::RenderWindow &window);

	virtual void setPostion(float x, float y);
	virtual sf::Vector2f getPostition();
	virtual bool isLoaded() const;

private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	std::string _filename;
	bool _isLoaded;

};
#endif