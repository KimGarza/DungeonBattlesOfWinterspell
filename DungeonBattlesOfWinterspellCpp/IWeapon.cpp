#include "IWeapon.h"

#include <string>
#include "IWeapon.h"


// Getter methods implementation
std::string IWeapon::GetName() const {
	return name;
}

bool IWeapon::GetIsRanged() const {
	return isRanged;
}

std::string IWeapon::GetPrimarySkillName() const {
	return primarySkillName;
}

std::string IWeapon::GetSecondarySkillName() const {
	return secondarySkillName;
}

// functions virtual -  no need to implement b/c pure abstract
//void IWeapon::UseSkillPrimary() {
//	// attack roll to hit which is always the case if they don't have swiftness
//	// pass in the enemy*s armour? to be affected to evaluate the damage to them provided their armour?
//	// return damage count w/out aoe, secondary with aoe
//}
//
//void IWeapon::UseSkillSecondary() {}
IWeapon::~IWeapon() {
}