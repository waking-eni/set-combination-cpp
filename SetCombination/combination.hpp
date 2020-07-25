#ifndef KOMBINACIJA_HPP_INCLUDED
#define KOMBINACIJA_HPP_INCLUDED

#include "set.hpp"

class Kombinacija{
    private:
        Set<int> brojevi;
    public:
        Kombinacija(const Set<int> &a) { brojevi=a; }
        Kombinacija(const Kombinacija &k) { brojevi=k.brojevi; }
        ~Kombinacija() {}
        void dodaj(int broj) { brojevi.insert(broj); }
        void ukloni(int i) { brojevi.remove(i); }
        void print() { brojevi.print(); }
        void spoji(const Kombinacija &k) {
            brojevi += k.brojevi;
        }
};

#endif // KOMBINACIJA_HPP_INCLUDED
