#pragma once

enum class GameState {
	None,
	Begin,
	LoadAct,
	Event,
	RevealMap,
	Room,
	Battle,
	Loot,
	Explore,
	UpdateMap,
	EndGame,
};