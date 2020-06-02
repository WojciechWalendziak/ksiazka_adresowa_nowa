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
        cout << "druga petla" << endl;
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
    //.wypiszWszystkichUzytkownikow();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    //ksiazkaAdresowa.logowanieUzytkownika();
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();

    //ksiazkaAdresowa.dodajAdresata();
    //ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    //KsiazkaAdresowa.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    //ksiazkaAdresowa.wyloguj();

    return 0;
}
