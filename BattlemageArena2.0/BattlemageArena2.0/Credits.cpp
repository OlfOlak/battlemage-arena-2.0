#include "Credits.h"



Credits::Credits()
{
	bgTexture = new Texture();
	bgTexture->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Images\\mainMenuBackground.jpg");
	bgSprite = new Sprite();
	bgSprite->setTexture(*bgTexture);
	bgSprite->setPosition(0.0, 0.0);

	shadeRect = new RectangleShape(Vector2f(1200.0, 600.0));
	shadeRect->setFillColor(Color::Color(0, 0, 0, 170));

	titleFont = new Font();
	titleFont->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Fonts\\viking\\VIKING-N.ttf");

	titleText = new Text("BATTLEMAGE\n   ARENA 2.0", *titleFont);
	titleText->setCharacterSize(60);
	titleBoundsBox = new FloatRect;
	*titleBoundsBox = titleText->getLocalBounds();
	titleText->setOrigin(titleBoundsBox->width / 2, titleBoundsBox->height / 2);
	titleText->setPosition(600.0, 80.0);
	titleText->setFillColor(Color::Color(158, 22, 7));

	creditsFont = new Font;
	creditsFont->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Fonts\\lemon_milk\\LemonMilk.otf");
	creditsText = new Text("Created by Olaf Olak\nGithub: github.com/OlfOlak\nE-mail: olf.olak@gmail.com", *creditsFont);
	creditsText->setFillColor(Color::White);
	creditsText->setCharacterSize(40.0);
	creditsText->setPosition(300.0, 200.0);

	returnButton = new Button_(600.0, 550.0, "Return");
}


Credits::~Credits()
{
	delete bgTexture;
	delete bgSprite;
	delete shadeRect;
	delete titleText, *creditsText;
	delete titleFont, *creditsFont;
	delete titleBoundsBox;
	delete returnButton;
}

void Credits::draw(RenderTarget &target, RenderStates states) const
{
	target.draw(*bgSprite);
	target.draw(*shadeRect);
	target.draw(*titleText);
	target.draw(*returnButton);
	target.draw(*creditsText);
}

void Credits::CheckButtonForHighlight(RenderWindow &target)
{
	if ((Mouse::getPosition(target).x < (returnButton->posX + (returnButton->textBoundsBox->width / 2) + 5.0))
		&& (Mouse::getPosition(target).x >(returnButton->posX - (returnButton->textBoundsBox->width / 2) - 10.0))
		&& (Mouse::getPosition(target).y < (returnButton->posY + (returnButton->textBoundsBox->height / 2) + 15.0))
		&& (Mouse::getPosition(target).y >(returnButton->posY - (returnButton->textBoundsBox->height / 2) + 5.0)))
	{
		returnButton->buttonHighlight();
		if (Mouse::isButtonPressed(Mouse::Button::Left))
			returnChoice = 1;
	}
	else
		returnButton->buttonEndHighlight();
}

void Credits::ShowCredits(RenderWindow &target)
{
	Event creditsEvent;

	this->draw(target, RenderStates::Default);
	//this->CheckButtonsForHighlight(target);

	while (target.pollEvent(creditsEvent))
	{
		this->CheckButtonForHighlight(target);

		switch (creditsEvent.type)
		{
		case Event::Closed:
			target.close();
			break;

		case Event::MouseButtonPressed:

			cout << "MouseButton pressed!" << endl;
			if ((Mouse::getPosition(target).x < (returnButton->posX + (returnButton->textBoundsBox->width / 2) + 5.0))
				&& (Mouse::getPosition(target).x >(returnButton->posX - (returnButton->textBoundsBox->width / 2) - 10.0))
				&& (Mouse::getPosition(target).y < (returnButton->posY + (returnButton->textBoundsBox->height / 2) + 15.0))
				&& (Mouse::getPosition(target).y >(returnButton->posY - (returnButton->textBoundsBox->height / 2) + 5.0)))
			{
				returnButton->buttonHighlight();
				if (Mouse::isButtonPressed(Mouse::Button::Left))
					returnChoice = 1;
			}
			else
				returnButton->buttonEndHighlight();
			break;

		default:
			cout << "Default" << endl;
			break;
		}
	}
}

void Credits::setMenuChoice(int choice)
{
	returnChoice = choice;
}
bool Credits::getMenuChoice()
{
	return returnChoice;
}