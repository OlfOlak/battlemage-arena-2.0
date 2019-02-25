#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "AdditionalFunctions.h"

using namespace std;
using namespace sf;


class Credits
{
private:
	// Attributes.
	bool returnChoice = 0;
	Texture* bgTexture;
	Sprite* bgSprite;
	RectangleShape* shadeRect;
	Text* titleText, *creditsText;
	Font* titleFont, *creditsFont;
	FloatRect* titleBoundsBox;
	Button_* returnButton;

public:
	// Methods.
	virtual void draw(RenderTarget &target, RenderStates states) const;

	void CheckButtonForHighlight(RenderWindow &target);
	void ShowCredits(RenderWindow &target);

	void setMenuChoice(int choice);
	bool getMenuChoice();
	// Constructors.
	Credits();
	~Credits();
};

