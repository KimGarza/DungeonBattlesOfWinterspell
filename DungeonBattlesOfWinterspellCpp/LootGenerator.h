#pragma once
#include "LootItem.h"
#include <random>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

class LootGenerator
{
public:
	std::vector<std::shared_ptr<LootItem>> GenerateLoot();
};

