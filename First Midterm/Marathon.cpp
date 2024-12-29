//
// Created by Jovan on 29.12.2024.
//

/*
Да се дефинира класа Ucesnik за учесник во маратон за кој ќе се чуваат информации за:

име (динамички алоцирана низа од знаци)
пол (bool)
возраст (цел број) (5 поени).
За потребите на оваа класа да се преоптоварат потребните конструктори и да се напише соодветен деструктор. (10 поени)

Дополнително за оваа класа да се преоптоварат:

оператор за споредување > (споредува двајца учесници според возраста) (5 поени)
операторот за проследување на излезен тек << кој ќе ги печати името, полот (машки/женски) и возраста, секој во посебен ред. (5 поени)
Да се дефинира класа Maraton за кој се чуваат:

локација (низа од максимум 100 знаци)
низа од Ucesnik објекти (динмички алоцирана низа од објекти од класата Ucesnik)
број на учесници (цел број) (5 поени).
За потребите на оваа класа да се преоптоварат потребните конструктори и да се напише соодветен деструктор. (10 поени) Исто така да се имплементираат следните методи:

оператор += за додавање нов Ucesnik на маратонот Maraton. (10 поени)
prosecnoVozrast() вреќа просечена возраст на учесниците на маратонот (5 поени)
pecatiPomladi(Ucesnik &u) ги печати сите учесници помлади од учесникот проследен како аргумент на методот. (5 поени)
For example:

Input
5
Skopje
Elena 0 23
Mitko 1 41
Iskra 0 31
Jovan 1 28
Zoran 1 40
Result
Elena
zhenski
23
Iskra
zhenski
31
Jovan
mashki
28
 */

#include <iostream>
#include <cstring>
using namespace std;

class Ucesnik {
private:
    char *ime;
    bool pol;
    int vozrast;
public:
    Ucesnik () {
        ime = new char[0];
        pol =false;
        vozrast =0;
    }
    Ucesnik (char *ime, bool pol, int vozrast){
        this->ime = new char[strlen(ime)+1];
        strcpy(this->ime, ime);
        this->pol = pol;
        this->vozrast = vozrast;
    }
    Ucesnik (const Ucesnik &u){
        this->ime = new char[strlen(u.ime)+1];
        strcpy(this->ime, u.ime);
        this->pol = u.pol;
        this->vozrast = u.vozrast;
    }
    Ucesnik &operator=(const Ucesnik &u){
        if (this!=&u){
            delete [] ime;
            this->ime = new char[strlen(u.ime)+1];
            strcpy(this->ime, u.ime);
            this->pol = u.pol;
            this->vozrast = u.vozrast;
        }
        return *this;
    }
    ~Ucesnik() {
        delete [] ime;
    }

    bool operator>(const Ucesnik &u1){
        if (vozrast > u1.vozrast)
            return true;
        else
            return false;
    }

    friend ostream &operator<<(ostream &output, const Ucesnik &u){
        output << u.ime <<endl;
        if (u.pol == false)
            output <<"zhenski"<<endl;
        else
            output <<"mashki"<<endl;
        output << u.vozrast <<endl;
        return output;
    }

    int getAge () {
        return vozrast;
    }
};

class Maraton {
private:
    char lokacija[100];
    Ucesnik *ucesnici;
    int n;
public:
    Maraton () {
        lokacija[0]='\0';
        ucesnici = new Ucesnik[0];
        n=0;
    }
    Maraton (char *lokacija){
        strcpy(this->lokacija, lokacija);
        ucesnici = new Ucesnik[0];
        n=0;
    }
    Maraton (const Maraton &m){
        strcpy(this->lokacija, m.lokacija);
        ucesnici = new Ucesnik[m.n];
        n=m.n;
        for (int i=0; i<n; i++){
            ucesnici[i] = m.ucesnici[i];
        }
    }
    Maraton &operator=(const Maraton &m){
        if (this!=&m){
            delete [] ucesnici;
            strcpy(this->lokacija, m.lokacija);
            ucesnici = new Ucesnik[m.n];
            n=m.n;
            for (int i=0; i<n; i++){
                ucesnici[i] = m.ucesnici[i];
            }
        }
        return *this;
    }
    ~Maraton() {
        delete [] ucesnici;
    }

    Maraton &operator+=(const Ucesnik &u){
        Ucesnik *temp= new Ucesnik[n+1];
        for (int i=0; i<n; i++){
            temp[i] = ucesnici[i];
        }
        temp[n] = u;
        delete [] ucesnici;
        ucesnici = temp;
        n++;
        return *this;
    }

    float prosecnoVozrast() {
        float zbir=0;
        for (int i=0; i<n; i++){
            zbir += ucesnici[i].getAge();
        }
        return float((zbir*1.0/n*1.0)*1.0);
    }

    void pecatiPomladi(Ucesnik &u){
        for (int i=0; i<n; i++){
            if (ucesnici[i].getAge() < u.getAge())
                cout <<ucesnici[i];
        }
    }
};

int main() {
    char ime[100];
    bool maski;
    int vozrast, n;
    cin >> n;
    char lokacija[100];
    cin >> lokacija;
    Maraton m(lokacija);
    Ucesnik **u = new Ucesnik*[n];
    for(int i = 0; i < n; ++i) {
        cin >> ime >> maski >> vozrast;
        u[i] = new Ucesnik(ime, maski, vozrast);
        m += *u[i];
    }
    m.pecatiPomladi(*u[n - 1]);
    cout << m.prosecnoVozrast() << endl;
    for(int i = 0; i < n; ++i) {
        delete u[i];
    }
    delete [] u;
    return 0;
}