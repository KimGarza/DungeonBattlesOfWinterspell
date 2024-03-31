#pragma once

enum class GameState {
	None,
	Begin,
	LoadAct,
	RevealMap,
	Room,
	ForgottenCatacombs,
	Battle,
	Changeling,
	Loot,
	Explore,
	UpdateMap,
	EndGame,

	MeetAbalask,
	AbalaskTrading
};