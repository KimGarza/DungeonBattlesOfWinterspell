#pragma once
#include <vector>
#include <memory>
#include "Abalask.h"
#include "AbalaskUI.h"

class AbalaskTrader
{
private:
    AbalaskUI abalaskUI;
    std::shared_ptr<Abalask> abalask;

public:
    std::shared_ptr<Abalask> GenerateAbalask();
    std::vector<std::shared_ptr<LootItem>> GenerateWares();
    void BeginTrading(std::shared_ptr<PlayerCharacter> player);
};

