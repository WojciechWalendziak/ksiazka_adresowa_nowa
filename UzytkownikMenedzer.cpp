#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}
Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

        string haslo;
        cout << "Podaj haslo: ";
        cin >> haslo;
        uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}
int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    vector <Uzytkownik> uzytkownicy;
    //PlikZUzytkownikami plikZUzytkownikami;
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}
bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    vector <Uzytkownik> uzytkownicy;
    //PlikZUzytkownikami plikZUzytkownikami;
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    for(int i = 0; i < uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim samym loginie" << endl;
            return true;
        }
    }
    return false;
}
void UzytkownikMenedzer::wypiszWszystkichUzytkownikow()
{
    vector <Uzytkownik> uzytkownicy;
    //PlikZUzytkownikami plikZUzytkownikami;
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    for(int i = 0; i < uzytkownicy.size(); i++)
    {
        cout <<uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
}
//int UzytkownikMenedzer::logowanieUzytkownika(vector <Uzytkownik> &uzytkownicy)
void UzytkownikMenedzer::logowanieUzytkownika()
{
    vector <Uzytkownik> uzytkownicy;
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    cout << endl << "Podaj login: ";
    cin >> login;

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                cin >> haslo;

                if (itr -> pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    //return
                    itr -> pobierzId();
                    //int idZalogowanegoUzytkownika = pobierzIdZalogowanegoUzytkownika();
                    idZalogowanegoUzytkownika = itr -> pobierzId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            //return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    //return 0;
}
void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    cin >> noweHaslo;
    int idZalogowanegoUzytkownika = pobierzIdZalogowanegoUzytkownika();
    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if (itr -> pobierzId() == idZalogowanegoUzytkownika)
        {
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}
void UzytkownikMenedzer::wylogowanieUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
}
bool UzytkownikMenedzer::czyUzytkownikJestZalogowany()
{
    idZalogowanegoUzytkownika = pobierzIdZalogowanegoUzytkownika();
    if(idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}
int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}
