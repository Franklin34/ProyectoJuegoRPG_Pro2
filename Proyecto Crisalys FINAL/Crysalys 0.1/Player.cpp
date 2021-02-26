#include "Player.h"

Player::Player()
{
	name = "";
	maxhp = 100.0f;
	hp = 100.0f;
	str = 10.0f;
	def = 10.0f;
	dexterity = 10.0f;
	accuracy = 10.0f;
	Key = false;
	dagger = false;
	spear = false;
	room = 0;
	world = 0;
	exp = 0;
	nivel = 0;
	vecItems;
}

void Player::reset()
{
	name = "";
	maxhp = 100.0f;
	hp = 100.0f;
	str = 10.0f;
	def = 10.0f;
	dexterity = 10.0f;
	accuracy = 10.0f;
	Key = false;
	dagger = false;
	spear = false;
	room = 0;
	world = 0;
	exp = 0;
	nivel = 0;
	vecItems;
}

void Player::setName(std::string name)
{
	this->name = name;
}

std::string Player::getName()
{
	return name;
}

void Player::setMaxHealthPoints(float maxhp)
{
	this->maxhp = maxhp;
}

float Player::getMaxHealtPoints()
{
	return maxhp;
}

void Player::setHealthPoints(float hp)
{
	this->hp = hp;
}

float Player::getHealthPoints()
{
	return hp;
}

void Player::setStrenght(float str)
{
	this->str = str;
}

float Player::getStrenght()
{
	return str;
}

void Player::setDefense(float def)
{
	this->def = def;
}

float Player::getDefense()
{
	return def;
}

void Player::setDexterity(float dex)
{
	dexterity = dex;
}

float Player::getDexterity()
{
	return dexterity;
}

void Player::setAccuracy(float acc)
{
	accuracy = acc;
}

float Player::getAccuracy()
{
	return accuracy;
}

void Player::setDagger(bool dagger)
{
	this->dagger = dagger;
}

void Player::setSpear(bool spear)
{
	this->spear = spear;
}

bool Player::getDagger()
{
	return dagger;
}

bool Player::getSpear()
{
	return spear;
}

void Player::setRoom(int room)
{
	this->room = room;
}

void Player::setWorld(int world)
{
	this->world = world;
}

void Player::setCoordenadas(int a, int b)
{
	this->coordenada1 = a;
	this->coordenada2 = b;
}

std::tuple<int, int> Player::getCoordenadas()
{
	return std::make_tuple<>(coordenada1, coordenada2);
}

int Player::getRoom()
{
	return room;
}

int Player::getWorld()
{
	return world;
}

float Player::getSkill()
{
	atk1 = str * 1.15f + dexterity * 1.35f;
	return atk1;
}

size_t Player::tamanovec()
{
	return vecItems.size();
}

std::string Player::retotnarVec(int i)
{
	return vecItems[i]->getNombre();
}

void Player::deleteVector(int i)
{
	
	if (i == 7658) {
		for (int a = 0; a < vecItems.size(); a++) {
		delete vecItems[a];
		}
		vecItems.clear();
	}
	else {
		delete vecItems[i];
		vecItems.erase(vecItems.begin() + i);
	}
}

void Player::setItem(Item* a)
{
	vecItems.push_back(a);
}

bool Player::verificarDaga()
{
	for (int i = 0; i < vecItems.size(); i++) {
		if (vecItems[i]->getNombre() == "Daga") {
			return true;
		}
	}
	return false;
}

bool Player::verificarLanza()
{
	for (int i = 0; i < vecItems.size(); i++) {
		if (vecItems[i]->getNombre() == "Lanza") {
			return true;
		}
	}
	return false;
}

bool Player::verificaLlave()
{
	for (int i = 0; i < vecItems.size(); i++) {
		if (vecItems[i]->getNombre() == "Key") {
			return true;
		}
	}
	return false;
}

void Player::setExp(int expe)
{
	exp += expe;
}

int Player::getExp()
{
	return exp;
}

void Player::AsigNivel()
{
	if (exp >= 25 && exp < 50) {
		nivel = 1;
	}
	else if (exp >= 50 && exp < 75) {
		nivel = 2;
	}
	else if (exp >= 75 && exp < 100) {
		nivel = 3;
	}
	else if (exp >= 100 && exp < 125) {
		nivel = 4;
	}
	else if (exp >= 125 && exp < 150) {
		nivel = 5;
	}
	else if (exp >= 150 && exp < 185) {
		nivel = 6;
	}
	else if (exp >= 185 && exp < 220) {
		nivel = 7;
	}
	else if (exp >= 220 && exp < 255) {
		nivel = 8;
	}
	else if (exp >= 255 && exp < 290) {
		nivel = 9;
	}
	else if (exp >= 290 && exp < 330) {
		nivel = 10;
	}
	else if (exp >= 335 && exp < 380) {
		nivel = 11;
	}
	else if (exp >= 380 && exp < 425) {
		nivel = 12;
	}
	else if (exp >= 425 && exp < 470) {
		nivel = 13;
	}
	else if (exp >= 470 && exp < 515) {
		nivel = 14;
	}
	else if (exp >= 515 && exp < 560) {
		nivel = 15;
	}
	else if (exp >= 560 && exp < 615) {
		nivel = 16;
	}
	else if (exp >= 615 && exp < 670) {
		nivel = 17;
	}
	else if (exp >= 670 && exp < 730) {
		nivel = 18;
	}
	else if (exp >= 730 && exp < 795) {
		nivel = 19;
	}
	else if (exp >= 795 && exp < 865) {
		nivel = 20;
	}
}

int Player::getNivel()
{
	return nivel;
}

void Player::setMarcado(bool a)
{
	marcado = a;
}

bool Player::getMarcado()
{
	return marcado;
}

