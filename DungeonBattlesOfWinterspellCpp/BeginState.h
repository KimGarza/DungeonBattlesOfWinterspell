#pragma once
#include "GameContext.h"
#include <memory>

class BeginState
{
private:
	std::shared_ptr<GameContext> ctx_;

public:
	BeginState(std::shared_ptr<GameContext> inContext) : ctx_(inContext) {}

	void Begin();
	void RenderSFMLGraphics();
};

