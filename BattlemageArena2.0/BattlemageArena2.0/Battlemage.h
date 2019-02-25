#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include <iostream>
#include "AdditionalFunctions.h"
#include "Action.h"
#include "Enemy.h"

using namespace std;
using namespace sf;

class Battlemage
	: public Drawable
{
private:
	// Attributes.
	string characterName;
	float characterHealth;
	float initHealth;
	float characterMana;
	float initMana;
	int characterStrength;
	int characterMagicPower;

	// Technicals.
	Texture* portretTexture;
	Sprite* portretSprite;
	Font* lemonmilkFont, *vikingFont;
	Text* displayNameText,* healthText,* manaText,* strengthText,* magicpowerText, *atacText;
	FloatRect* nameTextBoundsBox, *atacTextBoundsBox;
	RectangleShape* line,* healthBar,* manaBar;
	vector <Action*> actionsVector;
	
	

public:
	virtual void draw(RenderTarget &target, RenderStates states) const;
	float getBattlemageHealth();
	void highlightAction(int whichAction);
	int makeAction(RenderWindow &target);
	void updateBars();
	void swordAttack(Enemy &enemy);
	void fireballThrow(Enemy &enemy);
	void swordParry(Enemy &enemy);
	void magicShield(Enemy &enemy);
	

	Battlemage(string inputName,
		int inputHP,
		int inputMN,
		int inputStr,
		int inputMP);
	~Battlemage();


};

