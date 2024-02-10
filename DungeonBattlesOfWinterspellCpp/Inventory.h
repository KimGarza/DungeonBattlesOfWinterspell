#pragma once
#include "PlayerCharacter.h"
#include "UI.h"

class Inventory
{
private:
	UI ui;
public:

	void OpenInventory(std::shared_ptr<PlayerCharacter> playerCharacter);

};

