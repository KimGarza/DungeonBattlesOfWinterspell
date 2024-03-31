#include "Game.h"

/// <summary>
/// Game loop that continuously checks each game state until end of game. This is what keeps the game persisting.
/// First ran in main.cpp, constructor decides Begin is initial state
/// </summary>
void Game::StateCycle() {

	while (ctx_->GetState() != GameState::EndGame) {

		CheckGameState();
	} 

	CheckGameState(); // requires one more check game state for the end game but will close afterwards
	return;
}

/// <summary>
/// State machine: switches between states to execute relevant state. Each state will set the current state to the next relevant state.
/// </summary>
void Game::CheckGameState() {
	switch (ctx_->GetState()) {

	case GameState::Begin: {

		beginState_.Begin();
		return;
	}
	case GameState::LoadAct: {

		switch (ctx_->GetAct()) {
		case ActState::One: {
			loadActOneState_.Load();
			return;
		}
		case ActState::Two: {
			loadActTwoState_.Load();
			return;
		}
		case ActState::Three: {
			loadActThreeState_.Load();
			return;
		}
		}
		return;
	}
	case GameState::RevealMap: { // yes

		mapRevealState_.RevealMap();
		return;
	}
	case GameState::Explore: { // yes

		exploreState_.Explore();
		return;
	}
	case GameState::Battle: { // yes

		battleState_.Battle();
		return;
	}
	case GameState::Changeling: { // maybe seperate out events specific to acts by sending them to a sepcial 
		// class called ActGameState which is this exact class but with act specific events. In order to determine which, it sends 
		// it to the EventGameState and it either has them all together or by act. I like the all together idea since they are all special events.
		// Otherwise there would first have to be a act deciding game state where upon entering even t state here switch between acts
		// depending on which act send it to that act gamestate cycler

		changelingState_.ChangelingEncounter();
		return;
	}
	case GameState::MeetAbalask: { // Convert to trader and switch between which act within trader for different trader meets

		abalaskCreateState_.MeetAbalask();
		return;
	}
	case GameState::AbalaskTrading: { // same as above

		abalaskTradeState_.Trade();
		return;
	}
	case GameState::Loot: { // match

		lootState_.Loot();
		return;
	}
	case GameState::UpdateMap: { // mathc

		mapUpdateState_.UpdateMap();
		return;
	}
	case GameState::EndGame: { // End act instead of end state and only act 3 state specific has end game

		std::cout << "Congrats on finishing the game!";
		exit(0);

		break;
	}
	}
}