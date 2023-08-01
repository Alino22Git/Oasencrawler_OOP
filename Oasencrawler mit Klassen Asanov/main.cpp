#include <iostream>
#include <time.h>
#include <string>
#include "Person.h"
#include "Gameworld.h"
#include "Player.h"
using namespace std;
void input(Player *p);
int main() {

    int r=1,s=3;
    string log;
    srand(time(NULL));
    Person per(s);
    Gameworld gw(s,r,&per);
    gw.createWorld();
    Player p(1,&gw);
    log="Game has started with:\nWorldsize: "+to_string(s)+"\nRelics: "+to_string(r)+"\nLifepoints: "+to_string(p.GetLifepoints())+"\n-------------------\n";
    p.playerInfo();
    gw.printWorld(p.Getx(),p.Gety());

    do {
        input(&p);
        system("cls");
        p.playerInfo();
        p.GetWorld()->printWorld(p.Getx(),p.Gety());
        p.react();
        per.movePerson(gw.GetSize());
        if(p.GetWorld()->GetRelics()==0) {
            if(s+1==16) {
                system("cls");

            } else {
                system("cls");
                s+=1;
                r+=1;
                gw=Gameworld(s,r,&per);
                p.increaseLevel();
                if(p.GetLevel()==6){
                    std::cout<<"You won the game with "<<p.GetRespectpoints()<<" respect points!"<<endl;
                return 0;
                }
                gw.createWorld();
                p.SetWorld(&gw);

                p.playerInfo();
                gw.printWorld(p.Getx(),p.Gety());
            }

        }

    } while(p.GetLifepoints()!=0);
    system("cls");

std::cout<<"You lost the game with "<<p.GetRespectpoints()<<" respect points!\nLog of the game:"<<endl;
log.append(p.GetPlayerLog());
std::cout<<log;
    return 0;
}

void input(Player *p) {
    char direction;
    int error=0;
    do {
        error=0;
        cout<<"Move your player:";
        cin>> direction;
        if(direction != 'w' && direction != 'a' && direction != 's' && direction != 'd') {
            error=1;
            cout<<"Wrong input!"<<endl;
        }

        if(error!=1) {
            error=p->move(direction);
            if(error==1) {
                cout<<"Illegal move!"<<endl;
            }
        }


    } while(error==1);
//    cout<<"He is on the field"<<" x:"<<p.x<<" y:"<<p.y<<endl;dfd
}
