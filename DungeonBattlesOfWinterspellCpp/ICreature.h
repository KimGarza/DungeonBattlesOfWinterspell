#pragma once
class ICreature {
private:
	int name_;

public:
	int GetName() { return name_; }

	virtual ~ICreature() = default;
};

