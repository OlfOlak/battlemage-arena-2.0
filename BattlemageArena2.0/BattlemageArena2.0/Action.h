#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include <iostream>
#include "AdditionalFunctions.h"

using namespace std;
using namespace sf;

class Action
	: public Drawable
{
private:
	int posX, posY;
	Texture* actionTexture;
	Sprite* actionSprite;
	Font* actionchoiceFont;
	Text* actionchoiceText;
	RectangleShape* bgRect;

public:
	int actionChoice;

	virtual void draw(RenderTarget &target, RenderStates states) const;
	void spellHighlight();
	void spellEndHighlight();

	Action(float x, float y, string textureSource, int id);
	~Action();
};

