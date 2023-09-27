#include "GameEnvironment.h"

using namespace std;
/**
 * @file GameEnvironment.cpp
 * @author Billy Ndegwah Micah
 *
 * This is the implementation of the GameEnvironment class defined in GameEnvironment.h
 */
GameEnvironment::GameEnvironment()
{
	string char1 = "Mickey";
	string char2 = "Ndegwah";
	string char3 = "Myka";
	string char4 = "Camille";
	string char5 = "Kanade";

	string playerName = "Billy";

	Environ* environ1 = new Environ("Forest", Booster::BackpackBooster, 3, new Position(10, 10));

	Position* startPos = new Position(10, 10);
	Position* endPos = new Position(200, 200);

	Character* character1 = new Character(char1, 100.0f, false);
	Character* character2 = new Character(char2, 100.0f, false);
	Character* character3 = new Character(char3, 100.0f, false);
	Character* character4 = new Character(char4, 100.0f, true);
	Character* character5 = new Character(char5, 100.0f, true);

	Character* playerChar = new Character(playerName, 100.0f, true);

	characters = { character1, character2, character3, character4, character5 };
	player = playerChar;



}