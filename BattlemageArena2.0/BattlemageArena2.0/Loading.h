#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>
#include <regex>
#include <fstream>
#include <vector>
#include <iostream>
#include "AdditionalFunctions.h"
#include "MainMenu.h"
#include "Game.h"



using namespace std;
using namespace sf;

class Loading
	: public Drawable
{
private:
	// Attributes.
	Texture* bgTexture;
	Sprite* bgSprite;
	Font *vikingFont, *lemonFont;
	Text  *titleText;
	RectangleShape* shadeRect, *enterRect;
	FloatRect *titleBoundsBox;
	vector <Text*> typesVector;
	vector <string> savesVector;
	vector <Text> savesTextsVector;
	vector <Button_*> buttonsVector;



public:
	// Attributes.
	bool savesDisplayed = 0;

	// Methods.
	virtual void draw(RenderTarget &target, RenderStates states) const;

	void CheckButtonsForHighlight(RenderWindow &target);
	void LoadFromFile();
	vector <string> ChooseSave(int i);
	vector <string> Load(RenderWindow &target);
	void FixSaves();

	// Constructors.
	Loading();
	~Loading();
};

