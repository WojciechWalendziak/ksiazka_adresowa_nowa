#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include<fstream>
#include <sstream>

//#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMenedzer
{
    //const string nazwaPlikuZAdresatami;

    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    //int idZalogowanegoAdresata;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

    //Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    Adresat podajDaneNowegoAdresata();
    //string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int podajIdWybranegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

public:

    //AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
        //: plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
        //{
            //adresaci = plikZAdresatami.wczytajAdresatowZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        //}
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
        : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
        {
            adresaci = plikZAdresatami.wczytajAdresatowZPliku();
        }
    //int dodajAdresata(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void dodajAdresata();
    void edytujAdresata();
    int usunAdresata();
    void wyswietlWszystkichAdresatow();
    int pobierzIdNowegoAdresata();

    //void wyloguj (vector <Adresat> &adresaci, int idZalogowanegoUzytkownika);
};
#endif
