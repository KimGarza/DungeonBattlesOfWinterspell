//#include "UI.h"
//#include "GameText.h"
//#include <iostream>
//#include <vector>
//
//void UI::DisplayMap(std::vector<std::string> dungeonRooms) {
//	GameText gameText;
//	gameText.WriteText("Winterspell --> ");
//
//	for (Dungeon dungeon : dungeonRooms) {
//		if (dungeon->Completed == true) {
//			gameText.WriteText(dungeon->GetName() + "...	-->		");
//		}
//		if (dungeon->IsCurrent == true) {
//			gameText.WriteText(dungeon->GetName() + "...	-->		");
//		}
//		else {
//			gameText.WriteText("undiscovered...	-->		");
//		}
//	}
//}