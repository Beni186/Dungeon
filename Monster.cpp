#include "Monster.h"

Monster::Monster(){
}
Monster::Monster(string name,int h, int a, int d, vector<Item> c){
    setName(name);
    setCurrentHealth(h);
    setAttack(a);
    setDefense(d);
    this->equip=c;
}
void Monster::setEquip(Item h){
    equip.push_back(h);
}
vector<Item> Monster::getEquip(){
    return this->equip;
}
bool Monster::triggerEvent(Object *o){
    Player *player1=dynamic_cast<Player*>(o);
    if(checkIsDead()){
    }
    else{
        cout<<" \n";
        cout<<"-------You meet the "<<this->getName()<<" !-------\n";
        cout<<"CurrentHealth: "<<this->getCurrentHealth()
            <<" Attack: "<<this->getAttack()<<" Defense: "<<getDefense()<<endl;
        while(!this->checkIsDead()&&!player1->checkIsDead()){  
            cout<<"\nWhat you gonna do?"<<endl;
            cout<<"A. Attack"<<endl;
            cout<<"B. Retreat"<<endl;
            int n=player1->getInventory().size();
            if(n>0)
                cout<<"C. Use Item"<<endl;
            char act;
            cin>>act;
            //attack
            if(act=='A'||act=='a'){
                int damage; damage=player1->getAttack()-this->getDefense();
                cout<<"\nYou have caused "<<damage
                    <<" damage on "<<this->getName()<<".\n";
                this->takeDamage(player1->getAttack());
                if(this->checkIsDead()){
                    cout<<this->getName()<<" now remains 0 HP.\n";
                    cout<<"\n!! You Win The Battle !!\n";
                    if(this->getName()!="Final Boss Mr.Yang"){
                        getEquip()[0].triggerEvent(player1);
                        player1->addEquip(this->getEquip()[0]);
                    }
                    if(getName()=="Final Boss Mr.Yang"){
                        player1->getCurrentRoom()->setIsExit(true);
                    }
                    return true;
                    break;
                }   
                else    
                    cout<<this->getName()<<" now remains "<<this->getCurrentHealth()<<" HP.\n";
                cout<<this->getName()<<" attacks you !\n";
                player1->takeDamage(this->getAttack());
                if(player1->checkIsDead()){
                    cout<<"You Lose ><\n";
                    return false;
                    break;
                }   
                else    
                    cout<<"You now have "<<player1->getCurrentHealth()<<" HP."<<endl;
            }
            //retreat
            else if(act=='B'||act=='b'){
                cout<<"You Lose ><\n";
                player1->changeRoom(player1->getPreviousRoom());
                return false;
            }
            else if(act=='c'||act=='C'){
                int i=0;
                for(i; i<n; i++){
                    cout<<i+1<<". "<<player1->getInventory()[i].getName()<<endl;
                }
                cout<<i+1<<". Back"<<endl;
                int d;
                cin>>d;
                if(d==i+1){
                }
                else{
                    if(player1->getInventory()[d-1].getName()=="Silver_Bullet"){
                        srand( time(NULL));
                        int x=rand() % (10) + 1;
                        if(x==4||x==7|| x==9){
                            this->setCurrentHealth(0);
                            cout<<"It works! You beat the "<<this->getName()<<endl;
                            if(getName()=="Final Boss Mr.Yang"){
                                player1->getCurrentRoom()->setIsExit(true);
                            }
                            break;
                        }
                        else{
                            cout<<"It doesn't work. Keep tring.\n";
                            cout<<this->getName()<<" attacks you !\n";
                            player1->takeDamage(this->getAttack());
                            if(player1->checkIsDead()){
                                cout<<"You Lose ><\n";
                                return false;
                                break;
                            }      
                            else    
                                cout<<"You now have "<<player1->getCurrentHealth()<<" HP."<<endl;
                        }
                    }
                    else if(player1->getInventory()[d-1].getName()=="Magic_Dice"){
                        srand( time(NULL));
                        int x=rand() % (4) + 1;
                        cout<<"You use the Magic Dice.\n";
                        if(x==1){
                            cout<<"\nYou have caused 40 damage on "<<this->getName()<<".\n";
                            this->setCurrentHealth(getCurrentHealth()-40);
                        }
                        else if(x==2){
                            cout<<"\nYou have caused 50 damage on "<<this->getName()<<".\n";
                            this->setCurrentHealth(getCurrentHealth()-50);
                        }
                        else if(x==3){
                            cout<<"\nYou have caused 60 damage on "<<this->getName()<<".\n";
                            this->setCurrentHealth(getCurrentHealth()-60);
                        }
                        else if(x==4){
                            cout<<"\nYou have caused 70 damage on "<<this->getName()<<".\n";
                            this->setCurrentHealth(getCurrentHealth()-70);
                        }
                        if(this->checkIsDead()){
                            cout<<this->getName()<<" now remains 0 HP.\n";
                            cout<<"\n!! You Win The Battle !!\n";
                            if(this->getName()!="Final Boss Mr.Yang"){
                                getEquip()[0].triggerEvent(player1);
                                player1->addEquip(this->getEquip()[0]);
                            }
                            if(getName()=="Final Boss Mr.Yang"){
                                player1->getCurrentRoom()->setIsExit(true);
                            }
                            return true;
                            break;
                        }   
                        else    
                            cout<<this->getName()<<" now remains "<<this->getCurrentHealth()<<" HP.\n";
                        cout<<this->getName()<<" attacks you !\n";
                        player1->takeDamage(this->getAttack());
                        if(player1->checkIsDead()){
                            cout<<"You Lose ><\n";
                            return false;
                            break;
                        }   
                        else    
                            cout<<"You now have "<<player1->getCurrentHealth()<<" HP."<<endl;
                    }
                    else {
                        player1->getInventory()[d-1].triggerEvent(player1);  
                        cout<<this->getName()<<" now remains "<<this->getCurrentHealth()<<" HP.\n";
                        cout<<this->getName()<<" attacks you !\n";
                        player1->takeDamage(this->getAttack());
                        if(player1->checkIsDead()){
                            cout<<"You Lose ><\n";
                            return false;
                            break;
                        }   
                        else    
                            cout<<"You now have "<<player1->getCurrentHealth()<<" HP."<<endl;
                    }
                    player1->deleteItem(d-1);
                }
            }
        }    
    }
}