#include <iostream>
#include <ctime>
#include <cstring>
#include <windows.h>
#include "bin/chardata.h"
spell s1;
spell s2;
spell s3;
spell s4;
spell s5;
spell s6;
void setdata (chardata &data1){//makes a charictor. names canot contain spaces
    int in;
    string tamp;
    cout<<"enter one(1) for warier, two(2) for ranger, three for sorcerer(3)"<<endl;
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
        data1.hasposin=false;
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
        data1.pdice=6;
        data1.hasposin=true;
    }
    if (in==3){
        data1.clas="sorcerer";
        data1.hp=15;
        data1.hpcap=15;
        data1.dice=10;
        data1.spud=10;
        data1.surge=5;
        data1.spellp=25;
        data1.spellpc=25;
        data1.hasposin=false;
    }
}
int in=0,count=0,threshhold=30,in2,in3,a,in4;
float exp;
edata bastrd;//enimy data
void encounter(chardata data1, edata &bastrd){
    int oh;
    srand(time(NULL));
    oh=rand()%15+1;
    if (oh==1)bastrd.ename="1 ghoul";bastrd.ehp=10*data1.leval;bastrd.edice=10*data1.leval;bastrd.expg=10*data1.leval;bastrd.isposiond=false;bastrd.isstunned=false;
    if (oh==2)bastrd.ename="1 skulk";bastrd.ehp=12*data1.leval;bastrd.edice=12*data1.leval;bastrd.expg=12*data1.leval;bastrd.isposiond=false;bastrd.isstunned=false;
    if (oh==3)bastrd.ename="1 cave fisher";bastrd.ehp=10*data1.leval;bastrd.edice=10*data1.leval;bastrd.expg=10*data1.leval;bastrd.isposiond=false;bastrd.isstunned=false;
    if (oh==4)bastrd.ename="rat swarm";bastrd.ehp=8*data1.leval;bastrd.edice=8*data1.leval;bastrd.expg=8*data1.leval;bastrd.isposiond=false;bastrd.isstunned=false;
    if (oh==4)bastrd.ename="4 zombies";bastrd.ehp=20*data1.leval;bastrd.edice=12*data1.leval;bastrd.expg=15*data1.leval;bastrd.isposiond=false;bastrd.isstunned=false;
    if (oh==5)bastrd.ename="4 ROUS's";bastrd.ehp=25*data1.leval;bastrd.edice=12*data1.leval;bastrd.expg=18*data1.leval;bastrd.isposiond=false;bastrd.isstunned=false;
    if (oh==6)bastrd.ename="1 ice memphuit";bastrd.ehp=15*data1.leval;bastrd.edice=10*data1.leval;bastrd.expg=13*data1.leval;bastrd.isposiond=false;bastrd.isstunned=false;
    if (oh==7)bastrd.ename= "3 raiders";bastrd.ehp=20*data1.leval;bastrd.edice=10*data1.leval;bastrd.expg=15*data1.leval;bastrd.isposiond=false;bastrd.isstunned=false;
    if (oh==8)bastrd.ename="1 yeth hound";bastrd.ehp=10*data1.leval*data1.leval;bastrd.edice=8*data1.leval;bastrd.expg=8*data1.leval;bastrd.isposiond=false;bastrd.isstunned=false;
    if (oh==9)bastrd.ename="1 decapus";bastrd.ehp=15*data1.leval;bastrd.edice=8*data1.leval;bastrd.expg=10*data1.leval;bastrd.isposiond=false;bastrd.isstunned=false;
    if (oh==10)bastrd.ename="4 gient spiders";bastrd.ehp=8*data1.leval;bastrd.edice=10*data1.leval;bastrd.expg=8*data1.leval;bastrd.isposiond=false;bastrd.isstunned=false;
    if (oh==11)bastrd.ename="Axe Beak";bastrd.ehp=5*data1.leval;bastrd.edice=10*data1.leval;bastrd.expg=8*data1.leval;bastrd.isposiond=false;bastrd.isstunned=false;
    if (oh==12)bastrd.ename="Gnoll";bastrd.ehp=15*data1.leval;bastrd.edice=8*data1.leval;bastrd.expg=10*data1.leval;bastrd.isposiond=false;bastrd.isstunned=false;
    if (oh==13)bastrd.ename="Snake";bastrd.ehp=2*data1.leval;bastrd.edice=12*data1.leval;bastrd.expg=5*data1.leval;bastrd.isposiond=false;bastrd.isstunned=false;
    if (oh==14)bastrd.ename="Cloaker";bastrd.ehp=25*data1.leval;bastrd.edice=12*data1.leval;bastrd.expg=20*data1.leval;bastrd.isposiond=false;bastrd.isstunned=false;
    if (oh==15)bastrd.ename="Troglodyte";bastrd.ehp=10*data1.leval;bastrd.edice=10*data1.leval;bastrd.expg=10*data1.leval;bastrd.isposiond=false;bastrd.isstunned=false;
}

static void spellist (spell &s1,spell &s2,spell &s3,spell &s4,spell &s5){
s1.name="fireball ";s1.dmg=35;s1.mpcost=30;s1.kamahamah=true;//kamahamah actualy dose something
s2.name="magic missal ";s2.dmg=15;s2.mpcost=10;s1.kamahamah=false;
s3.name="jolt ";s3.dmg=10;s3.mpcost=10;s1.kamahamah=false;
s4.name="death bolt ";s4.dmg=100;s4.mpcost=50;s4.kamahamah=true;
s5.name="pew ";s5.dmg=10;s5.mpcost=5;s5.kamahamah=true;
s6.name="spud shot";s6.dmg=8;s6.mpcost=1;s6.kamahamah=false;
}

static void fight(chardata &data1, edata bastrd,spell &s1,spell &s2,spell &s3,spell &s4,spell &s5){
int a=0,b=0,c=0,yd=0,e,f=0,ed=0,eh=1,count=0,hs,inm;//gets hard to find unused variabels with this much code
    string temp,output;
    srand(time(NULL));
    eh=bastrd.ehp;
    cout<<"you enconter "<<bastrd.ename<<endl;
    while(ed<data1.hp&&bastrd.ehp>yd){
    cout<<"smack(1), cast(2), or run(3)?"<<endl;//add magic to this, and change the names of the actions
    cin>>a;

    if (a==1){//how you hit
        if (data1.hasposin==true){
            cout<<"use posion?(1)"<<endl;
            cin>>in4;
            if(in4==1){
            c+=rand()%data1.pdice+1;
            data1.spellp-=5;
            cout<<"the "<<bastrd.ename<<" is posiond for "<<c<<" dameg"<<endl;
            }
        }
        if (bastrd.isposiond==true){bastrd.ehp-=rand()%data1.pdice+1;}
        if (bastrd.isstunned==false){f=rand()%bastrd.edice+1;}
        else {cout<<"they are stunned"<<endl;}
        hs=rand()%20+1;
        yd+=c;
        if(hs==1){cout<<"you miss"<<endl;}//if you miss. d20 beased
        if(hs==20){//if you crit, also d20 based
            c+=rand()%data1.dice+1;
            cout<<"you get a crit"<<endl;
            c=c*2;
            cout<<"you do "<<c<<" damaeg!"<<endl;
            cout<<"you take "<<f<<" damaeg"<<endl;
            data1.hp-=f;
            bastrd.ehp-=c;
            cout<<"you have "<<data1.hp<<" health remaining"<<endl;
        }
        else if(hs<20&&hs>1){//basic smack
            c+=rand()%data1.dice+1;
            cout<<"you do "<<c<<" damaeg!"<<endl;
            cout<<"you take "<<f<<" damaeg"<<endl;
            data1.hp-=f;
            bastrd.ehp-=c;
            cout<<"you have "<<data1.hp<<" health remaining"<<endl;
        }
    }
    if (a==2){//magic engine
        if (bastrd.isposiond==true){
                bastrd.ehp-=rand()%data1.pdice+1;

        }
        cout<<"you have "<<data1.spellp<<" mana"<<endl;
        cout<<"chose a spell, "<<s1.name<<s1.mpcost<<"(1) "<<s2.name<<s2.mpcost<<"(2) "<<s3.name<<s3.mpcost<<"(3) "<<s4.name<<s4.mpcost<<"(4) "<<s5.name<<s5.mpcost<<"(5)"<<endl;
        cout<<"or just use a potato(6)"<<endl;
        cin>>inm;
        if (inm == 1 && data1.spellp>=s1.mpcost){
            c=s1.dmg;
            f=rand()%bastrd.edice+1;
            cout<<s1.name<<"!"<<endl;
            cout<<"you do "<<c<<" damaeg!"<<endl;
            cout<<"you take "<<f<<" damaeg"<<endl;
            data1.hp-=f;
            bastrd.ehp-=c;
            data1.spellp-=s1.mpcost;
            cout<<"you have "<<data1.hp<<" health remaining"<<endl;
            }
        if (inm==2 && data1.spellp>=s2.mpcost){
            c=s2.dmg;
            f=rand()%bastrd.edice;
            cout<<"you do "<<c<<" damaeg!"<<endl;
            cout<<"you take "<<f<<" damaeg"<<endl;
            data1.hp-=f;
            bastrd.ehp-=c;
            data1.spellp-=s2.mpcost;
            cout<<"you have "<<data1.hp<<" health remaining"<<endl;
        }
        if (inm==3 && data1.spellp>=s3.mpcost){
            c=s3.dmg;
            f=rand()%bastrd.edice+1;
            if (s3.kamahamah==true){cout<<s3.name<<"!"<<endl;}
            cout<<"you do "<<c<<" damaeg!"<<endl;
            cout<<"you take "<<f<<" damaeg"<<endl;
            data1.hp-=f;
            bastrd.ehp-=c;
            data1.spellp-=s3.mpcost;
            cout<<"you have "<<data1.hp<<" health remaining"<<endl;
            }
        if (inm==4 && data1.spellp>=s4.mpcost){
            c=s4.dmg;
            f=rand()%bastrd.edice+1;
            cout<<s4.name<<"!"<<endl;
            cout<<"you do "<<c<<" damaeg!"<<endl;
            cout<<"you take "<<f<<" damaeg"<<endl;
            data1.hp-=f;
            bastrd.ehp-=c;
            data1.spellp-=s4.mpcost;
            cout<<"you have "<<data1.hp<<" health remaining"<<endl;
        }
        if (inm==5 && data1.spellp>=s5.mpcost){
            c=s5.dmg;
            f=rand()%bastrd.edice+1;
            cout<<s1.name<<"!"<<endl;
            cout<<"you do "<<c<<" damaeg!"<<endl;
            cout<<"you take "<<f<<" damaeg"<<endl;
            data1.hp-=f;
            bastrd.ehp-=c;
            data1.spellp-=s5.mpcost;
            cout<<"you have "<<data1.hp<<" health remaining"<<endl;
        }
        if (inm==6){
            cout<<"you use a potato, they cant hit you"<<endl;
            c=s6.dmg;
            cout<<"potato attack!"<<endl;
            cout<<"you do "<<c<<" damaeg!"<<endl;
            bastrd.isstunned=true;
        }
    }
    else if (a==3) {//runing away
            f=rand()%data1.spud+1;
            if (f==1)cout<<"you fail to absocnd, try actualy runing"<<endl;
            else cout<<"you abscond"<<endl;break;
    }
    }
    if(bastrd.ehp <= 0&&data1.hp>0)cout<<"you beat the "<<bastrd.ename<<endl;//if you killed it
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
    cout<<"you have "<< data1.hp <<" helth, "<<data1.spellp<<" mana, and "<<data1.exp<<" exp will you advace to the fight(1), or stay back and rest(2)"<<endl;
    cin>>in;
    if (data1.exp >= threshhold){
        cout<<"upgrage a skill: \n hp(1) \n spud(2) \n dameg(3) \n heailing(4) \n spellcasting (5)"<<endl;
        cin>>in2;
        data1.leval+=1;
        if(in2==1){data1.hpcap+=2*data1.leval;}
        if(in2==2){data1.spud+=2*data1.leval;}
        if(in2==3){data1.dice+=2*data1.leval;}
        if(in2==4){data1.surge+=2*data1.leval;}
        if(in2==5){data1.spellpc+= 5*data1.leval;}
        data1.surge+=data1.leval;
        data1.hpcap+=data1.leval;
        data1.dice+=data1.leval;
        threshhold+=10*data1.leval;
        data1.exp=0;
    }
    if( in == 1){
        encounter(data1,bastrd);
        fight(data1,bastrd,s1,s2,s3,s4,s5);
        count+=data1.hp;
        data1.exp+=bastrd.expg;
    }
    if (in == 2){
        cout<<"rest(1), see exp(2), or see stats(3)"<<endl;
        cin>>in3;
        if(in3==1){
         data1.hp+= rand()%data1.surge+1;
         data1.spellp+= rand()%data1.surge+1*2;
         data1.spud+=rand()%1+0;
         if (data1.hp>data1.hpcap){data1.hp=data1.hpcap;}
         if (data1.spellp>data1.spellpc){data1.spellp=data1.spellpc;}
        }
        if(in3==2){
                cout<<"you have "<<data1.exp<<" out of "<<threshhold<<" needed to advance a leval"<<endl;
        }
        if(in3==3){
            cout<<"you have "<<data1.hpcap<<" max hp"<<endl;
            cout<<"you have "<<data1.spud<<" spuds"<<endl;
            cout<<"you do 1d"<<data1.dice<<" of dameg"<<endl;
            cout<<"you heal "<<data1.surge<<" hp per rest"<<endl;
            cout<<"you have "<<data1.spellpc<<" max mana"<<endl;
        }
    }
    }
    cout<<"so ends the tale "<<data1.name<<", a not so mighty "<<data1.clas<<"\nwho made "<<count<<" dollers im my endless muder dungon for his poor famaly, i shuld send them a card"<<endl;
    return 0;
}
