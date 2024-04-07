#include "TraderInteractState.h"

/// <summary>
/// Upon entering a room with a trader, here it will evaluate which trader is met, meet diologue if never met, and afterwards or if met, will ask if player wishes to trade.
/// Switches state to either trade or back to map.
/// </summary>
void TraderInteractState::TraderInteract() {

    if (ctx_->GetAct() == ActState::One) {

        std::vector<std::shared_ptr<INpc>> npcs = ctx_->GetActOneNpcs();

        for (auto& npc : npcs) {

            // if current location name == the name of iterated npc's origin
            if (npc->GetLocation() == ctx_->GetCurrentLocation()->GetName() && npc->GetIsTrader()) { 

                std::shared_ptr<NpcTrader> activeTrader = std::dynamic_pointer_cast<NpcTrader>(npc); // downcasting

                if (!activeTrader->GetHasPlayerMet()) {
                    MeetTrader();
                    activeTrader->SetHasPlayerMet();
                }

                bool isPlayerTrading = traderUI_.TradeInquiry();
                if (isPlayerTrading) {

                    ctx_->SetEventState(EventState::Trade);
                    ctx_->SetState(GameState::Event);
                    return;
                }

                ctx_->SetState(GameState::RevealMap);
            }
        }
    }
}


/* Determining Act State by case isntead of inheritance method of unique TraderState for each trader bc in this case, few requirements for difference
 in functionality that are better streamlined and less complex by simply switching between. */
void TraderInteractState::MeetTrader() {

    switch (ctx_->GetAct()) {
    case ActState::One: {

        story_.AbalaskTraderIntroduction();
        break;
    }
    case ActState::Town: {

      /*  story_.MergleTraderIntro();
        story_.BueruthTraderIntro();
        story_.ArmsmanTraderIntro();
        story_.IlayaTraderIntro();*/

        break;
    }
    case ActState::Three: {

        //story_.BalaskTraderIntro();
        break;
    }
    }
}