#include "Story.h"
#include <conio.h>

void Story::OpeningStory() {
	//gameText.WriteLine("Hello traveler! The Town of Winterspell has been overtaken by the dark creatures of the North, Goblins, the Undying and Trolls... Among other foul creatures of the deep."); /**/ _getch();
	//gameText.WriteLine("They mean to destroy our resources, harbinge our foes and swallow our townsfolk."); /**/ _getch();
	//gameText.WriteLine("Winter is come. We yet have been able to scurge the unholy creatures....."); /**/ _getch();

	bool validResult = false;
	while (!validResult) {


		gameText.WriteLine("\n#%*		Will you help fight? And save the town of Winterspell?(y/n):		%#*");



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

std::string Story::Changeling() {

	system("cls");
	gameText.WriteLine("Entering into the Forgotten Catacombs you feel an eerie tingle run down your spine.");
	gameText.WriteLine("The air feels colder in her dost it not me lord?"); _getch();
	gameText.WriteLine("*weeping*"); _getch();
	gameText.WriteLine("*man crying*"); _getch();
	gameText.WriteLine("....."); _getch();
	gameText.WriteLine("Those be the cries of scared man sire, it's the same cries as I've heard many solcistes whence came, farther ago moonlight didn't sail into the old prison cells of the Old NOrth of th etown"); _getch();
	gameText.WriteLine("That man sounds to be in a great lot of pain..."); _getch();
	system("cls");

	while (true) {
		gameText.WriteLine("Walk toward the crying?");

		gameText.WriteLine("y)	yes"); /**/ gameText.WriteLine("n)	no");
		std::string playerChoice; /**/ std::cin >> playerChoice;

		if (playerChoice == "y") {
			//gameText.WriteLine("The crying continues, you move toward the darker area of the room."); _getch();
			//gameText.WriteLine("It feels colder now, such as if a lover could be sculpted of ice and embraces you as if to never see you again..."); _getch();
			//gameText.WriteLine("The cry grows louder as you hug the left wall nearing the back of the dungeon room. It reeks of old and fresh death."); _getch();
			//gameText.WriteLine("You see a man crying toward the wall in tattered dresses, looking pale and quite skinny and tall. Actually, long..."); _getch();
			//gameText.WriteLine("You reach forward to touch the man's shoulder..."); _getch();
			//gameText.WriteLine("The sound of the cry turns into a whale. It an agonizing sorrowful belch of torment."); _getch();
			//gameText.WriteLine("The sound is piercing now, it sounds of black"); _getch();

			//gameText.WriteLine("The man starts to turn, but as he does he grows... longer... inhuman!"); _getch();
			//gameText.WriteLine("*foul deep raspy voice* WRETCHED MAN! YOU ARE A FOOL TO COME HERE IN THE TOMB OF THE DAMNED !");
			//gameText.WriteLine("LET ME TASTE YOUR HEART TO KNOW IF IT IS TAINTED WITH HARAZITH'S COMPLIANCE OR IF YOU ARE NOT WELCOME !!!"); _getch();
			//// more visual description

			//gameText.WriteLine("Sire! This tomb tis not forsaken, the man that's soul lyith here is that of the Old King Arifell!"); _getch();
			//gameText.WriteLine("His soul remains pure, this tomb is foul and ridden with stink of the dark fae, rid Good King Arifel of this grusom evil!"); _getch();

			return "y";

		}
		else if (playerChoice == "n") {
			/*gameText.WriteLine("The sound of the cry turns into a whale. It an agonizing sorrowful belch of torment."); _getch();
			gameText.WriteLine("The sound is piercing now, it sounds of black... but it fades as you near the right side of the room, near the torch light."); _getch();
			gameText.WriteLine("You venture forth from the mystery of it."); _getch();*/

			return "n";
		}
		else {
			gameText.WriteLine("wut UwU");
			system("cls");
		}
	}

	gameText.WriteLine("*weeping*");

	gameText.WriteLine("Entering the next room...");

	_getch();
}