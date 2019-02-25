#include "Action.h"



Action::Action(float x, float y, string textureSource, int id)
{
	posX = x;
	posY = y;
	actionChoice = id;
	actionTexture = new Texture;
	actionTexture->loadFromFile(textureSource);

	bgRect = new RectangleShape(Vector2f(100.0, 100.0));
	bgRect->setPosition(posX, posY);


	actionSprite = new Sprite;
	actionSprite->setTexture(*actionTexture);
	actionSprite->setPosition(posX, posY);
	ScaleSpriteByWidth(*actionSprite, 100.0);

	actionchoiceFont = new Font;
	actionchoiceFont->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Fonts\\lemon_milk\\LemonMilk.otf");

	actionchoiceText = new Text(to_string(actionChoice), *actionchoiceFont);
	actionchoiceText->setPosition(posX + 4.0, posY + 4.0);
	actionchoiceText->setFillColor(Color::Color(158, 22, 7));
}


Action::~Action()
{
	delete actionTexture;
	delete actionSprite;
	delete actionchoiceFont;
	delete actionchoiceText;
}


void Action::draw(RenderTarget &target, RenderStates states) const
{
	target.draw(*bgRect);
	target.draw(*actionSprite);
	target.draw(*actionchoiceText);
}

void Action::spellHighlight()
{
	bgRect->setFillColor(Color::Color(158, 22, 7, 160));

}

void Action::spellEndHighlight()
{
	bgRect->setFillColor(Color::White);
}