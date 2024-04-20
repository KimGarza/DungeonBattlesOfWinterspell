#include "ExploreTownState.h"

void ExploreTownState::Explore() {

	SetValues();
	EvaluateSpecial();
	EnterPlace();

	ctx_->SetState(GameState::RevealMap);
}

void ExploreTownState::EvaluateSpecial() {

}

void ExploreTownState::EnterPlace() {

}

void ExploreTownState::SetValues() {

}