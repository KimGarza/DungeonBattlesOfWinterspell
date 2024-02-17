#include "Story.h"
#include <conio.h>

void Story::OpeningStory() {
	gameText.WriteLineInput("Hail traveler!");
	gameText.WriteLineInput("The Town of Winterspell has been overtaken by creatures of the dark, \nfrom the portals of the North Mountain they've squarbled hither. \nGoblins, the Undying and Trolls... Among other foul creatures of the deep.");
	gameText.WriteLineInput("They mean to destroy our resources, harbinge our foes and swallow our townsfolk.");
	gameText.WriteLineInput("Winter is come, yet we hath not prevailed in our right to scurge the unholy creatures!");
	system("cls");

	while (true) {

		std::cout << "#%*%#*%#*%#*%#*%#*%#*%#*%#*%#*%#*%#*%#*%#*%#*%#*%#*%#*%#*%#*%#*%#*%#*%#*%#*%#*%#*%#*%#%#*%#%\n";
		gameText.WriteLine("\n#%*		Will you help fight? And save the town of Winterspell? (y/n):		%#*");

		std::string result = input.PlayerChoiceYN();

		if (result == "n") {
			system("cls");

			gameText.WriteLineInput("Not but a beastly ogress in beachware I fair you, lewd cowardice! You truly detestable unworthy soul. Slither away you vile pestilance back to the magmatic forces of repentence!");
			gameText.WriteLineInput("You do not desire to help this lowley town?! Pfsttt! Go squander in the cellars with the pigs and the ugly children.");
			exit(0);
		}
		else if (result == "y") {
			system("cls");

			gameText.WriteLineInput("Wonderful! I shall meet you at the Iron Gates! They are NorthWest of the fortifying stone walls of Winterspell. \nPlease be weary of ice traveller.");
			gameText.WriteLineInput("Oh! Forgive me Master, I have failed to do the customaries! \nI am Burtued, your spellbound guide! I am a great Mage of Winterspell!");
			gameText.WriteLineInput("... Oh alright! Still learning by the dusty binds of old writings by all accounts I'm afraid.");
			gameText.WriteLineInput("I shall provoke you with my psychomancy practices that yee shall fair more boldley with company on your hallowed journey. \nBut you can trust me not to turn you into a bobbling toad! By my troth, I can hold true to that me lord!");
			gameText.WriteLineInput("Cross me heart! Hazah!");
			return;
		}
		else {
			system("cls");
			gameText.WriteLine("I don't think I quite understood good sir, again ?");
		}
	}
	
	system("cls");
	
}

void Story::MapIntro() {

	system("cls");
	gameText.WriteLineInput("Behold your map!");
	gameText.WriteLineInput("Oh prithee forgive me sire, it's old and tattered I know of it!");
	gameText.WriteLineInput("That blotch? Surely sire that is merely the spill of mine morning brew, it marks no isle of mystery...");
	gameText.WriteLineInput("Does sort of resemble the likeness of a skull, doesn't it.");
	gameText.WriteLineInput("Pay it no mind me lord....");
}

void Story::EnterDungeonRoom() {
	
	system("cls");
	gameText.WriteLineInput("Embarking through the cavernous and decrepid dungeon, \nyou search for evil in the halls and into the next room...");
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