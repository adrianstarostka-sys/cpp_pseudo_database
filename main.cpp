#include <iostream>
#include "baza.h"

using namespace std;

int main() {
    baza_danych baza_glowna;


    baza_glowna.dodaj_wpis(Wpis{"Adrian", "Starostka", 123456789L});
    baza_glowna.dodaj_wpis(Wpis{"Adrian", "Kowalski", 987654321L}); // To samo imię
    baza_glowna.dodaj_wpis(Wpis{"Anna", "Nowak", 111222333L});
    baza_glowna.dodaj_wpis(Wpis{"Maria", "Nowak", 444555666L});    // To samo nazwisko

    string Wpis::* wsk_nazwisko = &Wpis::nazwisko;
    string Wpis::* wsk_imie = &Wpis::imie;

    vector<Wpis*> znalezieni_nazwisko = baza_glowna.szukaj("Nowak", wsk_nazwisko);

    if(znalezieni_nazwisko.empty()) {
        cout << "Nie znaleziono nikogo o takim nazwisku." << endl;
    } else {
        for(Wpis* w : znalezieni_nazwisko) {
            cout << "Znaleziono: " << w->imie << " " << w->nazwisko << ", Tel: " << w->numer_telefonu << endl;
        }
    }

    vector<Wpis*> znalezieni_imie = baza_glowna.szukaj("Adrian", wsk_imie);

    if(znalezieni_imie.empty()) {
        cout << "Nie znaleziono nikogo o takim imieniu." << endl;
    } else {
        for(Wpis* w : znalezieni_imie) {
            cout << "Znaleziono: " << w->imie << " " << w->nazwisko << ", Tel: " << w->numer_telefonu << endl;
        }
    }


    int wybor;
    do {
        cout << "\nMENU: " << endl;
        cout << "1. Wyswietl wszystkie wpisy" << endl;
        cout << "2. Dodaj nowy wpis" << endl;
        cout << "3. Usun wpis" << endl;
        cout << "0. Wyjdz" << endl;
        cout << "Twoj wybor: ";
        cin >> wybor;

        if (wybor == 1) {
            baza_glowna.wyswietl_baze();
        }
        else if (wybor == 2) {
            Wpis nowy;
            cout << "Podaj imie: ";
            cin >> nowy.imie;
            cout << "Podaj nazwisko: ";
            cin >> nowy.nazwisko;
            cout << "Podaj numer telefonu: ";
            cin >> nowy.numer_telefonu;

            baza_glowna.dodaj_wpis(nowy);
            cout << "Dodano rekord." << endl;
        }
        else if (wybor == 3) {
            int index;
            cout << "Podaj indeks do usuniecia: ";
            cin >> index;
            baza_glowna.usun_wpis(index);
        }

    } while (wybor != 0);

    return 0;
}