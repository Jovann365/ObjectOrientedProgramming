//
// Created by Jovan on 29.12.2024.
//

/*
Да се дефинира класа Пица за која ќе се чуваат податоци за:

име на пицата (низа од 15 знаци)
цена (цел број)
состојки (динамички алоцирана низа од знаци)
намалување на цената во проценти (цел број) - ако пицата не е на промоција намалувањето има вредност нула, во спротивно, вредност поголема од нула и не поголема од 100.
За потребите на оваа класа да се креираат потребните конструктори и да се напише соодветен деструктор. Дополнително за оваа класа да се дефинира функцијата:

pecati() - функција во која ќе се печатат податоците за пицата во следниот формат: име - состојки, цена.
istiSe(Pica p) - функција за споредба на две пици според состојките :
Да се дефинира класа Picerija во која се чуваат:

име (низа од максимум 15 знаци)
динмички алоцирана низа од објекти од класата Pica
број на пици (цел број)
За потребите на оваа класа да се дефинираат потребните конструктори и да се напише соодветен деструктор. Да се имплементираат и следниве методи:

dodadi(Pica P) - за додавање нова пица во пицеријата, но само ако не постои иста во низата (нема пица со исти состојки со пицата што треба да се додаде).
void piciNaPromocija() - се печатат сите пици од пицеријата што се на промоција во формат : име - состојки, цена, цена со попуст.
For example:

Input
FINKI-Pica
4
Margarita
200
Domaten sos, kaskaval, maslinovo maslo
0
Napolitana
210
Domaten sos, kaskaval, svezi sampinjoni, maslinovo maslo
0
Kapricioza
210
Domaten sos, kaskaval, sunka, svezi sampinjoni
30
Vegetarijana
230
Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka
20
Pica-FINKI
Vegetarijana
230
Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka
20
Result
FINKI-Pica
Pici na promocija:
Kapricioza  - Domaten sos, kaskaval, sunka, svezi sampinjoni, 210 147
Vegetarijana - Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka, 230 184
Pica-FINKI
Pici na promocija:
Kapricioza  - Domaten sos, kaskaval, sunka, svezi sampinjoni, 210 147
Vegetarijana - Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka, 230 184
 */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Pica {
private:
    char ime[15];
    int cena;
    char *sostojki;
    int namaluvanje;
public:
    Pica () {
        ime[0]='\0';
        cena = 0;
        sostojki = new char[0];
        namaluvanje =0;
    }
    Pica (char *ime, int cena, char *sostojki, int namaluvanje) {
        strcpy(this->ime, ime);
        this->cena = cena;
        this->sostojki = new char[strlen(sostojki)+1];
        strcpy(this->sostojki, sostojki);
        this->namaluvanje = namaluvanje;
    }
     Pica(const Pica &p){
        strcpy(this->ime, p.ime);
        this->cena = p.cena;
        this->sostojki = new char[strlen(p.sostojki)+1];
        strcpy(this->sostojki, p.sostojki);
        this->namaluvanje =p.namaluvanje;
    }
     Pica&operator=(const Pica &p) {
        if (this!=&p) {
            delete [] sostojki;
            strcpy(this->ime, p.ime);
            this->cena = p.cena;
            this->sostojki = new char[strlen(p.sostojki)+1];
            strcpy(this->sostojki, p.sostojki);
            this->namaluvanje =p.namaluvanje;
        }
        return *this;
    }
    ~Pica () {
        delete [] sostojki;
    }
    bool istiSe (Pica &p) {
        if (strcmp(ime, p.ime)==0 && cena == p.cena && strcmp(sostojki, p.sostojki)==0 && namaluvanje == p.namaluvanje)
            return true;
        else
            return false;
    }
    int get_namaluvanje () {
        return namaluvanje;
    }
    void pecati () {
        cout <<ime<<" - "<<sostojki<<", "<<cena<<" "<<float(cena - (cena*namaluvanje)/100.0)<<endl;
    }
};

class Picerija {
private:
    char ime[15];
    Pica *pici;
    int n;
public:
    Picerija () {
        ime[0]='\0';
        pici = new Pica[0];
        n = 0;
    }
    Picerija (char *ime) {
        strcpy(this->ime, ime);
        pici = new Pica[0];
        n =0;
    }
    Picerija (const Picerija &pi) {
        strcpy(this->ime, pi.ime);
        pici = new Pica[pi.n];
        n = pi.n;
        for (int i=0; i<pi.n; i++){
            pici[i] = pi.pici[i];
        }
    }
    Picerija &operator=(const Picerija &pi) {
        if (this!=&pi) {
            delete [] pici;
            strcpy(this->ime, pi.ime);
            pici = new Pica[pi.n];
            n = pi.n;
            for (int i = 0; i < pi.n; i++) {
                pici[i] = pi.pici[i];
            }
        }
        return *this;
    }
    ~Picerija() {
        delete [] pici;
    }
    void operator+=(Pica p) {
        for (int i=0; i<n; i++){
            if (pici[i].istiSe(p))
                return;
        }
        Pica *temp = new Pica[n+1];
        for (int i=0; i<n; i++){
            temp[i] = pici[i];
        }
        temp[n] = p;
        delete [] pici;
        pici = temp;
        n++;
    }
    void piciNaPromocija() {
        for (int i=0; i<n; i++){
            if (pici[i].get_namaluvanje() > 0)
                pici[i].pecati();
        }
    }
    void setIme (char *ime) {
        strcpy (this->ime, ime);
    }
    char *getIme () {
        return ime;
    }
};

int main(){
    int n;
    char ime[15];
    cin >> ime;
    cin >> n;

    Picerija p1(ime);
    for (int i = 0; i < n; i++){
        char imp[100];
        cin.get();
        cin.getline(imp, 100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki, 100);
        int popust;
        cin >> popust;
        Pica p(imp, cena, sostojki, popust);
        p1+=p;
    }

    Picerija p2 = p1;
    cin >> ime;
    p2.setIme(ime);
    char imp[100];
    cin.get();
    cin.getline(imp, 100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki, 100);
    int popust;
    cin >> popust;
    Pica p(imp, cena, sostojki, popust);
    p2+=p;

    cout << p1.getIme() << endl;
    cout << "Pici na promocija:" << endl;
    p1.piciNaPromocija();

    cout << p2.getIme() << endl;
    cout << "Pici na promocija:" << endl;
    p2.piciNaPromocija();

    return 0;
}