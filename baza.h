#ifndef BAZA_H
#define BAZA_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Wpis {
    string imie;
    string nazwisko;
    long long numer_telefonu;
};

class baza_danych {
private:
    vector<Wpis> tablica_wpisow;

public:
    void wyswietl_baze();
    void usun_wpis(int indeks);
    void dodaj_wpis(const Wpis &nowy_wpis);
    vector<Wpis*> szukaj(const string &wartosc, string Wpis::* pole);
};

#endif