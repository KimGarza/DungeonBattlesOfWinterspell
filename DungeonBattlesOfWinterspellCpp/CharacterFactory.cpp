#include "CharacterFactory.h"

// Supply this method with all possible characters to generate
std::vector<std::string> CharacterFactory::ListAllCharacterOptions() {

	// list of all characters and their strings will happen dynamically with only need for adding factory class and generating here,
	// then player selection process will dynamically be able to associate a map of id to name and search for name in the search method
	// which will allow character selection to be totally dynamic and so many new character choices can be added in!

	std::vector<Character> characters;
	std::vector<std::string> characterNames;

	characters.emplace_back(GenerateDwarf());
	characters.emplace_back(GenerateWoodElf());
	characters.emplace_back(GenerateEnchantress());

	//for (int i = 0; i < )

}

// Generates a new wood elf using a factory generation method
Character CharacterFactory::GenerateWoodElf() {

	// name, health, int, dex, str, armour, evasion, weapon names
	Character woodElf("Wood Elf", 400, 0, 4, 0, 0, 10,
		{ "Elven Longsword", "Ivory Longbow and Quiver", "Short Ernest Bow and Quiver" });
}


// Generates a new dwarf using a factory generation method
Character CharacterFactory::GenerateDwarf() {

	Character dwarf("Dwarf", 400, 0, 4, 0, 0, 10,
		{ "Elven Longsword", "Ivory Longbow and Quiver", "Short Ernest Bow and Quiver" });
}


// Generates a new enchantress using a factory generation method
Character CharacterFactory::GenerateEnchantress() {

	Character enchantress("Enchantress", 350, 4, 0, 0, 2, 8,
		{ "Dual Ethereal Daggers", "Gnarled Branch Staff", "Oak Carved Wand" });
}