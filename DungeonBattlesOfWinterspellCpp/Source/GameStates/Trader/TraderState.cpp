#include "..\..\..\Headers\GameStates\Trader\TraderState.h"


/// <summary>
/// The initial interaction with the trader when ran into. Meet the trader with story intro first or if met, ask player if they want to trade; change state.
/// </summary>
void TraderState::TraderInteract() {

    if (!ctx_->GetTrader()->GetHasPlayerMet()) {

        MeetTrader();
        ctx_->GetTrader()->SetHasPlayerMet();
    }


    bool isPlayerTrading = traderUI_.TradeInquiry();
    if (isPlayerTrading) {
        
        ctx_->SetEventState(EventState::Trade);
        ctx_->SetState(GameState::Event);
        return;
    }

    ctx_->SetState(GameState::RevealMap);
}


/* Determining Act State by case isntead of inheritance method of unique TraderState for each trader bc in this case, few requirements for difference
 in functionality that are better streamlined and less complex by simply switching between. */
void TraderState::MeetTrader() {

    switch (ctx_->GetAct()) {
    case ActState::One: {

        story_.AbalaskTraderIntroduction();
        break;
    }
    case ActState::Town: {

        story_.AbalaskTraderIntroduction();

        break;
    }
    case ActState::Three: {

        story_.AbalaskTraderIntroduction();
        break;
    }
    }
}