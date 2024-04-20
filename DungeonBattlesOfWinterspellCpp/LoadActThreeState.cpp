#include "LoadActThreeState.h"

void LoadActThreeState::Load() {

	music_.PlayMusic(L"slow-2021-08-17_-_8_Bit_Nostalgia_-_www.FesliyanStudios.com.wav"); // new song

	//story_.ActTwoOpening();

	GeneratePlaces();
	CreateMap();

	//story_.MapActTwoIntro();

	ctx_->SetState(GameState::RevealMap);
}
std::vector<std::shared_ptr<IPlace>> LoadActThreeState::GeneratePlaces() {

	DungeonGenerator dungeonGenerator;
	return dungeonGenerator.GenerateDungeon(ctx_->GetAct());
}

void LoadActThreeState::CreateMap() {

	ctx_->SetDungeonMap(std::make_shared<DungeonMap>(GeneratePlaces()));
}