//
// Created by Jovan on 29.12.2024.
//

/*
Да се креира структура SkiLift во која се чуваат податоци за името на ски лифтот (низа од 15 знаци), максимален број на корисници што може да опслужи на едно возење, дали е пуштен во функција.

Потоа да се креирa структура SkiCenter во која се чуваат податоци за името на скијачкиот центар, држава во која се наоѓа (низи од 20 знаци), низа од ски лифтови (макс 20) што ги има и број на ски лифтови.

Треба да се направи функција со потпис

void najgolemKapacitet(SkiCenter *sc, int n)
која што ќе го отпечати ски центарот што има најголем капацитет за опслужување скијачи (вкупниот број на скијачи кои може да се опслужуваат во еден момент вкупно на сите ски лифтови во центарот). Доколку два ски центри имаат ист капацитет, тогаш се печати оној кој има поголем број на ски лифтови. Притоа треба да се испечатат во посебен ред името, државата и капацитетот на ски центарот. Кога се пресметува капацитет на еден ски центар во предвид се земаат само ски лифтовите кои се поставени дека се во функција.

For example:

Input
1
Mavrovo
Makedonija
6
Ednosed
30
1
Dvosed
60
1
Ciciban
10
1
Galicki
20
1
Belicki
36
0
Plavi
40
1
Result
Mavrovo
Makedonija
160
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

struct SkiLift {
    char ime[15];
    int maks_kor;
    bool vo_funkcija;
};

struct SkiCenter {
    char ime[20];
    char drzhava[20];
    SkiLift liftovi[20];
    int br_liftovi;
};

void najgolemKapacitet(SkiCenter *sc, int n) {\
    SkiCenter kapacitet;
    int maks_kapacitet;
    int flag=0;
    for (int i=0; i<n; i++){
        int maks_lugje = 0;
        if (flag==0) {
            for (int j = 0; j < sc[i].br_liftovi; j++){
                if (sc[i].liftovi[j].vo_funkcija == 1)
                    maks_lugje += sc[i].liftovi[j].maks_kor;
            }
            maks_kapacitet = maks_lugje;
            kapacitet = sc[i];
            flag ++;
        }
        else{
            for (int j = 0; j < sc[i].br_liftovi; j++){
                if (sc[i].liftovi[j].vo_funkcija == 1)
                    maks_lugje += sc[i].liftovi[j].maks_kor;
            }
            if (maks_lugje > maks_kapacitet){
                maks_kapacitet = maks_lugje;
                kapacitet = sc[i];
            }
            else if (maks_lugje == maks_kapacitet){
                if (sc[i].br_liftovi > kapacitet.br_liftovi){
                    kapacitet = sc[i];
                }
            }
        }
    }
    cout <<kapacitet.ime<<endl;
    cout <<kapacitet.drzhava<<endl;
    cout <<maks_kapacitet<<endl;
}

int main() {
    int n;
    cin >>n;
    SkiCenter sc[100];
    for (int i=0; i<n; i++){
        cin >>sc[i].ime;
        cin >>sc[i].drzhava;
        cin >>sc[i].br_liftovi;
        for (int j=0; j<sc[i].br_liftovi; j++){
            cin >>sc[i].liftovi[j].ime;
            cin >>sc[i].liftovi[j].maks_kor;
            cin >>sc[i].liftovi[j].vo_funkcija;
        }
    }
    najgolemKapacitet(sc, n);
    return 0;
}
