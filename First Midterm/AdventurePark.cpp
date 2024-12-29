//
// Created by Jovan on 29.12.2024.
//

/*
Во програмскиот јазик С++ да се креира структура Vozenje за опишување на адреналински возења во забавен парк. Структурата треба да содржи: (5 поени)

Име на возењето ( низа од 100 знаци)
Времетраење во минути (цел број)
Цена (децимален број)
Дали има студентски попуст (1-да, 0-не)
Да се креира структура ZabavenPark, што содржи: (10 поени)

Име на забавниот парк (низа од 100 знаци)
Локација (низа од 100 знаци)
Низа од адреналински возења во паркот (низа од максимум 100 елементи од структурата Vozenje)
Број на елементи во низата (цел број)
Да се креира функција print за печатење на информациите за сите возења во забавниот парк во формат: (10 поени)

[Ime na parkot] [Lokacija]
[Ime1] [Vremetraenje1] [Cena1]
[Ime2] [Vremetraenje2] [Cena2]
[Ime3] [Vremetraenje3] [Cena3]
...
Да се креира функција najdobar_park, што прима низа од променливи од типот ZabavenPark и го печати името и локацијата на паркот кој е најефтин за посета од страна на студенти. Најефтин парк е оној што содржи најголем број возења со студентски попуст. Ако повеќе паркови ги делат овие карактеристики, да се испечати паркот со најголемото времетраење од сите возења.* (20 поени)*

Да се дополни функцијата main (5 поени).

For example:

Input
2
Disneyland
Paris
2
BigThunderMountain
15
10
1
Shark
22
13
0
TivoliGardens
Copenhagen
3
Devil
16
11
1
FlyMountain
35
19
1
Nemo
8
7
0
Result
Disneyland Paris
BigThunderMountain 15 10.00
Shark 22 13.00
TivoliGardens Copenhagen
Devil 16 11.00
FlyMountain 35 19.00
Nemo 8 7.00
Najdobar park: TivoliGardens Copenhagen
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;

struct Vozenje {
    char ime[100];
    int traenje;
    float cena;
    bool daliPopust;
};

struct ZabavenPark {
    char ime[100];
    char lokacija[100];
    Vozenje niza[100];
    int n;
};

void pecati(ZabavenPark *park, int n){
    for (int i=0; i<n; i++) {
        cout << park[i].ime << " " << park[i].lokacija<<endl;
        for (int j = 0; j < park[i].n; j++) {
            cout << park[i].niza[j].ime << " " << park[i].niza[j].traenje << " " <<fixed<<setprecision(2)<< park[i].niza[j].cena << endl;
        }
    }
}

void najdobar_park (ZabavenPark *park, int n) {
    ZabavenPark najeftin;
    najeftin = park[0];
    int vozenja=0;
    int najgolemo_vremetraenje=0;
    for (int i=0; i<najeftin.n; i++){
        najgolemo_vremetraenje += najeftin.niza[i].traenje;
        if (najeftin.niza[i].daliPopust == 1)
            vozenja++;
    }
    for (int i=1; i<n; i++){
        int min_voz=0;
        int vremetraenje=0;
        for (int j=0; j<park[i].n; j++){
            vremetraenje += park[i].niza[j].traenje;
            if (park[i].niza[j].daliPopust == 1)
                min_voz++;
        }
        if (min_voz > vozenja){
            vozenja = min_voz;
            najeftin = park[i];
        }
        else if (min_voz == vozenja){
            if (vremetraenje >= najgolemo_vremetraenje) {
                najgolemo_vremetraenje = vremetraenje;
                najeftin = park[i];
            }
        }
    }
    cout <<"Najdobar park: "<<najeftin.ime<<" "<<najeftin.lokacija<<endl;
}

int main() {
    int i, j, n, broj;
    //kreiraj niza od maksimum 100 zabavni parkovi
    ZabavenPark ff[100];
    scanf("%d", &n);
    //citanje na podatocite
    for (i = 0; i < n; i++){
        //ime na festivalot
        scanf("%s", ff[i].ime);
        //mesto
        scanf("%s", ff[i].lokacija);
        //broj na filmovi
        scanf("%d", &ff[i].n);

        for (j = 0; j < ff[i].n; j++){
            scanf("%s", ff[i].niza[j].ime);  			/* Ime na filmot */
            scanf("%d", &ff[i].niza[j].traenje); 		/* Vremetraenje   */
            scanf("%f", &ff[i].niza[j].cena); 	/* Cena */
            scanf("%d", &ff[i].niza[j].daliPopust);	/* Popust */

        }


    }
    pecati(ff,n);
    najdobar_park(ff,n);
}