#include "Loading.h"



Loading::Loading()
{
	vikingFont = new Font;
	vikingFont->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Fonts\\viking\\VIKING-N.ttf");

	lemonFont = new Font;
	lemonFont->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Fonts\\lemon_milk\\LemonMilk.otf");

	bgTexture = new Texture();
	bgTexture->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Images\\mainMenuBackground.jpg");
	bgSprite = new Sprite();
	bgSprite->setTexture(*bgTexture);
	bgSprite->setPosition(0.0, 0.0);

	shadeRect = new RectangleShape(Vector2f(1200.0, 600.0));
	shadeRect->setFillColor(Color::Color(0, 0, 0, 170));

	Button_ *tmpPtr = new Button_(600.0, 500.0, "Exit");
	buttonsVector.push_back(tmpPtr);

}


Loading::~Loading()
{
	delete vikingFont;
	delete lemonFont;
	
	delete titleBoundsBox;
	delete bgSprite;
	delete bgTexture;
	delete shadeRect;
}


void Loading::draw(RenderTarget &target, RenderStates states) const
{
	
	target.draw(*bgSprite);
	target.draw(*shadeRect);

	for (int i = 0; i < buttonsVector.size(); i++)
		target.draw(*buttonsVector[i]);

	for (int i = 0; i < savesTextsVector.size(); i++)
	{
		target.draw(savesTextsVector[i]);
	}
}

void Loading::CheckButtonsForHighlight(RenderWindow &target)
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

void Loading::LoadFromFile()
{
	int i = 0;
	string line;
	
	fstream file;

	file.open("Saves.txt", ios::in);
	if (file.good() == true)
	{
		while (!file.eof())
		{
			getline(file, line);
			savesVector.push_back(line);
		}
	}
	else
	{
		cout << "Problem with file access!!" << endl;
	}
	file.close();

}

vector <string> Loading::ChooseSave(int i)
{
	int j = 0, k = 0;
	string tmp;
	vector <string> tmpVector;
 	fstream file;
	try {
		file.open("Saves.txt", ios::in);
		if (file.good() == true)
		{
			while (j != i)
			{
				getline(file, tmp);
				j++;
			}
			getline(file, tmp);
		}
		else
		{
			throw 0; 
		}
	}
	catch (int x) {
		cout << "Problem with file access!!" << endl;
	}

	

	for (j = 0; j < 6; j++)
	{
		tmpVector.push_back(LineDivider(k, tmp));
	}

	file.close();

	return tmpVector;
}

vector <string> Loading::Load(RenderWindow &target)
{
	CheckButtonsForHighlight(target);

	this->draw(target, RenderStates::Default);

	vector <string> loadVector;
	loadVector.push_back("1");
	/*
	Event pressEvent;

	while (target.pollEvent(pressEvent))
	{
		switch (pressEvent.type)
		{
		case Event::MouseButtonPressed:
			for (int i = 0; i < buttonsVector.size(); i++)
			{
				if ((Mouse::getPosition(target).x < (buttonsVector[i]->posX + (buttonsVector[i]->textBoundsBox->width / 2) + 10.0))
					&& (Mouse::getPosition(target).x >(buttonsVector[i]->posX - (buttonsVector[i]->textBoundsBox->width / 2) - 20.0))
					&& (Mouse::getPosition(target).y < (buttonsVector[i]->posY + (buttonsVector[i]->textBoundsBox->height / 2) + 5.0))
					&& (Mouse::getPosition(target).y >(buttonsVector[i]->posY - (buttonsVector[i]->textBoundsBox->height / 2) - 10.0)))
				{
					buttonsVector[i]->buttonHighlight();
					{
						if (i == 0)
						{
							loadVector.push_back("0");
							return loadVector;
						}
						else
						{
							loadVector = ChooseSave(i - 1);
							return loadVector;
						}
					}
				}
				else
					buttonsVector[i]->buttonEndHighlight();

			}
			break;
		}
	}*/
	return loadVector;
}

void Loading::FixSaves()
{
	Text * tmpPtr;
	Button_ * tmpButPtr;
	vector <string> tmpVector;
	int k = 0;

	for (int i = 0; i < savesVector.size(); i++)
	{
		for (int j = 0; j < 6; j++)
		{
			tmpVector.push_back(LineDivider(k, savesVector[i]));
		}
		k = 0;
		tmpPtr = new Text(tmpVector[0] + " - "
			+ tmpVector[1] + "HP - "
			+ tmpVector[2] + "MN - "
			+ tmpVector[3] + "STR - "
			+ tmpVector[4] + "MP - "
			+ "Game Progress: " + tmpVector[5], *lemonFont);
		tmpPtr->setCharacterSize(20);
		tmpPtr->setPosition(50.0, 100.0 + i * 50.0);
		savesTextsVector.push_back(*tmpPtr);
		tmpButPtr = new Button_(800.0, 100.0 + i * 50.0, "Load");
		buttonsVector.push_back(tmpButPtr);


		tmpVector.clear();
	}
	savesDisplayed = 1;
}