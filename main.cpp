#include <iostream>
#include "Ksiazkaadresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy2.txt");
    //ksiazkaAdresowa.wczytajUzytkownikowZPliku();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    //ksiazkaAdresowa.logowanieUzytkownika();
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();

    //ksiazkaAdresowa.dodajAdresata();
    //ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    //KsiazkaAdresowa.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    //ksiazkaAdresowa.wyloguj();

    return 0;
}
