#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include<fstream>
#include <sstream>

//#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMenedzer
{
    vector <Uzytkownik> uzytkownicy;
    int idZalogowanegoUzytkownika;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);
    PlikZUzytkownikami plikZUzytkownikami;

public:

    int logowanieUzytkownika(vector <Uzytkownik> &uzytkownicy);
    void zmianaHaslaZalogowanegoUzytkownika(vector <Uzytkownik> &uzytkownicy, int idZalogowanegoUzytkownika);
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {};
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();

};
#endif
