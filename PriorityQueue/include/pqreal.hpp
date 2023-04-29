#ifndef PQUEUE_REAL
#define PQUEUE_REAL
#include <iostream>
#include "pqabstract.hpp"

namespace ProjectAlpha{

    template<class T>
    class PQueue_realisation : public abstract_Pqueue<T> {
    public:

        PQueue_realisation();

        size_t get_size();

        void insert(T x);

        T remove();

        void print();

    private:

        size_t size;    

    };
}




#endif
//Hier folgt die realisation der Priority Queue