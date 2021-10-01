#ifndef __SKUP_HPP__ 
#define __SKUP_HPP__ 1

#include <iostream>
#include <set>

using namespace std;

class Skup {
public:
    Skup(set<int> s) {
        _elementi = s;
    }
    Skup() {
        
    }
    void dodajElement(int e);
    void obrisiElement(int e);
    void ispisi() const;
    Skup unija(const Skup a) const;
    Skup presek(const Skup a) const;
    Skup razlika(const Skup a) const;
    void proveri(const int broj) const;
    void podskup(const Skup a) const;
    void kardinalnost() const;
private:
    set<int> _elementi;
};

#endif
