#pragma once
class ICreature {
private:
	int name;

public:
	int GetName() {
		return name;
	}

	virtual bool IsPlayableCharacter() const = 0;
	virtual ~ICreature() = default;
};

