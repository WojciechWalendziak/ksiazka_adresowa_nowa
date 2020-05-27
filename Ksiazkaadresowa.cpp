#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}
void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}
//int KsiazkaAdresowa::logowanieUzytkownika(vector <Uzytkownik> &uzytkownicy)
//{
    //return uzytkownikMenedzer.logowanieUzytkownika(uzytkownicy);
//}
void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}
void KsiazkaAdresowa::dodajAdresata()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer -> dodajAdresata();
    }
    else
    {
        cout << "Aby dodac adresata najpierw musisz sie zalogowac" << endl;
        system("pause");
    }
}
//void KsiazkaAdresowa::dodajAdresata(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
//{
    //adresatMenedzer.dodajAdresata(adresaci, idZalogowanegoUzytkownika, idOstatniegoAdresata);
//}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatMenedzer -> wyswietlWszystkichAdresatow();
}
void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenedzer.wylogowanieUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}
//void KsiazkaAdresowa::wyloguj(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika)
//{
    //adresatMenedzer.wyloguj(adresaci, idZalogowanegoUzytkownika);
//}
