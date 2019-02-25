#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>
#include <regex>
#include "AdditionalFunctions.h"

using namespace std;
using namespace sf;


class Enemy
	: public Drawable
{
private:
	// Attributes.
	string enemyName;
	float health;
	float initHealth;
	int attack;
	int armour;
	int initAttack;
	int initArmour;
	int attackIncrement;
	int armourIncrement;

	// Technicals.
	int attackBoxesCount = 20;
	int armourBoxesCount = 20;
	Texture* portretTexture;
	Sprite* portretSprite;
	Font* lemonFont, *vikingFont;
	Text* nameText, *healthText,* attackText,* armourText, *attackIncText, *armourIncText;
	RectangleShape* line,* healthBar;

	FloatRect* nameBoundsBox;

	vector <RectangleShape> attackVector;
	vector <RectangleShape> armourVector;

public:

	virtual void draw(RenderTarget &target, RenderStates states) const;

	string getEnemyName();
	float getEnemyHealth();
	int getEnemyAttack();
	int getEnemyArmour();
	int getEnemyAttackIncrement();
	int getEnemyArmourIncrement();
	void updateBars();
	void receiveDamage(int damage, int attackType);

	Enemy(string name, int inputHP, int inputAC, int inputAM, int inputACinc, int inputAMinc, string portretSource);
	~Enemy();
};

