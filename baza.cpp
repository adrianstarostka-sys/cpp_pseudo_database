#include "baza.h"

void baza_danych::wyswietl_baze() {
    cout << "\nKsiazka Telefoniczna: " << endl;
    if (tablica_wpisow.empty()) {
        cout << "Baza jest pusta." << endl;
    } else {
        for (size_t i = 0; i < tablica_wpisow.size(); i++) {
            cout << "[" << i << "] " << tablica_wpisow[i].imie
                 << " " << tablica_wpisow[i].nazwisko
                 << " Tel: " << tablica_wpisow[i].numer_telefonu << endl;
        }
    }
}

void baza_danych::usun_wpis(int indeks) {
    if (indeks < 0 || indeks >= tablica_wpisow.size()) {
        cout << "Blad: Niepoprawny indeks!" << endl;
        return;
    }
    tablica_wpisow.erase(tablica_wpisow.begin() + indeks);
    cout << "Wpis zostal usuniety." << endl;
}

void baza_danych::dodaj_wpis(const Wpis &nowy) {
    tablica_wpisow.push_back(nowy);
}

vector<Wpis*> baza_danych::szukaj(const string &wartosc, string Wpis::* pole) {
    vector<Wpis*> znalezione;
    for (auto &wpis : tablica_wpisow) {
        if (wpis.*pole == wartosc) {
            znalezione.push_back(&wpis);
        }
    }
    return znalezione;
}