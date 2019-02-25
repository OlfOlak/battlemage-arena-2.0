#include "Button_.h"



Button_::Button_(float x, float y, string text)
{
	posX = x;
	posY = y;

	textFont = new Font();
	textFont->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Fonts\\morris_roman\\MorrisRomanBlack.ttf");
	
	buttonText = new Text(text, *textFont);
	buttonText->setCharacterSize(43);

	textBoundsBox = new FloatRect;
	*textBoundsBox = buttonText->getLocalBounds();

	buttonText->setOrigin(textBoundsBox->width / 2, textBoundsBox->height / 2);
	buttonText->setPosition(Vector2f(posX, posY));
	buttonText->setFillColor(Color::Black);
	buttonText->setOutlineColor(Color::White);
	buttonText->setOutlineThickness(4);
	
}


Button_::~Button_()
{
	delete buttonText;
	delete textFont;
	delete textBoundsBox;
}

void Button_::setPosition(float x, float y)
{
	posX = x;
	posY = y;
}

void Button_::draw(RenderTarget &target, RenderStates states) const
{
	target.draw(*buttonText);
}

void Button_::buttonHighlight()
{
	buttonText->setFillColor(Color::Color(158, 22, 7));
}

void Button_::buttonEndHighlight()
{
	buttonText->setFillColor(Color::Black);
}

void Button_::showBoundBox(RenderTarget &target)
{
	RectangleShape boundRect(Vector2f(textBoundsBox->width, textBoundsBox->height));
	boundRect.setPosition(textBoundsBox->left, textBoundsBox->top);
	boundRect.setFillColor(Color::Transparent);
	boundRect.setOutlineThickness(4);
	boundRect.setOutlineColor(Color::Red);
	target.draw(boundRect);
}