#ifndef __FORMULA_HPP__
#define __FORMULA_HPP__ 1

#include <iostream>

using namespace std;

class Formula {
public:
    Formula(int i) {
        _element = i;
    }
    Formula() {
        
    }
    void ispisi() const;
    int negacija() const;
    int i(Formula f) const;
    int ili(Formula f) const;
    int ekv(Formula f) const;
    int sledi(Formula f) const;
private:
    int _element; 
};

#endif
