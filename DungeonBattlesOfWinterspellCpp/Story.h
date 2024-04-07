#pragma once
#include "GameText.h"
#include "Input.h"

class Story
{
private:
    GameText gameText;
    Input input;

public:

    void OpeningStory();
    void MapIntro();
    void EnterDungeonRoom();
    std::string Changeling();
    void AbalaskTraderIntroduction();

};