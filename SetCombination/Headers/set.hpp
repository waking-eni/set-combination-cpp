#ifndef SET_HPP_INCLUDED
#define SET_HPP_INCLUDED

#include <iostream.h>

template <class T>
class Set{
    protected:
        T skup[20];
        int brEl;
    public:
        Set() { brEl=0; }
        Set(int, const Set<T>&);
        int getBr() const { return brEl; }
        ~Set() {}
        Set<T>& operator=(const Set<T>&);
        Set<T>& operator+=(const Set<T>&);
        Set<T>& operator*=(const Set<T>&);
        void insert(const T&);
        void remove(int k);
        void print();
};

template <class T>
Set<T>::Set(int n, const Set<T> &a){
    brEl=n;
    for (int i=0; i<n; i++)
        skup[i] = a.skup[i];
}

template <class T>
Set<T>& Set<T>::operator = (const Set<T> &s){
    brEl = s.brEl;
    for (int i=0; i<20; i++)
        skup[i] = 0;
    for (int i=0; i<s.brEl; i++)
        skup[i] = s.skup[i];

    return *this;
}

template <class T>
Set<T>& Set<T>::operator+=(const Set<T> &s){
    bool isHere;
    std::cout << brEl << "    " << s.brEl << std::endl;
    for (int i=0; i<s.brEl; i++){
        isHere = false;
        for (int j=0; j<brEl; j++){
            std::cout << i << "-" << s.skup[i] << " " << skup[j] << std::endl;
            if (skup[j] == s.skup[i]) isHere = true;}
        if (!isHere) insert(s.skup[i]);
    }
    return *this;
}

template <class T>
Set<T>& Set<T>::operator* = (const Set<T> &s){
    bool isHere;
    for (int i=0; i<brEl; i++){
        isHere = false;
        for (int j=0; j<s.brEl; j++){
            std::cout << skup[j] << " " << s.skup[i] << std::endl;
            if (skup[j] == s.skup[i]) isHere = true;}
        if (!isHere) remove(i);
    }
    return *this;
}

template <class T>
void Set<T>::insert(const T &vr){
    skup[brEl] = vr;
    brEl++;
}

template <class T>
void Set<T>::remove(int k){
    skup[k-1] = 0;
    for (int i=k; i<brEl; i++)
        skup[i] = skup[i+1];
    brEl--;
};

template <class T>
void Set<T>::print(){
    cout<<"-------SKUP-------brEl="<<brEl<<"---"<<endl;
    for (int i=0; i<brEl; i++)
        std::cout << i << ". " << skup[i] << std::endl;
    std::cout << "---------------------------" << std::endl;
}

#endif // SET_HPP_INCLUDED
