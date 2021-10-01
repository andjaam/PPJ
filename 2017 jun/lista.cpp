#include "lista.hpp"
#include <iostream>

using namespace std;

void Lista::dodajElement(int i) {
    _elementi.push_back(i);
}

void Lista::ispisi() const {
    cout << "[";
    for (auto it = _elementi.begin(); it != _elementi.end(); it++) {
        cout << *it << " ";
    }
    cout << "]" << endl;
}

void Lista::nadovezi(Lista l) {
    for (auto it = l._elementi.begin(); it != l._elementi.end(); it++) {
        _elementi.push_back(*it);
    }
}

void Lista::izvuciGlavu() const {
    cout << _elementi.front() << endl;
}

Lista Lista::izvuciRep() const {
    Lista rez;
    for (auto it = ++_elementi.begin(); it != _elementi.end(); it++) {
        rez.dodajElement(*it);
    }
    return rez;
}

void Lista::izvuciElement(int index) const {
    if (index < 1 || (unsigned)index > _elementi.size()) {
        cout << "Indeks nije odgovarajuci" << endl;
        exit(EXIT_FAILURE);
    }
    auto it = _elementi.begin();
    for (int i=1; i < index; i++) {
        ++it;
    }
    cout << *it << endl;
}

void Lista::sortiraj() const {
    Lista rez(*this);
    rez._elementi.sort();
    cout << "[";
    for (auto it = rez._elementi.begin(); it != rez._elementi.end(); it++) {
        cout << *it << " ";
    }
    cout << "]" << endl;
}

void Lista::vratiDuzinu() const {
    cout << _elementi.size() << endl;
}

void Lista::skalarniProizvod(Lista l) const {
    if (_elementi.size() != l._elementi.size()) {
        cout << "Liste nisu iste duzine" << endl;
        exit(EXIT_FAILURE);
    }
    int rez = 0;
    int velicina = _elementi.size();
    auto it1 = _elementi.begin();
    auto it2 = l._elementi.begin();
    for (int i=0; i < velicina; i++) {
        rez += (*it1) * (*it2);
        it1++;
        it2++;
    }
    cout << rez << endl;
}

int Lista::jednaki(Lista l) const {
    if (_elementi.size() != l._elementi.size())
        return 1;
    
    int velicina = _elementi.size();
    auto it1 = _elementi.begin();
    auto it2 = l._elementi.begin();
    for (int i=0; i < velicina; i++) {
        if (*it1 != *it2)
            return 1;
    }
    
    return 0;
}
