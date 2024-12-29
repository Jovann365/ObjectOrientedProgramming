//
// Created by Jovan on 29.12.2024.
//

/*
Input
3
Aleksandar
240992
3
CH0038863350
Nestle
100
90
100
DE000BAY0017
Bayer
60
70
500
DE0007164600
SAP
110
115
200
Result
=====TEST NA KLASATA Client=====
Konstruktor OK
Operator += OK
240992 67000
Nestle 100 100 90 -1000
Bayer 500 60 70 5000
SAP 200 110 115 1000
Operator << OK
 */

#include <iostream>
#include <cstring>
using namespace std;

class StockRecord {
private:
    char id[12];
    char ime[50];
    double cena;
    double momentalna_cena;
    int br_akcii;
public:
    StockRecord () {
        id[0] = '\0';
        ime[0] = '\0';
        cena = 0;
        br_akcii =0;
    }
    StockRecord (char *id, char *ime, double cena, int br_akcii) {
        strcpy(this->id, id);
        strcpy(this->ime, ime);
        this->cena = cena;
        this->br_akcii = br_akcii;
    }
    ~StockRecord() {}

    void setNewPrice(double np) {
        momentalna_cena = np;
    }

    double value() {
        return br_akcii*momentalna_cena;
    }

    double profit() {
        return br_akcii*(momentalna_cena - cena);
    }

    friend ostream &operator<<(ostream &output, StockRecord &sr){
        output <<sr.ime<<" "<<sr.br_akcii<<" "<<sr.cena<<" "<<sr.momentalna_cena<<" "<<sr.profit()<<endl;
        return output;
    }

    StockRecord &operator=(const StockRecord &sr){
        if (this!=&sr) {
            strcpy(ime, sr.ime);
            strcpy(this->ime, sr.ime);
            this->momentalna_cena = sr.momentalna_cena;
            this->cena = sr.cena;
            this->br_akcii = sr.br_akcii;
        }
        return *this;
    }
};

class Client {
private:
    char ime[60];
    int id;
    StockRecord *kompanii;
    int n;
public:
    Client () {
        ime[0]='\0';
        id =0;
        kompanii = new StockRecord[0];
        n=0;
    }
    Client (char *ime, int id){
        strcpy(this->ime, ime);
        this->id = id;
        kompanii = new StockRecord[0];
        n=0;
    }
    Client (const Client &cl){
        strcpy(this->ime, cl.ime);
        this->id = cl.id;
        kompanii = new StockRecord[cl.n];
        n=cl.n;
        for (int i=0; i<n; i++){
            kompanii[i] = cl.kompanii[i];
        }
    }
    Client &operator=(const Client &cl){
        if (this!=&cl){
            delete [] kompanii;
            strcpy(this->ime, cl.ime);
            this->id = cl.id;
            kompanii = new StockRecord[cl.n];
            n=cl.n;
            for (int i=0; i<n; i++){
                kompanii[i] = cl.kompanii[i];
            }
        }
        return *this;
    }
    ~Client () {
        delete [] kompanii;
    }

    const double totalValue () const{
        double zbir=0;
        for (int i=0; i<n; i++){
            zbir += kompanii[i].value();
        }
        return zbir;
    }

    Client &operator+=(const StockRecord &sr){
        StockRecord *temp = new StockRecord[n+1];
        for (int i=0; i<n; i++){
            temp[i] = kompanii[i];
        }
        temp[n] = sr;
        delete [] kompanii;
        kompanii = temp;
        n++;
        return *this;
    }

    friend ostream &operator<< (ostream &output, const Client &cl){
        output << cl.id <<" "<< cl.totalValue() <<endl;
        for (int i=0; i<cl.n; i++){
            output <<cl.kompanii[i];
        }
        return output;
    }
};

int main() {
    int test;
    cin >> test;

    if(test == 1){
        double price;
        cout << "=====TEST NA KLASATA StockRecord=====" << endl;
        StockRecord sr("1", "Microsoft", 60.0, 100);
        cout << "Konstruktor OK" << endl;
        cin >> price;
        sr.setNewPrice(price);
        cout << "SET metoda OK" << endl;
    }
    else if(test == 2){
        cout << "=====TEST NA METODITE I OPERATOR << OD KLASATA StockRecord=====" << endl;
        char id[12], company[50];
        double price, newPrice;
        int n, shares;
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> id;
            cin >> company;
            cin >> price;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(id, company, price, shares);
            sr.setNewPrice(newPrice);
            cout << sr.value() << endl;
            cout << sr;
        }
    }
    else if(test == 3){
        cout << "=====TEST NA KLASATA Client=====" << endl;
        char companyID[12], companyName[50], clientName[50];
        int clientID, n, shares;
        double oldPrice, newPrice;
        bool flag = true;
        cin >> clientName;
        cin >> clientID;
        cin >> n;
        Client c(clientName, clientID);
        cout << "Konstruktor OK" << endl;
        for(int i = 0; i < n; ++i){
            cin >> companyID;
            cin >> companyName;
            cin >> oldPrice;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(companyID, companyName, oldPrice, shares);
            sr.setNewPrice(newPrice);
            c += sr;
            if(flag){
                cout << "Operator += OK" << endl;
                flag = false;
            }
        }
        cout << c;
        cout << "Operator << OK" << endl;
    }
    return 0;

}