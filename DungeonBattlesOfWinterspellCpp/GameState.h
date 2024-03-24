#pragma once

enum class GameState {
	None,
	Begin,
	RevealMap,
	Room,
	ForgottenCatacombs,
	Battle,
	Loot,
	Explore,
	UpdateMap,
	EndGame,

	BattleChangeling,
	AbalaskTrader
};