Dungeon Battles of Winterspell

This game is a soley text based game, where the focus can be fixed on code and not art as well at this time. It is a small old school retro style fantasy adventure game. It involvs dungeons, turn-based battles and trading.
My biggest inspiration for this game is Elder Scrolls Arena, (the very first Elder Scrolls game!).

This project is a revision of my very first coding project I started in 2021 with C#. I have converted it to C++ as this language is the language of Unreal Engine 5 which I want to work with this year on a 3D game.
(Hence the seperation between headers and source files, this is the practice in UE5.)

This game is currently running as a console app, however I have the SFML dlls and libs prepared to transition it into an SFML graphical application. Once I accomplish this I plan to convert it into an executable
and package it for Steam. This is both for the experience of the process of that, as well as for fun and to make it free to play for friends and future interested parties.

## Little tidbit on code design things
In Dungeon Battles, origonally my code was and still is quite clunky, needing much work. I have already started refactoring it to be much cleaner. This was my first personal major project and in learning C++,
I definitely am learning a lot as I go.

One thing to note is where previously there were interfaces representing enemies, character classes, weapons and concrete subclasses, I have converted all of these repeatable
actors to be factories via C++ Style Guide from Google.
I have incorperated a State Machine pattern which roots at Game.cpp. I also may need to break down the states more but at this time they are being split apart, soon to be merged into development.
I took large inspiration in promoting best game design coding patterns from Robert Nystrom. I may continue to convert other aspects of the game to different patterns but at this time, state machine and basic refactoring are in the works!
