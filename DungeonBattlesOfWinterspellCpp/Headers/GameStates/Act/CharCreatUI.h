#pragma once
#include "..\..\Actors\Character.h"
#include "..\..\Game\GameText.h"
#include "..\..\Helper\Input.h"
#include <memory>
#include <map>
#include <iostream>

class CharCreatUI
{
private:
	GameText gameText;
	Input input;

public:
	std::string ChooseClass();

	void DisplayWeaponOptions(std::shared_ptr<Character> characterClass);
	void CharacterSelected(std::shared_ptr<Character> characterClass);

	std::string ChooseWeapon(std::shared_ptr<Character> characterClass);
	void WeaponSelected(std::string weaponName);

	std::string AttributeAssignment(int pointsRemaining, std::map<std::string, int> attributeJournal);
	int PointsAllocation(std::string chosenAttribute, std::map<std::string, std::string> selectableAttributes, int pointsRemaining, std::string specializedAttribute, std::map<std::string, int> attributeJournal);
};

