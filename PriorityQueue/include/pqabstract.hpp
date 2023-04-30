#ifndef ABSTRACT_PQUEUE
#define ABSTRACT_PQUEUE
#include <iostream>
#include "PQueuenode.hpp"

namespace ProjectAlpha{

    template<class T>
    class abstract_Pqueue
    {
    public:
          virtual int get_size() = 0;
          virtual void insert (PQnode <T>) = 0;
          virtual T remove() =0; 
    };

}

#endif








//Hier folgt das Interface der Priority Queue