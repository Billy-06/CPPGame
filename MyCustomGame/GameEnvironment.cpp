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
	// Instantiate the characters
	string char1 = "Mickey", char2 = "Ndegwah", char3 = "Myka", char4 = "Camille", char5 = "Kanade";

	string camelHints = "Head North, there's an oasis there. Stay away from the eastern routes, tones of spiders there";

	string charCamel = "[Camel] Ziggler", charCSpider = "[Camel Spider] Humped Crawler", charRSnake = "[Rattle Snake] Rattler";
	string playerName = "Billy";

	Camel* camel = new Camel(charCamel, 100.0f, true, camelHints, 100);
	CamelSpider* camelSpider = new CamelSpider(charCSpider, 100.0f, false, 100, 120, 100);
	RattleSnake* rattleSnake = new RattleSnake(charRSnake, 100.0f, false, 100);

	auto* character1 = new Character(char1, 100.0f, false);
	auto* character2 = new Character(char2, 100.0f, false);
	auto* character3 = new Character(char3, 100.0f, false);
	auto* character4 = new Character(char4, 100.0f, true);
	auto* character5 = new Character(char5, 100.0f, true);

	auto* playerChar = new Character(playerName, 100.0f, true);

	// Instantiate the Environments
	auto* envPos1 = new Position(10, 10);
	auto* envPos2 = new Position(20, 20);
	auto* envPos3 = new Position(30, 30);
	auto* endPos4 = new Position(22, 35);

	string envName1 = "Cacti Forest";
	string envName2 = "Desert Oasis";
	string envName3 = "Spider Ocean";
	string envName4 = "Sand Dune";

	auto* environ1 = new Environ(envName1, Booster::BackpackBooster, 3, *envPos1);
	auto* environ2 = new Environ(envName2, Booster::HealthBooster, 2, *envPos2);
	auto* environ3 = new Environ(envName3, Booster::AttackBooster, 1, *envPos3);
	auto* environ4 = new Environ(envName4, Booster::AttackBooster, 1, *endPos4);


	// Instantiate the spawn and the destination Point
	auto* startPos = new Position(10, 10);
	auto* endPos = new Position(200, 200);

	characters = { character1, character2, character3, character4, character5, camel, camelSpider, rattleSnake };
	player = playerChar;
	environs = { environ1, environ2, environ3, environ4 };
	playerSpawn = startPos;
	playerDestination = endPos;

	string Ch3Name = "Curly", Ch3Name2 = "Larry";
	// Added for Task 3
	CharacterTask3 characterTask3 = CharacterTask3(Ch3Name, 100.0f, false);
	CharacterTask3 characterTask3b = CharacterTask3(Ch3Name2, 100.0f, false);

	cout << "Character Task 3: " << endl;
	cout << characterTask3 << endl;

	cout << "Let the attack begin" << endl;
	while (characterTask3.GetCurrentHealth() > 0 && characterTask3b.GetCurrentHealth() > 0)
	{
		int turn = rand() % 2;
		if (turn == 1)
		{
			cout << characterTask3.GetName() << " attacks " << characterTask3b.GetName() << endl;
			characterTask3 >> characterTask3b;
		} else
		{
			cout << characterTask3b.GetName() << " attacks " << characterTask3.GetName() << endl;
			characterTask3b >> characterTask3;
		}

	}

	// Issue Command
	cout << "Issue Command: " << endl;
	cout << "Available Commands are: attack, move, shield, jump" << endl;
	cout << "Provide a value after the command e.g attack 56, shield 120" << endl;
	cin >> characterTask3;


	// Print out the creation message
	CreationMessage();
}

GameEnvironment::GameEnvironment(vector<Character*>& characters, Character* player, vector<Environ*>& environs,
		Position* playerSpawn, Position* playerDestination)
	: characters(characters), player(player), environs(environs), playerSpawn(playerSpawn), playerDestination(playerDestination)
{
		CreationMessage();
}

GameEnvironment::~GameEnvironment()
{
	delete player;
	delete playerSpawn;
	delete playerDestination;
	for (auto& chrcter : characters)
	{
		delete chrcter;
	}
	for (auto& env : environs)
	{
		delete env;
	}
	delete &characters;
}

void GameEnvironment::CreationMessage() const
{
	cout << "[Notification] Environment Created Successfully" << endl;
	cout << "Characters Created: " << endl;
	for (auto& character : characters)
	{
		cout << "> " << character->GetName() << endl;
		character->ShowAttributes();
	}
	cout << "Environs Created: " << endl;
	for (auto& env : environs)
	{
		cout << env->GetName() << endl;
	}

	cout << "[Confirmation] Player Spawn Point: " << playerSpawn->GetX() << ", " << playerSpawn->GetY() << endl;
	player->SetPosition(*playerSpawn);
	cout << "[Confirmation] Player is at position: " << player->GetPosition().GetX() << ", " << player->GetPosition().GetY() << endl;
}

vector<string> GameEnvironment::GetCharacterNames() const
{
	vector<string> names;
	for (auto& character : characters)
	{
		names.push_back(character->GetName());
	}
	return names;
}

vector<Character*> GameEnvironment::GetCharacters() const
{
	return characters;
}

vector<Environ*> GameEnvironment::GetEnvirons() const
{
	return environs;
}

Character* GameEnvironment::GetPlayer() const
{
	return player;
}

Position* GameEnvironment::GetPlayerSpawn() const
{
	return playerSpawn;
}

Position* GameEnvironment::GetPlayerDestination() const
{
	return playerDestination;
}


void GameEnvironment::SetCharacters(std::vector<Character*>& chrcters)
{
	// if the characters list is empty assign the characters list to the new list
	if (this->characters.empty())
	{
		characters = chrcters;
		cout << "Characters Set Successfully. New Set of Character List" << endl;
	} else
	{
		// find the characters that aren't in the characters list and add them
		for (auto& character : chrcters)
		{
			if (find(characters.begin(), characters.end(), character) == characters.end())
			{
				characters.push_back(character);

				cout << character->GetName() << " added to the characters list" << endl;
			}else
			{
				cout << character->GetName() << " already exists in the characters list" << endl;
			}
		}
	}
}

void GameEnvironment::SetPlayer(Character* player)
{
	// if the player is not in the characters list add them
	if (find(characters.begin(), characters.end(), player) == characters.end())
	{
		characters.push_back(player);
		cout << player->GetName() << " added to the characters list" << endl;
	}
	else
	{
		cout << player->GetName() << " already exists in the characters list" << endl;
	}
}

void GameEnvironment::SetEnvirons(std::vector<Environ*>& envs)
{
	// if the environs list is empty assign the environs list to the new list
	if (this->environs.empty())
	{
		this->environs = envs;
		cout << "Environs Set Successfully. New Set of Environs List" << endl;
	} else
	{
		// find the environs that aren't in the environs list and add them
		for (auto& env : envs)
		{
			if (find(this->environs.begin(), this->environs.end(), env) == this->environs.end())
			{
				this->environs.push_back(env);

				cout << env->GetName() << " added to the environs list" << endl;
			}else
			{
				cout << env->GetName() << " already exists in the environs list" << endl;
			}
		}
	}
}

void GameEnvironment::SetPlayerSpawn(Position* plyerSpawn)
{
	this->SetPlayerPosition(plyerSpawn);
	this->playerSpawn = plyerSpawn;
	cout << "Player is now at position: " << player->GetPosition().GetX() << ", " << player->GetPosition().GetY() << endl;
	cout << "Player Spawn Point Set Successfully" << endl;
}

void GameEnvironment::SetPlayerDestination(Position* plyrDestination)
{
	this->playerDestination = plyrDestination;
	cout << "Player is now at position: " << player->GetPosition().GetX() << ", " << player->GetPosition().GetY() << endl;
	cout << "Player Destination Point Set Successfully" << endl;
}

void GameEnvironment::SetPlayerPosition(Position* plyerPosition) const
{
	player->SetPosition(*plyerPosition);
}

void GameEnvironment::AddCharacter(Character* chrcter)
{
	// if the character is not in the characters list add them
	if (find(characters.begin(), characters.end(), chrcter) == characters.end())
	{
		characters.push_back(chrcter);
		cout << chrcter->GetName() << " added to the characters list" << endl;
	}
	else
	{
		cout << chrcter->GetName() << " already exists in the characters list" << endl;
	}
}

void GameEnvironment::AddEnviron(Environ* env)
{
	// if the environ is not in the environs list add them
	if (find(environs.begin(), environs.end(), env) == environs.end())
	{
		environs.push_back(env);
		cout << env->GetName() << " added to the environs list" << endl;
	}
	else
	{
		cout << env->GetName() << " already exists in the environs list" << endl;
	}
}

void GameEnvironment::DropCharacter(Character* chrcter)
{
	// if the character is in the characters list remove them
	if (find(characters.begin(), characters.end(), chrcter) != characters.end())
	{
		characters.erase(remove(characters.begin(), characters.end(), chrcter), characters.end());
		cout << chrcter->GetName() << " removed from the characters list" << endl;
	}
	else
	{
		cout << chrcter->GetName() << " does not exist in the characters list" << endl;
	}
}

void GameEnvironment::DropEnviron(Environ* env)
{
	// if the environ is in the environs list remove them
	if (find(environs.begin(), environs.end(), env) != environs.end())
	{
		environs.erase(remove(environs.begin(), environs.end(), env), environs.end());
		cout << env->GetName() << " removed from the environs list" << endl;
	}
	else
	{
		cout << env->GetName() << " does not exist in the environs list" << endl;
	}
}

void GameEnvironment::ShuffleSpawnPoint() const
{
	// generate a random number between 0 and the size of the environs list
	int random = rand() % environs.size();
	// set the player spawn to the position of the environ at the random index
	playerSpawn->SetX(environs[random]->GetPosition()->GetX());
	playerSpawn->SetY(environs[random]->GetPosition()->GetY());

	SetPlayerPosition(playerSpawn);
	cout << "Player Spawn Point Shuffled Successfully" << endl;
}

void GameEnvironment::ShuffleDestination() const
{
	// generate a random number between 0 and the size of the environs list
	int random = rand() % environs.size();
	// set the player destination to the position of the environ at the random index
	playerDestination->SetX(environs[random]->GetPosition()->GetX());
	playerDestination->SetY(environs[random]->GetPosition()->GetY());

	cout << "Player Destination Point Shuffled Successfully" << endl;
}

void GameEnvironment::ShowEnvirons() const
{
	cout << "Environs List: " << endl;
	for (auto& env : environs)
	{
		cout << env->GetName() << endl;
	}
}

void GameEnvironment::ShowCharacters() const
{
	cout << "Characters List: " << endl;
	for (auto& character : characters)
	{
		cout << character->GetName() << endl;
	}
}
