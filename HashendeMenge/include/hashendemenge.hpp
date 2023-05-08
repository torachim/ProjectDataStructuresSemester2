#ifndef ABSTRACT_HASH
#define ABSTRACT_HASH
#include <iostream>
#include <functional>

namespace ProjectAlpha
{
    template <class T>
    class abstract_hashendemenge
    {
    public:
        virtual void insert(const T x) = 0;                  //Einfuegen eines Wertes
        virtual bool find(const T& x)const = 0;              //Kontrolle ob ein Wert bereits in der Hashtabelle enthalten ist
        virtual void remove(const T& x) = 0;                 //Entfernt einen Wert aus der Hashtabelle
       
    };

}

#endif