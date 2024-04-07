#pragma once
#include "Enemy.h"
#include "GameContext.h"
#include <memory>
#include <vector>
#include <sstream>
#include <map>
#include <random>
#include <cstdlib>
#include <ctime>

class EnemyGenerator
{
public:
	std::vector<std::shared_ptr<Enemy>> GenerateActOneEnemies(int roomLevel);
	std::vector<std::shared_ptr<Enemy>> GenerateActThreeEnemies(int roomLevel);
};

