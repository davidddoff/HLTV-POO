#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Player {
    private:
        char* name;
        int age;
        float rating;
        const double noMatches;

    public:
        Player();
        Player(const char*, int, float, double);
        Player(const Player &obj);
        ~Player();

        Player& operator=(const Player& obj);

        char* getName() const;
        int getAge() const;
        float getRating() const;
        double getNoMatches() const;

        void setName(const char* n);
        void setAge(int a);
        void setRating(float r);
};

Player::Player() : noMatches(0) {
    name = new char[4];
    strcpy(name, "N/A");
    age = 0;
    rating = 0.0;
}

Player::Player(const char* name, int age, float rating, double noMatches) : noMatches(noMatches) {
    this->age = age;
    this->rating = rating;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Player::Player(const Player &obj) : noMatches(obj.noMatches) {
    this->age = obj.age;
    this->rating = obj.rating;
    this->name = new char[strlen(obj.name) + 1];
    strcpy(this->name, obj.name);
}

Player::~Player() {
    if (name != NULL) {
        delete[] name;
    }
}

Player& Player::operator=(const Player& obj) {
    if (this == &obj)
        return *this;
    this->name = new char[strlen(obj.name) + 1];
    strcpy(this->name, obj.name);
    this->age = obj.age;
    this->rating = obj.rating;
}

char* Player::getName() const {
    return name;
}

int Player::getAge() const {
    return age;
}

float Player::getRating() const {
    return rating;
}

double Player::getNoMatches() const {
    return noMatches;
}

void Player::setName(const char* n) {
    if (name != NULL) {
        delete[] name;
    }
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}

void Player::setAge(int a) {
    age = a;
}

void Player::setRating(float r) {
    rating = r;
}



class Team {
    private:
        Player* Player1;
        Player* Player2;
        Player* Player3;
        Player* Player4;
        Player* Player5;
        int points;
        bool calif;
        bool TeamCalif(int p);

    public:
        Team();
        Team(Player*, Player*, Player*, Player*, Player*, int);
        Team(const Team &obj);
        Team& operator=(const Team& obj);
        int getPoints() const;
        void setPoints(int p);
        bool getCalif() const;
        Player* getP1() const;
        Player* getP2() const;
        Player* getP3() const;
        Player* getP4() const;
        Player* getP5() const;
};

bool Team::TeamCalif(int p) {
    if (p >= 300)
        return true;
    return false;
}

Team::Team() {
    Player1 = Player2 = Player3 = Player4 = Player5 = NULL;
    points = 0;
    calif = false;
}

Team::Team(Player* P1, Player* P2, Player* P3, Player* P4, Player* P5, int pts) {
    this->Player1 = P1;
    this->Player2 = P2;
    this->Player3 = P3;
    this->Player4 = P4;
    this->Player5 = P5;
    this->setPoints(pts);
}

Team::Team(const Team &obj) {
    this->Player1 = obj.Player1;
    this->Player2 = obj.Player2;
    this->Player3 = obj.Player3;
    this->Player4 = obj.Player4;
    this->Player5 = obj.Player5;
    this->points = obj.points;
    this->calif = obj.calif;
}

Team& Team::operator=(const Team& obj) {
    if (this == &obj)
        return *this;
    this->Player1 = obj.Player1;
    this->Player2 = obj.Player2;
    this->Player3 = obj.Player3;
    this->Player4 = obj.Player4;
    this->Player5 = obj.Player5;
    this->points = obj.points;
    this->calif = obj.calif;
    return *this;
}

int Team::getPoints() const {
    return points;
}

void Team::setPoints(int p) {
    points = p;
    calif = TeamCalif(points);
}

bool Team::getCalif() const {
    return calif;
}

Player* Team::getP1() const { return Player1; }
Player* Team::getP2() const { return Player2; }
Player* Team::getP3() const { return Player3; }
Player* Team::getP4() const { return Player4; }
Player* Team::getP5() const { return Player5; }



class Match {
    private:
        Team* Team1;
        Team* Team2;
        char* kd1; char* kd2; char* kd3; char* kd4; char* kd5;
        char* kd6; char* kd7; char* kd8; char* kd9; char* kd10;
        char* results;
        void PointsMatch();
        void updatePlayerRating(Player* p, char* KDD);

    public:
        Match();
        Match(Team*, Team*, const char*, const char*, const char*, const char*, const char*, const char*, const char*, const char*, const char*, const char*, const char*,);
        Match(const Match &obj);
        ~Match();
        Match& operator=(const Match& obj);
};

Match::Match() {
    Team1 = Team2 = NULL;
    results = kd1 = kd2 = kd3 = kd4 = kd5 = kd6 = kd7 = kd8 = kd9 = kd10 = NULL;
}

Match::Match(Team* Team1, Team* Team2, const char* res, 
             const char* kd1, const char* kd2, const char* kd3, const char* kd4, const char* kd5,
             const char* kd6, const char* kd7, const char* kd8, const char* kd9, const char* kd10) {
    
    this->Team1 = Team1;
    this->Team2 = Team2;
    results = new char[strlen(res) + 1]; strcpy(results, res);
    kd1 = new char[strlen(k1) + 1]; strcpy(kd1, k1);
    kd2 = new char[strlen(k2) + 1]; strcpy(kd2, k2);
    kd3 = new char[strlen(k3) + 1]; strcpy(kd3, k3);
    kd4 = new char[strlen(k4) + 1]; strcpy(kd4, k4);
    kd5 = new char[strlen(k5) + 1]; strcpy(kd5, k5);
    kd6 = new char[strlen(k6) + 1]; strcpy(kd6, k6);
    kd7 = new char[strlen(k7) + 1]; strcpy(kd7, k7);
    kd8 = new char[strlen(k8) + 1]; strcpy(kd8, k8);
    kd9 = new char[strlen(k9) + 1]; strcpy(kd9, k9);
    kd10 = new char[strlen(k10) + 1]; strcpy(kd10, k10);
    this->PointsMatch();
}

Match::~Match() {
    delete[] results;
    delete[] kd1; delete[] kd2; delete[] kd3; delete[] kd4; delete[] kd5;
    delete[] kd6; delete[] kd7; delete[] kd8; delete[] kd9; delete[] kd10;
}

void Match::PointsMatch() {
    int a = (results[0] - '0') * 10 + (results[1] - '0');
    int b = (results[3] - '0') * 10 + (results[4] - '0');

    if (a > b) {
        Team1->setPoints(Team1->getPoints() + 50);
        Team2->setPoints(Team2->getPoints() - 25);
    }
    else{
        Team2->setPoints(Team2->getPoints() + 50);
        Team1->setPoints(Team1->getPoints() - 25);
    }

    updatePlayerRating(Team1->getP1(), kd1);
    updatePlayerRating(Team1->getP2(), kd2);
    updatePlayerRating(Team1->getP3(), kd3);
    updatePlayerRating(Team1->getP4(), kd4);
    updatePlayerRating(Team1->getP5(), kd5);

    updatePlayerRating(Team2->getP1(), kd6);
    updatePlayerRating(Team2->getP2(), kd7);
    updatePlayerRating(Team2->getP3(), kd8);
    updatePlayerRating(Team2->getP4(), kd9);
    updatePlayerRating(Team2->getP5(), kd10);
}

void Match::updatePlayerRating(Player* p, char* KDD) {
    if (!p || !kdString) return;
    int k, d;
    sscanf(KDD, "%d %d", &k, &d);
    if (d == 0) d = 1;
    float matchRating = (float)k / (d * 1.2f);
    double n = p->getNoMatches();
    float oldR = p->getRating();
    float finalRating = ((oldR * (float)n) + matchRating) / (float)(n + 1);
    p->setRating(finalRating);
}

Match::Match(const Match &obj) {
    this->Team1 = obj.Team1;
    this->Team2 = obj.Team2;
    this->results = new char[strlen(obj.results) + 1]; strcpy(this->results, obj.results);
}