#include "ExitMenu.h"



ExitMenu::ExitMenu()
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

	textFont = new Font;
	textFont->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Fonts\\morris_roman\\MorrisRomanBlack.ttf");

	questionText = new Text("Are you sure to quit?", *textFont);
	questionText->setCharacterSize(50.0);

	questionBoundBox = new FloatRect;
	*questionBoundBox = questionText->getGlobalBounds();

	questionText->setOrigin(questionBoundBox->width / 2, questionBoundBox->height / 2);
	questionText->setPosition(600.0, 300.0);
	

	Button_* tmpButtonPtr = new Button_(questionText->getPosition().x - (questionBoundBox->width / 4),
		questionText->getPosition().y + 2 * questionBoundBox->height, "Yes");
	buttonsVector.push_back(tmpButtonPtr);

	tmpButtonPtr = new Button_(questionText->getPosition().x + (questionBoundBox->width / 4),
		questionText->getPosition().y + 2 * questionBoundBox->height, "No");
	buttonsVector.push_back(tmpButtonPtr);
}


ExitMenu::~ExitMenu()
{
	delete textFont;
	delete questionText;
	delete shadeRect;
	delete questionBoundBox;

	for (int i = 0; i < buttonsVector.size(); i++)
		delete buttonsVector[i];
}

void ExitMenu::draw(RenderTarget &target, RenderStates states) const
{
	target.draw(*bgSprite);
	target.draw(*shadeRect);
	target.draw(*titleText);
	target.draw(*questionText);

	for (int i = 0; i < buttonsVector.size(); i++)
		target.draw(*buttonsVector[i]);
}

void ExitMenu::CheckButtonsForHighlight(RenderWindow &target)
{

	for (int i = 0; i < buttonsVector.size(); i++)
	{
		if ((Mouse::getPosition(target).x < (buttonsVector[i]->posX + (buttonsVector[i]->textBoundsBox->width / 2) + 10.0))
			&& (Mouse::getPosition(target).x >(buttonsVector[i]->posX - (buttonsVector[i]->textBoundsBox->width / 2) - 20.0))
			&& (Mouse::getPosition(target).y < (buttonsVector[i]->posY + (buttonsVector[i]->textBoundsBox->height / 2) + 5.0))
			&& (Mouse::getPosition(target).y >(buttonsVector[i]->posY - (buttonsVector[i]->textBoundsBox->height / 2) - 10.0)))
		{
			buttonsVector[i]->buttonHighlight();
		}
		else
			buttonsVector[i]->buttonEndHighlight();
	}
}

void ExitMenu::OptionChoice(RenderWindow &target)
{
	Event menuEvent;

	this->draw(target, RenderStates::Default);

	while (target.pollEvent(menuEvent))
	{
		CheckButtonsForHighlight(target);

		switch (menuEvent.type)
		{
		case Event::Closed:
			target.close();
			break;


		case Event::MouseButtonPressed:

			cout << "MouseButton pressed!" << endl;
			for (int i = 0; i < buttonsVector.size(); i++)
			{
				if ((Mouse::getPosition(target).x < (buttonsVector[i]->posX + (buttonsVector[i]->textBoundsBox->width / 2) + 5.0))
					&& (Mouse::getPosition(target).x >(buttonsVector[i]->posX - (buttonsVector[i]->textBoundsBox->width / 2) - 10.0))
					&& (Mouse::getPosition(target).y < (buttonsVector[i]->posY + (buttonsVector[i]->textBoundsBox->height / 2) + 15.0))
					&& (Mouse::getPosition(target).y >(buttonsVector[i]->posY - (buttonsVector[i]->textBoundsBox->height / 2) + 5.0)))
				{
					buttonsVector[i]->buttonHighlight();
					
					if (Mouse::isButtonPressed(Mouse::Button::Left))
						menuChoice = i + 1;
					cout << "(exit) menuChoice set to " << i + 1 << endl;
				}
				else
					buttonsVector[i]->buttonEndHighlight();
			}
			break;

		default:
			cout << "Default" << endl;
			break;

		}


	}

}

void ExitMenu::setMenuChoice(int choice)
{
	menuChoice = choice;
}
int ExitMenu::getMenuChoice()
{
	return menuChoice;
}