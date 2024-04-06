#include "LoadActThreeState.h"

void LoadActThreeState::Load() {

	music_.PlayMusic(L"slow-2021-08-17_-_8_Bit_Nostalgia_-_www.FesliyanStudios.com.wav"); // new song

	//story_.ActTwoOpening();

	GeneratePlaces();
	GenerateTrader();
	CreateMap();

	//story_.MapActTwoIntro();

	ctx_->SetState(GameState::RevealMap);
}

void LoadActThreeState::GeneratePlaces() {

	DungeonGenerator dungeonGenerator;
	ctx_->SetDungeonRooms(dungeonGenerator.GenerateDungeons());
}

void LoadActThreeState::CreateMap() {

	ctx_->SetMap(std::make_shared<Map>(ctx_->GetDungeonRooms()));
	PopulateMap();
}

void LoadActThreeState::PopulateMap() {

	std::vector<std::string> roomNames;

	for (const auto& dungeon : ctx_->GetDungeonRooms()) {

		roomNames.push_back(dungeon->GetName());
	}
	ctx_->GetMap()->SetRoomNames(roomNames);
}

void LoadActThreeState::GenerateTrader() {

	CreateTrader createTrader(ctx_);
	ctx_->SetTrader(createTrader.GenerateTrader());
}