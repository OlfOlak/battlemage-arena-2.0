#include "Enemy.h"



Enemy::Enemy(string name, int inputHP, int inputAC, int inputAM, int inputACinc, int inputAMinc, string portretSource)
{
	enemyName = name;
	health = inputHP;
	initHealth = inputHP;
	attack = inputAC;
	armour = inputAM;
	initAttack = inputAC;
	initArmour = inputAM;
	attackIncrement = inputACinc;
	armourIncrement = inputAMinc;

	portretTexture = new Texture;
	portretTexture->loadFromFile(portretSource);
	
	portretSprite = new Sprite;
	portretSprite->setTexture(*portretTexture);
	ScaleSprite(*portretSprite, 400.0, 266.67);
	portretSprite->setPosition(800.0, 0.0);

	lemonFont = new Font;
	lemonFont->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Fonts\\lemon_milk\\LemonMilk.otf");

	vikingFont = new Font;
	vikingFont->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Fonts\\viking\\VIKING-N.TTF");

	nameText = new Text(enemyName, *vikingFont);
	nameText->setCharacterSize(25);

	nameBoundsBox = new FloatRect;
	*nameBoundsBox = nameText->getGlobalBounds();

	nameText->setOrigin(nameBoundsBox->width / 2, nameBoundsBox->height / 2);
	nameText->setPosition(1000.0, 283.0);

	healthBar = new RectangleShape(Vector2f( health / initHealth * 400.0, 40.0));
	healthBar->setFillColor(Color::Color(158, 22, 7));
	healthBar->setPosition(800.0, 300.0);

	healthText = new Text("Health: " + to_string((int)health), *lemonFont);
	healthText->setPosition(800.0, 300.0);

	attackIncText = new Text("Attack Increment (+" + to_string(attackIncrement) + "):", *vikingFont);
	attackIncText->setCharacterSize(22);
	attackIncText->setPosition(800.0, 340.0);

	RectangleShape* tmpIncRectPtr;

	for (int i = 0; i < 20; i++)
	{
		tmpIncRectPtr = new RectangleShape(Vector2f(18.0, 18.0));
		if (i < attack)
			tmpIncRectPtr->setFillColor(Color::Color(158, 22, 7));
		else
			tmpIncRectPtr->setFillColor(Color::White);

		tmpIncRectPtr->setPosition(800.0 + i * 20.0, 380.0);
		tmpIncRectPtr->setOutlineThickness(2.0);
		tmpIncRectPtr->setOutlineColor(Color::Black);
		attackVector.push_back(*tmpIncRectPtr);
	}

	armourIncText = new Text("Armour Increment (+" + to_string(armourIncrement) + "):", *vikingFont);
	armourIncText->setCharacterSize(22);
	armourIncText->setPosition(800.0, 420.0);

	for (int i = 0; i < 20; i++)
	{
		tmpIncRectPtr = new RectangleShape(Vector2f(18.0, 18.0));
		if (i < armour)
			tmpIncRectPtr->setFillColor(Color::Color(113, 113, 116));
		else
			tmpIncRectPtr->setFillColor(Color::White);
		tmpIncRectPtr->setPosition(800.0 + i * 20.0, 460.0);
		tmpIncRectPtr->setOutlineThickness(2.0);
		tmpIncRectPtr->setOutlineColor(Color::Black);
		armourVector.push_back(*tmpIncRectPtr);
	}

	delete tmpIncRectPtr;

	line = new RectangleShape(Vector2f(3.0, 600.0));
	line->setFillColor(Color::White);
	line->setPosition(797.0, 0.0);
}


Enemy::~Enemy()
{
	delete portretSprite;
	delete portretTexture;
	delete lemonFont;
	delete vikingFont;
	delete nameText;
	delete nameBoundsBox;
	delete healthText;
	delete healthBar;
	delete attackIncText;
	delete armourIncText;

}

void Enemy::draw(RenderTarget &target, RenderStates states) const
{
	target.draw(*portretSprite);
	target.draw(*nameText);
	target.draw(*healthBar);
	target.draw(*healthText);
	target.draw(*attackIncText);
	target.draw(*armourIncText);

	
	
	for (int i = 0; i < attackVector.size(); i++)
		target.draw(attackVector[i]);
	
	for (int i = 0; i < armourVector.size(); i++)
		target.draw(armourVector[i]);
	

	target.draw(*line);
}

string Enemy::getEnemyName()
{
	return enemyName;
}

float Enemy::getEnemyHealth()
{
	return health;
}

int Enemy::getEnemyAttack()
{
	return attack;
}

int Enemy::getEnemyArmour()
{
	return armour;
}

int Enemy::getEnemyAttackIncrement()
{
	return attackIncrement;
}

int Enemy::getEnemyArmourIncrement()
{
	return armourIncrement;
}

void Enemy::updateBars()
{
	// update health bar.
	healthText->setString("Health: " + to_string((int)health));
	healthBar->setSize(Vector2f((health / initHealth) * 400.0, 40.0));

	// update attack bar.

	if (attackBoxesCount - 10 <= attack)
		attackBoxesCount += 10;

	RectangleShape* tmpIncRectPtr = nullptr;

	attackVector.clear();

	float boxSize, outlineSize;
	if (attackBoxesCount <= 40)
	{
		outlineSize = 2.0;
		boxSize = 400.0 / attackBoxesCount - outlineSize;
	}
	else
	{
		outlineSize = 1.0;
		boxSize = 400.0 / attackBoxesCount - outlineSize;
	}

	for (int i = 0; i < attackBoxesCount; i++)
	{
		
		tmpIncRectPtr = new RectangleShape(Vector2f(boxSize, 20.0));
		
		if (i < attack)
			tmpIncRectPtr->setFillColor(Color::Color(158, 22, 7));
		else
			tmpIncRectPtr->setFillColor(Color::White);

		tmpIncRectPtr->setPosition(800.0 + i * (boxSize + outlineSize), 380.0);
		tmpIncRectPtr->setOutlineThickness(outlineSize);
		tmpIncRectPtr->setOutlineColor(Color::Black);
		attackVector.push_back(*tmpIncRectPtr);

	}

	// update armour bar.

	if (armourBoxesCount - 10 <= armour)
		armourBoxesCount += 10;

	armourVector.clear();

	if (armourBoxesCount <= 40)
	{
		outlineSize = 2.0;
		boxSize = 400.0 / armourBoxesCount - outlineSize;
	}
	else
	{
		outlineSize = 1.0;
		boxSize = 400.0 / armourBoxesCount - outlineSize;
	}

	for (int i = 0; i < armourBoxesCount; i++)
	{
		tmpIncRectPtr = new RectangleShape(Vector2f(boxSize, 20.0));
		if (i < armour)
			tmpIncRectPtr->setFillColor(Color::Color(113, 113, 116));
		else
			tmpIncRectPtr->setFillColor(Color::White);
		tmpIncRectPtr->setPosition(800.0 + i * (boxSize + outlineSize), 460.0);
		tmpIncRectPtr->setOutlineThickness(outlineSize);
		tmpIncRectPtr->setOutlineColor(Color::Black);
		armourVector.push_back(*tmpIncRectPtr);
	}

	delete tmpIncRectPtr;
}

void Enemy::receiveDamage(int damage, int attackType)
{
	health -= damage;
	
	switch (attackType)
	{
	case 1:
		attack += attackIncrement;
		armour += armourIncrement;
		updateBars();
		break;
	case 2:
		armour = initArmour;
		updateBars();
		break;
	case 3:
		attack += attackIncrement;
		armour += armourIncrement;
		updateBars();
		break;
	case 4:
		attack = initAttack;
		updateBars();
		break;
	default:
		break;
	}
	
		
}