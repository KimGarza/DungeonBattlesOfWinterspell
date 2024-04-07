#include "LoadActOneState.h"

void LoadActOneState::Load() {

	music_.PlayMusic(L"slow-2021-08-17_-_8_Bit_Nostalgia_-_www.FesliyanStudios.com.wav");

	story_.OpeningStory();

	CreateCharacter();
	GeneratePlaces();
	GenerateNPCs();
	CreateMap();

	story_.MapIntro();

	ctx_->SetState(GameState::RevealMap);
}

void LoadActOneState::CreateCharacter() {

	CharacterCreation characterCreation;
	ctx_->SetPlayer(characterCreation.CreateCharacter());
}

void LoadActOneState::GenerateNPCs() {

	CreateNpcs createNpcs(ctx_);
	ctx_->SetActOneNpcs(createNpcs.Generate());
}

void LoadActOneState::GeneratePlaces() {

	DungeonGenerator dungeonGenerator;
	ctx_->SetDungeonRooms(dungeonGenerator.GenerateActOneDungeons());
}

void LoadActOneState::CreateMap() {

	ctx_->SetMap(std::make_shared<Map>(ctx_->GetDungeonRooms()));
	PopulateMap();
}

void LoadActOneState::PopulateMap() {

	std::vector<std::string> roomNames;

	for (const auto& dungeon : ctx_->GetDungeonRooms()) {

		roomNames.push_back(dungeon->GetName());
	}
	ctx_->GetMap()->SetRoomNames(roomNames);
}