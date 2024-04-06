#include "GameEvent.h"

void GameEvent::CheckEventState() {

	switch (ctx_->GetEventState()) {
	case EventState::Changeling: {

		changelingState_.ChangelingEncounter();
		return;
	}
	case EventState::Trader: {

		traderState_.TraderInteract();
		return;
	}
	case EventState::Trade: {

		tradeState_.Trade();
		return;
	}
	}
}