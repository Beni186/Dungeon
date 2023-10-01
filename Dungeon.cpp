#include "Dungeon.h"

Dungeon::Dungeon(){
}
void Dungeon::createPlayer(){
	string c;
	cout<<"Please enter your name:\n";
	cin >>c;
	player=Player(c, 130, 20, 0);
	player.setCurrentRoom(&rooms[0]);
	}
void Dungeon::createMap(){
	rooms.resize(8);
	int n=rooms.size();
	for(int i=0; i<n; i++){
		rooms[i]=Room();
		rooms[i].setIndex(i);
		rooms[i].setUpRoom(NULL);
		rooms[i].setDownRoom(NULL);
		rooms[i].setRightRoom(NULL);
		rooms[i].setLeftRoom(NULL);
		rooms[i].setIsExit(0);
	}
	rooms[0].setUpRoom(&rooms[1]);
	rooms[1].setDownRoom(&rooms[0]);
	rooms[1].setLeftRoom(&rooms[2]);
	rooms[1].setUpRoom(&rooms[3]);
	rooms[2].setRightRoom(&rooms[1]);
	rooms[3].setUpRoom(&rooms[4]);
	rooms[3].setDownRoom(&rooms[1]);
	rooms[4].setDownRoom(&rooms[3]);
	rooms[4].setLeftRoom(&rooms[7]);
	rooms[4].setUpRoom(&rooms[6]);
	rooms[4].setRightRoom(&rooms[5]);
	rooms[7].setRightRoom(&rooms[4]);
	rooms[5].setLeftRoom(&rooms[4]);
	rooms[6].setDownRoom(&rooms[4]);
}
void Dungeon::handleMovement(){
	Room *cur=player.getCurrentRoom();
	cout<< "\nWhere do you want to go ?"<<endl;
	if(cur->getUpRoom()!=NULL) cout<<"u. Go Up"<<endl;
	if(cur->getDownRoom()!=NULL) cout<<"d. Go Down"<<endl;
	if(cur->getLeftRoom()!=NULL) cout<<"l. Go Left"<<endl;
	if(cur->getRightRoom()!=NULL) cout<<"r. Go Right\n";
	char dir;
	cin>>dir;
	player.setPreviousRoom(cur);
	if(dir=='u'||dir=='U')
		player.changeRoom(cur->getUpRoom());
	else if(dir=='d'||dir=='D')
		player.changeRoom(cur->getDownRoom());
	else if(dir=='l'||dir=='L')
		player.changeRoom(cur->getLeftRoom());
	else if(dir=='r'||dir=='R')
		player.changeRoom(cur->getRightRoom());
}
bool Dungeon::checkGameLogic(){
	if(player.getCurrentRoom()->getIsExit()==true) 
		return 0;
	else if(!player.checkIsDead()) 
		return true;
	else 
		return 0;
}
void Dungeon::startGame(){
	createMap();
	createPlayer();
}
void Dungeon::handleEvent(Object *o){
	if(Monster *monster1=dynamic_cast<Monster*>(o)){
		monster1->triggerEvent(&player);
		//else cout<<"You Lose ><";
	}
	else if(NPC *npc1=dynamic_cast<NPC*>(o))
		npc1->triggerEvent(&player);
			//cout<<"There's nothing left here\n";
}
void Dungeon::chooseAction(vector<Object*> o){
	while(1){
		cout<<"\nWhat do you want to do now?\n";
		cout<<"A. Move"<<endl;
		cout<<"B. Save to file"<<endl;
		cout<<"C. Check status"<<endl;
		cout<<"D. Show Map"<<endl;
		char act;
		cin>>act;
		if(act=='a'||act=='A'){
			handleMovement();
			break;
		}
		else if(act=='b'||act=='B'){
			Record record;
			ofstream outstream;
			record.saveToFile(&player, rooms);
		}
		else if(act=='c'||act=='C'){
			player.triggerEvent(&player);
		}
		else if(act=='d'||act=='D'){
			cout<<" ////////////////////////////////"<<endl;
			cout<<"             |-----|          "<<endl;
			cout<<"             |  6  |          "<<endl;
			cout<<"             |-----|          "<<endl;
			cout<<"                /             "<<endl;
			cout<<"   |-----|   |-----|   |-----|"<<endl;
			cout<<"   |  7  |///|  4  |///|  5  |"<<endl;
			cout<<"   |-----|   |-----|   |-----|"<<endl;
			cout<<"                /             "<<endl;
			cout<<"             |-----|          "<<endl;
			cout<<"             |  3  |          "<<endl;
			cout<<"             |-----|          "<<endl;
			cout<<"                /             "<<endl;
			cout<<"   |-----|   |-----|          "<<endl;
			cout<<"   |  2  |///|  1  |          "<<endl;
			cout<<"   |-----|   |-----|          "<<endl;
			cout<<"                /             "<<endl;
			cout<<"             |-----|          "<<endl;
			cout<<"             |  0  |          "<<endl;
			cout<<"             |-----|          "<<endl;
			cout<<"\n     You're now at Room "<<player.getCurrentRoom()->getIndex()<<endl;
			cout<<" ////////////////////////////////"<<endl;
		}
	}
}
void Dungeon::runDungeon(){
	//basic settings
	createMap();
	vector<Object*> o;
	vector<Object*> r0;
	vector<Object*> r1;
	vector<Object*> r2;
	vector<Object*> r3;
	vector<Object*> r4;
	vector<Object*> r5;
	vector<Object*> r6;
	vector<Object*> r7;
	vector<Item> com1;
	vector<Item> com2;
	vector<Item> mon1;
	vector<Item> mon2;
	vector<Item> mon3;
	Monster monster("Monster Slime", 50, 10, 0, mon1);
	Item sword("Golden_Sword", 0, 30, 5);
	monster.setEquip(sword);
	r1.push_back(&monster);
	rooms[1].setObjects(r1);
	NPC treasure("Treasure chest", "NPC", com1, 50);
	Item potion("Healing_Potion", 0, 0, 0);
	treasure.setCommodity(potion);
	r2.push_back(&treasure);
	rooms[2].setObjects(r2);
	NPC jerry("Merchant", "NPC", com2, 50);
	Item gol("Silver_Bullet", 0, 0, 0);
	Item dice("Magic_Dice", 0, 0, 0);
	jerry.setCommodity(gol);
	jerry.setCommodity(dice);
	r5.push_back(&jerry);
	rooms[5].setObjects(r5);
	Monster monster2("Monster James", 70, 20, 5, mon2);
	Item shield("Golden_Shield", 20, 0, 25);
	monster2.setEquip(shield);
	r6.push_back(&monster2);
	rooms[6].setObjects(r6);
	Monster boss("Final Boss Mr.Yang", 200,60,15, mon3);
	r7.push_back(&boss);
	rooms[7].setObjects(r7);
	//start
	Record record; char dec;
	cout<<"Do you want to load previous game ?"<<endl;
	cout<<"A. Yes\n";
	cout<<"B. No\n";
	cin>>dec;
	if(dec=='a'||dec=='A'){
		player.setMaxHealth(130);
		record.loadFromFile(&player, rooms);
	}
	else if(dec=='b'||dec=='B'){
		createPlayer();
	}
	
	while(1){
		if(checkGameLogic()==true){
			chooseAction(o);
			if(player.getCurrentRoom()->getObjects().size()>0)
				handleEvent(player.getCurrentRoom()->getObjects()[0]);
		}
		else if(checkGameLogic()==0){
			break;
		}
	}
	if(player.checkIsDead())
		cout<<"\n///////GAME OVER///////\n";
	else cout<<"\n///////VICTORY///////\n";
}
