//
// Created by Jovan on 29.12.2024.
//

/*
Да се креира структура Воз во која се чуваат податоци за релацијата по која се движи возот (низа од најмногу 50 знаци), предвиден бројот на километри што треба да се поминат (реален број), како и бројот на патници во возот (цел број).

Потоа да се креирa структура ZeleznickaStanica во која се чуваат податоци за градот во кој се наоѓа (низа од 20 знаци), низа од возови што поаѓаат од станицата (најмногу 30) и бројот на возови (цел број).

Треба да се направи функција со потпис

void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad)
во која се печати релацијата и бројот на километри на возот што поминува најкратка релација (најмалку километри), а поаѓа од железничката станица од градот што се проследува како влезен аргумент. Ако има повеќе возови со ист најмал број на километри, да се испечати релацијата на последниот таков.

Забелешка: Задачата да се реши во програмскиот јазик C++

For example:

Input
1
Dresden
2
Dresden-Berlin 192 200
Dresden-Lajpcig 115 90
Dresden
Result
Najkratka relacija: Dresden-Lajpcig (115 km)
 */


#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct Voz {
    char relazija[50];
    float kilometri;
    int patnici;
};

struct ZeleznickaStanica {
    char grad[20];
    Voz vozovi[30];
    int br_vozovi;
};

void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad) {
    Voz najkratok;
    for (int i=0; i<n; i++) {
        if (strcmp(zs[i].grad, grad) == 0) {
            najkratok = zs[i].vozovi[0];
            for (int j=1; j<zs[i].br_vozovi; j++){
                if (zs[i].vozovi[j].kilometri <= najkratok.kilometri)
                    najkratok = zs[i].vozovi[j];
            }
        }
    }
    cout <<"Najkratka relacija: "<<najkratok.relazija<<" ("<<najkratok.kilometri<<" km)"<<endl;
}

int main() {
    int n;
    cin>>n; //se cita brojot na zelezlnichki stanici

    ZeleznickaStanica zStanica[100];
    for (int i=0;i<n;i++){
        cin>>zStanica[i].grad;
        cin>>zStanica[i].br_vozovi;
        for (int j=0; j<zStanica[i].br_vozovi; j++){
            cin >>zStanica[i].vozovi[j].relazija;
            cin >>zStanica[i].vozovi[j].kilometri;
            cin >>zStanica[i].vozovi[j].patnici;
        }
    }

    char grad[25];
    cin>>grad;

    najkratkaRelacija(zStanica,n,grad);
    return 0;
}
