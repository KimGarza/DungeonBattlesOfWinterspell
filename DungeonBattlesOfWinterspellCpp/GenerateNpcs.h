#pragma once
#include <string>

class GenerateNpcs
{
private:
	std::string locName_;

public:
	GenerateNpcs(std::string inLocName) : locName_(inLocName) {}

	void Generate();
};

