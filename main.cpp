#include <iostream>
#include <string.h>
using namespace std;

class Player {
    private:
        char* name;
        int age;
        float rating;
        const double noMatches;

    public:

        char* getName() const { return name; }
        float getRating() const { return rating; }
        void setRating(float r) { rating = r; }

        Player() : noMatches(0) {
            name = new char[4];
            strcpy(name, "N/A");
            age = 0;
            rating = 0.0;
        }

        Player(const char* n, int a, float r, double m) : noMatches(m) {
            age = a;
            name = new char[strlen(n) + 1];
            strcpy(name, n);
            rating = r;
        }

        Player(const Player &obj) : noMatches(obj.noMatches) {
            this->name = new char[strlen(obj.name) + 1];
            strcpy(this->name, obj.name);
            this->age = obj.age;
            this->rating = obj.rating;
        }

        ~Player() { delete[] name; }
};

class Team{

    private:
        Player* Player1;
        Player* Player2;
        Player* Player3;
        Player* Player4;
        Player* Player5;
        int points;
        int getPoints() const
        {return points;}
        void setPoints(int p){
            p=points;
        }
        bool calif;
        calif=TeamCalif(int);
        int getCalif() const
        {return calif;}

    public:
    Team(Player*, Player*, Player*, Player*, Player* ,int);
    Team(const Team &obj);
    Team& operator=(const Team& obj);

};

Player::Player(char* Player1 ,char* Player2 ,char* Player3 ,char* Player4 ,char* Player5 ,int points){
    this->Player1=new char[strlen(Player1)];
    strcpy(this->Player1,Player1);
    this->Player2=new char[strlen(Player2)];
    strcpy(this->Player2,Player2);
    this->Player3=new char[strlen(Player3)];
    strcpy(this->Player3,Player3);
    this->Player4=new char[strlen(Player4)];
    strcpy(this->Player4,Player4);
    this->Player5=new char[strlen(Player5)];
    strcpy(this->Player5,Player5);
    this->points=points;
}

Team::Team(const Team &obj){
    this->Player1=obj.Player1;
    this->Player2=obj.Player2;
    this->Player3=obj.Player3;
    this->Player4=obj.Player4;
    this->Player5=obj.Player5;
    this->points=obj.points;
}

Team& Team::operator=(const Team& obj){
    if(this==&obj)
        return *this;
    this->Player1=obj.Player1;
    this->Player2=obj.Player2;
    this->Player3=obj.Player3;
    this->Player4=obj.Player4;
    this->Player5=obj.Player5;
    this->points=obj.points;
}

Team::Team(int points){
    if (points>=300)
        return true;
    return false;
}

class Match{

    private:
        Team* Team1;
        char* kd1;
        char* kd2;
        char* kd3;
        char* kd4;
        char* kd5;
        Team* Team2;
        char* kd6;
        char* kd7;
        char* kd8;
        char* kd9;
        char* kd10;
        char* results;
        PointsMatch(char*);


    public:
    Match();
    Match(Team*, char*, char*, char*, char*,Team*, char*, char*, char*, char*,char*);
    Match(const Match &obj);
};

Match::Match(){
    Team1= new char["4"];
    Team2= new char["4"];
    results= new char["4"];
    kd1= new char["4"];
    kd2= new char["4"];
    kd3= new char["4"];
    kd4= new char["4"];
    kd5= new char["4"];
    kd6= new char["4"];
    kd7= new char["4"];
    kd8= new char["4"];
    kd9= new char["4"];
    kd10= new char["4"];
    strcpy(Team1, "N/A");
    strcpy(Team2, "N/A");
    strcpy(results,"N/A");
    strcpy(kd1, "N/A");
    strcpy(kd2, "N/A");
    strcpy(kd3, "N/A");
    strcpy(kd4, "N/A");
    strcpy(kd5, "N/A");
    strcpy(kd6, "N/A");
    strcpy(kd7, "N/A");
    strcpy(kd8, "N/A");
    strcpy(kd9, "N/A");
    strcpy(kd10, "N/A");
}

Match::Match(Team* Team1, Team* Team2, char* results){
    This-> Team1= new char[strlen(Team1)];
    strcpy(This->Team1, Team1);
    This->Team2= new char[strlen(Team2)];
    strcpy(This->Team2, Team2);
    This->results= new char[strlen(results)];
    strcpy(This->results, results);
    This->kd1= new char[strlen(kd1)];
    strcpy(This->kd1, kd1);
    This->kd2= new char[strlen(kd2)];
    strcpy(This->kd2, kd2);
    This->kd3= new char[strlen(kd3)];
    strcpy(This->kd3, kd3);
    This->kd4= new char[strlen(kd4)];
    strcpy(This->kd4, kd4);
    This->kd5= new char[strlen(kd5)];
    strcpy(This->kd5, kd5);
    This->kd6= new char[strlen(kd6)];
    strcpy(This->kd6, kd6);
    This->kd7= new char[strlen(kd7)];
    strcpy(This->kd7, kd7);
    This->kd8= new char[strlen(kd8)];
    strcpy(This->kd8, kd8);
    This->kd9= new char[strlen(kd9)];
    strcpy(This->kd9, kd9);
    This->kd10= new char[strlen(kd10)];
    strcpy(This->kd10, kd10);
}

Match::Match(const Match &obj){
    This->Team1=obj.Team1;
    This->Team2=obj.Team2;
    This->results=obj.results; 
    This->kd1=obj.kd1;   
    This->kd2=obj.kd2;   
    This->kd3=obj.kd3;   
    This->kd4=obj.kd4;   
    This->kd5=obj.kd5;   
    This->kd6=obj.kd6;   
    This->kd7=obj.kd7;   
    This->kd8=obj.kd8;   
    This->kd9=obj.kd9;   
    This->kd10=obj.kd10;   
}

Match::Match(char* results){
    int a,b;
    a=(results[0]-'0')*10+results[1]-'0';
    b=(results[3]-'0')*10+results[4]-'0';
    if(a>b){
        Team1->setPoints(Team1->getPoints() + 50);
            Team2->setPoints(Team2->getPoints() - 25);
        } else if (b > a) {
            Team2->setPoints(Team2->getPoints() + 50);
            Team1->setPoints(Team1->getPoints() - 25);
        }
}

