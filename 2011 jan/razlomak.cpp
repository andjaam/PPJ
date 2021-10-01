#include "razlomak.hpp"
#include <iostream>

using namespace std;

void Razlomak::ispisi() const {
    cout << "[" << _elementi.first << "," << _elementi.second << "]" << endl;
}

Razlomak Razlomak::saberi(Razlomak r) const {
    Razlomak rez;
    
    rez._elementi.first  = _elementi.first * r._elementi.second + r._elementi.first * _elementi.second;
    rez._elementi.second = _elementi.second * r._elementi.second;
    
    return rez;
}

Razlomak Razlomak::oduzmi(Razlomak r) const {
    Razlomak rez;
    
    rez._elementi.first  = _elementi.first * r._elementi.second - r._elementi.first * _elementi.second;
    rez._elementi.second = _elementi.second * r._elementi.second;
    
    return rez;
}

Razlomak Razlomak::pomnozi(Razlomak r) const {
    Razlomak rez;
    
    rez._elementi.first  = _elementi.first  * r._elementi.first;
    rez._elementi.second = _elementi.second * r._elementi.second;
    
    return rez;
}

Razlomak Razlomak::podeli(Razlomak r) const {
    Razlomak rez;
    
    rez._elementi.first  = _elementi.first  * r._elementi.second;
    rez._elementi.second = _elementi.second * r._elementi.first;
    
    return rez;
}

void Razlomak::skrati() {
    int br = _elementi.first;
    int im = _elementi.second;
    int pom = 0;
    while (im) {
        pom = im;
        im = br % im;
        br = pom;
    }
    _elementi.first  /= br;
    _elementi.second /= br;
}

void Razlomak::proveri(Razlomak r) {
    this->skrati();
    r.skrati();
    if (_elementi.first == r._elementi.first && _elementi.second == r._elementi.second)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}

void Razlomak::brojilac() {
    this->skrati();
    cout << _elementi.first << endl;
}

void Razlomak::imenilac() {
    this->skrati();
    cout << _elementi.second << endl;
}

void Razlomak::vrednost() const {
    cout << (double)_elementi.first / _elementi.second << endl;
}
