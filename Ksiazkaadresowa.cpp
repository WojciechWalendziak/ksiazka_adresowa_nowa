#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

int KsiazkaAdresowa::logowanieUzytkownika(vector <Uzytkownik> &uzytkownicy)
{
    return uzytkownikMenedzer.logowanieUzytkownika(uzytkownicy);
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(vector <Uzytkownik> &uzytkownicy, int idZalogowanegoUzytkownika)
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::dodajAdresata(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    adresatMenedzer.dodajAdresata(adresaci, idZalogowanegoUzytkownika, idOstatniegoAdresata);
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow(vector <Adresat> &adresaci)
{
    adresatMenedzer.wyswietlWszystkichAdresatow(adresaci);
}

void KsiazkaAdresowa::wyloguj(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika)
{
    adresatMenedzer.wyloguj(adresaci, idZalogowanegoUzytkownika);
}
