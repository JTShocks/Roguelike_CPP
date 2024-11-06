#pragma once
#include "stattypes.h"
struct StatBlock {

	statType Strength; 
	statType Dexterity;
	statType Constitution;
	statType Intelligence;
	statType Wisdom;
	statType Charisma;

	StatBlock() {
		Strength = (statType)10u;
		Dexterity = (statType)10u;
		Constitution = (statType)10u;
		Intelligence = (statType)10u;
		Wisdom = (statType)10u;
		Charisma = (statType)10u;
	}
	explicit StatBlock(statType str, statType dex, statType c, statType i, statType wis, statType cha) {
		Strength = (statType)str;
		Dexterity = (statType)dex;
		Constitution = (statType)c;
		Intelligence = (statType)i;
		Wisdom = (statType)wis;
		Charisma = (statType)cha;
	};
};