#include "Story.h"
#include <conio.h>

void Story::OpeningStory() {
	//gameText.WriteLine("Hello traveler! The Town of Winterspell has been overtaken by the dark creatures of the North, Goblins, the Undying and Trolls... Among other foul creatures of the deep."); /**/ _getch();
	//gameText.WriteLine("They mean to destroy our resources, harbinge our foes and swallow our townsfolk."); /**/ _getch();
	//gameText.WriteLine("Winter is come. We yet have been able to scurge the unholy creatures....."); /**/ _getch();

	bool validResult = false;
	while (!validResult) {

		gameText.WriteLine("Will you help fight? And save the town of Winterspell?(y/n): ");

		std::string result = input.PlayerChoiceYN();

		if (result == "n") {
			system("cls");

			gameText.WriteLine("Cowardice! You truly detestable creature. Slither away you vile pestilance!");
			gameText.WriteLine("You do not desire to help this lowley town?! Pfsttt! Go squander in the cellars with the pigs and the ugly children.");
			exit(0);
		}
		else if (result == "y") {
			validResult = true;
			gameText.WriteLine("Wonderful! I shall meet you at the Iron Gates! Be weary of ice traveller."); /**/ _getch();
		}
		else {
			system("cls");
			gameText.WriteLine("I don't think I quite understood good sir, again ?");
		}
	}
	
}

void Story::MapIntro() {

	system("cls");
	//gameText.WriteLine("Behold thine map. Oh prithee forgive its woefully tattered!"); /**/ _getch();
	//gameText.WriteLine("That blotch? Surely sire that is merely the spill of mine evening brew, it marks no isle of mystery..."); /**/ _getch();
	//gameText.WriteLine("Doth sort of resemble the likeness of a skull, dost it not?"); /**/ _getch();
	//gameText.WriteLine("Pay it no mind me lord....");

	_getch();
}

void Story::EnterDungeonRoom() {
	
	system("cls");
	gameText.WriteLine("Embarking through the cavernous and decrepid dungeon, \nyou search through each room for the ugly beasts!");
	gameText.WriteLine("Entering the next room...");

	_getch();
}