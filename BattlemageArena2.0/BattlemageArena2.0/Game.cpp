#include "Game.h"



Game::Game()
{
	playerHealth = 100;
	playerMana = 40;
	playerStrength = 10;
	playerMagicPower = 10;
}

Game::Game(string nameInput, float healthInput, float manaInput, int strengthInput, int magicInput, int progressInput)
{
	playerName = nameInput;
	playerHealth = healthInput;
	playerMana = manaInput;
	playerStrength = strengthInput;
	playerMagicPower = magicInput;
	progressIndicator = progressInput;
}

Game::~Game()
{
}

void Game::InitializeNamingMenuTechnicals()
{
	titleFont = new Font();
	titleFont->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Fonts\\viking\\VIKING-N.ttf");

	titleText = new Text("BATTLEMAGE\n   ARENA 2.0", *titleFont);
	titleText->setCharacterSize(60);
	titleBoundsBox = new FloatRect;
	*titleBoundsBox = titleText->getLocalBounds();
	titleText->setOrigin(titleBoundsBox->width / 2, titleBoundsBox->height / 2);
	titleText->setPosition(600.0, 80.0);
	titleText->setFillColor(Color::Color(158, 22, 7));

	bgTexture = new Texture();
	bgTexture->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Images\\mainMenuBackground.jpg");
	bgSprite = new Sprite();
	bgSprite->setTexture(*bgTexture);
	bgSprite->setPosition(0.0, 0.0);

	shadeRect = new RectangleShape(Vector2f(1200.0, 600.0));
	shadeRect->setFillColor(Color::Color(0, 0, 0, 170));

	requestFont = new Font;
	requestFont->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Fonts\\morris_roman\\MorrisRomanBlack.ttf");

	enterFont = new Font;
	enterFont->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Fonts\\lemon_milk\\LemonMilk.otf");

	requestText = new Text("Enter your charecter's name:", *requestFont);
	requestText->setCharacterSize(40);
	requestText->setPosition(Vector2f(300.0, 200.0));

	requestBoudsBox = new FloatRect;
	*requestBoudsBox = requestText->getGlobalBounds();

	enterText = new Text(enterString, *enterFont);
	enterText->setPosition(Vector2f(300.0, 250.0));

	enterRect = new RectangleShape(Vector2f(requestBoudsBox->width, requestBoudsBox->height));
	enterRect->setPosition(requestBoudsBox->left, requestBoudsBox->top + 40.0);
	enterRect->setFillColor(Color::Black);

	nameWarningText = new Text("Wrong name sequence, letters only!", *requestFont);
	nameWarningText->setFillColor(Color::Transparent);
	nameWarningText->setPosition(Vector2f(requestBoudsBox->left, requestBoudsBox->top + 100.0));

	buttonsVector.clear();
	Button_* tmpButtonPtr = new Button_(350.0, 370.0, "Cancel");
	buttonsVector.push_back(tmpButtonPtr);
	tmpButtonPtr = new Button_(680.0, 370.0, "Submit");
	buttonsVector.push_back(tmpButtonPtr);
}

void Game::DeleteNamingMenuTechnicals()
{
	delete bgTexture;
	delete bgSprite;
	delete shadeRect;
	delete requestFont;
	delete requestText;
	delete requestBoudsBox;
	delete enterFont;
	delete enterRect;
	delete nameWarningText;
	delete titleFont;
	delete titleText;
	delete titleBoundsBox;

	for (int i = 0; i < buttonsVector.size(); i++)
		delete buttonsVector[i];
}

void Game::InitializeFightSequenceTechnicals()
{
	titleFont = new Font();
	titleFont->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Fonts\\viking\\VIKING-N.ttf");

	titleText = new Text("BATTLEMAGE\n   ARENA 2.0", *titleFont);
	titleText->setCharacterSize(30);
	titleBoundsBox = new FloatRect;
	*titleBoundsBox = titleText->getLocalBounds();
	titleText->setOrigin(titleBoundsBox->width / 2, titleBoundsBox->height / 2);
	titleText->setPosition(600.0, 40.0);
	titleText->setFillColor(Color::Color(158, 22, 7));

	vsText = new Text("VS", *titleFont);
	vsText->setCharacterSize(60);

	vsBoundsBox = new FloatRect;
	*vsBoundsBox = vsText->getGlobalBounds();

	vsText->setOrigin(vsBoundsBox->width / 2, vsBoundsBox->height / 2);
	vsText->setPosition(600.0, 300.0);
}

void Game::DeleteFightSequenceTechnicals()
{
	delete titleText;
	delete titleFont;
	delete vsText;
	delete vsBoundsBox;
}

void Game::InitializeProgressionTechnicals()
{

	winFont = new Font;
	winFont->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Fonts\\viking\\VIKING-N.ttf");

	attributesFont = new Font;
	attributesFont->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Fonts\\lemon_milk\\LemonMilk.otf");

	winText = new Text("You have won!", *winFont);
	winText->setCharacterSize(50);
	winText->setFillColor(Color(158, 22, 7));

	winBoundsBox = new FloatRect;
	*winBoundsBox = winText->getGlobalBounds();

	winText->setOrigin(winBoundsBox->width / 2, winBoundsBox->height / 2);
	winText->setPosition(Vector2f(600.0, 100.0));

	pointsText = new Text("Points left: " + to_string(progressPoints), *attributesFont);
	pointsText->setCharacterSize(30);
	pointsText->setPosition(400.0, 150.0);
	pointsText->setFillColor(Color(158, 22, 7));

	healthText = new Text("Health: " + to_string(playerHealth) + "(+" + to_string(healthPoints) + ")", *attributesFont);
	healthText->setCharacterSize(30);
	healthText->setPosition(400.0, 220.0);

	manaText = new Text("Mana: " + to_string(playerMana) + "(+" + to_string(manaPoints) + ")", *attributesFont);
	manaText->setCharacterSize(30);
	manaText->setPosition(400.0, 270.0);

	strengthText = new Text("Strength: " + to_string(playerStrength) + "(+" + to_string(strengthPoints) + ")", *attributesFont);
	strengthText->setCharacterSize(30);
	strengthText->setPosition(400.0, 320.0);

	magicText = new Text("Magic Power: " + to_string(playerMagicPower) + "(+" + to_string(magicPoints) + ")", *attributesFont);
	magicText->setCharacterSize(30);
	magicText->setPosition(400.0, 370.0);

	buttonsVector.clear();
	Button_ *tmpPtr;
	for (int i = 0, j = 1; i < 8; i += 2)
	{
		tmpPtr = new Button_(800.0, 220.0 + i/2 * 50.0, "add");
		buttonsVector.push_back(tmpPtr);
		tmpPtr = new Button_(880.0, 220.0 + i/2 * 50.0, "back");
		buttonsVector.push_back(tmpPtr);
	}
	if (progressPoints == 0)
	{
		tmpPtr = new Button_(1000.0, 500.0, "Next");
		buttonsVector.push_back(tmpPtr);
	}
}

void Game::DeleteProgressionTechnicals()
{
	delete winText;
	delete winFont;
	delete winBoundsBox;
	delete attributesFont;
	delete healthText;
	delete manaText;
	delete strengthText;
	delete magicText;

	
	for (int i = 0; i < buttonsVector.size(); i++)
		delete buttonsVector[i];
}

void Game::InitializeLooseTechnicals()
{

	winFont = new Font;
	winFont->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Fonts\\viking\\VIKING-N.ttf");

	looseText = new Text("You lost!", *winFont);
	looseText->setCharacterSize(70);

	looseBoundsBox = new FloatRect;
	*looseBoundsBox = looseText->getGlobalBounds();

	looseText->setOrigin(looseBoundsBox->width / 2, looseBoundsBox->height / 2);
	looseText->setPosition(600.0, 100.0);
	looseText->setFillColor(Color(158, 22, 7));

	requestFont = new Font;
	requestFont->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Fonts\\lemon_milk\\LemonMilk.otf");

	requestText = new Text("Do you want to try again?", *requestFont);
	requestText->setCharacterSize(30);

	requestBoudsBox = new FloatRect;
	*requestBoudsBox = requestText->getGlobalBounds();

	requestText->setOrigin(requestBoudsBox->width / 2, requestBoudsBox->height / 2);
	requestText->setPosition(600.0, 200.0);

	Button_ *tmpPtr;

	buttonsVector.clear();

	tmpPtr = new Button_(400.0, 400.0, "No");
	buttonsVector.push_back(tmpPtr);

	tmpPtr = new Button_(800.0, 400.0, "Yes");
	buttonsVector.push_back(tmpPtr);


}

void Game::DeleteLooseTechnicals()
{
	delete winFont;
	delete looseText;
	delete requestFont;
	delete requestText;
	delete requestBoudsBox;

	for (int i = 0; i < buttonsVector.size(); i++)
		delete buttonsVector[i];
}

void Game::InitializeEndGameTechnicals()
{
	winFont = new Font;
	winFont->loadFromFile("C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Fonts\\viking\\VIKING-N.ttf");

	winText = new Text("      Congratulations!\nYou have wone the game", *winFont);
	winText->setCharacterSize(40);
	winText->setFillColor(Color(158, 22, 7));

	winBoundsBox = new FloatRect;
	*winBoundsBox = winText->getGlobalBounds();

	winText->setOrigin(winBoundsBox->width / 2, winBoundsBox->height / 2);
	winText->setPosition(Vector2f(600.0, 250));

	buttonsVector.clear();
	Button_ *tmpPtr = new Button_(600.0, 400.0, "Exit");
	buttonsVector.push_back(tmpPtr);
}

void Game::DeleteEndGameTechnicals()
{
	delete winFont;
	delete winText;
	delete winBoundsBox;
	
	for (int i = 0; i < buttonsVector.size(); i++)
		delete buttonsVector[i];
}

void Game::draw(RenderTarget &target, RenderStates states) const
{
	if (gameState == 0)
	{
		target.draw(*bgSprite);
		target.draw(*shadeRect);
		target.draw(*requestText);
		target.draw(*titleText);
		target.draw(*enterRect);
		target.draw(*enterText);
		target.draw(*nameWarningText);

		for (int i = 0; i < buttonsVector.size(); i++)
			target.draw(*buttonsVector[i]);
	}

	if (gameState == 2)
	{
		if(titleText != nullptr)
			target.draw(*titleText);

		if(vsText != nullptr)
			target.draw(*vsText);

		if(battlemageObj != nullptr)
			target.draw(*battlemageObj);

		if(enemyObj != nullptr)
			target.draw(*enemyObj);

	}

	if (gameState == 3)
	{
		target.draw(*winText);
		target.draw(*pointsText);
		target.draw(*healthText);
		target.draw(*manaText);
		target.draw(*strengthText);
		target.draw(*magicText);

		for (int i = 0; i < buttonsVector.size(); i++)
			target.draw(*buttonsVector[i]);

	}

	if (gameState == 4)
	{
		target.draw(*looseText);
		target.draw(*requestText);

		for (int i = 0; i < buttonsVector.size(); i++)
			target.draw(*buttonsVector[i]);
	}

	if (gameState == 5)
	{
		target.draw(*winText);

		for (int i = 0; i < buttonsVector.size(); i++)
			target.draw(*buttonsVector[i]);
	}
}

void Game::CheckButtonsForHighlight(RenderWindow &target)
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

void Game::checkNameEnterRegex()
{
	regex stringRegex("[A-Za-z]{1,12}");
	smatch regexResult;

	if (nameWarningText != nullptr)
	{
		switch (enterString.length())
		{
		case 0:
			nameWarningText->setFillColor(Color::Color(158, 22, 7));
			nameWarningText->setString("Name sequence can't be empty!");
			isStringGood = 0;
			break;
		default:
			nameWarningText->setString("Wrong name sequence, letters only!");
			if (regex_match(enterString, regexResult, stringRegex))
			{
				cout << "Nazwa poprawna" << endl;
				isStringGood = 1;
				nameWarningText->setFillColor(Color::Transparent);
				if (nameWarningText->getFillColor() == Color::Transparent)
					cout << "Kolor niewidoczny!" << endl;
				else
					cout << "Kolor czerwony" << endl;
			}
			else
			{
				isStringGood = 0;
				cout << "Nazwa niepoprawna" << endl;
				nameWarningText->setFillColor(Color::Color(158, 22, 7));
				if (nameWarningText->getFillColor() == Color::Transparent)
					cout << "Kolor niewidoczny!" << endl;
				else
					cout << "Kolor czerwony" << endl;
			}
			break;
		}
		
		cout << enterString.length() << endl;
	}
	else
	{
		cout << "Nie istnieje obiekt nameWarningText!" << endl;
	}
	
}

void Game::namePlayer(RenderWindow &target)
{
	InitializeNamingMenuTechnicals();
	
	Event enterEvent;
	
	CheckButtonsForHighlight(target);
	checkNameEnterRegex();
	this->draw(target, RenderStates::Default);

	while (target.pollEvent(enterEvent))
	{
		
		switch (enterEvent.type)
		{
		case Event::TextEntered:
			if (enterEvent.text.unicode == '\b'
				&& enterString.size() != 0)
			{
				enterString.pop_back();
			}
			else if (enterEvent.text.unicode >= 32
				&& enterEvent.text.unicode <= 126)
			{
				if (enterString.length() < 12)
					enterString += static_cast<char>(enterEvent.text.unicode);
				else
					break;
			}
		case Event::MouseButtonPressed:
			//if (Mouse::isButtonPressed(Mouse::Left))
			//{
				for (int i = 0; i < buttonsVector.size(); i++)
				{
					if ((Mouse::getPosition(target).x < (buttonsVector[i]->posX + (buttonsVector[i]->textBoundsBox->width / 2) + 10.0))
						&& (Mouse::getPosition(target).x > (buttonsVector[i]->posX - (buttonsVector[i]->textBoundsBox->width / 2) - 20.0))
						&& (Mouse::getPosition(target).y < (buttonsVector[i]->posY + (buttonsVector[i]->textBoundsBox->height / 2) + 5.0))
						&& (Mouse::getPosition(target).y > (buttonsVector[i]->posY - (buttonsVector[i]->textBoundsBox->height / 2) - 10.0)))
					{
						buttonsVector[i]->buttonHighlight();
						{
							switch (i)
							{
							case 0:
								if(Mouse::isButtonPressed(Mouse::Left))
									gameState = 1;
								break;
							case 1:
								if (isStringGood == 1 && Mouse::isButtonPressed(Mouse::Left))
								{
									playerName = enterString;
									if (battlemageObj == nullptr)
									{
										SetUpBattlemageObj();
										SetUpEnemy();
									}
									gameState = 2;
								}
								break;
							}
						}
					}
					else
						buttonsVector[i]->buttonEndHighlight();

				}
			//}
			break;
		}
		this->draw(target, RenderStates::Default);
	}
	cout << "isStringGood: " << isStringGood << endl;
	delete enterText;
	DeleteNamingMenuTechnicals();
}

int Game::getGameState()
{
	return gameState;
}

void Game::setGameState(int newState)
{
	gameState = newState;
}

void Game::SetUpBattlemageObj()
{
	battlemageObj = new Battlemage(playerName,
		playerHealth,
		playerMana,
		playerStrength,
		playerMagicPower);

}

void Game::SetUpEnemy()
{
	//enemyObj = new Enemy("Skeletor", 20, 2, 2, 1, 3,
	//	"C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Images\\enemyPortrets\\enemySkeletor.jpg");

	fstream file;
	string Line, temp;
	int i = 0;
	try {
		file.open("Enemys.txt", ios::in);
		if (file.good() == true)
		{
			while (i != progressIndicator)
			{
				getline(file, temp);
				i++;
			}
			getline(file, Line);
		}
		else
		{
			throw 0;  
		}
	}catch(int x){
		cout << "Problem with enemys file access!!" << endl;
	}
	file.close();

	i = 0;

	// Entering enemyobject's attributes.
	paramVector.clear();

	for (int j = 0; j < 7; j++)
		paramVector.push_back(LineDivider(i, Line));


	enemyObj = new Enemy(paramVector[0],
		stoi(paramVector[1]),
		stoi(paramVector[2]),
		stoi(paramVector[3]),
		stoi(paramVector[4]),
		stoi(paramVector[5]),
		"C:\\Users\\OlafPC\\source\\repos\\Olak_Olaf_czwartek12\\BattlemageArena2.0\\BattlemageArena2.0\\Images\\enemyPortrets\\" + paramVector[6]);
}

void Game::FightSequence(RenderWindow &target)
{
	InitializeFightSequenceTechnicals();

	this->draw(target, RenderStates::Default);

	switch (sequenceState)
	{
		case 0:
		switch (battlemageObj->makeAction(target))
		{
		case 1:
			cout << "Sword Attack!" << endl;
			battlemageObj->swordAttack(*enemyObj);
			this->draw(target, RenderStates::Default);

			break;
		case 2:
			battlemageObj->swordParry(*enemyObj);
			this->draw(target, RenderStates::Default);
			cout << "Sword Parry!" << endl;		

			break;
		case 3:
			battlemageObj->fireballThrow(*enemyObj);
			this->draw(target, RenderStates::Default);
			cout << "Throw Fireball!" << endl;

			break;
		case 4:
			battlemageObj->magicShield(*enemyObj);
			this->draw(target, RenderStates::Default);
			cout << "Magic Shield!" << endl;

			break;
		default:

			break;
		}
		break;
	}

	DeleteFightSequenceTechnicals();

	if (battlemageObj->getBattlemageHealth() <= 0)
		setGameState(4);
	else if (enemyObj->getEnemyHealth() <= 0)
	{
		if (progressIndicator == 7)
			setGameState(5);
		else
			setGameState(3);
	}
}

void Game::Progression(RenderWindow &target)
{
	InitializeProgressionTechnicals();

	CheckButtonsForHighlight(target);

	this->draw(target, RenderStates::Default);
	cout << "Progression" << endl;

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
						switch (i)
						{
						case 0:
							if (progressPoints > 0)
							{
								progressPoints -= 1;
								healthPoints++;
								playerHealth += 20;
							}
							break;
						case 1:
							if (healthPoints > 0)
							{
								progressPoints += 1;
								healthPoints--;
								playerHealth -= 20;
							}
							break;
						case 2:
							if (progressPoints > 0)
							{
								progressPoints -= 1;
								manaPoints++;
								playerMana += 10;
							}
							break;
						case 3:
							if (manaPoints > 0)
							{
								progressPoints += 1;
								manaPoints--;
								playerMana -= 10;
							}
							break;
						case 4:
							if (progressPoints > 0)
							{
								progressPoints -= 1;
								strengthPoints++;
								playerStrength += 1;			
							}
							break;
						case 5:
							if (strengthPoints > 0)
							{
								progressPoints += 1;
								strengthPoints--;
								playerStrength -= 1;
							}
							break;
						case 6:
							if (progressPoints > 0)
							{
								progressPoints -= 1;
								magicPoints++;
								playerMagicPower += 1;
							}
							break;
						case 7:
							if (magicPoints > 0)
							{
								progressPoints += 1;
								magicPoints--;
								playerMagicPower -= 1;
							}
							break;
						case 8:
							if (progressPoints == 0)
							{
								SetUpBattlemageObj();
								progressIndicator++;
								SetUpEnemy();
								progressPoints = 5;
								healthPoints = 0;
								manaPoints = 0;
								strengthPoints = 0;
								magicPoints = 0;
								gameState = 2;
							}
							SaveGame();
							
							break;
						}
					}
				}
				else
					buttonsVector[i]->buttonEndHighlight();

			}
			break;
		}
	}


	DeleteProgressionTechnicals();
}

void Game::LooseGame(RenderWindow &target)
{
	InitializeLooseTechnicals();

	CheckButtonsForHighlight(target);

	this->draw(target, RenderStates::Default);


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
						switch (i)
						{
						case 0:
							gameState = 1;
							break;
						case 1:
							SetUpBattlemageObj();
							SetUpEnemy();
							gameState = 2;
							break;
						}
					}
				}
				else
					buttonsVector[i]->buttonEndHighlight();
			}
			break;
		}
	}

	DeleteLooseTechnicals();
}

void Game::EndGame(RenderWindow &target)
{
	InitializeEndGameTechnicals();

	CheckButtonsForHighlight(target);

	this->draw(target, RenderStates::Default);

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
						switch (i)
						{
						case 0:
							gameState = 1;
							break;
						}
					}
				}
				else
					buttonsVector[i]->buttonEndHighlight();
			}
			break;
		}
	}
	DeleteEndGameTechnicals();
}

void Game::SaveGame()
{
	string SaveLine;
	string* SavesArrayPointer;
	int i = 0;

	if (firstSave == 0)
	{
		SaveLine = playerName + ","
			+ to_string(playerHealth) + ","
			+ to_string(playerMana) + ","
			+ to_string(playerStrength) + ","
			+ to_string(playerMagicPower) + ","
			+ to_string(progressIndicator) + ",";
		SavesArrayPointer = ArrayCreator(SaveLine, i);

		fstream SaveFile;
		try {
			SaveFile.open("Saves.txt", ios::out);
			if (SaveFile.good() == true)
			{
				for (int k = 0; k <= i - 1; k++)
				{
					SaveFile << SavesArrayPointer[k];
					SaveFile << endl;
				}
			}
			else
				throw 0; 
		}
		catch (int x) {
			cout << "File access error!" << endl;
		}
		SaveFile.close();
		cout << "Game has been saved!" << endl;
	}
	else
	{
		i = 0;
		SavesArrayPointer = ArrayCreator2(i);
		int j = 0, k = 0;
		while (LineDivider(k, SavesArrayPointer[j]) != playerName)
		{
			j++;
			k = 0;
		}
		SavesArrayPointer[j] = playerName + ","
			+ to_string(playerHealth) + ","
			+ to_string(playerMana) + ","
			+ to_string(playerStrength) + ","
			+ to_string(playerMagicPower) + ","
			+ to_string(progressIndicator) + ",";

		fstream SaveFile;
		try {
			SaveFile.open("Saves.txt", ios::out);
			if (SaveFile.good() == true)
			{
				for (int k = 0; k <= i - 1; k++)
				{
					SaveFile << SavesArrayPointer[k];
					SaveFile << endl;
				}
			}
			else
				throw 0; 
		}
		catch (int x) {
			cout << "File access error!" << endl;
		}
		SaveFile.close();
		cout << "Game has been saved!" << endl;
	}
}
