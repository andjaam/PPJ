#include "skup.hpp"
#include <iostream>

using namespace std;

void Skup::dodajElement(int e) {
    _elementi.insert(e);
}

void Skup::obrisiElement(int e) {
    _elementi.erase(e);
}

void Skup::ispisi() const {
    cout << "{";
    for (auto itr = _elementi.begin(); itr != _elementi.end(); itr++) {
        cout << *itr << " ";
    }
    cout << "}" << endl;
}

Skup Skup::unija(const Skup a) const {
    Skup r(*this);
    for (auto itr = a._elementi.begin(); itr != a._elementi.end(); itr++) {
        r.dodajElement(*itr);
    }
    return r;
}

Skup Skup::presek(const Skup a) const {
    Skup r;
    for (auto itr = a._elementi.begin(); itr != a._elementi.end(); itr++) {
        if (_elementi.find(*itr) != _elementi.end())
            r.dodajElement(*itr);
    }
    return r;
}

Skup Skup::razlika(const Skup a) const {
    Skup r(*this);
    for (auto itr = a._elementi.begin(); itr != a._elementi.end(); itr++) {
        if (_elementi.find(*itr) != _elementi.end())
            r.obrisiElement(*itr);
    }
    return r;
}

void Skup::proveri(const int broj) const {
    if (_elementi.find(broj) != _elementi.end()) 
        cout << "True" << endl;
    else
        cout << "False" << endl;
}

void Skup::podskup(const Skup a) const {
    int flag = 0;
    for (auto itr = a._elementi.begin(); itr != a._elementi.end(); itr++) {
        if (_elementi.find(*itr) == _elementi.end()) {
            cout << "False" << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "True" << endl;
}

void Skup::kardinalnost() const {
    cout << _elementi.size() << endl;
}
