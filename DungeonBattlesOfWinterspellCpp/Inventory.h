#pragma once
#include "PlayerCharacter.h"
#include "UI.h"
#include <memory>
#include <conio.h>

class Inventory
{
private:
	UI ui;

public:
	void OpenInventory(std::shared_ptr<PlayerCharacter> playerCharacter);
};

