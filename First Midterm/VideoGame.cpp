//
// Created by Jovan on 29.12.2024.
//

/*
Да се креира структура Igrac во која се чуваат податоци за еден играч на компјутерската игра. За играчот се чуваат информации за корисничкото име на играчот (низа од 15 знаци), број на ниво до кој играчот е стигнат (цел број) и број на освоени поени (цел број) (10 поени).

Потоа да се креирa структура KompjuterskaIgra во која се чуваат податоци за името на играта (низа од 20 знаци), низа од играчи кои ја играат играта (најмногу 30) и бројот на играчи. (10 поени)

Треба да се направи функција со потпис (15 поени)

void najdobarIgrac(KompjuterskaIgra *lista, int n)
Оваа функција треба да го испечати името на најдобриот играч на онаа игра која има најголема популарност (ја играат наjголем број на играчи). Најдобар играч е играчот кој има најголем број на освоени поени. Ако има повеќе играчи со ист максимален број на освоени поени, најдобар е играчот кој има достигнато најголемо ниво.

Печатењето е во форматот: "Najdobar igrac e igracot so korisnicko ime XXXXX koj ja igra igrata YYYYYY". (XXXXXX е корисничкото име на најдобриот играч,а YYYYY е името на играта која ја играат најголем број на играчи)

(Забелешка: секогаш ќе има точно еден најдобар играч)

Функционалност на задачата и дополнување на main функцијата (10 поени)

Забелешка: Задачата да се реши во програмскиот јазик C+

For example:

Input
2
Snake
2
user1 5 120
user2 4 120
Cars
3
koliubavi 5 130
fikjo 3 150
motor 4 140
Result
Najdobar igrac e igracot so korisnicko ime fikjo koj ja igra igrata Cars
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;

struct Igrac {
    char ime[15];
    int nivo;
    int poeni;
};

struct KompjuterskaIgra {
    char ime[20];
    Igrac igraci[30];
    int br_igraci;
};

void najdobarIgrac(KompjuterskaIgra *lista, int n){
    KompjuterskaIgra najpopularna = lista[0];
    int najmnogu = najpopularna.br_igraci;
    for (int i=0; i<n; i++){
        if (lista[i].br_igraci > najmnogu){
            najmnogu = lista[i].br_igraci;
            najpopularna = lista[i];
        }
    }

    Igrac najdobar = najpopularna.igraci[0];
    int naj_poeni = najdobar.poeni;
    for (int i=0; i<najpopularna.br_igraci; i++){
        if (najpopularna.igraci[i].poeni > naj_poeni){
            naj_poeni = najpopularna.igraci[i].poeni;
            najdobar = najpopularna.igraci[i];
        }
    }

    cout <<"Najdobar igrac e igracot so korisnicko ime "<<najdobar.ime<<" koj ja igra igrata "<<najpopularna.ime<<endl;
}

int main() {
    int n;
    cin >>n;
    KompjuterskaIgra igri[n];
    for (int i = 0; i < n; ++i) {
        cin >>igri[i].ime;
        cin >>igri[i].br_igraci;
        for (int j = 0; j < igri[i].br_igraci; ++j) {
            cin >>igri[i].igraci[j].ime;
            cin >>igri[i].igraci[j].nivo;
            cin >> igri[i].igraci[j].poeni;
        }
    }
    najdobarIgrac(igri, n);
    return 0;
}