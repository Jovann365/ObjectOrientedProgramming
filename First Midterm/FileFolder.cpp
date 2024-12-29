//
// Created by Jovan on 29.12.2024.
//

/*
Потребно е да се имплементираат класи File (датотека) и Folder (директориум) за работа со едноставен податочен систем.

Во класата File треба да се чуваат следниве податоци:

Име на датотеката (динамички алоцирана низа од знаци)
Екстензија на датотеката (енумерација со можни вредности: txt, pdf, exe)
Име на сопственикот на датотеката (динамички алоцирана низа од знаци)
Големина на датотеката (цел број на мегабајти)
Дополнително, во класата потребно е да се напишат и:

Конструктор без параметри
Конструктор со параметри
Конструктор за копирање
Деструктор
Преоптоварување на операторот =
Метод за печатење на информациите за една датотека (видете го излезот од тест примерите за структурата на печатење) - print()
Метод за проверка на еднаквост помеѓу две датотеки со потпис bool equals(const File & that) кој ќе враќа true ако датотеките имаат исто име, екстензија и сопственик
Метод за споредба на типот помеѓу две датотеки со потпис bool equalsType(const File & that) кој ќе враќа true ако датотеките се од ист тип, т.е. имаат исто име и екстензија
Во класата Folder треба да се чуваат следниве податоци:

Име на директориумот (динамички алоцирана низа од знаци)
Број на датотеки во него (на почеток директориумот е празен)
Динамички алоцирана низа од датотеки, објекти од класата File
Дополнително, во класата потребно е да се напишат и:

Конструктор со потпис Folder(const char* name)
Деструктор
Метод за печатење на информациите за еден директориум (видете го излезот од тест примерите за структурата на печатење) - print()
Метод за бришење на датотека од директориумот со потпис void remove(const File & file) кој ќе ја избрише првата датотека од директориумот која е еднаква според equals методот
Метод за додавање на датотека во директориумот со потпис void add(const File & file) кој ќе додава датотеката во директориумот
Не го менувајте почетниот код.
 */

#include <iostream>
#include <cstring>
using namespace std;

enum Extension{txt,pdf,exe};

class File{
private:
    char *ime;
    Extension ek;
    char *sopstvenik;
    int golemina;
public:
    File (){
        ime = new char[0];
        ek = txt;
        sopstvenik = new char[0];
        golemina =0;
    }
    File (char *ime, char *sopstvenik, int golemina, Extension ek){
       this->ime = new char[strlen(ime)+1];
       strcpy(this->ime, ime);
       this->ek = ek;
       this->sopstvenik = new char[strlen(sopstvenik)+1];
        strcpy(this->sopstvenik, sopstvenik);
        this->golemina = golemina;
    }
    File (const File &f){
        this->ime = new char[strlen(f.ime)+1];
        strcpy(this->ime, f.ime);
        this->ek = f.ek;
        this->sopstvenik = new char[strlen(f.sopstvenik)+1];
        strcpy(this->sopstvenik, f.sopstvenik);
        this->golemina = f.golemina;
    }
    File &operator=(const File &f){
        if (this!=&f){
            delete [] ime;
            delete [] sopstvenik;
            this->ime = new char[strlen(f.ime)+1];
            strcpy(this->ime, f.ime);
            this->ek = f.ek;
            this->sopstvenik = new char[strlen(f.sopstvenik)+1];
            strcpy(this->sopstvenik, f.sopstvenik);
            this->golemina = f.golemina;
        }
        return *this;
    }
    ~File() {
        delete [] ime;
        delete [] sopstvenik;
    }

    void print() {
        cout <<"File name: "<<ime<<".";
        if (ek == 0)
            cout <<"pdf"<<endl;
        else if (ek == 1)
            cout <<"txt"<<endl;
        else
            cout <<"exe"<<endl;
        cout <<"File owner: "<<sopstvenik<<endl;
        cout <<"File size: "<<golemina<<endl;
    }

    bool equals(const File & that){
        if (strcmp(ime, that.ime)==0 && ek==that.ek && strcmp(sopstvenik, that.sopstvenik)==0)
            return true;
        else
            return false;
    }

    bool equalsType(const File & that){
        if (strcmp(ime, that.ime)==0 && ek==that.ek)
            return true;
        else
            return false;
    }

};

class Folder {
private:
    char *ime;
    int br_datoteki;
    File *datoteki;
public:
    Folder (const char* name){
        ime = new char[strlen(name)+1];
        strcpy(ime, name);
        br_datoteki=0;
        datoteki = new File[0];
    }
    Folder (const Folder &fl){
        ime = new char[strlen(fl.ime)+1];
        strcpy(ime, fl.ime);
        br_datoteki=fl.br_datoteki;
        datoteki = new File[br_datoteki];
        for (int i=0; i<br_datoteki; i++){
            datoteki[i] = fl.datoteki[i];
        }
    }
    Folder &operator=(const Folder &fl){
        if (this!=&fl){
            delete [] ime;
            delete [] datoteki;
            ime = new char[strlen(fl.ime)+1];
            strcpy(ime, fl.ime);
            br_datoteki=fl.br_datoteki;
            datoteki = new File[br_datoteki];
            for (int i=0; i<br_datoteki; i++){
                datoteki[i] = fl.datoteki[i];
            }
        }
        return *this;
    }
    ~Folder(){
        delete [] ime;
        delete [] datoteki;
    }

    void print() {
        cout <<"Folder name: "<<ime<<endl;
        for (int i=0; i<br_datoteki; i++){
            datoteki[i].print();
        }
    }

    void remove(const File & file){
        for (int i=0; i<br_datoteki; i++){
            if (datoteki[i].equals(file)){
                File *temp = new File[br_datoteki-1];
                int br=0;
                for (int j=0; j<br_datoteki; j++){
                    if (!datoteki[j].equals(file)){
                        temp[br] = datoteki[j];
                        br++;
                    }
                }
                delete [] datoteki;
                datoteki = temp;
                br_datoteki--;
                return;
            }
        }
    }

    void add(const File & file){
        File *temp = new File[br_datoteki+1];
        for (int i=0; i<br_datoteki; i++){
            temp[i] = datoteki[i];
        }
        temp[br_datoteki] = file;
        delete [] datoteki;
        datoteki = temp;
        br_datoteki++;
    }
};

int main() {
    char fileName[20];
    char fileOwner[20];
    int ext;
    int fileSize;

    int testCase;
    cin >> testCase;
    if (testCase == 1) {
        cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File created = File(fileName, fileOwner, fileSize, (Extension) ext);
        File copied = File(created);
        File assigned = created;

        cout << "======= CREATED =======" << endl;
        created.print();
        cout << endl;
        cout << "======= COPIED =======" << endl;
        copied.print();
        cout << endl;
        cout << "======= ASSIGNED =======" << endl;
        assigned.print();
    }
    else if (testCase == 2) {
        cout << "======= FILE EQUALS & EQUALS TYPE =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File first(fileName, fileOwner, fileSize, (Extension) ext);
        first.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File second(fileName, fileOwner, fileSize, (Extension) ext);
        second.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File third(fileName, fileOwner, fileSize, (Extension) ext);
        third.print();

        bool equals = first.equals(second);
        cout << "FIRST EQUALS SECOND: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equals = first.equals(third);
        cout << "FIRST EQUALS THIRD: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        bool equalsType = first.equalsType(second);
        cout << "FIRST EQUALS TYPE SECOND: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equalsType = second.equals(third);
        cout << "SECOND EQUALS TYPE THIRD: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

    }
    else if (testCase == 3) {
        cout << "======= FOLDER CONSTRUCTOR =======" << endl;
        cin >> fileName;
        Folder folder(fileName);
        folder.print();

    }
    else if (testCase == 4) {
        cout << "======= ADD FILE IN FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        folder.print();
    }
    else {
        cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0) {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (Extension) ext);
            folder.add(file);
            iter--;
        }
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File file(fileName, fileOwner, fileSize, (Extension) ext);
        folder.remove(file);
        folder.print();
    }
    return 0;
}