#include "formula.hpp"
#include <iostream>

using namespace std;

void Formula::ispisi() const {
    if (_element == 1)
        cout << "True" << endl;
    else if (_element == 0)
        cout << "False" << endl;
    else 
        cout << "Undef" << endl;
}

int Formula::negacija() const {
    if (_element == 0)
        return 1;
    if (_element == 1)
        return 0;
    return -1;
}

int Formula::i(Formula f) const {
    if (_element == 0 || f._element == 0)
        return 0;
    if (_element == 1 && f._element == 1)
        return 1;
    return -1;
}

int Formula::ili(Formula f) const {
    if (_element == 1 || f._element == 1)
        return 1;
    if (_element == 0 && f._element == 0)
        return 0;
    return -1;
}

int Formula::ekv(Formula f) const {
    Formula f1 = Formula(this->sledi(f));
    Formula f2 = Formula(f.sledi(*this));
    return f1.i(f2);
}

int Formula::sledi(Formula f) const {
    return Formula(this->negacija()).ili(f);
}
