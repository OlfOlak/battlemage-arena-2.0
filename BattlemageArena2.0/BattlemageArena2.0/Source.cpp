#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "AdditionalFunctions.h"
#include "MainMenu.h"
#include "Game.h"
#include "Credits.h"
#include "ExitMenu.h"
#include "Loading.h"

using namespace std;
using namespace sf;


int main()
{
	RenderWindow mainWindow(VideoMode(1200, 600), "Battlemage Arena 2.0");
	mainWindow.setFramerateLimit(9);
	MainMenu mainMenu;
	//Game* gameObjPtr = new Game;
	//gameObjPtr->SetUpBattlemageObj();
	Game* gamePtr = nullptr;
	Loading* loadMenu = nullptr;
	Credits creditsMenu;
	ExitMenu exitMenu; 
	Event mainWindowEvent;
	vector <string> loadVector;

	
	
	// Main game loop.
	while (mainWindow.isOpen())
	{
		mainWindow.clear();
		//cout << "menuChoice: " << mainMenu.getMenuChoice() << endl;
		

		switch (mainMenu.getMenuChoice())
		{
		case 1:
			// Player name section.
			if (gamePtr == nullptr)
				gamePtr = new Game;
			switch (gamePtr->getGameState())
			{
			case 0:
				// Name player.
				cout << "gameState: 0" << endl;
				gamePtr->namePlayer(mainWindow);
				break;
			case 1:
				// Return to main menu.
				cout << "gameState: 1" << endl;
				mainMenu.setMenuChoice(0);
				delete gamePtr;
				break;
			case 2:
				// Start fight sequence.
				cout << "gameState: 2" << endl;

				gamePtr->FightSequence(mainWindow);
				
				break;
			case 3:
				// Give away attributes bonuses.
				cout << "gameState: 3" << endl;

				gamePtr->Progression(mainWindow);

				break;
			case 4:
				// Fight lost window.
				cout << "gameState: 4" << endl;

				gamePtr->LooseGame(mainWindow);

				break;
			case 5:
				// Win the game window.
				cout << "gameState: 5" << endl;

				gamePtr->EndGame(mainWindow);

				break;
			}
			break;
			// Gameplay section.


		case 2:
			// Load game section.
			if (loadMenu == nullptr)
				loadMenu = new Loading;

			
			if (loadMenu->savesDisplayed == 0)
			{
				loadMenu->LoadFromFile();
				loadMenu->FixSaves();
			}

			loadVector = loadMenu->Load(mainWindow);

			if (loadVector[0] == "0")
			{
				mainMenu.setMenuChoice(0);
			}
			else
			{
				gamePtr = new Game(loadVector[0],
					stof(loadVector[1]),
					stof(loadVector[2]),
					stoi(loadVector[3]),
					stoi(loadVector[4]),
					stoi(loadVector[5]));
				mainMenu.setMenuChoice(1);
				gamePtr->setGameState(2);
			}

			break;
		case 3:
			switch (creditsMenu.getMenuChoice())
			{
			case 0:
				creditsMenu.ShowCredits(mainWindow);
				break;
			case 1:
				mainMenu.setMenuChoice(0);
				creditsMenu.setMenuChoice(0);
				break;
			}
			break;
		case 4:
			switch (exitMenu.getMenuChoice())
			{
			case 1:
				mainWindow.close();
				break;
			case 2:
				mainMenu.setMenuChoice(0);
				exitMenu.setMenuChoice(0);
				break;
			default:
				exitMenu.OptionChoice(mainWindow);
				break;

			}
			break;
		default:
			mainMenu.OptionChoice(mainWindow);
			break;
		}
		

	


		mainWindow.display();
	}

	

	//system("pause");
	return 0;
}