#pragma once
#include "HitPointTypes.h"
class Health
{
public:
	/*Returns true if set successfully*/
	bool setMaxHP(hpType new_max_hp)
	{
		if (new_max_hp < 1)
			return false;

		MaxHP = new_max_hp;

		if (CurrentHP > MaxHP)
			CurrentHP = MaxHP;

		return true;
		
	}
	hpType getMaxHP() {
		return MaxHP;
	}
	hpType getCurrentHP() {
		return CurrentHP;
	}

	void takeDamage(hpType damage) {

		hpType remainingDamage;
		if (damage > TempHP)
		{
			remainingDamage = damage - TempHP;
			//First remove the TempHP before taking away CurrentHP
			TempHP = 0;
			if (remainingDamage > CurrentHP)
			{
				CurrentHP = 0;
				return;
			}
			else
			{
				CurrentHP -= remainingDamage;
			}
		}
		else
		{
			TempHP -= damage;
		}
	}

	void heal(hpType amount)
	{
		if (amount + CurrentHP > MaxHP)
		{
			CurrentHP = MaxHP;
			return;
		}
		CurrentHP += amount;
	}

	Health() { CurrentHP = 1; MaxHP = 1, TempHP = 0; }
	Health(hpType cHP, hpType mHP)
	{
		CurrentHP = cHP;
		MaxHP = mHP;
		if (CurrentHP > MaxHP)
		{
			CurrentHP = MaxHP;
		}
	}



private:
	hpType TempHP;
	hpType CurrentHP;
	hpType MaxHP;
};

