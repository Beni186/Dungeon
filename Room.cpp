#include "Room.h"

Room::Room(){
	
}
Room::Room(bool isExit, int index, vector<Object*> objects){
	this->isExit=isExit;
	this->index=index;
	this->objects=objects;
}
bool Room::popObject(Object* o){
	//???
}
void Room::setUpRoom(Room *uproom){
	this->upRoom=uproom;
}
void Room::setDownRoom(Room *downroom){
	this->downRoom=downroom;
}
void Room::setLeftRoom(Room *leftroom){
	this->leftRoom=leftroom;
}
void Room::setRightRoom(Room *rightroom){
	this->rightRoom=rightroom;
}
void Room::setIsExit(bool isExit){
	this->isExit=isExit;
}
void Room::setIndex(int index){
	this->index=index;
}
void Room::setObjects(vector<Object*> objects){
	this->objects=objects;
}
bool Room::getIsExit(){
	return this->isExit;
}
int Room::getIndex(){
	return this-> index;
}
vector<Object*> Room::getObjects(){
	return this->objects;
}
Room* Room::getUpRoom(){
	return this->upRoom;
}
Room* Room::getDownRoom(){
	return this->downRoom;
}
Room* Room::getLeftRoom(){
	return this->leftRoom;
}
Room* Room::getRightRoom(){
	return this->rightRoom;
}








