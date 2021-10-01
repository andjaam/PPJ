#ifndef __LISTA_HPP__
#define __LISTA_HPP__ 1

#include <iostream>
#include <list>

using namespace std;

class Lista {
public:
    Lista(list<int> l) {
        _elementi = l;
    }
    Lista() {
    
    }
    void dodajElement(int i);
    void ispisi() const;
    void nadovezi(Lista l);
    void izvuciGlavu() const;
    Lista izvuciRep() const;
    void izvuciElement(int i) const;
    void sortiraj() const;
    void vratiDuzinu() const;
    void skalarniProizvod(Lista l) const;
    int jednaki(Lista l) const;
private:
    list<int> _elementi;
};

#endif
