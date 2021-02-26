#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>


class Enemy
{
public:
	Enemy();
	~Enemy() {}
	Enemy(std::string, float, float, float, float, float, float);
	void setDifficulty(float);
	void setName(std::string);
	std::string getName();
	void setMaxHealthPoints(float);
	float getMaxHealtPoints();
	void setHealthPoints(float);
	float getHealtPoints();
	void setStrenght(float);
	float getStrenght();
	void setDefense(float);
	float getDefense();
	void setDexterity(float);
	float getDexterity();
	void setAccuracy(float);
	float getAccuracy();
	void setAbility();
	float getAbility();
	void setAbility2();
	float getAbility2();
	void setPassive();
	float getPassive();
    void setPassiveAbilityName(std::string);

	virtual std::string getPassiveAbilityName();
private:
	std::string name;
	std::string passivename;
	float difficulty;
	float maxhp;
	float hp;
	float str;
	float def;
	float dexterity;
	float accuracy;
	float atk1;
	float atk2;
	float atk3;
};

#endif