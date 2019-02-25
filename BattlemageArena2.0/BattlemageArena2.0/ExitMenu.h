#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "AdditionalFunctions.h"

using namespace std;
using namespace sf;


class ExitMenu 
	: public MainMenu
{
private:
	// Attributes.
	int menuChoice = 0;
	vector <Button_*> buttonsVector;
public:
	// Attributes.
	Font * textFont;
	Text* questionText;
	RectangleShape* shadeRect;
	FloatRect* questionBoundBox;

	// Methods.
	virtual void draw(RenderTarget &target, RenderStates states) const;

	void CheckButtonsForHighlight(RenderWindow &target);
	void OptionChoice(RenderWindow &target);
	
	void setMenuChoice(int choice);
	int getMenuChoice();
	// Constructors.
	ExitMenu();
	~ExitMenu();
};

