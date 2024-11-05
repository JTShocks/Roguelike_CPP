#pragma once
#include "Health.h"
class Fighter : public Health {
public:
	static const hpType CLASSHP = 10u;
	Fighter() : Health(CLASSHP, CLASSHP) {

	};

private:
};
