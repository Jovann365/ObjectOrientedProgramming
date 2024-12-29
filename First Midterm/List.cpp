//
// Created by Jovan on 29.12.2024.
//

/*
Input
2
1
1
2
0 1
0
Result
List number: 1 List info: 1: 1 sum: 1 average: 1
Sum: 1 Average: 1
Successful attempts: 1 Failed attempts: 1
 */

#include <iostream>
#include <cstring>
using namespace std;

class List {
private:
    int *lista;
    int n;
public:
    List () {
        lista = new int[0];
        n=0;
    }
    List (int *lista, int n){
        this->lista = new int[n];
        for (int i=0; i<n; i++){
            this->lista[i] = lista[i];
        }
        this->n = n;
    }
    List (const List &l){
        this->lista = new int[l.n];
        for (int i=0; i<l.n; i++){
            this->lista[i] = l.lista[i];
        }
        this->n = l.n;
    }
    List &operator=(const List &l){
        if (this!=&l) {
            delete [] lista;
            this->lista = new int[l.n];
            for (int i=0; i<l.n; i++){
                this->lista[i] = l.lista[i];
            }
            this->n = l.n;
        }
        return *this;
    }
    ~List () {
        delete [] lista;
    }

    int sum (){
        int suma=0;
        for (int i=0; i<n; i++){
            suma += lista[i];
        }
        return suma;
    }

    double average (){
        double a;
        a = (sum()*1.0/n*1.0)*1.0;
        return a;
    }

    void pecati() {
        cout <<n<<": ";
        for (int i=0; i<n; i++){
            cout <<lista[i]<<" ";
        }
        cout <<"sum: "<<sum()<<" average: "<<average()<<endl;
    }
    int get_n () {
        return n;
    }
};

class ListContainer {
private:
    List *listi;
    int elementi;
    int sa;
    int fa;
public:
    ListContainer () {
        listi = new List[0];
        elementi=0;
        sa =0;
        fa=0;
    }
    ListContainer (const ListContainer &lc) {
        listi = new List[lc.elementi];
        elementi = lc.elementi;
        sa = lc.sa;
        fa = lc.fa;
        for (int i=0; i<elementi; i++){
            listi[i] = lc.listi[i];
        }
    }
    ListContainer &operator=(const ListContainer &lc){
        if (this!=&lc) {
            delete [] listi;
            listi = new List[lc.elementi];
            elementi = lc.elementi;
            sa = lc.sa;
            fa = lc.fa;
            for (int i=0; i<elementi; i++){
                listi[i] = lc.listi[i];
            }
        }
        return *this;
    }
    ~ListContainer () {
        delete [] listi;
    }

    int sum () {
        int suma=0;
        for (int i=0; i<elementi; i++){
            suma += listi[i].sum();
        }
        return suma;
    }

    double average () {
        double br=0;
        double sum=0;
        for (int i=0; i<elementi; i++){
            sum += listi[i].sum();
            br += listi[i].get_n();
        }
        return double((sum/br)*1.0);
    }

    void print() {
        if (elementi == 0)
            cout <<"The list is empty"<<endl;
        else {
           for (int i=0; i<elementi; i++){
               cout <<"List number: "<<i+1<<" List info: ";
               listi[i].pecati();
           }
           cout <<"Sum: "<<sum()<<" Average: "<<average()<<endl;
           cout <<"Successful attempts: "<<sa<<" Failed attempts: "<<fa<<endl;
        }
    }

    void addNewList (List l) {
        for (int i=0; i<elementi; i++){
            if (l.sum() == listi[i].sum()) {
                fa++;
                return;
            }
        }
        List *temp = new List[elementi+1];
        for (int i=0; i<elementi; i++){
            temp[i] = listi[i];
        }
        temp[elementi] = l;
        delete [] listi;
        listi = temp;
        sa++;
        elementi++;
    }

};


int main() {

    ListContainer lc;
    int N;
    cin>>N;

    for (int i=0;i<N;i++) {
        int n;
        int niza[100];

        cin>>n;

        for (int j=0;j<n;j++){
            cin>>niza[j];

        }

        List l=List(niza,n);

        lc.addNewList(l);
    }


    int testCase;
    cin>>testCase;

    if (testCase==1) {
        cout<<"Test case for operator ="<<endl;
        ListContainer lc1;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1=lc;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1.sum();
        lc1.average();

    }
    else {
        lc.print();
    }
}