#include <unistd.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;int w;int wielkosc;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);COORD CursorPosition;

class Tekstkultury{
    protected:
        string Nazwa;
    public:
        void setNazwa(const string& Nazwa){this->Nazwa = Nazwa;}
        string getNazwa(){return Nazwa;}};

class Filmy: public Tekstkultury{
    private:
        string gatunek;
        float cena;
        int ilosc;
        int ocena;
        int opakowania;

    public:

        void setCena(float cena){this->cena = cena;}
        void setOcena(int ocena){this->ocena = ocena;}
        void setIlosc(int ilosc){this->ilosc = ilosc;}
        void setOpakowania(int opakowania){this->opakowania = opakowania;}
        void setGatunek(const string& gatunek){this->gatunek=gatunek;}

        float getCena(){return cena;}
        int getOcena(){return ocena;}
        int getSztuk(){return ilosc;}
        int getOpakowania(){return opakowania;}
        string getGatunek(){return gatunek;}};

class bazaFilmy{
    private:
        int current=0;
        vector<Filmy> films;
    public:
        void dodaj(const string& Nazwa, float cena,int ocena, int sztuk,int opakowania,const string& gatunek);
        void czyscWszystko();
        void stworzPlik();
        void drukujCalosc();
        void usun();
        void usuncurrent();
        void drukuj();
        void setcurrent();
        void zapisz();
        void wczytaj();
        };



void bazaFilmy::dodaj(const string& Nazwa, float cena,int ocena, int sztuk,int opakowania,const string& gatunek){
    Filmy film=Filmy();
    film.setNazwa(Nazwa);
    film.setCena(cena);
    film.setOcena(ocena);
    film.setIlosc(sztuk);
    film.setOpakowania(opakowania);
    film.setGatunek(gatunek);
    films.push_back(film);
    films.size();
    wielkosc++;}

void bazaFilmy::drukujCalosc(){
    for(int i=0;i<films.size();i++)
        {cout<<endl<<"XXX  Pozycja: "<<i<<"  XXX"<<endl<<"Tytul: "<<films.at(i).getNazwa()<<endl<<"Cena: "<<films.at(i).getCena()<<endl;
        cout<<"Ocena: "<<films.at(i).getOcena()<<endl<<"Sztuk: "<<films.at(i).getSztuk()<<endl<<"Opakowania: "<<films.at(i).getOpakowania()<<endl<<"Gatunek: "<<films.at(i).getGatunek();}}



void bazaFilmy::usun(){films.erase(films.begin()+w);wielkosc--;}

void bazaFilmy::usuncurrent(){films.erase(films.begin()+current);wielkosc--;}

void bazaFilmy::czyscWszystko(){films.clear();wielkosc=0;}

void bazaFilmy::wczytaj(){
    ifstream file("pp.txt");
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string Nazwa;
        string CenaStr;
        string OcenaStr;
        string SztukStr;
        string OpakowaniaStr;
        string Gatunek;
        getline(ss, Nazwa, ';');
        getline(ss, CenaStr, ';');
        getline(ss, OcenaStr, ';');
        getline(ss, SztukStr, ';');
        getline(ss, OpakowaniaStr, ';');
        getline(ss, Gatunek, ';');

        float Cena = stof(CenaStr);
        int  Ocena = stoi(OcenaStr);
        int  Sztuk = stoi(SztukStr);
        int  Opakowania = stoi(Opakowania);

        Filmy Tekstkultury = films();
        Tekstkultury.setNazwa(Nazwa);
        Tekstkultury.setCena(cena);
        Tekstkultury.setOcena(ocena);
        Tekstkultury.setSztuk(sztuk);
        Tekstkultury.setOpakowania(Opakowania);
        Tekstkultury.setGatunek(gatunek);

        TekstkulturyTemp.push_back(Tekstkultury);


    }

    file.close();
    return TekstkulturyTemp;}

void bazaFilmy::zapisz(){
    ofstream fout("pp.txt");


        for (int i = 0; i < films.size(); i++)
        {
            Filmy Tekstkultury = films.at(i);
            fout << Tekstkultury.getNazwa();
            fout << ";";
            fout << Tekstkultury.getCena();
            fout << ";";
            fout << Tekstkultury.getOcena();
            fout << ";";
            fout << Tekstkultury.getSztuk();
            fout << ";";
            fout << Tekstkultury.getOpakowania();
            fout << ";";
            fout << Tekstkultury.getGatunek();
            fout << endl;
        }
        fout.close();}

void gotoXY(int x, int y){CursorPosition.X = x;CursorPosition.Y = y;SetConsoleCursorPosition(console,CursorPosition);}
void czekaj(){cin.sync();cout << "## Nacisnij ENTER by wrocic do menu ##";cin.get();};

int main(){int opcje;bazaFilmy baza=bazaFilmy();string j;float y=0;int z=0;int a=0;int k=0;string b;int opcje2;
HWND console = GetConsoleWindow();RECT r;GetWindowRect(console, &r);MoveWindow(console, r.left, r.top, 1280, 720, TRUE);

menu:
    system ("CLS");int menu_item=0, run, x=10;bool dziala = true;int num;num=155;char symbol;symbol ='X';
    gotoXY(58,1);cout<<"   ___       _      ___                "<<endl;gotoXY(58,2);cout<<"  |_  |     | |    |_  |               "<<endl;
    gotoXY(58,3);cout<<"    | | __ _| | __   | | __ ___      __"<<endl;gotoXY(58,4);cout<<"    | |/ _` | |/ /   | |/ _` \\ \\ /\\ / /"<<endl;
    gotoXY(58,5);cout<<"/\\__/ / (_| |   </\\__/ / (_| |\\ V  V / "<<endl;gotoXY(58,6);cout<<"\\____/ \\__,_|_|\\_\\____/ \\__,_| \\_/\\_/  "<<endl;
    gotoXY(0,41);cout<<string(num, symbol);gotoXY(0,0);cout<<string(num, symbol);gotoXY(69,8); cout << "##  MENU GLOWNE  ##";gotoXY(68,10);cout << "->";
        while(dziala){
            gotoXY(70,10);cout << "1.Dodaj nowy film";gotoXY(70,11);cout << "2.Pokaz wszystkie filmy";gotoXY(70,12);cout << "3.Pokaz film";gotoXY(70,13);cout << "4.Usun film";gotoXY(70,14);cout << "5.Usun wszystko";gotoXY(70,15);cout<<"6.Stworz plik";
            gotoXY(70,16);cout << "7.Otworz plik";gotoXY(70,17);cout << "8.Zapisz plik";gotoXY(70,18);cout << "9.Przegladaj gatunki";gotoXY(70,19);cout << "10.Szukaj gatunku";gotoXY(70,20);cout << "11.Sortuj gatunki";
            gotoXY(70,21);cout << "12.Wyjscie z programu";system("pause>nul");gotoXY(50,15);
            if(GetAsyncKeyState(VK_DOWN) && x != 21){gotoXY(68,x); cout << "  ";x++;gotoXY(68,x); cout << "->";menu_item++;continue;}
            if(GetAsyncKeyState(VK_UP) && x != 10){gotoXY(68,x); cout << "  ";x--;gotoXY(68,x); cout << "->";menu_item--;continue;}
            if(GetAsyncKeyState(VK_RETURN)){switch(menu_item){
                case 0: {opcje=1;goto nowa;}
                case 1: {opcje=2;goto nowa;}
                case 2: {opcje=3;goto nowa;}
                case 3: {opcje=4;goto nowa;}
                case 4: {opcje=5;goto nowa;}
                case 5: {opcje=6;goto nowa;}
                case 6: {opcje=7;goto nowa;}
                case 7: {opcje=8;goto nowa;}
                case 8: {opcje=9;goto nowa;}
                case 9: {opcje=10;goto nowa;}
                case 10: {opcje=11;goto nowa;}
                case 11: {goto koniec;}}} }///MENU

nowa:{system ("CLS");
    if(opcje==1){char symbol;symbol ='X';cout<<string(155, symbol);
                cout<<"Podaj nazwe filmu: ";cin>>j;
                cout<<"Podaj cene: ";cin>>y;
                cout<<"Podaj ilosc: ";cin>>z;
                cout<<"Podaj ilosc opakowan: ";cin>>k;
                cout<<"Podaj ocene: ";cin>>a;
                cout<<"Podaj gatunek: ";cin>>b;
                baza.dodaj(j,y,z,k,a,b);cout<<"XXX  dodano  XXX"<<endl;Sleep(1000);goto menu;}

    if(opcje==2){baza.drukujCalosc();cout<<endl;czekaj();goto menu;}

    if(opcje==3){menu2:
            system ("CLS");int menu_item=0, run, x=10;bool dziala = true;gotoXY(69,8); cout << "##  MENU Przegladania filmow  ##";gotoXY(68,10);cout << "->";
            while(dziala){
            gotoXY(70,10);cout << "1.Pokaz nastepny";gotoXY(70,11);cout << "2.Pokaz poprzedni";gotoXY(70,12);cout << "3.Pokaz pierwszy";gotoXY(70,13);cout << "4.Pokaz ostatni";gotoXY(70,14);
            cout << "5.Ustaw jako aktualny (current)";gotoXY(70,15);cout<<"6.Usun aktualny film";gotoXY(70,16);cout << "7.Nadpisz film";gotoXY(70,17);cout << "X";gotoXY(70,18);
            cout << "X";gotoXY(70,19);cout << "X";gotoXY(70,20);cout << "X";
            gotoXY(70,21);cout << "12.Powrot do menu";system("pause>nul");gotoXY(50,15);
            if(GetAsyncKeyState(VK_DOWN) && x != 21){gotoXY(68,x); cout << "  ";x++;gotoXY(68,x); cout << "->";menu_item++;continue;}
            if(GetAsyncKeyState(VK_UP) && x != 10){gotoXY(68,x); cout << "  ";x--;gotoXY(68,x); cout << "->";menu_item--;continue;}
            if(GetAsyncKeyState(VK_RETURN)){switch(menu_item){
                case 0: {opcje2=1;goto nowa2;}
                case 1: {opcje2=2;goto nowa2;}
                case 2: {opcje2=3;goto nowa2;}
                case 3: {opcje2=4;goto nowa2;}
                case 4: {opcje2=5;goto nowa2;}
                case 5: {opcje2=6;goto nowa2;}
                case 6: {opcje2=7;goto nowa2;}
                case 7: {opcje2=8;goto nowa2;}
                case 8: {opcje2=9;goto nowa2;}
                case 9: {opcje2=10;goto nowa2;}
                case 10: {opcje2=11;goto nowa2;}
                case 11: {goto menu;}}} }///MENU
            nowa2:
                {system("CLS");
                if(opcje2==1){}
                if(opcje==6){baza.usuncurrent();goto menu2;}
                }goto menu;}

    if(opcje==4){gotoXY(60,5);cout<<"Podaj pozycje filmu ktory chcesz wykasowac";gotoXY(70,6);cin>>w;
        if(w<0 || w>wielkosc-1){system ("CLS");gotoXY(77,10);cout<<"Blad";Sleep(2000);goto menu;}baza.usun();goto menu;}

    if(opcje==5){baza.czyscWszystko();czekaj();goto menu;}

    if(opcje==6){ofstream outfile ("pp.txt");outfile.close();gotoXY(70,5);cout<<"Stworzono plik projekt.txt";Sleep(2000);goto menu;}

    if(opcje==7){goto menu;}
    if(opcje==8){baza.zapisz();goto menu;}
    if(opcje==9){goto menu;}
    if(opcje==10){goto menu;}
    if(opcje==11){goto menu;}}//NOWA

koniec:{system ("CLS");gotoXY(60,10);cout<<"##  Zakonczono dzialanie programu  ##";Sleep(2000);return 0;}
}
