#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "World.h"

class Player
{
public:
	Player();
	~Player() {}
	void reset();
	void setName(std::string);
	std::string getName();
	void setMaxHealthPoints(float);
	float getMaxHealtPoints();
	void setHealthPoints(float);
	float getHealthPoints();
	void setStrenght(float);
	float getStrenght();
	void setDefense(float);
	float getDefense();
	void setDexterity(float);
	float getDexterity();
	void setAccuracy(float);
	float getAccuracy();
	void setDagger(bool);
	void setSpear(bool);
	bool getDagger();
	bool getSpear();
	void setRoom(int);
	void setWorld(int);
	void setCoordenadas(int, int);
	std::tuple<int, int>getCoordenadas();
	int getRoom();
	int getWorld();
	float getSkill();
	size_t tamanovec();
	std::string retotnarVec(int i);
	void deleteVector(int i);
	void setItem(Item* a);
	bool verificarDaga();
	bool verificarLanza();
	bool verificaLlave();
	void setExp(int);
	int getExp();
	void AsigNivel();
	int getNivel();
	void setMarcado(bool);
	bool getMarcado();

	void setDiamante(bool d) {
		diamante = d;
	}
	bool getDiamante() { return diamante; }
private:
	std::string name;
	float maxhp;
	float hp;
	float str;
	float def;
	float dexterity;
	float accuracy;
	int Key;
	bool dagger;
	bool spear;
	int room;
	int world;
	int coordenada1;
	int coordenada2;
	float atk1;
	int exp;
	int nivel;
	bool marcado;
	std::vector<Item*> vecItems;
	bool diamante;
};

#endif