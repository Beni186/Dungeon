#include "Player.h"

Player::Player(){
}
Player::Player(string name, int h, int a, int d):GameCharacter(name, h, a, d){
}
void Player::addItem(Item a){
	inventory.push_back(a);
}
void Player::addEquip(Item a){
	equipment.push_back(a);
}
void Player::increaseStates(int a,int b,int c){
	setCurrentHealth(getCurrentHealth()+a);
	setAttack(getAttack()+b);
	setDefense(getDefense()+c);
}
void Player::changeRoom(Room*r){
	previousRoom=currentRoom;
	currentRoom=r;
}
bool Player::triggerEvent(Object* o){
	if(Player *player1=dynamic_cast<Player*>(o)){
		cout<<"     /////////////////////////////// \n";
		cout<<"          "<<player1->getName()<<"'s Current Status:\n"
			<<"Health:"<<player1->getCurrentHealth()<<"/"<<player1->getMaxHealth()<<"\n"
			<<"Attack:"<<player1->getAttack()<<"\n"
			<<"Defense:"<<player1->getDefense()<<endl;
		int n=getEquipment().size();
		if(n>0)
			cout<<"\nEquipment : \n";
		for(int i=0; i<n; i++){
			cout<<getEquipment()[i].getName()<<endl;
		}
		int d=getInventory().size();
		if(d>0)
			cout<<"\nInventory : \n";
		for(int i=0; i<d; i++){
			cout<<getInventory()[i].getName()<<endl;
		}
		cout<<"     ///////////////////////////////\n";
	}
	else cout<<"Error!";
}
void Player::setCurrentRoom(Room*c){
	currentRoom=c; 
}
void Player::setPreviousRoom(Room*p){
	previousRoom=p;
}
void Player::setInventory(vector<Item> inventory){
	this->inventory=inventory;
}
void Player::setEquipment(vector<Item> inventory){
	this->equipment=inventory;
}
Room* Player::getCurrentRoom(){
	return this->currentRoom;
}
Room*Player:: getPreviousRoom(){
	return this->previousRoom;
} 
vector<Item> Player::getInventory(){
	return this->inventory;
}
vector<Item> Player::getEquipment(){
	return this->equipment;
}
void Player::deleteItem(int n){
	inventory.erase(inventory.begin()+n);
}








