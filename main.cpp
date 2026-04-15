#include <iostream> //skonczone
#include <vector>

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
};

void baza_danych::wyswietl_baze() {
    cout << "\nKsiazka Telefoniczna: " << endl;
    if (tablica_wpisow.size() == 0) {
        cout << "Baza jest pusta." << endl;
    } else {
        for (int i = 0; i < tablica_wpisow.size(); i++) {
            cout << "[" << i << "] " << tablica_wpisow[i].imie
                 << " " << tablica_wpisow[i].nazwisko
                 << " Tel: " <<tablica_wpisow[i].numer_telefonu << endl;
        }
    }
}
void baza_danych::usun_wpis(int indeks) {
    if (indeks < 0 || indeks >= tablica_wpisow.size()) {
        cout << "Błąd: Niepoprawny indeks!" << endl;
        return;
    }
    tablica_wpisow.erase(tablica_wpisow.begin() + indeks);
    cout << "Wpis zostal usuniety." << endl;
}
void baza_danych::dodaj_wpis(const Wpis &nowy) {
    tablica_wpisow.push_back(nowy);
}

int main() {
    baza_danych baza_glowna;
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
