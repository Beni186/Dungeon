#include "GameCharacter.h"

GameCharacter::GameCharacter():Object(){
	
}

GameCharacter::GameCharacter(string name, int h, int attack, int defense):Object(name, "tag"),maxHealth(h), currentHealth(h){
	this->name=name;
	this->maxHealth=maxHealth;
	this->currentHealth=currentHealth;
	this->attack=attack;
	this->defense=defense;
}
void GameCharacter::setMaxHealth(int maxHealth){
	this->maxHealth=maxHealth;
}
void GameCharacter::setCurrentHealth(int currentHealth){
	this->currentHealth=currentHealth;
}
void GameCharacter::setAttack(int attack){
	this->attack=attack;
}
void GameCharacter::setDefense(int defense){
	this->defense=defense;
}
int GameCharacter::getMaxHealth(){
	return this-> maxHealth;
}
int GameCharacter::getCurrentHealth(){
	return this-> currentHealth;
}
int GameCharacter::getAttack(){
	return this->attack;
}
int GameCharacter::getDefense(){
	return this->defense;
}
bool GameCharacter::checkIsDead(){
	if(currentHealth<=0) return 1;
	else return 0;
}
int GameCharacter::takeDamage(int a){
	int o;
	o=a-getDefense();
	if(o>0){
		setCurrentHealth(getCurrentHealth()-o);
		return getCurrentHealth();
	}		
}
