#include <vector>
#include <string>
#include <iostream>
#include "DungeonGenerator.h"
#include "DungeonRoom.h"
#include <iostream>
#include <random>
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "Enemies.h"


std::vector<DungeonRoom> DungeonGenerator::GenerateDungeons() {

	std::vector<DungeonRoom> dungeonRooms;

	for (std::string dungeon : dungeonList) { 
		// generate random num method

        std::random_device rand;
        std::mt19937 gen(rand());

        int min_value = 2; // Minimum value (inclusive)
        int max_value = 4; // Maximum value (inclusive)

        // distribution for the range
        std::uniform_int_distribution<int> distribution(min_value, max_value);
        int random_number = distribution(gen);

        std::cout << "Random number " << random_number << std::endl;
        for (int i = 0; i < random_number; i++) {
            std::srand(static_cast<unsigned int>(std::time(nullptr)));

            // Create a collection of enemy objects
            std::vector<std::shared_ptr<IEnemy>> enemies;
            enemies.push_back(std::make_shared<Firespitter>());
            enemies.push_back(std::make_shared<DungeonDweller>());
            enemies.push_back(std::make_shared<Goblin>());
            enemies.push_back(std::make_shared<HauntingSpirit>());
            enemies.push_back(std::make_shared<Troll>());
            enemies.push_back(std::make_shared<Skeleton>());
            enemies.push_back(std::make_shared<UndeadWolf>());

            // Generate a random index
            int randomIndex = std::rand() % enemies.size();

            // Retrieve and use the random enemy
            std::shared_ptr<IEnemy> randomEnemy = enemies[randomIndex];

            std::vector<std::shared_ptr<IEnemy>> enemiesInRoom;
            enemiesInRoom.push_back(randomEnemy);

            std::cout << "Enemy" << randomEnemy->GetName() << std::endl;
        }
		/*DungeonRoom newDungeonRoom = new DungeonRoom(
		dungeon, );*/

        return dungeonRooms;
	}
}

