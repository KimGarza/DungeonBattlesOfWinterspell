#include "LoadActTownState.h"

void LoadActTownState::Load() {

	music_.PlayMusic(L"slow-2021-08-17_-_8_Bit_Nostalgia_-_www.FesliyanStudios.com.wav"); // new song

	story_.OpeningStory();

	GeneratePlaces();
	CreateMap();

	story_.MapIntro();

	ctx_->SetState(GameState::RevealMap);
}

void LoadActTownState::GeneratePlaces() {

	DungeonGenerator dungeonGenerator;
	ctx_->SetDungeonRooms(dungeonGenerator.GenerateDungeons());
}

void LoadActTownState::CreateMap() {

	ctx_->SetMap(std::make_shared<Map>(ctx_->GetDungeonRooms()));
	PopulateMap();
}

void LoadActTownState::PopulateMap() {

	std::vector<std::string> roomNames;

	for (const auto& dungeon : ctx_->GetDungeonRooms()) {

		roomNames.push_back(dungeon->GetName());
	}
	ctx_->GetMap()->SetRoomNames(roomNames);
}

void LoadActTownState::GenerateTrader() {

	CreateTrader createTrader;
	ctx_->SetTrader(createTrader.GenerateTrader());
}
