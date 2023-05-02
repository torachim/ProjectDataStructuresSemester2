#ifndef ABSTRACT_MENGE
#define ABSTRACT_MENGE
#include <iostream>

namespace ProjectAlpha{

    template<class T>
    class geordneteMengeabstract{

        virtual void insert(T x) = 0;
        virtual bool find (T x) = 0;
        virtual void remove(T x) = 0;
    };
}

#endif