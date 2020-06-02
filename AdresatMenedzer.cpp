#include "AdresatMenedzer.h"
//#include "PlikZAdresatami.h"
//#include "MetodyPomocnicze.h"

//int AdresatMenedzer::dodajAdresata(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;
    //vector <Adresat> adresaci;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    //adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);
    adresat = podajDaneNowegoAdresata();
    wyswietlDaneAdresata(adresat);
    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
    //if(plikZAdresatami.dopiszAdresataDoPliku(adresat))
        //cout << "Nowy adresat zostal dodany" << endl;
    //else
        //cout << "Blad. Nie udalo sie dodac adresata do pliku" << endl;
    system("pause");
}
//Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    Adresat adresat;
    string wejscie;

    adresat.ustawId(pobierzIdNowegoAdresata());
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    wejscie = MetodyPomocnicze::wczytajLinie();
    wejscie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(wejscie);
    adresat.ustawImie(wejscie);

    cout << "Podaj nazwisko: ";
    wejscie = MetodyPomocnicze::wczytajLinie();
    wejscie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(wejscie);
    adresat.ustawNazwisko(wejscie);

    cout << "Podaj numer telefonu: ";
    wejscie = MetodyPomocnicze::wczytajLinie();
    wejscie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(wejscie);
    adresat.ustawNumerTelefonu(wejscie);

    cout << "Podaj email: ";
    wejscie = MetodyPomocnicze::wczytajLinie();
    wejscie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(wejscie);
    adresat.ustawEmail(wejscie);

    cout << "Podaj adres: ";
    wejscie = MetodyPomocnicze::wczytajLinie();
    wejscie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(wejscie);
    adresat.ustawAdres(wejscie);
    return adresat;
}
int AdresatMenedzer::pobierzIdNowegoAdresata()
{
    vector <Adresat> adresaci;
    //PlikZUzytkownikami plikZUzytkownikami;
    //idZalogowanegoUzytkownika = pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    if (adresaci.empty() == true)
    {
        return 1;
    }
    else
    {
        return adresaci.back().pobierzId() + 1;
    }
}
void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}
void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
    //vector <Adresat> adresaci;
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}
Adresat AdresatMenedzer::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}
int AdresatMenedzer::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}
int AdresatMenedzer::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}
//void AdresatMenedzer::wyloguj (vector <Adresat> &adresaci, int idZalogowanegoUzytkownika)
//{
    //idZalogowanegoUzytkownika = 0;
    //adresaci.clear();
//}
