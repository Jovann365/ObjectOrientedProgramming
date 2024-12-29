//
// Created by Jovan on 29.12.2024.
//

/*
Во програмскиот јазик C++ да се креира структура Pacient и истата треба да содржи: (5 поени)

Име и презиме на пациентот ( низа од макс. 100 знаци)
Дали е здраствено осигуран (1-да, 0-не)
Број на прегледи во текот на последниот месец (цел број)
Да се креира структура MaticenDoktor, која во себе содржи: (5 поени)

Име на докторот (низа од 100 знаци)
Број на пациенти (цел број)
Листа од пациенти (низа од максимум 200 елементи од структурата Pacient)
Цена на преглед (децимален број)
Да се креираат метода najuspesen_doktor, која прима низа од променливи од типот MaticenDoktor и нивниот број; и го печати името, заработената сума и бројот на прегледи на оној доктор кој заработил најголема сума од пациенти кои ги прегледувал приватно (не се здраствено осигурани) (10 поени). Доколку два или повеќе доктори имаат иста сума, тогаш се печати оној доктор кој има направено најголем број на прегледи вкупно во текот на последниот месец. (20 поени)

Функционалност (5 поени).

For example:

Input
3
Д-р.Јованка_Јовановска
3
300.00
Јованова_Ивана 1 2
Боцевска_Ивана 0 3
Илиевска_Ангела 1 0
Д-р.Петко_Петковски
1
50.00
Ивановска_Цветанка 0 18
Д-р.Трајче_Трајчев
3
300.00
Крстевски_Филип 1 0
Цветановски_Иван 1 10
Ивановска_Цветанка 0 3
Result
Д-р.Петко_Петковски 900.00 18
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <stdio.h>
using namespace std;

struct Pacient{
    char ime[100];
    bool zdrastveno;
    int pregledi;
};

struct MaticenDoktor {
    char ime[100];
    int br_pac;
    Pacient niza[20];
    float cena;
};

void najuspesen_doktor (MaticenDoktor *md, int n){
    MaticenDoktor najdobar;
    int flag =0;
    float naj_suma=0;
    int naj_pregledi=0;
    for (int i=0; i<n; i++){
        int preg=0;
        float suma=0;
        if (flag ==0){
            for (int j=0; j<md[i].br_pac; j++){
                if (md[i].niza[j].zdrastveno == 0){
                    suma += md[i].cena*md[i].niza[j].pregledi;

                }
                 preg += md[i].niza[j].pregledi;
            }
            naj_suma = suma;
            najdobar = md[i];
            naj_pregledi = preg;
            flag ++;
        }
        else{
            int pregledi_md=0;
            for (int k=0; k<md[i].br_pac; k++){
                pregledi_md += md[i].niza[k].pregledi;
            }
            for (int j=0; j<md[i].br_pac; j++){
                if (md[i].niza[j].zdrastveno == 0){
                    suma += md[i].cena * md[i].niza[j].pregledi;
                }
            }
            if (suma > naj_suma){
                naj_suma = suma;
                najdobar = md[i];
                naj_pregledi = pregledi_md;
            }
            else if (suma == naj_suma){
                if (pregledi_md > naj_pregledi){
                    najdobar = md[i];
                    naj_pregledi = pregledi_md;
                }
            }
        }
    }
    cout <<najdobar.ime<<" "<<fixed<<setprecision(2)<<naj_suma<<" "<<naj_pregledi<<endl;
}


int main() {
    int n;
    MaticenDoktor md[20];
    cin >>n;
    for (int i=0; i<n; i++){
        cin >>md[i].ime;
        cin >>md[i].br_pac;
        cin >>md[i].cena;
        for (int j=0; j<md[i].br_pac; j++){
            cin >>md[i].niza[j].ime;
            cin >>md[i].niza[j].zdrastveno;
            cin >>md[i].niza[j].pregledi;
        }
    }
    najuspesen_doktor(md, n);
    return 0;
}