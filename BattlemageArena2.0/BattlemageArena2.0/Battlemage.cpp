#include "Battlemage.h"



Battlemage::Battlemage(string inputName,
	int inputHP,
	int inputMN,
	int inputStr,
	int inputMP)
{
	characterName = inputName;
	characterHealth = inputHP;
	initHealth = inputHP;
	characterMana = inputMN;
	initMana = inputMN;
	characterStrength = inputStr;
	characterMagicPower = inputMP;

	portretTexture = new Texture;
	portretTexture->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Images\\playerPortret.jpg");

	portretSprite = new Sprite;
	portretSprite->setTexture(*portretTexture);
	ScaleSpriteByWidth(*portretSprite, 400.0);
	
	
	lemonmilkFont = new Font;
	lemonmilkFont->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Fonts\\lemon_milk\\LemonMilk.otf");

	vikingFont = new Font;
	vikingFont->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Fonts\\viking\\VIKING-N.TTF");

	displayNameText = new Text(characterName, *vikingFont);
	displayNameText->setCharacterSize(25);

	nameTextBoundsBox = new FloatRect;
	*nameTextBoundsBox = displayNameText->getGlobalBounds();

	displayNameText->setOrigin(nameTextBoundsBox->width / 2, nameTextBoundsBox->height / 2);
	displayNameText->setPosition(200.0, 283.0);
	cout << "Stworzono obiekt battlemage" << endl;

	line = new RectangleShape(Vector2f(3.0, 600.0));
	line->setPosition(400.0, 0.0);
	line->setFillColor(Color::White);

	healthBar = new RectangleShape(Vector2f(400.0, 40.0));
	healthBar->setFillColor(Color::Color(158, 22, 7));
	healthBar->setPosition(0.0, 300.0);

	manaBar = new RectangleShape(Vector2f(400.0, 40.0));
	manaBar->setFillColor(Color::Color(56, 59, 233));
	manaBar->setPosition(0.0, 340.0);
	
	healthText = new Text("Health: " + to_string((int)characterHealth), *lemonmilkFont);
	healthText->setPosition(0.0, 300.0);

	manaText = new Text("Mana: " + to_string((int)characterMana), *lemonmilkFont);
	manaText->setPosition(0.0, 340.0);

	atacText = new Text("Attributes and Actions", *vikingFont);
	atacText->setCharacterSize(22);

	atacTextBoundsBox = new FloatRect;
	*atacTextBoundsBox = atacText->getGlobalBounds();

	atacText->setOrigin(atacTextBoundsBox->width / 2, atacTextBoundsBox->height / 2);
	atacText->setPosition(200.0, 400.0);

	strengthText = new Text("Strength: " + to_string(characterStrength), *lemonmilkFont);
	strengthText->setPosition(0.0, 420.0);

	magicpowerText = new Text("MagicPower: " + to_string(characterMagicPower), *lemonmilkFont);
	magicpowerText->setPosition(0.0, 460.0);
	
	Action* tmpActPtr = new Action(0.0, 500.0,
		"C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Images\\actionIcons\\swordAttack.png", 1);
	actionsVector.push_back(tmpActPtr);
	tmpActPtr = new Action(100.0, 500.0,
		"C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Images\\actionIcons\\swordParry.png", 2);
	actionsVector.push_back(tmpActPtr);

	tmpActPtr = new Action(200.0, 500.0,
		"C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Images\\actionIcons\\fireballSpell.png", 3);
	actionsVector.push_back(tmpActPtr);
	tmpActPtr = new Action(300.0, 500.0,
		"C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Images\\actionIcons\\magicShield.png", 4);
	actionsVector.push_back(tmpActPtr);

}


Battlemage::~Battlemage()
{
	delete displayNameText;
	delete lemonmilkFont;
	delete portretSprite;
	delete portretTexture;
	delete line;
	delete healthText;
}

void Battlemage::draw(RenderTarget &target, RenderStates states) const
{
	target.draw(*portretSprite);
	target.draw(*displayNameText);
	target.draw(*line);
	target.draw(*healthBar);
	target.draw(*manaBar);
	target.draw(*healthText);
	target.draw(*manaText);
	target.draw(*atacText);
	target.draw(*strengthText);
	target.draw(*magicpowerText);
	for (int i = 0; i < actionsVector.size(); i++)
		target.draw(*actionsVector[i]);
}

float Battlemage::getBattlemageHealth()
{
	return characterHealth;
}

void Battlemage::highlightAction(int whichAction)
{
	actionsVector[whichAction]->spellHighlight();
}

int Battlemage::makeAction(RenderWindow &target)
{
	
	if (Keyboard::isKeyPressed(Keyboard::Num1))
	{
		actionsVector[0]->spellHighlight();
		
		return 1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Num2))
	{
		actionsVector[1]->spellHighlight();
		
		return 2;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Num3))
	{
		actionsVector[2]->spellHighlight();
	
		return 3;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Num4))
	{
		actionsVector[3]->spellHighlight();
		
		return 4;
	}
	else
	{
		for (int i = 0; i < actionsVector.size(); i++)
			actionsVector[i]->spellEndHighlight();
		return 0;
	}
	
}

void Battlemage::updateBars()
{
	healthText->setString("Health: " + to_string((int)characterHealth));
	healthBar->setSize(Vector2f(characterHealth / initHealth * 400.0, 40.0));

	manaText->setString("Mana: " + to_string((int)characterMana));
	manaBar->setSize(Vector2f(characterMana / initMana * 400.0, 40.0));
}

void Battlemage::swordAttack(Enemy &enemy)
{
	int damage = characterStrength - enemy.getEnemyArmour();

	if (damage > 0)
	{
		enemy.receiveDamage(damage, 1);
		updateBars();
	}
	else
	{
		enemy.receiveDamage(0, 1);
		updateBars();
	}
}

void Battlemage::swordParry(Enemy &enemy)
{
	int damage = enemy.getEnemyAttack() - characterStrength;
	
	if (damage > 0)
	{
		characterHealth -= damage;
		updateBars();
	}
	else
	{
		enemy.receiveDamage(0, 2);
		updateBars();
	}

	
}

void Battlemage::fireballThrow(Enemy &enemy)
{
	if (characterMana >= 30)
	{
		enemy.receiveDamage(characterMagicPower, 3);
		characterMana -= 30;
		updateBars();
	}
}

void Battlemage::magicShield(Enemy &enemy)
{
	if (enemy.getEnemyAttack() <= characterMana)
	{
		characterMana -= enemy.getEnemyAttack();
		enemy.receiveDamage(0, 4);
		updateBars();
	}
	else
		characterMana += enemy.getEnemyAttack();
}