#pragma once
#include <string>

class INpc
{
private:
	int name_;
	bool isTrader_;
	std::string location_;

public:
	int GetName() { return name_; }
	std::string GetLocation() { return location_; }
	bool GetIsTrader() { return isTrader_; }

	virtual ~INpc() = default;
};
