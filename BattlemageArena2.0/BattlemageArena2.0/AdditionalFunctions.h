#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <fstream>
#include "MainMenu.h"
#include "Button_.h"


using namespace std;
using namespace sf;
class MainMenu;

void ScaleSpriteByWidth(Sprite &inputSprite, float outputWidth);
void ScaleSprite(Sprite &inputSprite, float outputWidth, float outputHeight);
vector <Text> cutVector(vector <Text> currentVector);
string LineDivider(int &CharCounter, string InputLine);
string* ArrayCreator(string ExtraLine, int &Counter);
string* ArrayCreator2(int &Counter);



