#include "MainMenu.h"



MainMenu::MainMenu()
{
	bgTexture = new Texture();
	bgTexture->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Images\\mainMenuBackground.jpg");
	bgSprite = new Sprite();
	bgSprite->setTexture(*bgTexture);
	bgSprite->setPosition(0.0, 0.0);

	titleFont = new Font();
	titleFont->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Fonts\\viking\\VIKING-N.ttf");

	titleText = new Text("BATTLEMAGE\n   ARENA 2.0", *titleFont);
	titleText->setCharacterSize(60);
	titleBoundsBox = new FloatRect;
	*titleBoundsBox = titleText->getLocalBounds();
	titleText->setOrigin(titleBoundsBox->width / 2, titleBoundsBox->height / 2);
	titleText->setPosition(600.0, 80.0);
	titleText->setFillColor(Color::Color(158, 22, 7));

	Button_* tmpButtonPtr = new Button_(600.0, 220.0, "New Game");
	buttonsVector.push_back(tmpButtonPtr);
	tmpButtonPtr = new Button_(600.0, 270.0, "Load Game");
	buttonsVector.push_back(tmpButtonPtr);
	tmpButtonPtr = new Button_(600.0, 320.0, "Credits");
	buttonsVector.push_back(tmpButtonPtr);
	tmpButtonPtr = new Button_(600.0, 370.0, "Exit");
	buttonsVector.push_back(tmpButtonPtr);

	
}


MainMenu::~MainMenu()
{
	delete bgSprite;
	delete bgTexture;
	delete titleText;
	delete titleFont;
	delete titleBoundsBox;

	for (int i = 0; i < buttonsVector.size(); i++)
		delete buttonsVector[i];
}

void MainMenu::draw(RenderTarget &target, RenderStates states) const
{
	target.draw(*bgSprite, states);
	target.draw(*titleText, states);
	
	for (int i = 0; i < buttonsVector.size(); i++)
		target.draw(*buttonsVector[i]);
}

void MainMenu::CheckButtonsForHighlight(RenderWindow &target)
{
	
	for (int i = 0; i < buttonsVector.size(); i++)
	{
		if ((Mouse::getPosition(target).x < (buttonsVector[i]->posX + (buttonsVector[i]->textBoundsBox->width / 2) + 10.0))
			&& (Mouse::getPosition(target).x > (buttonsVector[i]->posX - (buttonsVector[i]->textBoundsBox->width / 2) - 20.0))
			&& (Mouse::getPosition(target).y < (buttonsVector[i]->posY + (buttonsVector[i]->textBoundsBox->height / 2) + 5.0))
			&& (Mouse::getPosition(target).y > (buttonsVector[i]->posY - (buttonsVector[i]->textBoundsBox->height / 2) - 10.0)))
		{
			buttonsVector[i]->buttonHighlight();
		}
		else
			buttonsVector[i]->buttonEndHighlight();
	}
}


void MainMenu::OptionChoice(RenderWindow &target)
{
	Event menuEvent;

	this->draw(target, RenderStates::Default);
	//this->CheckButtonsForHighlight(target);
		
	while (target.pollEvent(menuEvent))
	{
		this->CheckButtonsForHighlight(target);

		switch (menuEvent.type)
		{
		case Event::Closed:
			target.close();
			break;
		

		case Event::MouseButtonPressed:

			for (int i = 0; i < buttonsVector.size(); i++)
			{
				if ((Mouse::getPosition(target).x < (buttonsVector[i]->posX + (buttonsVector[i]->textBoundsBox->width / 2) + 5.0))
					&& (Mouse::getPosition(target).x > (buttonsVector[i]->posX - (buttonsVector[i]->textBoundsBox->width / 2) - 10.0))
					&& (Mouse::getPosition(target).y < (buttonsVector[i]->posY + (buttonsVector[i]->textBoundsBox->height / 2) + 15.0))
					&& (Mouse::getPosition(target).y > (buttonsVector[i]->posY - (buttonsVector[i]->textBoundsBox->height / 2) + 5.0)))
				{
					buttonsVector[i]->buttonHighlight();
					if (Mouse::isButtonPressed(Mouse::Button::Left))
						menuChoice = i + 1;
					cout << "(main) menuChoice set to " << i + 1 << endl;
				}
				else
					buttonsVector[i]->buttonEndHighlight();
			}
			break;

		default:
			break;

		}
			

	}

}

void MainMenu::setMenuChoice(int choice)
{
	menuChoice = choice;
}
int MainMenu::getMenuChoice()
{
	return menuChoice;
}