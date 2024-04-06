#include "..\..\..\Headers\GameStates\Loot\LootState.h"


/// <summary>
/// Using predetermined list of loot generated at game's begin for specific rooms, player can find and collect loot upon first room clear.
/// Also includes finding keys to unlock doors.
/// </summary>
void LootState::Loot() {

	music_.PlayMusic(L"slow-2021-08-17_-_8_Bit_Nostalgia_-_www.FesliyanStudios.com.wav");

	room_ = ctx_->GetCurrentRoom();

	if (room_->GetName() == "Tenebrific Depths" && room_->GetTimesExplored() == 1) {

		ui_.FoundKey(room_->GetName());

		// add key to player's inv
		ctx_->GetPlayer()->AddToInventory(std::make_shared<LootItem>("Iron Key", ItemType::Key, "For unlocking doors of course.", 1));
	}
	else if (room_->GetName() == "Abyssal Crypts" && room_->GetTimesExplored() == 1) {

		ui_.FoundKey(room_->GetName());

		// add key to player's inv
		ctx_->GetPlayer()->AddToInventory(std::make_shared<LootItem>("Jewel Encrested Key", ItemType::Key, "For unlocking doors of course. A rather unique one at that.", 1));
	}
	else if (room_->GetTimesExplored() == 0) {

		ui_.LootBegin(room_->GetLoot());

		for (const auto& item : room_->GetLoot()) {

			if (item->GetName() != "Gold Coin") {
				ctx_->GetPlayer()->AddToInventory(item);
			}
		}

		ctx_->SetState(GameState::UpdateMap);
	}
}