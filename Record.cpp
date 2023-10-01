#include "Record.h"

Record::Record(){
}
void Record::SaveHealth(Object *o, ofstream &outstream){
    if(Monster *monster1=dynamic_cast<Monster*>(o)){
        outstream<<monster1->getCurrentHealth()<<endl;
    }
    else if(NPC *npc1=dynamic_cast<NPC*>(o)){
        outstream<<npc1->getCurrentHealth()<<endl;
    }
}
void Record::savePlayer(Player *player, ofstream &outstream){
    int currenthealth, attack, defense;
    outstream.open("DungeonPlayer.txt");
    outstream<<player->getCurrentHealth()<<"\n"<<player->getAttack()<<"\n"
             <<player->getDefense()<<endl;
    outstream<<player->getName()<<endl;
    outstream<<player->getCurrentRoom()->getIndex()<<endl;
    int l=player->getEquipment().size();
    outstream<<l<<endl;
    for(int i=0; i<l; i++){
        outstream<<player->getEquipment()[i].getName()<<endl;
    }
    int p=player->getInventory().size();
    outstream<<p<<endl;
    for(int i=0; i<p; i++){
        outstream<<player->getInventory()[i].getName()<<endl;
    }
    outstream.close();
}
void Record::saveRooms(vector<Room> &room, ofstream &outstream){
    outstream.open("DungeonRoom.txt");
    for(int i=0; i<8; i++){
        if(room[i].getObjects().size()>0)
            SaveHealth(room[i].getObjects()[0], outstream);
    }
}
void Record::loadPlayer(Player *player, ifstream &instream,vector<Room> &room){
    int currenthealth, attack, defense, index, equipsize, inventsize;
    string name;
    instream.open("DungeonPlayer.txt");
    instream>>currenthealth>>attack>>defense>>name>>index;
    player->setCurrentHealth(currenthealth);
    player->setAttack(attack);
    player->setDefense(defense);
    player->setName(name);
    player->setCurrentRoom(&room[index]);
    instream>>equipsize;
    if(equipsize==2){
        string equip1, equip2;
        instream>>equip1>>equip2;
        Item equip11(equip1,0,0,0);
        Item equip22(equip2,0,0,0);
        player->addEquip(equip11);
        player->addEquip(equip22);
    }
    else if(equipsize==1){
        string equip1;
        instream>>equip1;
        Item equip11(equip1,0,0,0);
        player->addEquip(equip11);
    }
    else{
    }
    instream>>inventsize;
    if(inventsize==2){
        string invent1, invent2;
        instream>>invent1>>invent2;
        Item invent11(invent1,0,0,0);
        Item invent22(invent2,0,0,0);
        player->addItem(invent11);
        player->addItem(invent22);
    }
    else if(inventsize==1){
        string invent1;
        instream>>invent1;
        Item invent11(invent1,0,0,0);
        player->addItem(invent11);
    }
    else{
    }
    instream.close();
}
void Record::loadRooms(vector<Room> &room, ifstream&instream){
    instream.open("DungeonRoom.txt");
    for(int i=0; i<8; i++){
        if(room[i].getObjects().size()>0){
            vector <Object*> o =room[i].getObjects();
            int health;
            instream>>health;
            if(Monster *monster1=dynamic_cast<Monster*>(o[0])){
                monster1->setCurrentHealth(health);
            }
            else if(NPC *npc1=dynamic_cast<NPC*>(o[0]))
                npc1->setCurrentHealth(health);
        }
    }
    instream.close();
}
void Record::saveToFile(Player* player, vector<Room> &room){
    ofstream outstream;
    savePlayer(player, outstream);
    saveRooms(room, outstream);
}
void Record::loadFromFile(Player*player, vector<Room>&room){
    ifstream instream;
    loadPlayer(player, instream, room);
    loadRooms(room, instream);
}
