#include "LoadActOneState.h"

void LoadActOneState::Load() {

	music_.PlayMusic(L"slow-2021-08-17_-_8_Bit_Nostalgia_-_www.FesliyanStudios.com.wav");
	story_.OpeningStory();
	CreateCharacter();

	GeneratePlaces();
	CreateMap();

	story_.MapIntro();

	ctx_->SetState(GameState::RevealMap);
}

void LoadActOneState::CreateCharacter() {

	CharacterCreation characterCreation;
	ctx_->SetPlayer(characterCreation.CreateCharacter());
}

// Generates list of dungeons to populate into the active DungeonMap
std::vector<std::shared_ptr<IPlace>> LoadActOneState::GeneratePlaces() {

	DungeonGenerator dungeonGenerator;
	return dungeonGenerator.GenerateDungeon(ctx_->GetAct());
}

void LoadActOneState::CreateMap() {

	ctx_->SetDungeonMap(std::make_shared<DungeonMap>(GeneratePlaces()));
}