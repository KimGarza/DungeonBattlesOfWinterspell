#include "BeginState.h"

void BeginState::BeginSequence() {

	RenderSFMLGraphics();

	music_.PlayMusic(L"slow-2021-08-17_-_8_Bit_Nostalgia_-_www.FesliyanStudios.com.wav");

	story.OpeningStory();

	CreateCharacter();
	GenerateDungeons();
	CreateMap();

	story.MapIntro();

	context_->SetState(GameState::RevealMap);
}

void BeginState::RenderSFMLGraphics() {

	//sf::RenderWindow window(sf::VideoMode(1200, 1000), "My Game", sf::Style::Default);
//window.setFramerateLimit(60); // Limit the framerate to 60 FPS

//sf::Texture texture;
//if (!texture.loadFromFile("../images/brickwall.png")) {
//	// Handle error here
//	// For example, you can print an error message or throw an exception
//}

//sf::Sprite sprite;
//sprite.setTexture(texture);

//// Inside the game loop
//window.clear();
//window.draw(sprite);
//window.display();

}

void BeginState::CreateCharacter() {

	CharacterCreation characterCreation;
	context_->SetPlayer(characterCreation.CreateCharacter());
}

void BeginState::GenerateDungeons() {

	DungeonGenerator dungeonGenerator;
	context_->SetDungeonRooms(dungeonGenerator.GenerateDungeons());
}

void BeginState::CreateMap() {

	context_->SetMap(std::make_shared<Map>(context_->GetDungeonRooms()));
	PopulateDungeonMap();
}

void BeginState::PopulateDungeonMap() {

	std::vector<std::string> roomNames;

	for (const auto& dungeon : context_->GetDungeonRooms()) {

		roomNames.push_back(dungeon->GetName());
	}
	context_->GetMap()->SetRoomNames(roomNames);
}