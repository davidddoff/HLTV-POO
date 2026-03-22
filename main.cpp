#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;


class Event {
    private:
        char* name;
        int requiredPoints;
    public:
        Event(const char* , int );
        ~Event(){ delete[] name; }

        int getRequiredPoints() const { return requiredPoints; }
        const char* getName() const { return name; }
};


Event::Event(const char* name, int requiredPoints){
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
            this->requiredPoints = requiredPoints;
}

class Player {
    private:
        char* name;
        int age;
        float rating;
        double noMatches;
        static int totalPlayers=0;

    public:
        Player();
        Player(const char*, int, float, double);
        Player(const Player &obj);
        ~Player();
        static int getTotalPlayers() { return totalPlayers; }
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
    totalPlayers++;
}

Player::Player(const char* name, int age, float rating, double noMatches) : noMatches(noMatches) {
    this->age = age;
    this->rating = rating;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    totalPlayers++;
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
        char* name;
        Player* Player1;
        Player* Player2;
        Player* Player3;
        Player* Player4;
        Player* Player5;
        int points;
        bool calif;

    public:
        Team();
        Team(char*, Player*, Player*, Player*, Player*, Player*, int);
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
        bool checkQualification(const Event& e) {
            if (this->points >= e.getRequiredPoints()) {
                this->calif = true;
            } else {
                this->calif = false;
            }
            return this->calif;
        }
};

Team::Team() {
    name= new char[4];
    strcpy(name, "N/A");
    Player1 = Player2 = Player3 = Player4 = Player5 = NULL;
    points = 0;
    calif = false;
}

Team::Team(char* name, Player* P1, Player* P2, Player* P3, Player* P4, Player* P5, int pts) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->Player1 = P1;
    this->Player2 = P2;
    this->Player3 = P3;
    this->Player4 = P4;
    this->Player5 = P5;
    this->setPoints(pts);
}

Team::Team(const Team &obj) {
    this->name= obj.name;
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
    this->name= obj.name;
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
        Match( Team*, Team*, const char*, const char*, const char*, const char*, const char*, const char*, const char*, const char*, const char*, const char*, const char*,);
        Match(const Match &obj);
        ~Match();
        Match& operator=(const Match& obj);
};

Match::Match() {
    teamName = Team1 = Team2 = NULL;
    results = kd1 = kd2 = kd3 = kd4 = kd5 = kd6 = kd7 = kd8 = kd9 = kd10 = NULL;
}

Match::Match(Team* Team1, Team* Team2, const char* res, const char* kd1, const char* kd2, const char* kd3, const char* kd4, const char* kd5, const char* kd6, const char* kd7, const char* kd8, const char* kd9, const char* kd10) {
    
    this->Team1 = Team1;
    this->Team2 = Team2;
    this->results = new char[strlen(res) + 1]; 
    strcpy(this->results, res);
    this->kd1 = new char[strlen(kd1) + 1]; 
    strcpy(this->kd1, kd1);
    this->kd2 = new char[strlen(kd2) + 1]; 
    strcpy(this->kd2, kd2);
    this->kd3 = new char[strlen(kd3) + 1]; 
    strcpy(this->kd3, kd3);
    this->kd4 = new char[strlen(kd4) + 1]; 
    strcpy(this->kd4, kd4);
    this->kd5 = new char[strlen(kd5) + 1]; 
    strcpy(this->kd5, kd5);
    this->kd6 = new char[strlen(kd6) + 1]; 
    strcpy(this->kd6, kd6);
    this->kd7 = new char[strlen(kd7) + 1]; 
    strcpy(this->kd7, kd7);
    this->kd8 = new char[strlen(kd8) + 1]; 
    strcpy(this->kd8, kd8);
    this->kd9 = new char[strlen(kd9) + 1]; 
    strcpy(this->kd9, kd9);
    this->kd10 = new char[strlen(kd10) + 1]; 
    strcpy(this->kd10, kd10);
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
    if (!p || !KDD) return;
    int k, d;
    sscanf(KDD, "%d/%d", &k, &d);
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
    this->results = new char[strlen(obj.results) + 1];
    strcpy(this->results, obj.results);
}

class Menu {
    private:
        Team* teams[100];
        Event* events[50];
        int teamCount;
        int eventCount;
        void showHeader();
        void addTeam();
        void registerMatch();
        void showPlayerStats();
        void manageEvent();
        void showAllData();

    public:
        Menu();
        ~Menu();
        void run();
};

Menu::Menu() : teamCount(0), eventCount(0) {
    for(int i=0; i<100; i++) teams[i] = NULL;
    for(int i=0; i<50; i++) events[i] = NULL;
}

void Menu::showHeader() {
    cout << "\n==================================== HLTV CS2 TRACKER ====================================\n";
    cout << "1.  [CONFIG] Adauga o Echipa (si Jucatorii acesteia)\n";
    cout << "2.  [MATCH]  Inregistreaza un Meci Nou (Scor, Statistici)\n";
    cout << "3.  [STATS]  Afiseaza Clasament Jucatori (dupa Rating)\n";
    cout << "4.  [EVENT]  Adauga un eveniment si afiseaza echipele care pot juca (prag de puncte)\n";
    cout << "5.  [DATA]   Afiseaza toate Echipele si Jucatorii\n";
    cout << "0.  [EXIT]   Iesire din aplicatie\n";
    cout << "========================================================================================\n";
}

void Menu::run() {
    int option = -1;
    while (option != 0) {
        showHeader();
        cout << "Alegeti o optiune: ";
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1: addTeam(); break;
            case 2: registerMatch(); break;
            case 3: showPlayerStats(); break;
            case 4: manageEvent(); break;
            case 5: showAllData(); break;
            case 0: cout << "Iesire program...\n"; break;
            default: cout << "Optiune invalida!\n"; break;
        }

        if (option != 0) {
            cout << "\nApasati ENTER pentru a reveni la meniul principal...";
            cin.get();
        }
    }
}

void Menu::addTeam() {
    if (teamCount >= 100) {
        cout << "Capacitate maxima de echipe atinsa!\n";
        return;
    }

    char tName[100];
    cout << "Numele echipei: ";
    cin.get(tName, 100); cin.ignore();

    Player* p[5];
    for (int i = 0; i < 5; i++) {
        char pName[100];
        int age;
        float rating;
        double matches;
        cout << "\n--- Jucatorul " << i + 1 << " ---\n";
        cout << "Nume: "; 
        cin.get(pName, 100); 
        cin.ignore();
        cout << "Varsta: "; 
        cin >> age;
        cout << "Rating initial: "; 
        cin >> rating;
        cout << "Meciuri jucate: "; 
        cin >> matches; 
        cin.ignore();
        p[i] = new Player(pName, age, rating, matches);
    }

    int initialPoints;
    cout << "\nPuncte initiale echipa: ";
    cin >> initialPoints; cin.ignore();
    teams[teamCount] = new Team(tName, p[0], p[1], p[2], p[3], p[4], initialPoints);
    teamCount++;

    cout << "\nEchipa " << tName << " a fost adaugata cu succes!\n";
}

void Menu::registerMatch() {
    if (teamCount < 2) {
        cout << "Aveti nevoie de cel putin 2 echipe pentru un meci!\n";
        return;
    }
    for (int i = 0; i < teamCount; i++) {
        cout << i << ". " << teams[i]->getName() << endl;
    }
    int idx1, idx2;
    cout << "Alegeti indexul primei echipe: "; cin >> idx1;
    cout << "Alegeti indexul echipei adverse: "; cin >> idx2;
    cin.ignore();
    if (idx1 == idx2 || idx1 >= teamCount || idx2 >= teamCount) {
        cout << "Selectie invalida!\n";
        return;
    }
    char scor[10], kd[10][20];
    cout << "Introduceti scorul (format 16-10): "; cin >> scor; cin.ignore();
    cout << "Introduceti statisticile K/D (format K/D):\n";
    for (int i = 0; i < 10; i++) {
        if (i < 5) cout << "Echipa 1 - Jucator " << i+1 << ": ";
        else cout << "Echipa 2 - Jucator " << (i-5)+1 << ": ";
        cin >> kd[i]; cin.ignore();
    }
    Match m(teams[idx1], teams[idx2], scor, 
            kd[0], kd[1], kd[2], kd[3], kd[4], 
            kd[5], kd[6], kd[7], kd[8], kd[9]);

    cout << "\nMeci inregistrat! Clasamentul si rating-urile au fost actualizate.\n";
}

void Menu::showAllData() {
    if (teamCount == 0) {
        cout << "Nu exista echipe inregistrate.\n";
        return;
    }

    for (int i = 0; i < teamCount; i++) {
        cout << "\nECHIPA: " << teams[i]->getName() << " | Puncte: " << teams[i]->getPoints();
        cout << " | Calificat: " << (teams[i]->getCalif() ? "DA" : "NU") << endl;
        Player* pTemp[5] = { teams[i]->getP1(), teams[i]->getP2(), teams[i]->getP3(), teams[i]->getP4(), teams[i]->getP5() };
        for (int j = 0; j < 5; j++) {
            cout << "  -> " << pTemp[j]->getName() << " | Rating: " << pTemp[j]->getRating() 
                 << " | Meciuri: " << pTemp[j]->getNoMatches() << endl;
        }
    }
}

void Menu::manageEvent() {
    char eName[100];
    int reqPts;
    
    cout << "Nume eveniment: "; cin.getline(eName, 100);
    cout << "Prag puncte calificare: "; cin >> reqPts; cin.ignore();

    Event currentEvent(eName, reqPts);
    cout << "\n--- Echipe calificate pentru " << currentEvent.getName() << " ---\n";
    
    bool found = false;
    for (int i = 0; i < teamCount; i++) {
        if (teams[i]->checkQualification(currentEvent)) {
            cout << "- " << teams[i]->getName() << " (" << teams[i]->getPoints() << " puncte)\n";
            found = true;
        }
    }
    if (!found) cout << "Nicio echipa nu indeplineste pragul de " << reqPts << " puncte.\n";
}

void Menu::showPlayerStats() {
    if (teamCount == 0) {
        cout << "Nu exista jucatori inregistrati.\n";
        return;
    } 
    cout << "\n[INFO] Total jucatori inregistrati in baza de date: " << Player::getTotalPlayers() << endl;
    Player* toti_jucatorii[500];
    int total_jucatori = 0;
    for (int i = 0; i < teamCount; i++) {
        toti_jucatorii[total_jucatori++] = teams[i]->getP1();
        toti_jucatorii[total_jucatori++] = teams[i]->getP2();
        toti_jucatorii[total_jucatori++] = teams[i]->getP3();
        toti_jucatorii[total_jucatori++] = teams[i]->getP4();
        toti_jucatorii[total_jucatori++] = teams[i]->getP5();
    }
    for (int i = 0; i < total_jucatori - 1; i++) {
        for (int j = 0; j < total_jucatori - i - 1; j++) {
            if (toti_jucatorii[j]->getRating() < toti_jucatorii[j + 1]->getRating()) {
                Player* temp = toti_jucatorii[j];
                toti_jucatorii[j] = toti_jucatorii[j + 1];
                toti_jucatorii[j + 1] = temp;
            }
        }
    }
    cout << "\n================ CLASAMENT JUCATORI (TOP RATING) ================\n";
    cout << "Pozitie | Nume Jucator         | Rating | Meciuri \n";
    cout << "-----------------------------------------------------------------\n";
    
    for (int i = 0; i < total_jucatori; i++) {
        printf("%-3d | %-20s | %-6.2f | %-7.0f\n", 
               i + 1, 
               toti_jucatorii[i]->getName(), 
               toti_jucatorii[i]->getRating(), 
               toti_jucatorii[i]->getNoMatches());
    }
    cout << "=================================================================\n";
}

Menu::~Menu() {
    for(int i = 0; i < teamCount; i++) {
        if(teams[i] != NULL) {
            delete teams[i]->getP1();
            delete teams[i]->getP2();
            delete teams[i]->getP3();
            delete teams[i]->getP4();
            delete teams[i]->getP5();
            delete teams[i];
        }
    }
}