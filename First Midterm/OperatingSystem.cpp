//
// Created by Jovan on 29.12.2024.
//

/*
Фирмата FINKI Cloud има потреба од решение за управување со image датотеките од различните оперативни системи кои ги користат при сетирање на нови сервери. За таа цел потребно е да се дефинираат следниве класи:

OperativenSistem
Во класата OperativenSistem треба да се чуваат следниве податоци:

име на оперативниот систем (динамички алоцирана низа од знаци)
верзија (float)
тип (енумерација со можни вредности LINUX, UNIX, WINDOWS)
големина (во GB) (float)
Дополнително, во рамките на класата потребно е да се дефинира:

конструктори со и без параметри
copy constructor
destructor
преоптоварување на операторот =
метод за печатење на информациите - void pecati() (видете го излезот од тест примерите за структурата)
метод за проверка на еднаквост помеѓу два оперативни системи (два оперативни системи се еднакви ако имаат исто име, верзија, тип и големина) - bool ednakviSe(const OperativenSistem &os)
метод за споредба на верзии помеѓу два оперативни система - int sporediVerzija(const OperativenSistem &os), кој ќе враќа 0 доколку верзиите се исти, -1 доколку верзијата на оперативниот систем од аргументот е поголема и 1 во преостанатиот случај.
метод за проверка дали два оперативни системи се од иста фамилија. Два оперативни системи се од иста фамилија доколку имаат исто име и се од ист тип. bool istaFamilija(const OperativenSistem &sporedba)
Repozitorium
Во класата Repozitorium треба да се чуваат следниве податоци:

име на репозиториумот (низа од 20 знака)
динамички алоцирана низа од OperativenSistem
број на оперативни системи кои моментално се наоѓаат во репозиториумот (int)
Дополнително, во рамките на класата потребно е да се дефинира:

конструктор Repozitorium(const char *ime)
деструктор
метод void pecatiOperativniSistemi() кој ќе ги печати сите оперативни системи кои се дел од репозиториумот
метод void izbrishi(const OperativenSistem &operativenSistem) кој ќе го избрише оперативниот систем проследен како аргумент, доколку тој се наоѓа во репозиториумот. Да се користи методот ednakviSe за споредба на два оперативни система.
метод за додавање на оперативен систем (void dodadi(const OperativenSistem &nov)) кој ќе го има следново однесување:
Доколку веќе постои оперативен систем од иста фамилија (да се користи методот за проверка на фамилија) кој е постар од проследениот оперативен систем, тогаш постоечкиот оперативен систем се заменува со новиот.
Во секој друг случај, проследениот оперативен систем се додава како дополнителен во репозиториумо

Input
FINKICloud
2
Ubuntu
17.04
1
2.25
Ubuntu
16.04
1
1.25
Ubuntu
14.04
1
1.25
Result
Repozitorium: FINKICloud
Ime: Ubuntu Verzija: 17.04 Tip: 1 Golemina:2.25GB
Ime: Ubuntu Verzija: 16.04 Tip: 1 Golemina:1.25GB
=====Brishenje na operativen sistem=====
Repozitorium: FINKICloud
Ime: Ubuntu Verzija: 17.04 Tip: 1 Golemina:2.25GB
Ime: Ubuntu Verzija: 16.04 Tip: 1 Golemina:1.25GB
 */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

enum Tip {LINUX, UNIX, WINDOWS};

class OperativenSistem {
private:
    char *ime;
    float verzija;
    Tip t;
    float golemina;
public:
    OperativenSistem () {
        ime = new char[1];
        ime[1] = '\0';
        verzija=0;
        t=LINUX;
        golemina=0;
    }
    OperativenSistem (char *ime, float verzija, enum Tip t, float golemina){
        this->ime = new char[strlen(ime)+1];
        strcpy(this->ime, ime);
        this->verzija = verzija;
        this->t = t;
        this->golemina = golemina;
    }
    OperativenSistem (const OperativenSistem &os) {
        this->ime = new char[strlen(os.ime)+1];
        strcpy(this->ime, os.ime);
        this->verzija = os.verzija;
        this->t = os.t;
        this->golemina = os.golemina;
    }
    OperativenSistem &operator=(const OperativenSistem &os){
        if (this!=&os){
            delete [] ime;
            this->ime = new char[strlen(os.ime)+1];
            strcpy(this->ime, os.ime);
            this->verzija = os.verzija;
            this->t = os.t;
            this->golemina = os.golemina;
        }
        return *this;
    }
    ~OperativenSistem() {
        delete [] ime;
    }
    void pecati () {
        cout <<"Ime: "<<ime<<" Verzija: "<<verzija<<" Tip: "<<t<<" Golemina:"<<golemina<<"GB"<<endl;
    }
    bool ednakviSe(const OperativenSistem &os) {
        if (strcmp(ime, os.ime)==0
        && verzija == os.verzija
        && t == os.t
        && golemina == os.golemina)
            return true;
        else
            return false;
    }
    int sporediVerzija(const OperativenSistem &os) {
        if (verzija == os.verzija)
            return 0;
        else if (os.verzija > verzija)
            return -1;
        else return 1;
    }
    bool istaFamilija(const OperativenSistem &os) {
        if (strcmp(os.ime, ime)==0 && t == os.t)
            return true;
        else
            return false;
    }
};

class Repozitorium {
private:
    char ime[20];
    OperativenSistem *operativen;
    int n;
public:
    Repozitorium () {
        ime[0] = '\0';
        n=0;
        operativen = new OperativenSistem[n];
    }
    Repozitorium(char *ime) {
        strcpy(this->ime, ime);
        n =0;
        operativen = new OperativenSistem[n];
    }
    Repozitorium (const Repozitorium &r){
        strcpy(this->ime, r.ime);
        this->n = r.n;
        this->operativen = new OperativenSistem[n];
        for (int i=0; i<n; i++){
            this->operativen[i] = r.operativen[i];
        }
    }
    Repozitorium &operator=(const Repozitorium &r){
        if (this!=&r){
            delete [] operativen;
            strcpy(this->ime, r.ime);
            this->n = r.n;
            this->operativen = new OperativenSistem[n];
            for (int i=0; i<n; i++){
                this->operativen[i] = r.operativen[i];
            }
        }
        return *this;
    }
    ~Repozitorium() {
        delete [] operativen;
    }

    void pecatiOperativniSistemi() {
        cout <<"Repozitorium: "<<ime<<endl;
        for (int i=0; i<n; i++){
            operativen[i].pecati();
        }
    }

    void dodadi(const OperativenSistem &nov) {
        for (int i=0; i<n; i++){
            if (operativen[i].istaFamilija(nov) && operativen[i].sporediVerzija(nov)==-1) {
                operativen[i] = nov;
                return;
            }
        }
        OperativenSistem *temp = new OperativenSistem[n+1];
        for (int i=0; i<n; i++){
            temp[i] = operativen[i];
        }
        temp[n] = nov;
        delete [] operativen;
        operativen = temp;
        n++;
    }

    void izbrishi(const OperativenSistem &os) {
        for (int i=0; i<n; i++){
            if (operativen[i].ednakviSe(os)){
                OperativenSistem *temp = new OperativenSistem[n-1];
                int br=0;
                for (int j=0; j<n; j++){
                    if (!operativen[j].ednakviSe(os)){
                        temp[br] = operativen[j];
                        br++;
                    }
                }
                delete [] operativen;
                operativen = temp;
                n--;
            }
        }
    }
};

int main(){
    char repoName[20];
    cin>>repoName;
    Repozitorium repozitorium=Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin>>brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i<brojOperativniSistemi; i++){
        cin>>ime;
        cin>>verzija;
        cin>>tip;
        cin>>golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
    cin>>ime;
    cin>>verzija;
    cin>>tip;
    cin>>golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
    cout<<"=====Brishenje na operativen sistem====="<<endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}