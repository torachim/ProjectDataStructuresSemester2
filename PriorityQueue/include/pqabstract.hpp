#ifndef ABSTRACT_PQUEUE
#define ABSTRACT_PQUEUE
#include <iostream>

namespace ProjectAlpha{

    template<class T>
    class abstract_Pqueue
    {
    public:
          virtual size_t get_size() = 0;
          virtual void insert (T data, int prioritaet) = 0;
          virtual T remove() =0; 
    };

}

#endif








//Hier folgt das Interface der Priority Queue