#include "LoadActTownState.h"

void LoadActTownState::Load() {

	//music_.PlayMusic(L"slow-2021-08-17_-_8_Bit_Nostalgia_-_www.FesliyanStudios.com.wav"); // new song

	story_.IntroToTown();

	GeneratePlaces();
	CreateMap();

	story_.TownMapIntro();

	ctx_->GetDungeonMap().reset();
	ctx_->SetRegion(RegionState::Winterspell);
	ctx_->SetState(GameState::RevealMap);
}

std::vector<std::shared_ptr<IPlace>> LoadActTownState::GeneratePlaces() {

	TownGenerator townGenerator;
	return townGenerator.GenerateTown();
}

void LoadActTownState::CreateMap() {

	ctx_->SetTownMap(std::make_shared<TownMap>(GeneratePlaces()));
}