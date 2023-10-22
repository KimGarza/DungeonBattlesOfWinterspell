#include "IWeapon.h"

// Elven weapons ---------------------------------
class ElvenLongsword : public IWeapon {
public:
	ElvenLongsword();

	std::string GetName() override { return name; }
	bool GetIsRanged() override { return isRanged; }
	std::string GetPrimarySkillName() override { return pSkillName; }
	std::string GetPrimarySkillDescription() override { return pSkillDescription; }
	std::vector<int> GetPrimarySkillDamageRange() override { return pSkillDamageRange; }

	std::string GetSecondarySkillName() override { return sSkillName; }
	std::string GetSecondarySkillDescription() override { return sSkillDescription; }
	std::vector<int> GetSecondarySkillDamageRange() override { return sSkillDamageRange; }

	virtual void UseSkillPrimary() override {};
	virtual void UseSkillSecondary() override {};


private:
	std::string name;
	int isRanged;
	std::string pSkillName;
	std::string pSkillDescription;
	std::vector<int> pSkillDamageRange;

	std::string sSkillName;
	std::string sSkillDescription;
	std::vector<int> sSkillDamageRange;
};

// ----------------------------------------------------------
class IvoryLongBowAndQuiver : public IWeapon {
public:
	IvoryLongBowAndQuiver();

	std::string GetName() override { return name; }
	bool GetIsRanged() override { return isRanged; }
	std::string GetPrimarySkillName() override { return pSkillName; }
	std::string GetPrimarySkillDescription() override { return pSkillDescription; }
	std::vector<int> GetPrimarySkillDamageRange() override { return pSkillDamageRange; }

	std::string GetSecondarySkillName() override { return sSkillName; }
	std::string GetSecondarySkillDescription() override { return sSkillDescription; }
	std::vector<int> GetSecondarySkillDamageRange() override { return sSkillDamageRange; }

	virtual void UseSkillPrimary() override {};
	virtual void UseSkillSecondary() override {};


private:
	std::string name;
	int isRanged;
	std::string pSkillName;
	std::string pSkillDescription;
	std::vector<int> pSkillDamageRange;

	std::string sSkillName;
	std::string sSkillDescription;
	std::vector<int> sSkillDamageRange;
};

// ----------------------------------------------------------
class ShortErnestBowAndQuiver : public IWeapon {
public:
	ShortErnestBowAndQuiver();

	std::string GetName() override { return name; }
	bool GetIsRanged() override { return isRanged; }
	std::string GetPrimarySkillName() override { return pSkillName; }
	std::string GetPrimarySkillDescription() override { return pSkillDescription; }
	std::vector<int> GetPrimarySkillDamageRange() override { return pSkillDamageRange; }

	std::string GetSecondarySkillName() override { return sSkillName; }
	std::string GetSecondarySkillDescription() override { return sSkillDescription; }
	std::vector<int> GetSecondarySkillDamageRange() override { return sSkillDamageRange; }

	virtual void UseSkillPrimary() override {};
	virtual void UseSkillSecondary() override {};


private:
	std::string name;
	int isRanged;
	std::string pSkillName;
	std::string pSkillDescription;
	std::vector<int> pSkillDamageRange;

	std::string sSkillName;
	std::string sSkillDescription;
	std::vector<int> sSkillDamageRange;
};


// Dwarven weapons ---------------------------------
class DoubleBladedAxe : public IWeapon {
public:
	DoubleBladedAxe();

	std::string GetName() override { return name; }
	bool GetIsRanged() override { return isRanged; }
	std::string GetPrimarySkillName() override { return pSkillName; }
	std::string GetPrimarySkillDescription() override { return pSkillDescription; }
	std::vector<int> GetPrimarySkillDamageRange() override { return pSkillDamageRange; }

	std::string GetSecondarySkillName() override { return sSkillName; }
	std::string GetSecondarySkillDescription() override { return sSkillDescription; }
	std::vector<int> GetSecondarySkillDamageRange() override { return sSkillDamageRange; }

	virtual void UseSkillPrimary() override {};
	virtual void UseSkillSecondary() override {};


private:
	std::string name;
	int isRanged;
	std::string pSkillName;
	std::string pSkillDescription;
	std::vector<int> pSkillDamageRange;

	std::string sSkillName;
	std::string sSkillDescription;
	std::vector<int> sSkillDamageRange;
};

// ----------------------------------------------------------
class OrnateShortSword : public IWeapon {
public:
	OrnateShortSword();

	std::string GetName() override { return name; }
	bool GetIsRanged() override { return isRanged; }
	std::string GetPrimarySkillName() override { return pSkillName; }
	std::string GetPrimarySkillDescription() override { return pSkillDescription; }
	std::vector<int> GetPrimarySkillDamageRange() override { return pSkillDamageRange; }

	std::string GetSecondarySkillName() override { return sSkillName; }
	std::string GetSecondarySkillDescription() override { return sSkillDescription; }
	std::vector<int> GetSecondarySkillDamageRange() override { return sSkillDamageRange; }

	virtual void UseSkillPrimary() override {};
	virtual void UseSkillSecondary() override {};


private:
	std::string name;
	int isRanged;
	std::string pSkillName;
	std::string pSkillDescription;
	std::vector<int> pSkillDamageRange;

	std::string sSkillName;
	std::string sSkillDescription;
	std::vector<int> sSkillDamageRange;
};

// ----------------------------------------------------------
class SteelSplitHammer : public IWeapon {
public:
	SteelSplitHammer();

	std::string GetName() override { return name; }
	bool GetIsRanged() override { return isRanged; }
	std::string GetPrimarySkillName() override { return pSkillName; }
	std::string GetPrimarySkillDescription() override { return pSkillDescription; }
	std::vector<int> GetPrimarySkillDamageRange() override { return pSkillDamageRange; }

	std::string GetSecondarySkillName() override { return sSkillName; }
	std::string GetSecondarySkillDescription() override { return sSkillDescription; }
	std::vector<int> GetSecondarySkillDamageRange() override { return sSkillDamageRange; }

	virtual void UseSkillPrimary() override {};
	virtual void UseSkillSecondary() override {};


private:
	std::string name;
	int isRanged;
	std::string pSkillName;
	std::string pSkillDescription;
	std::vector<int> pSkillDamageRange;

	std::string sSkillName;
	std::string sSkillDescription;
	std::vector<int> sSkillDamageRange;
};



// Enchatress weapons ---------------------------------
class DualEtherealDaggers : public IWeapon {
public:
	DualEtherealDaggers();

	std::string GetName() override { return name; }
	bool GetIsRanged() override { return isRanged; }
	std::string GetPrimarySkillName() override { return pSkillName; }
	std::string GetPrimarySkillDescription() override { return pSkillDescription; }
	std::vector<int> GetPrimarySkillDamageRange() override { return pSkillDamageRange; }

	std::string GetSecondarySkillName() override { return sSkillName; }
	std::string GetSecondarySkillDescription() override { return sSkillDescription; }
	std::vector<int> GetSecondarySkillDamageRange() override { return sSkillDamageRange; }

	virtual void UseSkillPrimary() override {};
	virtual void UseSkillSecondary() override {};


private:
	std::string name;
	int isRanged;
	std::string pSkillName;
	std::string pSkillDescription;
	std::vector<int> pSkillDamageRange;

	std::string sSkillName;
	std::string sSkillDescription;
	std::vector<int> sSkillDamageRange;
};

// ----------------------------------------------------------
class GnarledBranchStaff : public IWeapon {
public:
	GnarledBranchStaff();

	std::string GetName() override { return name; }
	bool GetIsRanged() override { return isRanged; }
	std::string GetPrimarySkillName() override { return pSkillName; }
	std::string GetPrimarySkillDescription() override { return pSkillDescription; }
	std::vector<int> GetPrimarySkillDamageRange() override { return pSkillDamageRange; }

	std::string GetSecondarySkillName() override { return sSkillName; }
	std::string GetSecondarySkillDescription() override { return sSkillDescription; }
	std::vector<int> GetSecondarySkillDamageRange() override { return sSkillDamageRange; }

	virtual void UseSkillPrimary() override {};
	virtual void UseSkillSecondary() override {};


private:
	std::string name;
	int isRanged;
	std::string pSkillName;
	std::string pSkillDescription;
	std::vector<int> pSkillDamageRange;

	std::string sSkillName;
	std::string sSkillDescription;
	std::vector<int> sSkillDamageRange;
};

// ----------------------------------------------------------
class OakCarvedWand : public IWeapon {
public:
	OakCarvedWand();

	std::string GetName() override { return name; }
	bool GetIsRanged() override { return isRanged; }
	std::string GetPrimarySkillName() override { return pSkillName; }
	std::string GetPrimarySkillDescription() override { return pSkillDescription; }
	std::vector<int> GetPrimarySkillDamageRange() override { return pSkillDamageRange; }

	std::string GetSecondarySkillName() override { return sSkillName; }
	std::string GetSecondarySkillDescription() override { return sSkillDescription; }
	std::vector<int> GetSecondarySkillDamageRange() override { return sSkillDamageRange; }

	virtual void UseSkillPrimary() override {};
	virtual void UseSkillSecondary() override {};


private:
	std::string name;
	int isRanged;
	std::string pSkillName;
	std::string pSkillDescription;
	std::vector<int> pSkillDamageRange;

	std::string sSkillName;
	std::string sSkillDescription;
	std::vector<int> sSkillDamageRange;
};