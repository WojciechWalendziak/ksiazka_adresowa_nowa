#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include<fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer
{
    const string nazwaPlikuZAdresatami;

    int idZalogowanegoAdresata;
    vector <Adresat> adresaci;

    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    PlikZAdresatami plikZAdresatami;
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void wyswietlDaneAdresata(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

public:

    int dodajAdresata(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void wyswietlWszystkichAdresatow(vector <Adresat> &adresaci);
    void wyloguj (vector <Adresat> &adresaci, int idZalogowanegoUzytkownika);
};
#endif
