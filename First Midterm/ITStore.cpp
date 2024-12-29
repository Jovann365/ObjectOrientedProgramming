//
// Created by Jovan on 29.12.2024.
//

/*
Во програмскиот јазик C++ да се креира структура Laptop за опишување на спецификациите на даден преносен компјутер. Структурата треба да содржи: (5 поени)

Фирма која го произведува ( низа од 100 знаци)
Големина на монитор во инчи (реален број)
Дали е со touch или не (булова променлива)
Цена (цел број)
Да се креира структура ITStore, што содржи: (5 поени)

Име на продавницата (низа од 100 знаци)
Локација (низа од 100 знаци)
Низа од достапни лаптопи (низа од максимум 100 елементи од структурата Laptop)
Број на елементи во низата (цел број)
Да се креира функција print за печатење на информациите за сите лаптопи во една продавница во формат: (10 поени)

[Ime na prodavnicata] [Lokacija]
[Marka1] [dim_monitor1] [Cena1]
[Marka2] [dim_monitor2] [Cena2]
[Marka3] [dim_monitor3] [Cena3]
...
Да се креира функција najeftina_ponuda, што прима низа од променливи од типот ITStore и го печати името и локацијата на онаа продавница која нуди најевтин преносен компјутер и неговата цена. Најефтин преносен компјутер е оној што има најниска цена и плус опција за touch. Ако има повеќе такви продавници, се печати прво најдената.* (15 поени)*

Да се дополни функцијата main (10 поени).

Од тастатура се внесува бројот на продавници, па потоа за секоја продавница се внесуваат името и локацијата, а потоа бројот на компјутери, па за секој од компјутерите фирма која го произведува, големина на монитор, дали има touch и цена. Потоа се печатат сите внесени продавници и најевтината понуда.

For example:

Input
2
AMC
Skopje
3
dell
13.1
1
32500
asus
15.0
0
20200
hp
13.1
1
42000
Anhoch
Skopje
1
asus
13.3
1
32000
Result
AMC Skopje
dell 13.1 32500
asus 15 20200
hp 13.1 42000
Anhoch Skopje
asus 13.3 32000
Najeftina ponuda ima prodavnicata:
Anhoch Skopje
Najniskata cena iznesuva: 32000
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;

struct Laptop {
    char firma[100];
    float golemina;
    bool touch;
    int cena;
};

struct ITStrore {
    char ime[100];
    char lokacija[100];
    Laptop laptopi[100];
    int br_laptopi;
};

void print (ITStrore *prod, int n){
    for (int i=0; i<n; i++){
        cout <<prod[i].ime<<" "<<prod[i].lokacija<<endl;
        for (int j=0; j<prod[i].br_laptopi; j++){
            cout <<prod[i].laptopi[j].firma<<" "<<prod[i].laptopi[j].golemina<<" "<<prod[i].laptopi[j].cena<<endl;
        }
    }
}

void najeftina_ponuda (ITStrore *prod, int n){
    ITStrore najeftin = prod[0];
    int najniska_cena=INT_MAX;
    for (int i=0; i<1; i++){
        for (int j=0; j<prod[i].br_laptopi; j++){
            if (prod[i].laptopi[j].touch == 1) {
                if (prod[i].laptopi[j].cena < najniska_cena)
                    najniska_cena = prod[i].laptopi[j].cena;
            }
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<prod[i].br_laptopi; j++){
            if (prod[i].laptopi[j].touch == 1) {
                if (prod[i].laptopi[j].cena < najniska_cena) {
                    najniska_cena = prod[i].laptopi[j].cena;
                    najeftin = prod[i];
                }
            }
        }
    }
    cout <<"Najeftina ponuda ima prodavnicata: "<<endl;
    cout <<najeftin.ime<<" "<<najeftin.lokacija<<endl;
    cout <<"Najniskata cena iznesuva: ";
    cout <<najniska_cena;
}

int main() {
    int n;
    cin >>n;
    ITStrore prodavnici[n];
    for (int i=0; i<n; i++) {
        cin >>prodavnici[i].ime;
        cin >>prodavnici[i].lokacija;
        cin >>prodavnici[i].br_laptopi;
        for (int j=0; j<prodavnici[i].br_laptopi; j++){
            cin >>prodavnici[i].laptopi[j].firma;
            cin >>prodavnici[i].laptopi[j].golemina;
            cin >>prodavnici[i].laptopi[j].touch;
            cin >>prodavnici[i].laptopi[j].cena;
        }
    }
    print(prodavnici, n);
    najeftina_ponuda(prodavnici, n);
    return 0;
}