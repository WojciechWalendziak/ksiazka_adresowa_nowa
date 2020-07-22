#include <iostream>
#include "Ksiazkaadresowa.h"

using namespace std;

int idZalogowanegoUzytkownika = 0;

char wybor;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    //ksiazkaAdresowa.wczytajUzytkownikowZPliku();
    while (true)
    {
        if (ksiazkaAdresowa.czyUzytkownikJestZalogowany())
        {
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
                break;
            case '2':
                ksiazkaAdresowa.dodajAdresata();
                break;
            case '3':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '4':
                ksiazkaAdresowa.wylogowanieUzytkownika();
                break;
            case '5':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '6':
                ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
                ksiazkaAdresowa.usunAdresata();
                break;
            case '8':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '3':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
