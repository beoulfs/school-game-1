#include <iostream>
#include <ctime>
#include <cstring>
#include <windows.h>
#include "bin/chardata.h"
#include "bin/combat.h"
spell s1;
spell s2;
spell s3;
spell s4;
spell s5;
void setdata (chardata &data1){//makes a charictor. names canot contain spaces
    int in;
    string tamp;
    cout<<"enter one(1) for warier, two(2) for ranger"<<endl;
    cin>>in;
    cout<<"now enter your name"<<endl;
    cin>>tamp;
    data1.name=tamp;
    if (in==1){
        data1.clas="warier";
        data1.hpcap=25;
        data1.hp=25;
        data1.dice=12;
        data1.spud=5;
        data1.surge=10;
        data1.spellp=10;
        data1.spellpc=10;
    }
    if (in==2){
        data1.clas="ranger";
        data1.hp=20;
        data1.hpcap=20;
        data1.dice=8;
        data1.spud=10;
        data1.surge=5;
        data1.spellp=15;
        data1.spellpc=15;
    }
}
int in=0,count=0,threshhold=30,in2,in3,a;
float exp;
edata bastrd;//enimy data
void encounter(){
    int oh;
    srand(time(NULL));
    oh=rand()%10+1;
    if (oh==1)bastrd.ename="1 ghoul";bastrd.ehp=10;bastrd.edice=10;bastrd.expg=10;
    if (oh==2)bastrd.ename="1 skulk";bastrd.ehp=12;bastrd.edice=12;bastrd.expg=12;
    if (oh==3)bastrd.ename="1 cave fisher";bastrd.ehp=10;bastrd.edice=10;bastrd.expg=10;
    if (oh==4)bastrd.ename="rat swarm";bastrd.ehp=8;bastrd.edice=8;bastrd.expg=8;
    if (oh==4)bastrd.ename="4 zombies";bastrd.ehp=20;bastrd.edice=12;bastrd.expg=15;
    if (oh==5)bastrd.ename="4 ROUS's";bastrd.ehp=25;bastrd.edice=12;bastrd.expg=18;
    if (oh==6)bastrd.ename="1 ice memphuit";bastrd.ehp=15;bastrd.edice=10;bastrd.expg=13;
    if (oh==7)bastrd.ename= "3 raiders";bastrd.ehp=20;bastrd.edice=10;bastrd.expg=15;
    if (oh==8)bastrd.ename="1 yeth hound";bastrd.ehp=10;bastrd.edice=8;bastrd.expg=8;
    if (oh==9)bastrd.ename="1 decapus";bastrd.ehp=15;bastrd.edice=8;bastrd.expg=10;
    if (oh==10)bastrd.ename="4 gient spiders";bastrd.ehp=8;bastrd.edice=10;bastrd.expg=8;
}

static void spellist (spell &s1,spell &s2,spell &s3,spell &s4,spell &s5){
s1.name="fireball ";s1.dmg=36;s1.mpcost=30;s1.kamahamah=true;//kamahamah actualy dose something
s2.name="magic missal ";s2.dmg=15;s2.mpcost=10;s1.kamahamah=false;
s3.name="jolt ";s3.dmg=10;s3.mpcost=10;s1.kamahamah=false;
s4.name="death bolt ";s4.dmg=100;s4.mpcost=50;s4.kamahamah=true;
s5.name="pew ";s5.dmg=10;s5.mpcost=5;s5.kamahamah=true;
}

static void fight(chardata &data1, edata bastrd,spell &s1,spell &s2,spell &s3,spell &s4,spell &s5){
int a=0,b=0,c=0,yd=0,e,f,ed=0,eh=1,count=0,hs,inm;//gets hard to find unused variabels with this much code
    string temp,output;
    srand(time(NULL));
    eh=bastrd.ehp;
    cout<<"you enconter "<<bastrd.ename<<endl;
    while(ed<data1.hp&&bastrd.ehp>yd){
    cout<<"smack(1), cast(2), or run(3)?"<<endl;//add magic to this, and change the names of the actions
    cin>>a;
    if (a==1){//how you hit
        c=rand()%data1.dice+1;
        f=rand()%bastrd.edice+1;
        hs=rand()%20+1;
        yd+=c;
        if(hs==1){cout<<"you miss"<<endl;}//if you miss. d20 beased
        if(hs==20){//if you crit, also d20 based
            cout<<"you get a crit"<<endl;
            c=c*2;
            cout<<"you do "<<c<<" damaeg!"<<endl;
            cout<<"you take "<<f<<" damaeg"<<endl;
            data1.hp-=f;
            cout<<"you have "<<data1.hp<<" health remaining"<<endl;
        }
        else if(hs<20&&hs>1){//basic smack
            cout<<"you do "<<c<<" damaeg!"<<endl;
            cout<<"you take "<<f<<" damaeg"<<endl;
            data1.hp-=f;
            cout<<"you have "<<data1.hp<<" health remaining"<<endl;
        }
    }
    if (a==2){//magic engine
        cout<<"you have "<<data1.spellp<<" mana"<<endl;
        cout<<"chose a spell, "<<s1.name<<s1.mpcost<<"(1 )"<<s2.name<<s2.mpcost<<"(2 )"<<s3.name<<s3.mpcost<<"(3 )"<<s4.name<<s4.mpcost<<"(4 )"<<s5.name<<s5.mpcost<<"(5)"<<endl;
        cin>>inm;
        cout<<inm<<data1.spell<<s1.mpcost<<endl;
        if (inm == 1 ){
            c=s1.dmg;
            f=rand()%bastrd.edice+1;
            if (s1.kamahamah==true){cout<<s1.name<<"!"<<endl;}
            cout<<"you do "<<c<<" damaeg!"<<endl;
            cout<<"you take "<<f<<" damaeg"<<endl;
            data1.hp-=f;
            cout<<"you have "<<data1.hp<<" health remaining"<<endl;
            }
        if (inm==2){
            c=s2.dmg;
            f=rand()%bastrd.edice+1;
            if (s2.kamahamah==true){cout<<s2.name<<"!"<<endl;}
            cout<<"you do "<<c<<" damaeg!"<<endl;
            cout<<"you take "<<f<<" damaeg"<<endl;
            data1.hp-=f;
            cout<<"you have "<<data1.hp<<" health remaining"<<endl;
        }
        if (inm==3){
            c=s3.dmg;
            f=rand()%bastrd.edice+1;
            if (s3.kamahamah==true){cout<<s3.name<<"!"<<endl;}
            cout<<"you do "<<c<<" damaeg!"<<endl;
            cout<<"you take "<<f<<" damaeg"<<endl;
            data1.hp-=f;
            cout<<"you have "<<data1.hp<<" health remaining"<<endl;
            }
        if (inm==4){
            c=s4.dmg;
            f=rand()%bastrd.edice+1;
            if (s4.kamahamah==true){cout<<s4.name<<"!"<<endl;}
            cout<<"you do "<<c<<" damaeg!"<<endl;
            cout<<"you take "<<f<<" damaeg"<<endl;
            data1.hp-=f;
            cout<<"you have "<<data1.hp<<" health remaining"<<endl;
        }
        if (inm==5){
            c=s5.dmg;
            f=rand()%bastrd.edice+1;
            if (s1.kamahamah==true){cout<<s1.name<<"!"<<endl;}
            cout<<"you do "<<c<<" damaeg!"<<endl;
            cout<<"you take "<<f<<" damaeg"<<endl;
            data1.hp-=f;
            cout<<"you have "<<data1.hp<<" health remaining"<<endl;
        }
    }
    else if (a==3) {//runing away
            f=rand()%data1.spud+1;
            if (f==1)cout<<"you fail to absocnd, try actualy runing"<<endl;
            else cout<<"you abscond"<<endl;break;
    }
    }
    if(yd>bastrd.ehp&&data1.hp>0)cout<<"you beat the "<<bastrd.ename<<endl;//if you killed it
}

int main()
{
    chardata data1;
    spellist(s1,s2,s3,s4,s5);
    cout<<"so you wnt to winn the championship, gutsy. you wont, but the rawards get bigger as you winn more. who knows you might evan get enught money to walk away. who are you anyway"<<endl;
    setdata(data1);
    cout<<"so begins the tale of "<<data1.name<<" ,a mighty "<<data1.clas<<" who might have a chance in hell of winning, who knows?"<<endl;
    cout<<"you are marched into the first chamber, there is something waiting in the shadows"<<endl;
    while (data1.hp>0){
    cout<<"you have "<< data1.hp <<" helth, and "<<data1.exp<<" exp will you advace to the fight(1), or stay back and rest(2)"<<endl;
    cin>>in;
    if (data1.exp >= threshhold){
        cout<<"upgrage a skill: \n hp(1) \n spud(2) \n dameg(3) \n heailing(4)"<<endl;
        cin>>in2;
        data1.leval+=1;
        if(in2==1){data1.hpcap+=data1.leval;}
        if(in2==2){data1.spud+=data1.leval;}
        if(in2==3){data1.dice+=data1.leval;}
        if(in2==4){data1.surge+=data1.leval;}
        if(in2==5){data1.spellpc+=data1.leval;}
        threshhold+=10*data1.leval;
        data1.exp=0;
    }
    if( in == 1){
        encounter();
        fight(data1,bastrd,s1,s2,s3,s4,s5);
        count+=data1.hp;
        data1.exp+=bastrd.expg;
    }
    if (in == 2){
        cout<<"rest(1) or see exp(2)"<<endl;
        cin>>in3;
        if(in3==1){
         data1.hp+= rand()%data1.surge+1;
         if (data1.hp>data1.hpcap){data1.hp=data1.hpcap;}
        }
        else if(in3==2){
                exp=data1.exp/threshhold;
                cout<<"you have "<<exp<<" present of exp needed to advence a leval"<<endl;}
    }

    }
    cout<<"so ends the tale "<<data1.name<<" a not so mighty "<<data1.clas<<"\nwho made "<<count<<" dolers im my endless muder dungon for his poor famaly, i shuld send them a card"<<endl;
    return 0;
}

