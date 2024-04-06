#include "..\..\Headers\Game\Story.h"

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

			gameText.WriteLineInput("Not but a beastly ogress in beachware I fair you, lewd cowardice! You truly detestable unworthy soul.\nSlither away you vile pestilance back to the magmatic forces of repentence!");
			gameText.WriteLineInput("You do not desire to help this lowley town?! Pfsttt!\nGo squander in the cellars with the pigs and the ugly children.");
			exit(0);
		}
		else if (result == "y") {
			system("cls");

			gameText.WriteLineInput("Wonderful! I shall meet you at the Iron Gates! They are NorthWest of the fortifying stone walls of Winterspell. \nPlease be weary of ice traveller.");
			gameText.WriteLineInput("Oh! Forgive me Master, I have failed to do the customaries! \nI am Burtued, your spellbound guide! I am a great Mage of Winterspell!");
			gameText.WriteLineInput("... Oh alright! Still learning by the dusty binds of old writings by all accounts I'm afraid.");
			gameText.WriteLineInput("I shall provoke you with my psychomancy practices that yee shall fair more boldley with company \non your hallowed journey. \nBut you can trust me not to turn you into a bobbling toad! By my troth, I can hold true to that me lord!");
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
	gameText.WriteLineInput("Oh forgive me sire, it's old and tattered I know of it!");
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
	gameText.WriteLineInput("Entering into the Forgotten Catacombs you feel an eerie tingle run down your spine.");
	gameText.WriteLineInput("The air feels of the winter chill Master.");
	gameText.WriteLineInput("*weeping*");
	gameText.WriteLineInput("*man crying*");
	gameText.WriteLineInput(".....");
	gameText.WriteLineInput("Cries of fear sire. Spark my mind of whence we kept prisoners in the old cells in the middle of the city, neith the cobble streets.");
	gameText.WriteLineInput("Twas in the cold of the nights, the same cries of suffering....");
	system("cls");

	while (true) {
		gameText.WriteLine("Walk toward the crying?");

		gameText.WriteLine("y)	yes"); /**/ gameText.WriteLine("n)	no");
		std::string playerChoice; /**/ std::cin >> playerChoice;

		if (playerChoice == "y") {
			system("cls");
			gameText.WriteLineInput("The crying continues.");
			gameText.WriteLineInput("You scrape your toes upon the ground, each step with hesitation as moonlight, \nnor torchlight bends the the whimb of the blackness here in the dark of the room.");
			gameText.WriteLineInput("It feels much colder now, such as if a lover was sculpted of ice and would embrace \nyou with their longing for your warm touch of life");
			gameText.WriteLineInput("The cry grows stronger, even the cold on your skin comforts you more than the sound of such sadness.");
			gameText.WriteLineInput("You hug the left wall nearing the back of the dungeonous room. It reeks of old bones and of fresh blood.");
			gameText.WriteLineInput("You see a old withering man crying, faced toward the wall.");
			gameText.WriteLineInput("In tattered dresses, looking pale and quite skinny and tall.");
			gameText.WriteLineInput("Actually...");
			gameText.WriteLineInput("Long.");
			gameText.WriteLineInput("He's not tall... he is long.");
			gameText.WriteLineInput("You reach forward to touch the man's shoulder...");
			gameText.WriteLineInput("The sound of the cry turns into a whale. Tis an agonizing sorrowful belch of torment.");
			gameText.WriteLineInput("The sound is piercing now, not of a pitch of describing sound, rather pitch of black...");

			gameText.WriteLineInput("The man starts to turn, but as he does he grows... longer.");
			gameText.WriteLineInput("*foul deep raspy voice* WRETCHED MAN! YOU ARE A FOOL TO COME HERE IN THE TOMB OF THE DAMNED !");
			gameText.WriteLineInput("Echoing on every surface, the sound reverberates almost echoing off of it's own echo.");
			gameText.WriteLineInput("LET ME TASTE YOUR HEART TO KNOW IF IT IS TAINTED WITH HARAZITH'S COMPLIANCE OR IF YOU'RE DEATH HATH BEEN SEELED!!!");
			// more visual description

			gameText.WriteLineInput("Sire! This tomb is not forsaken!");
			gameText.WriteLineInput("The man that's soul lyith here is that of the Old King Arifell! \nA good mark of Winterspell's historic rule!");
			gameText.WriteLineInput("His soul remains pure, yet this tomb is foul and ridden with stink of the dark fae, rid Good King Arifel of this grusom pestilence!");
			system("cls");


			return "y";
		}
		else if (playerChoice == "n") {
			system("cls");

			gameText.WriteLineInput("The sound of the cry turns into a whale, yet dampens in sound as you scuffle along the rightmost wall.");
			gameText.WriteLineInput("The sound is piercing now, it sounds of black... but it fades as you near the right side of the room, near the torch light.");
			gameText.WriteLineInput("You venture forth from the mystery of it.");
			gameText.WriteLineInput("Master, I would be thy scout, tredging ahead to unveil the mysteries of the sadness that plagues this room... for it not be that I am in the library near in the breadth of the town.");
			gameText.WriteLineInput("But I totally would if I weren't... definitely, yea...");
			system("cls");

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

void Story::AbalaskTraderIntroduction() {
	system("cls");

	gameText.WriteLineInput("Empty and quiet fills the room, but a slight sound of nervous breathing catches your ear.");
	gameText.WriteLineInput("Good Knight! Sire look! Behold a gigantis bat!");

	gameText.WriteLine("Ar-aRE th-THeY GoN-nE?");
	gameText.WriteLine("PrAy teLL! Ar-aRE th-THeY!?\n");

	while (true) {
		gameText.WriteLine("y)  Nod\nn)  Shake your head");

		std::string playerChoice; /**/ std::cin >> playerChoice;

		if (playerChoice == "y" || playerChoice == "n") {

			if (playerChoice == "n") {
				system("cls");
				gameText.WriteLineInput("The gigantis bat scuffles and flutters awkwardly in a panic to the extrodinarily large \nstilagmite hanging further up and back in the cavern.");
				gameText.WriteLineInput("You hear the sound of loose coin and metal items trinkling out of his furry pockets.");
				gameText.WriteLineInput("Pray! Donot touchith my properties!");
			}

			system("cls");
			gameText.WriteLineInput("A round whisp of air encompases the cavern, so quickly whence it came, it hath past just the same.");
			gameText.WriteLineInput("The gigantis bat carefully stumbles and glides down before you.");
			gameText.WriteLineInput("A great dark gray beast of soft smooth and furry skin, yet strong and truly gigiantis stands over you, \nrendering you nothing but shadow in his own.");
			gameText.WriteLineInput("I sense the monstrosities of the deep lye still. You have saved my home, thank you small squashable human!");
			gameText.WriteLineInput("Perhaps you would fancy to engage in a barter of sorts with the like of me. \n....Though I do not typically associate with plebeans of the surface world!");
			return;
		}
		else {
			gameText.WriteLineInput("YoUr sPeAk sOunDs Of tHe JiBBerWahkIe!");
			system("cls");
		}
	}
}