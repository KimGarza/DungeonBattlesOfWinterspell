#include "..\..\..\Headers\GameStates\Act\LoadActTownState.h"

void LoadActTownState::Load() {

	music_.PlayMusic(L"slow-2021-08-17_-_8_Bit_Nostalgia_-_www.FesliyanStudios.com.wav"); // new song

	//story_.IntroToTown();

	GeneratePlaces();
	GenerateTrader();
	CreateMap();

	//story_.TownMapIntro();

	ctx_->SetState(GameState::RevealMap);
}

//void LoadActTownState::GeneratePlaces() {
//
//	GenerateTown generateTown;
//	ctx_->SetTownPlaces(generateTown.GenerateDungeons());
//}

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

	CreateTrader createTrader(ctx_);
	ctx_->SetTrader(createTrader.GenerateTrader());
}
