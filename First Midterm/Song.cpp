//
// Created by Jovan on 29.12.2024.
//

/*
Да се дефинира класата Pesna во која се чуваат информации за (5 поени):

име на песна (динамички алоцирано поле од знаци)
времетраење на песната во минути
тип на песна кој може да биде: поп, рап или рок (енумерација tip)
Да се обезбедат сите потребни методи за класата за правилно функционирање на програмата. (10 поени)

Дополнително за оваа класа да се дефинира методот:

pecati() - функција во која ќе се печатат одделени со цртичка(-): името на песната во наводници и времетраењето на песната со постфикс min. (5 поени)
Да се креира класата CD во која се чуваат информации за (5 поени):

низа од песни снимени на CD-то (Поле од најмногу 10 објекти од класата Pesna )
број на песни снимени на CD-то
максимално времетраење на песните на CD-то (во минути)
Да се обезбедат сите потребни методи за класата за правилно функционирање на програмата. (5 поени)

Дополнително за оваа класа да се дефинираат методите:

dodadiPesna (Pesna p) - со кој се додава песната p на CDто, но само ако има доволно преостанато место (земајќи го предвид максималното времетраење на песните на CDто и времетраењата на песните на CD-то) и ако има помалку од 10 песни на CD-то. (10 поени)
pecatiPesniPoTip(tip t) – со кој се печатат информациите за сите песни од тип t (поп, рап или рок). (10 поени)
Комплетна функционалност (5 поени).

For example:

Input
3
4
Happy 5 0
Layla 8 2
Stan 4 1
Revolution 7 2
Result
===== Testiranje na metodot dodadiPesna() od klasata CD ======
"Happy"-5min
"Layla"-8min
"Stan"-4min
 */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

enum tip {
    pop, rap, rok
};

class Pesna {
private:
    char *ime;
    int minuti;
    tip t;
public:
    Pesna () {
        this->ime = new char[1];
        strcpy(this->ime, "");
        this->minuti = 0;
        this->t = pop;
    }
    Pesna (char *ime, int minuti,enum tip t) {
        this->ime = new char[strlen(ime)+1];
        strcpy (this->ime, ime);
        this->minuti = minuti;
        this->t = t;
    }
    Pesna (const Pesna &objekt) {
        this->ime = new char[strlen(objekt.ime)+1];
        strcpy (this->ime, objekt.ime);
        this->minuti = objekt.minuti;
        this->t = objekt.t;
    }
    Pesna &operator=(const Pesna &objekt){
        if (this!=&objekt){
            delete [] ime;
            this->ime = new char[strlen(objekt.ime)+1];
            strcpy (this->ime, objekt.ime);
            this->minuti = objekt.minuti;
            this->t = objekt.t;
        }
        return *this;
    }
    ~Pesna () {
        delete [] ime;
    }

    void pecati () {
        cout <<"\""<<ime<<"\""<<"-"<<minuti<<"min"<<endl;
    }

    int get_min () {
        return minuti;
    }

    tip get_t () {
        return t;
    }
};

class CD {
private:
    Pesna pesni[10];
    int br_pesni;
    int maks_vremetraenje;
public:
    CD () {
        this->br_pesni=0;
        this->maks_vremetraenje=0;
    }
    CD (int maks_vremetraenje) {
        br_pesni =0;
        this->maks_vremetraenje = maks_vremetraenje;
    }
    CD (const CD &c){
        br_pesni = c.br_pesni;
        for (int i=0; i<br_pesni; i++){
            pesni[i] = c.pesni[i];
        }
        maks_vremetraenje = c.maks_vremetraenje;
    }

    CD &operator=(CD &c){
        if (this!=&c) {
            br_pesni = c.br_pesni;
            for (int i=0; i<br_pesni; i++){
                pesni[i] = c.pesni[i];
            }
            maks_vremetraenje = c.maks_vremetraenje;
        }
        return *this;
    }

    ~CD () {
    }

    void dodadiPesna (Pesna p) {
        int mometalno_min =0;
        for (int i=0; i<br_pesni; i++){
            mometalno_min += pesni[i].get_min();
        }
        if (br_pesni >= 10 || mometalno_min + p.get_min() > maks_vremetraenje){
            return;
        }
        else{
            pesni[br_pesni] = p;
            br_pesni++;
        }
    }

    void pecatiPesniPoTip (enum tip t) {
        for (int i=0; i<br_pesni; i++){
            if (pesni[i].get_t() == t){
                pesni[i].pecati();
            }
        }
    }

    Pesna getPesna (int i) {
        return pesni[i];
    }

    int getBroj () {
        return br_pesni;
    }
};


int main(){
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, minuti, kojtip;
    char ime[50];

    if(testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime,minuti,(tip)kojtip);
        p.pecati();
    } else if(testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i=0; i<n; i++)
            (omileno.getPesna(i)).pecati();
    }
    else if(testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i=0; i<omileno.getBroj(); i++)
            (omileno.getPesna(i)).pecati();
    }
    else if(testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }
    else if(testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin>>n;
        for (int i=0;i<n;i++){
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime,minuti,(tip)kojtip);
            omileno.dodadiPesna(p);
        }
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }

    return 0;
}