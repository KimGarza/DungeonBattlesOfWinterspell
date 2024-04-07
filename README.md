Dungeon Battles of Winterspell

FYI It appears as though there is no organization to the files due to the fact that C++ uses filters for organization locally. These are not the same thing as folders and I didn't realize this was as much of a limitation as it is since they don't reveal in Github. I will go in and organize them in directories for the sake of easier viewing in Github.

Dungeon Battles of Winterspell is a text-based old school fantasy adventure game; turn-based dungeon crawler.
The biggest inspiration for this game is Elder Scrolls Arena, (the very first Elder Scrolls game!).

This project is a revision of my very first personal programming project I started in 2021 with C#. I have converted it to C++ as this language is primarily used in Unreal Engine 5 which I soon want to work with this year on my second 3D adventure game.
(Hence the seperation between headers and source files rather than combining them.)

This game is currently running as a console app, however I plan to convert it to a graphical application using SFML once the game itself is fleshed out. Once I accomplish this I plan to convert it into an executable
and package it for Steam. This is both for the experience of that process, as well as for fun and to make it easy to play for friends and other interested parties.

# Little tidbit on code design things
One thing to note is where previously there were interfaces representing enemies, character classes, weapons and concrete subclasses, I have converted all of these repeatable
actors to be factories via C++ Style Guide from Google.
I have incorperated a State Machine pattern which roots at Game.cpp using also a Game Loop.
A lot of the refactoring I used from what I learned from best game design coding patterns from Robert Nystrom. 

Best practices references and sources:

https://gameprogrammingpatterns.com/
https://www.linkedin.com/pulse/boosting-c-coding-efficiency-best-practices-cleaner-jha-he-him-/
https://docs.google.com/file/d/0B5FQoJdw1sdRVHRid21IalRRb3M/edit?resourcekey=0-0OIuS0JpAEz34vYFETmWUQ

