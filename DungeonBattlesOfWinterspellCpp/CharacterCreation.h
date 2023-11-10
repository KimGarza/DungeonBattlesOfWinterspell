 #pragma once

#include <iostream>
#include "PlayerCharacter.h"
#include "ICharacter.h"


class CharacterCreation
{
public:
	void ChooseClass();
	IWeapon* ChooseWeapon(ICharacter* character);
	void AllocateAttributes(ICharacter* character);
};

