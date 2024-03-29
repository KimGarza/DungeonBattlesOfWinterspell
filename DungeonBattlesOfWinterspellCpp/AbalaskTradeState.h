#pragma once
#include <memory>
#include "GameContext.h"
#include "AbalaskUI.h"

class AbalaskTradeState
{
private:
	std::shared_ptr<GameContext> ctx_;
	AbalaskUI abalaskUI_;
	std::shared_ptr < PlayerCharacter> player_;
	std::shared_ptr<Abalask> abalask_;

public:
	AbalaskTradeState(std::shared_ptr<GameContext> inCtx) : ctx_(inCtx) {}

	void Trade();
	void SetValues();
	void Trading();
};

