#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include<fstream>
#include<cstdlib>

//#include "UzytkownikMenedzer.h"
#include "PlikTekstowy.h"
#include "Adresat.h"
#include "MetodyPomocnicze.h"
class AdresatMenedzer;


using namespace std;

class PlikZAdresatami: public PlikTekstowy
{
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    int idOstatniegoAdresata;
    int idZalogowanegoUzytkownika;

    //bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    //void edytujAdresata(vector <Adresat> &adresaci);
    //void zaktualizujDaneWybranegoAdresata(Adresat adresat);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    void edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    int zwrocNumerLiniiSzukanegoAdresata(int idAdresata);
    int usunAdresata(vector <Adresat> &adresaci);

public:
    PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {};
    //PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    //{
        //idOstatniegoAdresata = 0;
    //}
    void dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZPliku();
    int pobierzIdOstatniegoAdresata();
    void zaktualizujDaneWybranegoAdresata(Adresat adresat);
    void usunWybranaLinieWPliku(int idAdresata);
    //int wczytajAdresatowZPliku(int idZalogowanegoUzytkownika);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
};
#endif
