#ifndef __VEKTOR_HPP__
#define __VEKTOR_HPP__ 1

#include <iostream>
#include <vector>

using namespace std;

class Vektor {
public:
    Vektor(vector<double> v) {
        _elementi = v;
    }
    Vektor() {
        
    }
    void dodajElement(double d);
    void ispisi() const;
    Vektor saberi(Vektor v) const;
    Vektor oduzmi(Vektor v) const;
    Vektor pomnozi(double d) const;
    void skalarni(Vektor v) const;
    void norma() const;
    void ugao(Vektor v) const;
    void ekv(Vektor v) const;
private:
    vector<double> _elementi; 
};

#endif
