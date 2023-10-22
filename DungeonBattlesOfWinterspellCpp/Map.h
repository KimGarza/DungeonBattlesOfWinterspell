#pragma once

#include <vector>
#include <string>

class Map
{

private:
	std::vector<std::string> dungeonRooms;
	int roomsRemaining;
	std::string currentRoom;

public:

	void GenerateRooms(); // can i somehow make the constructor do this on build

	void FindRoomsRemaining();

	void GenerateMap();

};

