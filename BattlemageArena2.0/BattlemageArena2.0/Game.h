#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>
#include <regex>
#include <fstream>
#include "AdditionalFunctions.h"
#include "MainMenu.h"
#include "Battlemage.h"
#include "Enemy.h"




using namespace std;
using namespace sf;


class Game 
	: public Drawable
{
private:
	// Attributes.
	// Basic information.
	string playerName;
	int progressIndicator = 0;
	// Player attributes.
	int playerHealth;
	int playerMana;
	int playerStrength;
	int playerMagicPower;
	
	// Technicals.
	bool isStringGood = 0;
	bool firstSave = 0;
	int gameState = 0;
	bool sequenceState = 0;
	int progressPoints = 5;
	int healthPoints = 0;
	int manaPoints = 0;
	int strengthPoints = 0;
	int magicPoints = 0;

	Texture* bgTexture;
	Sprite* bgSprite;
	RectangleShape* shadeRect, *enterRect;
	Font* titleFont,*requestFont, *enterFont, *winFont, *attributesFont;
	Text* titleText, *requestText, *enterText, *nameWarningText, *vsText,
		*winText, *pointsText, *healthText, *manaText, *strengthText, *magicText, *looseText;
	FloatRect* titleBoundsBox, *requestBoudsBox, *vsBoundsBox, *winBoundsBox, *looseBoundsBox;
	string enterString;
	vector <Button_*> buttonsVector;
	vector <Text> journalVector;
	vector <string> paramVector;
	

	// Methods.
	

public:
	// Attributes.
	Battlemage * battlemageObj;
	Enemy* enemyObj;

	// Methods.
	void InitializeNamingMenuTechnicals();
	void DeleteNamingMenuTechnicals();
	void InitializeFightSequenceTechnicals();
	void DeleteFightSequenceTechnicals();
	void InitializeProgressionTechnicals();
	void DeleteProgressionTechnicals();
	void InitializeLooseTechnicals();
	void DeleteLooseTechnicals();
	void InitializeEndGameTechnicals();
	void DeleteEndGameTechnicals();

	virtual void draw(RenderTarget &target, RenderStates states) const;

	void CheckButtonsForHighlight(RenderWindow &target);
	void checkNameEnterRegex();
	void namePlayer(RenderWindow &target);

	int getGameState();
	void setGameState(int newState);

	void SetUpBattlemageObj();
	void SetUpEnemy();
	void FightSequence(RenderWindow &target);
	void Progression(RenderWindow &target);
	void LooseGame(RenderWindow &target);
	void EndGame(RenderWindow &target);
	void SaveGame();

	
	// Constructors.
	Game();
	Game(string nameInput, float healthInput, float manaInput, int strengthInput, int magicInput, int progressInput);
	~Game();
};

