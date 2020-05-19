#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    AdresatMenedzer adresatMenedzer;
    UzytkownikMenedzer uzytkownikMenedzer;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami): uzytkownikMenedzer(nazwaPlikuZUzytkownikami){
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();
    };

    int logowanieUzytkownika(vector <Uzytkownik> &uzytkownicy);
    void zmianaHaslaZalogowanegoUzytkownika(vector <Uzytkownik> &uzytkownicy, int idZalogowanegoUzytkownika);
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();

    void dodajAdresata(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void wyswietlWszystkichAdresatow(vector <Adresat> &adresaci);
    void wyloguj(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika);
};
#endif
