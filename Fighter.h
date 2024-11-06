#pragma once
#include "Health.h"
#include "statblock.h"
class Fighter : public Health , public StatBlock{
public:
	static const hpType CLASSHP = (hpType)10u;
	static const statType CLASSBOOST = (statType)2u;
	Fighter() : Health(CLASSHP, CLASSHP), StatBlock() {

	};

private:
};
