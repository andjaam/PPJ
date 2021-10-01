#include "vektor.hpp"
#include <iostream>
#include <cmath>

using namespace std;

void Vektor::dodajElement(double d) {
    _elementi.push_back(d);
}

void Vektor::ispisi() const {
    if (!_elementi.empty()) {
        cout << "<";
        for (auto it = _elementi.begin(); it != _elementi.end(); it++)
            cout << *it << " ";
        cout << ">" << endl;
    }
}

Vektor Vektor::saberi(Vektor v) const {
    Vektor prazan;
    if (_elementi.size() != v._elementi.size()  && !_elementi.empty() && !v._elementi.empty()) {
        cout << "Greska u dimenzionalnosti vektora" << endl;
        return prazan;
    }
    if (_elementi.empty() || v._elementi.empty()) {
        return prazan;
    }
    Vektor rez(*this);
    for (unsigned i=0; i < _elementi.size(); i++) 
        rez._elementi[i] += v._elementi[i];
    return rez;
}

Vektor Vektor::oduzmi(Vektor v) const {
    Vektor prazan;
    if (_elementi.size() != v._elementi.size() && !_elementi.empty() && !v._elementi.empty()) {
        cout << "Greska u dimenzionalnosti vektora" << endl;
        return prazan;
    }
    if (_elementi.empty() || v._elementi.empty()) {
        return prazan;
    }
    Vektor rez(*this);
    for (unsigned i=0; i < _elementi.size(); i++)
        rez._elementi[i] -= v._elementi[i];
    return rez;
}

Vektor Vektor::pomnozi(double d) const {
    Vektor rez(*this);
    for (unsigned i=0; i < rez._elementi.size(); i++)
        rez._elementi[i] *= d;
    return rez;
}

void Vektor::skalarni(Vektor v) const {
    if (_elementi.size() != v._elementi.size() && !_elementi.empty() && !v._elementi.empty()) {
        cout << "Greska u dimenzionalnosti vektora" << endl;
        return;
    }
    if (_elementi.empty() || v._elementi.empty()) {
        return;
    }
    double rez = 0;
    for (unsigned i=0; i < _elementi.size(); i++)
        rez += _elementi[i] * v._elementi[i];
    cout << rez << endl;
}

void Vektor::norma() const {
    if (_elementi.empty()) {
        return;
    }
    double rez = 0;
    for (unsigned i=0; i < _elementi.size(); i++)
        rez += _elementi[i] * _elementi[i];
    cout << sqrt(rez) << endl;
}

void Vektor::ugao(Vektor v) const {
    if (_elementi.size() != v._elementi.size() && !_elementi.empty() && !v._elementi.empty()) {
        cout << "Greska u dimenzionalnosti vektora" << endl;
        return;
    }
    if (_elementi.empty() || v._elementi.empty()) {
        return;
    }
    double skalarni = 0;
    double norma1 = 0;
    double norma2 = 0;
    for (unsigned i=0; i < _elementi.size(); i++) {
        skalarni += _elementi[i] * v._elementi[i];
        norma1 += _elementi[i] * _elementi[i];
        norma2 += v._elementi[i] * v._elementi[i];
    }
    norma1 = sqrt(norma1);
    norma2 = sqrt(norma2);
    cout << acos(skalarni/(norma1 * norma2)) << endl;
}

void Vektor::ekv(Vektor v) const {
    if (_elementi.size() != v._elementi.size() && !_elementi.empty() && !v._elementi.empty()) {
        cout << "Greska u dimenzionalnosti vektora" << endl;
        return;
    }
    if (_elementi.empty() || v._elementi.empty()) {
        return;
    }
    double skalarni = 0;
    double norma1 = 0;
    double norma2 = 0;
    for (unsigned i=0; i < _elementi.size(); i++) {
        skalarni += _elementi[i] * v._elementi[i];
        norma1 += _elementi[i] * _elementi[i];
        norma2 += v._elementi[i] * v._elementi[i];
    }
    norma1 = sqrt(norma1);
    norma2 = sqrt(norma2);
    if (acos(skalarni/(norma1 * norma2)) == 0)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}
