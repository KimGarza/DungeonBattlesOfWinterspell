#pragma once

enum class GameState {
	None,
	Begin,
	Map,
	Room,
	Battle,
	Loot,
	Explore,
	UpdateMap,
	EndGame
};