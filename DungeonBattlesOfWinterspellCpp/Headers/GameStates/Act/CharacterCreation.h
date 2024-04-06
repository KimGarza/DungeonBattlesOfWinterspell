 #pragma once
#include <iostream>
#include "map"
#include "..\..\Helper\UI.h"
#include "CharCreatUI.h"
#include "..\..\Actors\PlayerCharacter.h"
#include "..\..\Game\GameText.h"
#include "..\..\Actors\Character.h"
#include "..\..\Actors\Weapon.h"
#include "..\..\Helper\InputManager.h"
#include "..\..\Helper\InputManager.h"
#include "..\..\Helper\UI.h"
#include "..\..\Helper\UI.h"
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>

class CharacterCreation
{
private:
	CharCreatUI charCreatUI;
	std::shared_ptr<Character> characterInGrogpress;
	std::string specializedAttribute;
	std::shared_ptr<Weapon> weapon;
	std::map<std::string, int> attributeJournal;

public:

	std::shared_ptr<PlayerCharacter> CreateCharacter();
	void ChooseClass();
	void ChooseWeapon();

	void AllocateAttributes();
	int AllocatePoints(std::string chosenAttribute, std::map<std::string, std::string> selectableAttributes, int pointsRemaining);
	std::shared_ptr<PlayerCharacter> GeneratePlayerCharacter();
	void Deallocation();
};

