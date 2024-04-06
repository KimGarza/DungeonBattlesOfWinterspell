#pragma once
class ICreature {
private:
	int name;

public:
	int GetName() { return name; }

	virtual ~ICreature() = default;
};

