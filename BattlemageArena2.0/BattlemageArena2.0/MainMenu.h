#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include <iostream>
#include "AdditionalFunctions.h"
#include "Button_.h"

class Button_;

using namespace std;
using namespace sf;

class MainMenu :
	public Drawable
{
private:
	// Attributes.
	int menuChoice = 0;
	vector <Button_*> buttonsVector;
public:
	// Attributes.
	Texture* bgTexture;
	Sprite* bgSprite;
	Text* titleText;
	Font* titleFont;
	FloatRect* titleBoundsBox;

	// Methods.
	virtual void draw(RenderTarget &target, RenderStates states) const;

	void CheckButtonsForHighlight(RenderWindow &target);
	void OptionChoice(RenderWindow &target);

	void setMenuChoice(int choice);
	int getMenuChoice();
	// Constructors.
	MainMenu();
	~MainMenu();
};

