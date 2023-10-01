#include "Item.h"

Item::Item():Object(){ 
}

Item::Item(string name, int health, int attack, int defense):Object(name, "tag"){
	this->health=health;
	this->attack=attack;
	this->defense=defense;
}
void Item::setHealth(int health){
	this->health=health;
}
void Item::setAttack(int attack){
	this->attack=attack;
}
void Item::setDefense(int defense){
	this->defense=defense;
}
int Item::getHealth(){
	return this->health;
}
int Item::getAttack(){
	return this->attack;
}
int Item::getDefense(){
	return this->defense;
}
bool Item::triggerEvent(Object* o) {
	Player *player1=dynamic_cast<Player*>(o);
	if(getName()!="Healing_Potion"&&getName()!="Silver_Bullet"){
		cout<<" \n";
		cout<<"///You get the "<<this->getName()<<"///\n";
		cout<<"MaxHealth+"<<this->getHealth()<<endl;
		cout<<"Attack+"<<this->getAttack()<<endl;
		cout<<"Defense+"<<this->getDefense()<<endl;
		player1->setAttack(this->getAttack()+player1->getAttack());
		player1->setMaxHealth(this->getHealth()+player1->getMaxHealth());
		player1->setDefense(player1->getDefense()+this->getDefense());
	}
	else if(getName()=="Healing_Potion"){
		player1->setCurrentHealth(130);
		cout<<"You use the Healing Potion.\n"
			<<"HP is full now.\n";
	}
	
} 
