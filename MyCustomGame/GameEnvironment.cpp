#include "GameEnvironment.h"

#include <cstdlib>
#include <algorithm>

#include "Iterator1D.h"
#include "Iterator2D.h"

using namespace std;
/**
 * @file GameEnvironment.cpp
 * @author Billy Ndegwah Micah
 *
 * This is the implementation of the GameEnvironment class defined in GameEnvironment.h
 */
GameEnvironment::GameEnvironment()
{
	// Initialise the basic utils for the default constructor
	BasicUtils();

	// Print out the creation message
	CreationMessage();

	// Call the takecommands function to start the game
	TakeCommands();
}

GameEnvironment::GameEnvironment(vector<Character*>& characters, Character* player, vector<Environ*>& environs,
		Position* playerSpawn, Position* playerDestination)
	: characters(characters), player(player), environs(environs), playerSpawn(playerSpawn), playerDestination(playerDestination)
{
	// Print out the creation message
	CreationMessage();

	// Comment out the following line to view Task 3 Tests output
	TakeCommands();
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
}

void GameEnvironment::BasicUtils()
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

void GameEnvironment::ProblemSet1()
{
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
		}
		else
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
}

void GameEnvironment::ProblemSet2()
{
	// 1D array of strings
	string array[10] = {
		"Sword", "Axe", "Mace", "Dagger", "Bow",
		"Crossbow", "Spear", "Halberd", "Flail", "Morning Star"
	};

	// 1D array of strings
	string arrayTwo[10] = {
		"Wind", "Fire", "Storm", "Snow Flake", "Noose",
		"Rope", "Kerosene", "Shears", "Torch", "Grinder"
	};

	// 2D array of strings
	string** anotherArray = new string*[4];
	for(int i = 0; i < 4; i++)
	{
		anotherArray[i] = new string[4];
	}

	// 2D array of strings
	string** yetAnotherArray = new string * [4];
	for (int i = 0; i < 4; i++)
	{
		yetAnotherArray[i] = new string[4];
	}

	string items[4][4] = {
		{"Sword", "Axe", "Mace", "Dagger"},
		{"Bow", "Crossbow", "Spear", "Halberd"},
		{"Flail", "Morning Star", "Spade", "Shovel"},
		{"Crow Bar", "Wheelbarrow", "Hammer", "Knife"}
	};

	string itemsTwo[4][4] = {
		{"Wind", "Fire", "Storm", "Snow Flake"},
		{"Noose", "Rope", "Kerosene", "Shears"},
		{"Torch", "Grinder", "Petrol", "Igniter"},
		{"Screw Driver", "Spanner", "Pliers", "Wrench"}
	};

	for(int i=0; i < 4; i++)
	{
		for(int j=0; j < 4; j++)
		{
			anotherArray[i][j] = items[i][j];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			yetAnotherArray[i][j] = itemsTwo[i][j];
		}
	}

	////////////////// Task 3 ////////////////

	// Pass the 1D array to the 1D iterator
	Iterator1D toolSet1D = Iterator1D(array, 10);
	Iterator1D toolSet1D2 = Iterator1D(arrayTwo, 10);

	// Pass the 2D array to the 2D iterator
	Iterator2D toolSet2D = Iterator2D(anotherArray, 4, 4);
	Iterator2D toolSet2D2 = Iterator2D(yetAnotherArray, 4, 4);

	--toolSet1D;
	cout << "Start of 1D Array (Iteration)" << endl;
	while(!toolSet1D.AtBeginning())
	{
		cout << "Tool: " << toolSet1D--.GetCurrentItem() << endl;

	}
	cout << "End of 1D Array (Iteration)" << endl;
	cout << "-----------------" << endl;
	cout  << endl;

	cout << "Start of 2D Array (Iteration)" << endl;
	while(!toolSet2D.ReachedEnd())
	{
		cout << "Tool: " << toolSet2D.GetCurrentItem() << endl;
		++toolSet2D;
	}
	cout << "End of 2D Array (Iteration)" << endl;
	cout << "-----------------" << endl;
	cout  << endl;

	cout << "-----------------" << endl;
	cout << "--- 1D Bags (Before Swapping)---" << endl;
	string char1 = "Danger Character", char2 = "Guard Character";

	auto* character1 = new CharacterTask3(char1, 100.0f, false);
	auto* character2 = new CharacterTask3(char2, 100.0f, false);

	character1->SetBag1D(&toolSet1D);
	character2->SetBag1D(&toolSet1D2);

	character1->SetBag2D(&toolSet2D);
	character2->SetBag2D(&toolSet2D2);

	cout << character1->GetName() << " has the following tools: " << endl;
	character1->InventoryGet();
	for (int i = 0; i < 10; i++)
	{
		cout << "\t > " << character1->InventoryNext() << endl;
	}

	cout << character2->GetName() << " has the following tools: " << endl;
	character2->InventoryGet();
	for (int i = 0; i < 10; i++)
	{
		cout << "\t > " << character2->InventoryNext() << endl;
	}

	cout << "--- 1D Bags Swapped ---" << endl;
	character1->SwapBags1D(*character2);

	cout << character1->GetName() << " has the following tools: " << endl;
	character1->InventoryGet();
	for (int i = 0; i < 10; i++)
	{
		cout << "\t > " << character1->InventoryNext() << endl;
	}

	cout << character2->GetName() << " has the following tools: " << endl;
	character2->InventoryGet();
	for (int i = 0; i < 10; i++)
	{
		cout << "\t > " << character2->InventoryNext() << endl;
	}

	cout << "-----------------" << endl;
	cout  << endl;

	///////// Task 4 /////////////


	cout << "-----------------" << endl;
	cout << "--- 2D Bags (Before Swapping)---" << endl;

	cout << character1->GetName() << " has the following tools: " << endl;
	character1->InventoryGet2D();
	for (int i = 0; i < 16; i++)
	{
		cout << "\t > " << character1->InventoryNext2D() << endl;
	}

	cout << character2->GetName() << " has the following tools: " << endl;
	character2->InventoryGet2D();
	for (int i = 0; i < 16; i++)
	{
		cout << "\t > " << character2->InventoryNext2D() << endl;
	}

	cout << "--- 2D Bags Swapped ---" << endl;
	character1->SwapBags2D(*character2);

	cout << character1->GetName() << " has the following tools: " << endl;
	character1->InventoryGet2D();
	for (int i = 0; i < 16; i++)
	{
		cout << "\t > " << character1->InventoryNext2D() << endl;
	}

	cout << character2->GetName() << " has the following tools: " << endl;
	character2->InventoryGet2D();
	for (int i = 0; i < 16; i++)
	{
		cout << "\t > " << character2->InventoryNext2D() << endl;
	}

	cout << "-----------------" << endl;
	cout << endl;

}

void GameEnvironment::ProblemSet3()
{
	// character name
	string char1 = "Danger Character";

	// skill names
	string skill1 = "Sword", skill2 = "Axe", skill3 = "Mace", skill4 = "Dagger", skill5 = "Bow",
	skill6 = "Crossbow", skill7 = "Spear", skill8 = "Halberd", skill9 = "Flail", skill10 = "Morning Star";

	string statement1 = "Ad hominem: Attacking the person making the argument instead of the argument itself.",
		statement2 = "Appeal to authority : Using an authority figure's opinion as evidence in an argument.",
		statement3 = "Appeal to emotion : Manipulating emotions to win an argument.",
		statement4 = "Appeal to fear: Using fear to sway someone's opinion.",
		statement5 = "Bandwagon fallacy: Assuming something is true because many people believe it.",
		statement6 = "Cherry picking: Selectively presenting only evidence that supports your argument while ignoring other evidence.",
		statement7 = "False dilemma: Presenting only two options when there are more than two options available.",
		statement8 = "Hasty generalization: Drawing a conclusion based on insufficient evidence.",
		statement9 = "Loaded question: Asking a question that contains an assumption that is likely to be accepted by the person being questioned.",
		statement10 = "Post hoc ergo propter hoc: Assuming that because one event followed another, the first event caused the second event.",
		statement11 = "Red herring: Introducing an irrelevant topic to divert attention from the original issue.",
		statement12 = "Motte and Bailey: Start with an easily defensible position but when challenged retreat to a more controversial argument.",
		statement13 = "Slippery slope: Suggesting that one event will lead to a chain of events with increasingly negative consequences.",
		statement14 = "Straw man: Misrepresenting someone's argument in order to make it easier to attack.",
		statement15 = "Tu quoque: Dismissing someone's argument because they themselves are inconsistent in their beliefs or actions.";

	// initialise the character
	auto* character = new CharacterTask3(char1, 100.0f, false);

	// 10 skills created as SkillNode objects then added them to the
	// character as a skill advancement linked list
	auto* skillNode1 = new SkillNode(skill1, 1);
	skillNode1->AddStatement(statement1);
	skillNode1->AddStatement(statement2);

	auto* skillNode2 = new SkillNode(skill2, 2);
	skillNode2->AddStatement(statement3);

	auto* skillNode3 = new SkillNode(skill3, 3);
	skillNode3->AddStatement(statement3);

	auto* skillNode4 = new SkillNode(skill4, 4);
	skillNode4->AddStatement(statement4);

	auto* skillNode5 = new SkillNode(skill5, 5);
	skillNode5->AddStatement(statement5);

	auto* skillNode6 = new SkillNode(skill6, 6);
	skillNode6->AddStatement(statement6);
	skillNode6->AddStatement(statement7);

	auto* skillNode7 = new SkillNode(skill7, 7);
	skillNode7->AddStatement(statement8);
	skillNode7->AddStatement(statement9);

	auto* skillNode8 = new SkillNode(skill8, 8);
	skillNode8->AddStatement(statement10);
	skillNode8->AddStatement(statement11);

	auto* skillNode9 = new SkillNode(skill9, 9);
	skillNode9->AddStatement(statement12);
	skillNode9->AddStatement(statement13);

	auto* skillNode10 = new SkillNode(skill10, 10);
	skillNode10->AddStatement(statement14);
	skillNode10->AddStatement(statement15);

	// skill advancement linked list
	auto* skillAdvancement = new SkillAdvancement(skillNode1);
	skillAdvancement->AppendSkill(skillNode2);
	skillAdvancement->PrependSkill(skillNode3);
	skillAdvancement->PrependSkill(skillNode4);
	skillAdvancement->PrependSkill(skillNode5);
	skillAdvancement->AppendSkill(skillNode6);
	skillAdvancement->AppendSkill(skillNode7);
	skillAdvancement->PrependSkill(skillNode8);
	skillAdvancement->PrependSkill(skillNode9);
	skillAdvancement->AppendSkill(skillNode10);

	// add to the character
	character->SetSkillNodes(skillAdvancement);

	// skill nodes
	character->AddUserCustomSkillNode();
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
		character->Print();
	}
}

 void GameEnvironment::TakeCommands() const
 {
	 cout << endl;
	 cout << "==================================" << endl;
	 cout << "=====\t\tBEGIN HERE\t\t====" << endl;
	 cout << "==================================" << endl;

	bool playing = true;
	const string com_1 = "help", com_2 = "about", com_3 = "p_set1", com_4 = "p_set2",
	com_5 = "p_set3", com_6 = "p_set4", com_7 = "show_character_names",
	com_8 = "show_characters", com_9 = "show_environs", com_10 = "quit", com_11 = "exit", com_12 = "clear";

	while (playing)
	{
		string response;
		cout << "How would you like to proceed? Please type 'help' to see the available commands: " << endl;
		getline(cin, response);

		// Converting the response to lowercase
		response = StringToLower(response);

		if (response == com_1) {
			cout << "Available Commands are:" << endl;
			cout << "-----------------------" << endl;
			cout << "\t -------- Stuff in The Game ---------" << endl;
			cout << "\t> help: \tshows this help page" << endl;
			cout << "\t> about: \tShows a summary of structure of the game intended on Problem set 1" << endl;
			cout << "\t> p_set1: \tShow the expected output of Problem Set 1 as per requirements in the assignment" << endl;
			cout << "\t> p_set2: \tShow the expected output of Problem Set 2 as per requirements in the assignment" << endl;
			cout << "\t> p_set3: \tShow the expected output of Problem Set 3 as per requirements in the assignment" << endl;
			cout << "\t> p_set4: \tShow the expected output of Problem Set 3 as per requirements in the assignment" << endl;
			cout << "\t> show_character_names: \tShow the names of the characters created in the game" << endl;
			cout << "\t> show_characters: \tShow the full set of attributes in characters created in the game" << endl;
			cout << "\t> show_environs: \tShow the environs created in the game" << endl;
			cout << "\t --------- Utilities ------------" << endl;
			cout << "\t> clear: \tClears the screen" << endl;
			cout << "\t> quit: \tExits the game" << endl;
			cout << "\t> exit: \tExits the game" << endl;
		}
		else if (response == com_2) {
			cout << "In the scorching sun of the desert, and the sand filled wind blowing hot air" << endl;
			cout << " on the player's face. The player is mean to make it across the savanna. Mapless! However, the Camel has hints for the player, ";
			cout << "the camel also has a water reserve in case the player is dehydrated. It is possible fo the player to die form dehydration in this harsh desert.";
			cout << "The player also needs to stay away from cacti, rattle snakes, camelSpiders (yea they're a thing) and any enemies on the way. The player only has villagers as friends and the camel.";
			cout << "As you travel through this savanna conserve your energy (there's a dehydration rate that automatically gorges upon your hydration value), find the camel, get the hints to the oasis.";
			cout << "Evade enemies if you haven't yet gotten to the oasis to prevent wasting your energy. Get to the oasis and drink up, fight your foes and get a cross the Savanna. Then you're safe." << endl;
			cout << "Good Luck!! Haha!" << endl;
		}
		else if (response == com_3) {
			cout << "==================================" << endl;
			cout << "===	Problem Set 1 (START)	===" << endl;
			cout << "==================================" << endl;
			cout << endl;
			ProblemSet1();
			cout << endl;
			cout << "===	Problem Set 1 (END)		===" << endl;
		}
		else if (response == com_4) {
			cout << "=================================" << endl;
			cout << "===	Problem Set 2 (START)  ===" << endl;
			cout << "=================================" << endl;
			cout << endl;
			ProblemSet2();
			cout << endl;
			cout << "===	Problem Set 2 (END)	   ===" << endl;
		}
		else if (response == com_5) {
			cout << "=================================" << endl;
			cout << "===	Problem Set 3 (START)  ===" << endl;
			cout << "=================================" << endl;
			cout << endl;
			ProblemSet3();
			cout << endl;
			cout << "===	Problem Set 3 (END)	   ===" << endl;
		}
		else if (response == com_6) {
			cout << "=================================" << endl;
			cout << "===	Problem Set 4 (START)  ===" << endl;
			cout << "=================================" << endl;
			cout << endl;
			cout << "Coming Soon!! " << endl;
			cout << endl;
			cout << "===	Problem Set 4 (END)	   ===" << endl;
		}
		else if (response == com_7) {
			cout << "==================================" << endl;
			cout << "===	Character Names (START)	===" << endl;
			cout << "==================================" << endl;
			cout << endl;
			cout << CharacterTask3::PrintVector(GetCharacterNames()) << endl;
			cout << endl;
			cout << "===	Character Names (END)	===" << endl;
		}
		else if (response == com_8) {
			cout << "==============================" << endl;
			cout << "===	Characters (START)	===" << endl;
			cout << "==============================" << endl;
			cout << endl;
			ShowCharacters();
			cout << endl;
			cout << "===	Characters (END)	===" << endl;
		}
		else if (response == com_9) {
			cout << "=================================" << endl;
			cout << "===	Environs (START)  ===" << endl;
			cout << "=================================" << endl;
			cout << endl;
			ShowEnvirons();
			cout << endl;
			cout << "===	Environs (END)	   ===" << endl;
		}
		else if (response == com_10 || response == com_11) {
			playing = false;
		}
		else if (response == com_12) {
			// Clear the console screen on windows
			#if defined _WIN32
						system("cls");
			#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
						system("clear");
			#elif defined (__APPLE__)
						system("clear");
			#endif

		}
		else {
			cout << "Invalid Command. Please try again or type 'quit' to leave the game" << endl;
			
		}

	}

 }


 string GameEnvironment::StringToLower(string& str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}