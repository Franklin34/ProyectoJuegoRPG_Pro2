#include "Enemy.h"

Enemy::Enemy()
{
	name = "eye5";
	maxhp = 0.0f;
	hp = 0.0f;
	str = 0.0f;
	def = 0.0f;
	dexterity = 0.0f;
	accuracy = 0.0f;
	atk1 = 0.0f;
	atk2 = 0.0f;
	atk3 = 0.0f;
}

Enemy::Enemy(std::string name,float maxhp, float hp, float str, float def, float dex, float acc)
{
	this->maxhp = maxhp;
	this->name = name;
	this->hp = hp;
	this->str = str;
	this->def = def;
	this->dexterity = dex;
	this->accuracy = acc;
}

void Enemy::setDifficulty(float dif)
{
	//futuro dlc
	difficulty = dif * 0.17f;
	maxhp = maxhp*difficulty;
	hp = hp * difficulty;
	str = str * difficulty;
	def = def * difficulty;
	dexterity = dexterity * difficulty;
	accuracy = accuracy * difficulty;
}

void Enemy::setName(std::string name)
{
	this->name = name;
}

std::string Enemy::getName()
{
	return name;
}

void Enemy::setMaxHealthPoints(float maxhp)
{
	this->maxhp = maxhp;
}

float Enemy::getMaxHealtPoints()
{
	return maxhp;
}

void Enemy::setHealthPoints(float hp)
{
	this->hp = hp;
}

float Enemy::getHealtPoints()
{
	return hp;
}

void Enemy::setStrenght(float str)
{
	this->str = str;
}

float Enemy::getStrenght()
{
	return str;
}

void Enemy::setDefense(float def)
{
	this->def = def;
}

float Enemy::getDefense()
{
	return def;
}

void Enemy::setDexterity(float dex)
{
	dexterity = dex;
}

float Enemy::getDexterity()
{
	return dexterity;
}

void Enemy::setAccuracy(float acc)
{
	accuracy = acc;
}

float Enemy::getAccuracy()
{
	return accuracy;
}

void Enemy::setAbility()
{
	atk1 = getStrenght() * 0.5f + getDexterity() * 0.5f;
}

float Enemy::getAbility()
{
	return atk1;
}

void Enemy::setAbility2()
{
	atk2 = getStrenght() * 0.7f + getDexterity() * 0.8f;
}

float Enemy::getAbility2()
{
	return atk2;
}

void Enemy::setPassive()
{
	atk3 = getStrenght() * 0.4f + getDexterity() * 0.5f;
}

float Enemy::getPassive()
{
	return atk3;
}

void Enemy::setPassiveAbilityName(std::string a)
{
        passivename = a;
}

std::string Enemy::getPassiveAbilityName()
{
	return passivename;
}
