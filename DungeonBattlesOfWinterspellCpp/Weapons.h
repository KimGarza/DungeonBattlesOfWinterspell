#include "IWeapon.h"

// Elven weapons ---------------------------------
class ElvenLongsword : public IWeapon {
public:
	ElvenLongsword();

	std::string GetName() { return name; }
	bool GetIsRanged() { return isRanged; }
	std::string GetPrimarySkillName() { return pSkillName; }
	std::string GetPrimarySkillDescription() { return pSkillDescription; }
	std::vector<int> GetPrimarySkillDamageRange() { return pSkillDamageRange; }

	std::string GetSecondarySkillName() { return sSkillName; }
	std::string GetSecondarySkillDescription() { return sSkillDescription; }
	std::vector<int> GetSecondarySkillDamageRange() { return sSkillDamageRange; }

	int UseSkillPrimary() override;
	int UseSkillSecondary() override;


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

	std::string GetName() { return name; }
	bool GetIsRanged() { return isRanged; }
	std::string GetPrimarySkillName() { return pSkillName; }
	std::string GetPrimarySkillDescription() { return pSkillDescription; }
	std::vector<int> GetPrimarySkillDamageRange() { return pSkillDamageRange; }

	std::string GetSecondarySkillName() { return sSkillName; }
	std::string GetSecondarySkillDescription() { return sSkillDescription; }
	std::vector<int> GetSecondarySkillDamageRange() { return sSkillDamageRange; }

	int UseSkillPrimary() override;
	int UseSkillSecondary() override;


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

	std::string GetName() { return name; }
	bool GetIsRanged() { return isRanged; }
	std::string GetPrimarySkillName() { return pSkillName; }
	std::string GetPrimarySkillDescription() { return pSkillDescription; }
	std::vector<int> GetPrimarySkillDamageRange() { return pSkillDamageRange; }

	std::string GetSecondarySkillName() { return sSkillName; }
	std::string GetSecondarySkillDescription() { return sSkillDescription; }
	std::vector<int> GetSecondarySkillDamageRange() { return sSkillDamageRange; }

	int UseSkillPrimary() override;
	int UseSkillSecondary() override;


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

	std::string GetName() { return name; }
	bool GetIsRanged() { return isRanged; }
	std::string GetPrimarySkillName() { return pSkillName; }
	std::string GetPrimarySkillDescription() { return pSkillDescription; }
	std::vector<int> GetPrimarySkillDamageRange() { return pSkillDamageRange; }

	std::string GetSecondarySkillName() { return sSkillName; }
	std::string GetSecondarySkillDescription() { return sSkillDescription; }
	std::vector<int> GetSecondarySkillDamageRange() { return sSkillDamageRange; }

	int UseSkillPrimary() override;
	int UseSkillSecondary() override;


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

	std::string GetName() { return name; }
	bool GetIsRanged() { return isRanged; }
	std::string GetPrimarySkillName() { return pSkillName; }
	std::string GetPrimarySkillDescription() { return pSkillDescription; }
	std::vector<int> GetPrimarySkillDamageRange() { return pSkillDamageRange; }

	std::string GetSecondarySkillName() { return sSkillName; }
	std::string GetSecondarySkillDescription() { return sSkillDescription; }
	std::vector<int> GetSecondarySkillDamageRange() { return sSkillDamageRange; }

	int UseSkillPrimary() override;
	int UseSkillSecondary() override;


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

	std::string GetName() { return name; }
	bool GetIsRanged() { return isRanged; }
	std::string GetPrimarySkillName() { return pSkillName; }
	std::string GetPrimarySkillDescription() { return pSkillDescription; }
	std::vector<int> GetPrimarySkillDamageRange() { return pSkillDamageRange; }

	std::string GetSecondarySkillName() { return sSkillName; }
	std::string GetSecondarySkillDescription() { return sSkillDescription; }
	std::vector<int> GetSecondarySkillDamageRange() { return sSkillDamageRange; }

	int UseSkillPrimary() override;
	int UseSkillSecondary() override;


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



// Enchantress weapons ---------------------------------
class DualEtherealDaggers : public IWeapon {
public:
	DualEtherealDaggers();

	std::string GetName() { return name; }
	bool GetIsRanged() { return isRanged; }
	std::string GetPrimarySkillName() { return pSkillName; }
	std::string GetPrimarySkillDescription() { return pSkillDescription; }
	std::vector<int> GetPrimarySkillDamageRange() { return pSkillDamageRange; }

	std::string GetSecondarySkillName() { return sSkillName; }
	std::string GetSecondarySkillDescription() { return sSkillDescription; }
	std::vector<int> GetSecondarySkillDamageRange() { return sSkillDamageRange; }

	int UseSkillPrimary() override;
	int UseSkillSecondary() override;


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

class GnarledBranchStaff : public IWeapon {
public:
	GnarledBranchStaff();

	std::string GetName() { return name; }
	bool GetIsRanged() { return isRanged; }
	std::string GetPrimarySkillName() { return pSkillName; }
	std::string GetPrimarySkillDescription() { return pSkillDescription; }
	std::vector<int> GetPrimarySkillDamageRange() { return pSkillDamageRange; }

	std::string GetSecondarySkillName() { return sSkillName; }
	std::string GetSecondarySkillDescription() { return sSkillDescription; }
	std::vector<int> GetSecondarySkillDamageRange() { return sSkillDamageRange; }

	int UseSkillPrimary() override;
	int UseSkillSecondary() override;


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

class OakCarvedWand : public IWeapon {
public:
	OakCarvedWand();

	std::string GetName() { return name; }
	bool GetIsRanged() { return isRanged; }
	std::string GetPrimarySkillName() { return pSkillName; }
	std::string GetPrimarySkillDescription() { return pSkillDescription; }
	std::vector<int> GetPrimarySkillDamageRange() { return pSkillDamageRange; }

	std::string GetSecondarySkillName() { return sSkillName; }
	std::string GetSecondarySkillDescription() { return sSkillDescription; }
	std::vector<int> GetSecondarySkillDamageRange() { return sSkillDamageRange; }

	int UseSkillPrimary() override;
	int UseSkillSecondary() override;


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