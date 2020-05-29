#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    AdresatMenedzer *adresatMenedzer;
    UzytkownikMenedzer uzytkownikMenedzer;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
        :uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
      adresatMenedzer = NULL;
    };
    ~KsiazkaAdresowa()
    {
        delete adresatMenedzer;
        adresatMenedzer = NULL;
    }
    //int logowanieUzytkownika(vector <Uzytkownik> &uzytkownicy);
    //wczytajUzytkownikowZPliku(uzytkownicy);

    bool czyUzytkownikJestZalogowany();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();

    //void dodajAdresata(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wylogowanieUzytkownika();
    //void wyloguj(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika);
};
#endif
