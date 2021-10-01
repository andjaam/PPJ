#ifndef __RAZLOMAK_HPP__
#define __RAZLOMAK_HPP__ 1

#include <iostream>
#include <utility>

using namespace std;

class Razlomak {
public:
    Razlomak(pair<int, int> p) {
        _elementi.first  = p.first;
        _elementi.second = p.second;
    }
    Razlomak() {
        
    }
    void ispisi() const;
    Razlomak saberi(Razlomak r) const;
    Razlomak oduzmi(Razlomak r) const;
    Razlomak pomnozi(Razlomak r) const;
    Razlomak podeli(Razlomak r) const;
    void skrati();
    void proveri(Razlomak r);
    void brojilac();
    void imenilac();
    void vrednost() const;
private:
    pair<int, int> _elementi;
};

#endif
