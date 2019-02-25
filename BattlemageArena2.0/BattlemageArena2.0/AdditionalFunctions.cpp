#include "AdditionalFunctions.h"

using namespace std;
using namespace sf;
class MainMenu;

void ScaleSpriteByWidth(Sprite &inputSprite, float outputWidth)
{
	float xScale = outputWidth / inputSprite.getTexture()->getSize().x;
	inputSprite.setScale(xScale, xScale);
}

void ScaleSprite(Sprite &inputSprite, float outputWidth, float outputHeight)
{
	float xScale = outputWidth / inputSprite.getTexture()->getSize().x;
	float yScale = outputHeight / inputSprite.getTexture()->getSize().y;
	inputSprite.setScale(xScale, yScale);
}

vector <Text> cutVector(vector <Text> currentVector)
{
	vector <Text> tmpVector;

	for (int i = 1; i < currentVector.size(); i++)
	{
		tmpVector.push_back(currentVector[i]);
		tmpVector[i - 1].setPosition(350.0, 400.0 + (i - 1)*22.0);
	}
	
	return tmpVector;
	
}

string LineDivider(int &CharCounter, string InputLine)
{
	string temp;
	temp.clear();
	while (InputLine[CharCounter] != ',')
	{
		temp += InputLine[CharCounter];
		CharCounter++;
	}
	CharCounter++;
	return temp;
}

string* ArrayCreator(string ExtraLine, int &Counter)
{
	string* SavesTab = nullptr;
	string* tmp;
	string Line;
	fstream SaveFile;
	try {
		SaveFile.open("Saves.txt", ios::in);

		while (getline(SaveFile, Line))
		{
			if (Line == "")
			{
				continue;
			}
			else
			{
				Counter++;
				tmp = new string[Counter];
				for (int j = 0; j < Counter - 1; j++)
				{
					tmp[j] = SavesTab[j];
				}
				tmp[Counter - 1] = Line;
				SavesTab = tmp;
			}
		}
		if (!SaveFile.good())
			throw 0;
	}
	catch (int x) {
		cout << "Problem with save file!" << endl;
	}

	Counter++;
	tmp = new string[Counter];
	for (int j = 0; j < Counter - 1; j++)
	{
		tmp[j] = SavesTab[j];
	}
	tmp[Counter - 1] = ExtraLine;
	SaveFile.close();

	return tmp;
}

string* ArrayCreator2(int &Counter)
{

	string* SavesTab = nullptr;
	string* tmp = nullptr;
	string Line;
	fstream SaveFile;
	try {
		SaveFile.open("Saves.txt", ios::in);

		while (getline(SaveFile, Line))
		{
			if (Line == "")
			{
				continue;
			}
			else
			{
				Counter++;
				tmp = new string[Counter];
				for (int j = 0; j < Counter - 1; j++)
				{
					tmp[j] = SavesTab[j];
				}
				tmp[Counter - 1] = Line;
				SavesTab = tmp;
			}
		}
		if (!SaveFile.good())
			throw 0;
	}
	catch (int x) {
		cout << "Problem with save file!!" << endl;
	}
	return tmp;
}