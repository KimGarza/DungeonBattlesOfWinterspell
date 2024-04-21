#include "GameEvent.h"

void GameEvent::CheckEventState() {

	// non specific events
	switch (ctx_->GetEventState()) {
	case EventState::Trader: {

		traderState_.TraderInteract();
		return;
	}
	case EventState::Trade: {

		tradeState_.Trade();
		return;
	}
	}

	// town specific events
	if (ctx_->GetRegion() == RegionState::Winterspell) {
		switch (ctx_->GetTownEvent()) {
		case TownEvent::SorcerersGuild: {

			return;
		}
		case TownEvent::KingsThroneRoom: {

			return;
		}
		case TownEvent::Armoury: {

			return;
		}
		case TownEvent::Jeweler: {

			return;
		}
		case TownEvent::Tavern: {

			return;
		}
		case TownEvent::Apothecary: {

			return;
		}
		}
	}
	else { // dungeon specific events
		switch (ctx_->GetEventState()) {
		case EventState::Changeling: {

			changelingState_.ChangelingEncounter();
			return;
		}
		}
	}
}
