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
/// State machine: switches between states to execute relevant state. Each state will set the currentState_ to the next relevant state.
/// </summary>
void Game::CheckGameState() {
	switch (ctx_->GetState()) {

	case GameState::Begin: {

		beginState_.BeginSequence();
		return;
	}
	case GameState::RevealMap: {

		mapRevealState_.RevealMap();
		return;
	}
	case GameState::Explore: {

		exploreState_.Explore();
		return;
	}
	case GameState::Battle: {

		battleState_.Battle();
		return;
	}
	case GameState::Changeling: {

		changelingState_.ChangelingEncounter();
		return;
	}
	case GameState::MeetAbalask: {

		abalaskCreateState_.MeetAbalask();
		return;
	}
	case GameState::AbalaskTrading: {

		abalaskTradeState_.Trade();
		return;
	}
	case GameState::Loot: {

		lootState_.Loot();
		return;
	}
	case GameState::UpdateMap: {

		mapUpdateState_.UpdateMap();
		return;
	}
	case GameState::EndGame: {

		std::cout << "Congrats on finishing the game!";
		exit(0);

		break;
	}
	default:

		ctx_->SetState(GameState::None);
		return;
	}
}