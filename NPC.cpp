#include "NPC.h"

NPC::NPC(){
}
NPC::NPC(string n, string t, vector<Item> c, int h){
    this->setName(n);
    this->setTag(t);
    this->commodity=c;
    this->setCurrentHealth(h);
}
void NPC::listCommodity(){
    int n=commodity.size();
    for(int i=0; i<n; i++){
        cout<<i+1<<". "<< commodity[i].getName()<<" ("<<commodity[i].getHealth()
            <<"/"<<commodity[i].getAttack()<<"/"<<commodity[i].getDefense()<<")\n";
    }
}
void NPC::setCommodity(Item o){
    commodity.push_back(o);
}
vector<Item> NPC::getCommodity(){
    return this->commodity;
}
bool NPC::triggerEvent(Object* o){
    if(this->checkIsDead()){ 
        cout<<"\nThere's nothing left here\n";
        return 0;
    }
    else{
        Player *player1=dynamic_cast<Player*>(o);
        if(this->getName()=="Treasure chest"){
            cout<<" \n";
            cout<<"-------You find a treasure chest!-------\n";
            cout<<"Do you want to open it ?\n";
            char decision;
            cout<<"A. Open it\n";
            cout<<"B. No\n";
            cin>>decision;
            if(decision=='a'||decision=='A'){
                cout<<"///You get the Healing Potion!///\n";
                player1->setInventory(player1->getInventory());
                player1->addItem(getCommodity()[0]);
                this->setCurrentHealth(0);
                return 0;
            }
            else if(decision=='b'||decision=='B'){
                cout<<"it's such a shame...\n";
                return 0;
            }
        }
        else if(getName()==" Merchant")  
            cout<<" "<<endl;
            cout<<" \n";
            cout<<"-------You meet Jerry the merchant !-------\n";
            cout<<"Jerry : Hello, I'm Jerry the merchant.\n"
                <<"        Here's are some commodity that you might get interested in.\n";
            cout<<"Pick the one you want.\n"
                <<"A. Silver Bullet : There are 30% of chance you could beat your enemy with only one shot.\n"
                <<"B. Magic Dice : It will cause 40, 50, 60 or 70 damge on your enenmy.\n"
                <<"C. Go back.\n";
            char dec;
            cin>> dec;
            if(dec=='a'||dec=='A'){
                player1->setInventory(player1->getInventory());
                player1->addItem(this->getCommodity()[0]);
                this->setCurrentHealth(0);
                cout<<"You're welcome. Hope it will help you to fight against those monsters.\n";
            }
            if(dec=='b'||dec=='B'){
                player1->setInventory(player1->getInventory());
                player1->addItem(this->getCommodity()[1]);
                this->setCurrentHealth(0);
                cout<<"Jerry : You're welcome. Hope it will help you to fight against those monsters.\n";
            }
            if(dec=='c'||dec=='C'){
                cout<<"Jerry: It's alright. You can come whenever you want.\n";
                return 0;
            }
        }
    }

