#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "AdditionalFunctions.h"


using namespace std;
using namespace sf;

class Button_ 
	: public Drawable
{
private:
	
	

public:
	// Attributes.
	float posX, posY;

	Text* buttonText;
	Font* textFont;

	FloatRect* textBoundsBox;

	// Methods.
	void setPosition(float x, float y);
	void buttonHighlight();
	void buttonEndHighlight();
	void showBoundBox(RenderTarget &target);
	

	virtual void draw(RenderTarget &target, RenderStates states) const;
	// Constructors.
	Button_(float x, float y, string text);
	~Button_();
};

