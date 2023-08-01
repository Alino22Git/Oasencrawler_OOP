#include "Gameworld.h"

Gameworld::Gameworld() {
    this->size = 3;
    this->relics = 2;
}

Gameworld::Gameworld(int size, int relics, Person *p) {
this->p=p;
    if(size>10) {
        std::cout<<"Size of the world too high!"<<std::endl<<"Size set to 3!"<<std::endl;
        this->size=3;
    } else if(size<3) {
        std::cout<<"Size can't be lower than 3!"<<std::endl<<"Size set to 3!"<<std::endl;
        this->size=3;
    } else {
        this->size=size;
    }

    if(relics>this->size*2) {
        std::cout<<"Too many relics!"<<std::endl<<"Relics set to 3!"<<std::endl;
        this->relics=2;
    } else {
        this->relics=relics;
    }
}

//Odds for:
//spring-> 1,2,3,4                       4/20
//empty->  5,6,7,8,9                     5/20
//danger-> 10,1112,13,14,15,16,17,18,19  8/20
void Gameworld::createWorld() {
    int random = 0;
    for(int i=0; i<size; i++) {
        for(int x=0; x<size; x++) {
            random=rand()%19+1;
            if(i==0 && x==0) {
                random=10;
            }
            this->fields[x][i]=random;
        }
    }
    int r=0;
    while(r!=this->relics) {
        int ran1=rand()%(size-1)+1, ran2=rand()%(size-1)+1;
//        std::cout<<"ran1:"<<ran1<<" ran2:"<<ran2<<std::endl;
        if(getFieldOfWorld(ran1,ran2)!=1&&getFieldOfWorld(ran1,ran2)!=10) {
            this->fields[ran1][ran2]=0;
            r++;
        }
    }
}

//0 -> person
//1 -> relic
//2 -> empty
//3 -> spring
//4 -> danger
int Gameworld::getFieldOfWorld(int x, int y) {
if(p->GetX()==y&&p->GetY()==x){
    return 0;
}
    if(this->fields[x][y]==0) {
        return 1;
    }
    if(this->fields[x][y]<=4) {
        return 3;
    }
    if(this->fields[x][y]<=9) {
        return 2;
    }
    return 4;
}

void Gameworld::printWorld(int posx,int posy) {
    using namespace std;
    for(int x = 0; x<this->size; x++) {
        for(int i = 0; i<this->size; i++) {
            if(posx==x&&posy==i) {
                cout <<  "[P]";
            } else if(Gameworld::getFieldOfWorld(x,i)==1) {
                cout <<  "[*]";
            } else if(Gameworld::getFieldOfWorld(x,i)==3) {
                cout <<  "[ ]";
            } else if(Gameworld::getFieldOfWorld(x,i)==2) {
                cout <<  "[ ]";

            }else if(Gameworld::getFieldOfWorld(x,i)==0) {
                cout <<  "[?]";
            } else {
                cout <<  "[ ]";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

int Gameworld::GetRelics() const {
    return this->relics;
}

void Gameworld::SetRelics(int i) {
    if(relics<size*2&&i>=0) {
        this->relics=i;
    }
}

int Gameworld::GetSize() const {
    return this->size;
}

void Gameworld::setField(int x, int y, int fieldtype) {
    this->fields[x][y]=fieldtype;
}

Person *Gameworld::GetPerson(){
return p;
}
